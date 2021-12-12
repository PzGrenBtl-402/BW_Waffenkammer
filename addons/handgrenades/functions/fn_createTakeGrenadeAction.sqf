#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Creates an ACE action to take a specifc granade from the DM51A1 box.
 *
 *  Parameter(s):
 *      0: OBJECT - DM51A1 box.
 *      1: NUMBER - Grenade id that defines which grenade will be taken.
 *
 *  Returns:
 *      ARRAY - ACE Action.
 *
 *  Example:
 *      [_box, 1] call pbw_handgrenades_fnc_createTakeGrenadeAction
 *
 */

params [["_box", objNull, [objNull]], ["_grenadeId", 0, [0]]];

if (isNull _box || _grenadeId <= 0) exitWith {};

private _selection = format ["G%1", _grenadeId - 1];

private _takeGrenade = [
    format ["pbw_takeGrenade_%1", _grenadeId],
    localize "STR_pbw_handgrenades_DM51A1_Box_Take",
    "",
    {
        params ["_box", "_player", "_args"];
        _args params ["_grenadeId"];

        _box setVariable [format ["pbw_dm51a1_box_hasGrenade_%1", _grenadeId], false, true];

        private _animName = format ["Grenade%1", [_grenadeId, 3] call CBA_fnc_formatNumber];
        _box animateSource [_animName, 0, true];

        _player addItem "PBW_DM51A1_Frag";
    },
    {
        params ["_box", "_player", "_args"];
        _args params ["_grenadeId"];

        _box getVariable ["pbw_dm51a1_box_isOpen", false] &&
        {_box getVariable [format ["pbw_dm51a1_box_hasGrenade_%1", _grenadeId], true]} &&
        {_player canAdd "PBW_DM51A1_Frag"}
    },
    {},
    [_grenadeId],
    _selection,
    2
] call ace_interact_menu_fnc_createAction;

_takeGrenade
