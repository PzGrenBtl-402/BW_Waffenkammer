#include "script_component.hpp"
/**
 *  Author: Lemonberries
 *
 *  Description:
 *      Checks if unit can receive a non lethal granade from the player.
 *
 *  Parameter(s):
 *      0: OBJECT - Player who gives granade.
 *      1: OBJECT - Unit who receives granade.
 *
 *  Returns:
 *      BOOLEAN - Player can pass non lethal granade.
 *
 *  Example:
 *      [player, cursorObject] call pbw_interactions_fnc_canPassNonLethal
 *
 */

params ["_player", "_target"];

private _magazines = magazines _player;
private _condition = false;

{
  if (_x in ace_weaponselect_GrenadesNonFrag && _target canAdd _x) exitWith {_condition = true};
} forEach _magazines;

_condition
