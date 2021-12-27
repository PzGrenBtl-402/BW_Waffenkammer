#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Event triggered after player placed fiber optic trigger cable. Starts the sensor and checks if it should trigger the mine.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 which was placed.
 *      1: STRING - DM12 magazine classname.
 *      2: ARRAY - Fibre optic cable end positon ATL.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      _this call pbw_mines_fnc_startSensorCheck
 *
 */

[{
    params ["_PFHArgs", "_PFHID"];
    _PFHArgs params ["_dm12", "_magClass", "_endPosATL"];

    if (isNull _dm12 || !(alive _dm12) || !(_dm12 getVariable ["pbw_mines_isArmed", false])) exitWith {
        [_PFHID] call CBA_fnc_removePerFrameHandler;
    };

    private _dm12PosATL = getPosATL _dm12;
    private _centerATL = (_dm12PosATL vectorAdd _endPosATL) vectorMultiply 0.5;

    private _xAxis = 0.5;
    private _yAxis = _centerATL distance2D _dm12PosATL;
    private _zAxis = 5;
    private _angle = _dm12PosATL getDir _endPosATL;

    private _allVehicles = vehicles select {_x isKindOf "Car" || _x isKindOf "Tank"};
    // The sensor doesn't trigger in MP when the vehicles drive fast.
    // Probably because inAreaArray checks object pos in simulation time scope.
    // Thats why we get the positions ourselfs and pass them to check if they're in the area.
    private _allPositions = _allVehicles apply {getPosATLVisual _x};
    private _positionsInTriggerArea = _allPositions inAreaArray [_centerATL, _xAxis, _yAxis, _angle, true, _zAxis];

    if (count _positionsInTriggerArea > 0) exitWith {
        [_PFHID] call CBA_fnc_removePerFrameHandler;

        ["pbw_mines_sensorDetectedVehicles", [_dm12, _magClass], _dm12] call CBA_fnc_targetEvent;
    };
}, 0, _this] call CBA_fnc_addPerFrameHandler;
