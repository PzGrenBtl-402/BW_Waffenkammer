#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Picks up DM12 mine and adds it to the inventory.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *      1: OBJECT - Player who picks up the mine.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [cursorObject, player] call pbw_mines_fnc_DM12_pickup
 *
 */

params ["_dm12", "_player"];

_player playAction "putdown";

[{((animationState (_this select 1)) select [25,7]) isEqualTo "putdown"}, {
    params ["_dm12", "_player"];
    
    deleteVehicle _dm12;
    [_player, "PBW_DM12"] call ace_common_fnc_addToInventory;
}, _this] call CBA_fnc_waitUntilAndExecute;

