#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Starts the process of placing the fiber optic trigger cable and saves the end location in the mine.
 *
 *  Parameter(s):
 *      0: OBJECT - Player.
 *      1: OBJECT - DM12 which was placed.
 *      2: STRING - DM12 magazine classname.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [player, cursorObject, "PBW_DM12"] call pbw_mines_fnc_placeFiberOpticCable
 *
 */

params ["_player", "_dm12", "_magClass"];

private _endPointHelper = ENDPOINTHELPER_CLASS createVehicleLocal [0, 0, 0];
_endPointHelper setVectorDirAndUp [[0, 0, 1], [0, 1, 0]];
_endPointHelper enableSimulation false;

pbw_mines_isPlacingCable = PLACE_WAITING;
_dm12 setVariable ["pbw_mines_blockSetTrigger", true, true];

[localize "STR_pbw_mines_DM12_PlaceFiberOpticCableAction", localize "STR_pbw_mines_DM12_Cancel"] call ace_interaction_fnc_showMouseHint;
private _mouseClickID = [
    _player,
    "DefaultAction",
    {pbw_mines_isPlacingCable isEqualTo PLACE_WAITING},
    {pbw_mines_isPlacingCable = PLACE_APPROVE}
] call ace_common_fnc_addActionEventHandler;

private _maxCableLength = getNumber (configFile >> "CfgMagazines" >> _magClass >> "ACE_Triggers" >> "FibreOpticCable" >> "maxCableLength");

[{
    params ["_PFHArgs", "_PFHID"];
    _PFHArgs params ["_endPointHelper", "_player", "_dm12", "_magClass", "_mouseClickID", "_maxCableLength"];

    if (isNull _endPointHelper) then {
        pbw_mines_isPlacingCable = PLACE_CANCEL;
    };

    private _endPointPos = ((eyePos _player) vectorAdd ((getCameraViewDirection _player) vectorMultiply ENDPOINTHELPER_DISTANCE));
    _endPointPos set [2, ENDPOINTHELPER_HEIGHT];

    _endPointHelper setPosATL _endPointPos;

    private _dm12Pos = getPosATL _dm12;
    private _begin = [_dm12Pos select 0, _dm12Pos select 1, CABLE_HEIGHT];

    private _cableLength = 0;
    private _stopExtendingLines = false;

    private ["_end"];
    while {true} do {
        private _vec = _endPointPos vectorDiff _begin;

        private _segmentLength = vectorMagnitude _vec;
        if (_segmentLength < CABLE_SEGMENT_LENGTH) then {
            _stopExtendingLines = true;
            _end = +_endPointPos;
            _cableLength = _cableLength + _segmentLength;
        } else {
            _vecNorm = vectorNormalized _vec;
            _end = _begin vectorAdd (_vecNorm vectorMultiply CABLE_SEGMENT_LENGTH);
            _cableLength = _cableLength + CABLE_SEGMENT_LENGTH;
        };

        private _lineStart = [_begin select 0, _begin select 1, CABLE_HEIGHT];
        private _lineEnd = [_end select 0, _end select 1, CABLE_HEIGHT];

        private _color = [CABLE_COLOR_BAD, CABLE_COLOR_GOOD] select (_cableLength <= _maxCableLength);

        drawLine3D [_lineStart, _lineEnd, _color];

        if (_stopExtendingLines) then {break};

        _begin = _end;
    };

    private _ctrlTextLMB = (uiNamespace getVariable ["ace_interaction_mouseHint", displayNull]) displayCtrl 2420;
    if (_cableLength <= _maxCableLength) then {
        _ctrlTextLMB ctrlSetText format [localize "STR_pbw_mines_DM12_PlaceFiberOpticCableAction", _maxCableLength - round _cableLength];
    } else {
        _ctrlTextLMB ctrlSetText localize "STR_pbw_mines_DM12_FiberOpticCableTooShort";
    };

    if (_cableLength > _maxCableLength && {pbw_mines_isPlacingCable isEqualTo PLACE_APPROVE}) then {
        pbw_mines_isPlacingCable = PLACE_WAITING;
    };

    if (pbw_mines_isPlacingCable isNotEqualTo PLACE_WAITING) exitWith {
        [_PFHID] call CBA_fnc_removePerFrameHandler;
        call ace_interaction_fnc_hideMouseHint;
        [_player, "DefaultAction", _mouseClickID] call ace_common_removeActionEventHandler;

        _dm12 setVariable ["pbw_mines_blockSetTrigger", false, true];

        if (pbw_mines_isPlacingCable isEqualTo PLACE_APPROVE) then {
            pbw_mines_isPlacingCable = PLACE_CANCEL;

            // End position of the object
            _player playAction "putdown";

            private _endPosATL = getPosATL _endPointHelper;
            _endPosATL set [2, 0];
            deleteVehicle _endPointHelper;

            _dm12 setVariable ["pbw_mines_fiberOpticCableEndPos", _endPosATL, true];
            _dm12 setVariable ["pbw_mines_magClass", _magClass, true];

            // Provide hook
            ["pbw_mines_DM12Placed", [_dm12, _magClass, _endPosATL]] call CBA_fnc_localEvent;
        } else {
            // Action is canceled
            deleteVehicle _endPointHelper;
        };
    };
}, 0, [_endPointHelper, _player, _dm12, _magClass, _mouseClickID, _maxCableLength]] call CBA_fnc_addPerFrameHandler;
