#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Checks if trigger can be set of the DM12 mine.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      BOOLEAN - Can set trigger of DM12 mine.
 *
 *  Example:
 *      [cursorObject] call pbw_mines_fnc_canSetTrigger
 *
 */
 
params ["_dm12"];

(alive _dm12) && 
{!(_dm12 getVariable ["pbw_mines_blockSetTrigger", false])} &&
{!(_dm12 getVariable ["pbw_mines_isTriggerSet", false])} &&
{!(_dm12 getVariable ["pbw_mines_isArmed", false])}