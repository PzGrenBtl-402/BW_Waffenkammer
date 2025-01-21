#include "script_component.hpp"

if (hasInterface) then {
    pbw_mines_isPlacingCable = PLACE_CANCEL;
    ["ace_interactMenuOpened", {pbw_mines_isPlacingCable = PLACE_CANCEL;}] call CBA_fnc_addEventHandler;
    player addEventHandler ["Killed", {pbw_mines_isPlacingCable = PLACE_CANCEL;}];
    ["ace_unconscious", {
        params ["_unit"];

        if (ACE_player isEqualTo _unit) exitWith {
            pbw_mines_isPlacingCable = PLACE_CANCEL;
        };
    }] call CBA_fnc_addEventHandler;
};

if (isServer) then {
    ["pbw_mines_startSensorCheck", pbw_mines_fnc_startSensorCheck] call CBA_fnc_addEventHandler;
    ["pbw_mines_sensorDetectedVehicles", pbw_mines_fnc_detonateDM12] call CBA_fnc_addEventHandler;
};

["pbw_mines_lock", {
    params ["_vehicle", ["_lock", false, [false]]];
    _vehicle lock ([0, 2] select _lock);
}] call CBA_fnc_addEventHandler;
