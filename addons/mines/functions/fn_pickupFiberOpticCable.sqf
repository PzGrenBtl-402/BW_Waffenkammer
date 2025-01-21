#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Picks up fibre optic cable.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [cursorObject] call pbw_mines_fnc_pickupFiberOpticCable
 *
 */

params ["_dm12"];

if ((_dm12 getVariable ["pbw_mines_fiberOpticCableEndPos", []]) isEqualTo []) exitWith {};

_dm12 setVariable ["pbw_mines_fiberOpticCableEndPos", nil, true];
_dm12 setVariable ["pbw_mines_magClass", nil, true];
