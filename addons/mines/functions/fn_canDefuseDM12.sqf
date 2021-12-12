#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Checks if DM12 mine can be defused.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      BOOLEAN - Can defuse DM12 mine.
 *
 *  Example:
 *      [cursorObject] call pbw_mines_fnc_canDefuseDM12
 *
 */

params ["_dm12"];

(alive _dm12) && 
{_dm12 getVariable ["pbw_mines_isArmed", false]}