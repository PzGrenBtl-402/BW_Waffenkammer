#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Creates an ACE action to stow a DM51A1 granade back into the DM51A1 box onto a specifc spot.
 *
 *  Parameter(s):
 *      0: OBJECT - DM51A1 box.
 *      1: NUMBER - Grenade id that defines where the grenade will be stowed.
 *
 *  Returns:
 *      ARRAY - ACE Action.
 *
 *  Example:
 *      [_box, 1] call pbw_handgrenades_fnc_createStowGrenadeAction
 *
 */

params [["_box", objNull, [objNull]], ["_grenadeId", 0, [0]]];

if (isNull _box || _grenadeId <= 0) exitWith {};

private _selection = format ["G%1", _grenadeId - 1];

private _stowGrenade = [
    format ["pbw_stowGrenade_%1", _grenadeId],
    localize "STR_PBW_Action_Box_Stow",
    "",
    {
        params ["_box", "_player", "_args"];
        _args params ["_grenadeId"];

        _box setVariable [format ["pbw_dm51a1_box_hasGrenade_%1", _grenadeId], true, true];

        private _animName = format ["Grenade%1", [_grenadeId, 3] call CBA_fnc_formatNumber];
        _box animateSource [_animName, 1, true];

        _player removeItem "PBW_DM51A1_Frag";
    },
    {
        params ["_box", "_player", "_args"];
        _args params ["_grenadeId"];

        _box getVariable ["pbw_dm51a1_box_isOpen", false] &&
        {!(_box getVariable [format ["pbw_dm51a1_box_hasGrenade_%1", _grenadeId], true])} &&
        {"PBW_DM51A1_Frag" in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems)}
    },
    {},
    [_grenadeId],
    _selection,
    2
] call ace_interact_menu_fnc_createAction;

_stowGrenade
