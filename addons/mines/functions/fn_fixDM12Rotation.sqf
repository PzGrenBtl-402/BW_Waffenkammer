#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Fixes rotation of DM12 mine after placing with ACE explosives system.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      _this call pbw_mines_fnc_fixDM12Rotation
 *
 */

params ["_dm12"];

if (!local _dm12) exitWith {};

// ACE Explosive placing system is rotating vehicles 180°, we want to revert this rotation.
// Stupid but better than copying the whole placing system
[{(_this select 0) getVariable ["ace_explosives_Direction", -1] isNotEqualTo -1}, {
    params ["_dm12"];

    private _dir = _dm12 getVariable ["ace_explosives_Direction", 0];
    _dm12 setDir _dir;
    _dm12 setVariable ["ace_explosives_Direction", _dir, true];
}, _this, 1] call CBA_fnc_waitUntilAndExecute;
