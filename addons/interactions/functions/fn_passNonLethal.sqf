#include "script_component.hpp"
/**
 *  Author: Lemonberries
 *
 *  Description:
 *      Passes non lethal granade to unit.
 *
 *  Parameter(s):
 *      0: OBJECT - Player who gives granade.
 *      1: OBJECT - Unit who receives granade.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [player, cursorObject] call pbw_interactions_fnc_passNonLethal
 *
 */

params ["_player", "_target"];

private _magazines = magazines _player;
private _grenade = "";
{
    if (_x in ace_weaponselect_GrenadesNonFrag) exitWith {_grenade = _x};
} forEach _magazines;

_player removeItem _grenade;
_target addItem _grenade;
[_player, "PutDown"] call ace_common_fnc_doGesture;
