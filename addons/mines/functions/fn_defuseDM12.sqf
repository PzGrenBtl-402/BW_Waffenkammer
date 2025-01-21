#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Defuses the mine and stops its sensor check.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [cursorObject] call pbw_mines_fnc_defuseDM12
 *
 */

params ["_dm12"];

if !(_dm12 getVariable ["pbw_mines_isArmed", false]) exitWith {};

["pbw_mines_lock", [_dm12, false]] call CBA_fnc_targetEvent;
[_dm12, true, nil, nil, nil, true] call ace_dragging_fnc_setCarryable;
[_dm12, true, nil, nil, nil, true] call ace_dragging_fnc_setDraggable;

_dm12 animateSource ["hideCap", 0, true];

_dm12 setVariable ["pbw_mines_isArmed", false, true];

// Provide hook
["pbw_mines_DM12Defused", [_dm12]] call CBA_fnc_localEvent;
