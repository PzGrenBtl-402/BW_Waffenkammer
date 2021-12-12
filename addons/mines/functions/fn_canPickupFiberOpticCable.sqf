#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Checks if fibre optic cable can be picked up.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      BOOLEAN - Can pick up fibre optic cable.
 *
 *  Example:
 *      [cursorObject] call pbw_mines_fnc_canPickupFiberOpticCable
 *
 */

params ["_dm12"];

(alive _dm12) &&
{!(_dm12 getVariable ["pbw_mines_isArmed", false])} &&
{_dm12 getVariable ["pbw_mines_isTriggerSet", false]}