#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Detonates the mine spawning a projectile which will fly in the aimed direction.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 mine.
 *      1: STRING - DM12 magazine classname.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [cursorObject, "PBW_DM12"] call pbw_mines_fnc_detonateDM12
 *
 */

params ["_dm12", "_magClass"];

private _warheadBeginRelPos = _dm12 selectionPosition ["warhead_begin", "Memory"];
private _warheadBeginPosASL = _dm12 modelToWorldVisualWorld _warheadBeginRelPos;

private _dm12Config = configFile >> "CfgMagazines" >> _magClass;
private _rocketStarterClass = getText (_dm12Config >> "ammo");
private _rocketStarter = _rocketStarterClass createVehicle [0, 0, 0];
["ace_common_hideObjectGlobal", [_rocketStarter, true]] call CBA_fnc_serverEvent;

private _dir0 = getDirVisual _dm12;
private _dir = _dir0 - deg (_dm12 animationSourcePhase "mainTurret");
private _pitch0 = (_dm12 call BIS_fnc_getPitchBank) select 0;
private _pitch = _pitch0 + deg (_dm12 animationSourcePhase "mainGun");

deleteVehicle _dm12;

_rocketStarter setPosASL _warheadBeginPosASL;
_rocketStarter setDir _dir;
[_rocketStarter, _pitch, 0] call BIS_fnc_setPitchBank;

_rocketStarter setDamage 1;
