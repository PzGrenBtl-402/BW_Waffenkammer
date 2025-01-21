#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Arms the DM12 mine. Start the checks for the trigger.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [cursorObject] call pbw_mines_fnc_armDM12
 *
 */

params ["_dm12"];

private _endPosATL = _dm12 getVariable ["pbw_mines_fiberOpticCableEndPos", []];
if ((_endPosATL isEqualTo []) || {_dm12 getVariable ["pbw_mines_isArmed", false]}) exitWith {};

_dm12 setVariable ["pbw_mines_isArmed", true, true];

["pbw_mines_lock", [_dm12, true]] call CBA_fnc_targetEvent;
[_dm12, false, nil, nil, nil, true] call ace_dragging_fnc_setCarryable;
[_dm12, false, nil, nil, nil, true] call ace_dragging_fnc_setDraggable;

_dm12 animateSource ["hideCap", 1, true];

private _magClass = _dm12 getVariable ["pbw_mines_magClass", "PBW_DM12"];
["pbw_mines_startSensorCheck", [_dm12, _magClass, _endPosATL]] call CBA_fnc_serverEvent;

// Provide hook
["pbw_mines_DM12Armed", [_dm12]] call CBA_fnc_localEvent;
