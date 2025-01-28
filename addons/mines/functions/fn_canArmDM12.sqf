#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Checks if DM12 mine can be armed.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      BOOLEAN - Can arm DM12 mine.
 *
 *  Example:
 *      [cursorObject] call pbw_mines_fnc_canArmDM12
 *
 */

params ["_dm12"];

(alive _dm12) &&
{(crew _dm12) isEqualTo []} &&
{(_dm12 getVariable ["pbw_mines_fiberOpticCableEndPos", []]) isNotEqualTo []} &&
{!(_dm12 getVariable ["pbw_mines_isArmed", false])}
