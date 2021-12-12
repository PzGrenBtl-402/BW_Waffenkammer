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

if (!(_dm12 getVariable ["pbw_mines_isTriggerSet", false]) || _dm12 getVariable ["pbw_mines_isArmed", false]) exitWith {};

_dm12 setVariable ["pbw_mines_isArmed", true, true];

["pbw_mines_lockDM12", [_dm12, true], "pbw_mines_lockDM12"] call CBA_fnc_globalEventJIP;

_dm12 animateSource ["hideCap", 1, true];

private _endPosATL = _dm12 getVariable ["pbw_mines_fiberOpticCableEndPos", []];
private _class = _dm12 getVariable ["pbw_mines_magClass", "PBW_DM12"];

["pbw_mines_armDM12Sensor", [_dm12, _class, _endPosATL]] call CBA_fnc_serverEvent;