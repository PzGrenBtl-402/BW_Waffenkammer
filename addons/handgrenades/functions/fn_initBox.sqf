#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Adds all ACE actions to the DM51A1 box.
 *
 *  Parameter(s):
 *      0: OBJECT - DM51A1 box.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      _this call pbw_handgrenades_fnc_initBox
 *
 */

params ["_box"];

if (!hasInterface) exitWith {};

private _openBox = [
    "pbw_openBox",
    localize "STR_pbw_handgrenades_DM51A1_Box_Open",
    "",
    {
        params ["_box"];

        _box animateSource ["Top", 1];
        _box setVariable ["pbw_dm51a1_box_isOpen", true, true];
    },
    {
        params ["_box"];
        !(_box getVariable ["pbw_dm51a1_box_isOpen", false]) // Default: the box is closed -> isOpen == false
    },
    {},
    [],
    [0,0,0],
    3
] call ace_interact_menu_fnc_createAction;
[_box, 0, ["ACE_MainActions"], _openBox] call ace_interact_menu_fnc_addActionToObject;

private _closeBox = [
    "pbw_closeBox",
    localize "STR_pbw_handgrenades_DM51A1_Box_Close",
    "",
    {
        params ["_box"];

        _box animateSource ["Top", 0];
        _box setVariable ["pbw_dm51a1_box_isOpen", false, true];
    },
    {
        params ["_box"];
        _box getVariable ["pbw_dm51a1_box_isOpen", false]
    },
    {},
    [],
    [0,0,0],
    3
] call ace_interact_menu_fnc_createAction;
[_box, 0, ["ACE_MainActions"], _closeBox] call ace_interact_menu_fnc_addActionToObject;


for "_grenadeId" from 1 to 10 do {
    private _takeGrenadeAction = [_box, _grenadeId] call pbw_handgrenades_fnc_createTakeGrenadeAction;
    [_box, 0, [], _takeGrenadeAction] call ace_interact_menu_fnc_addActionToObject;

    private _stowGrenadeAction = [_box, _grenadeId] call pbw_handgrenades_fnc_createStowGrenadeAction;
    [_box, 0, [], _stowGrenadeAction] call ace_interact_menu_fnc_addActionToObject;
};
