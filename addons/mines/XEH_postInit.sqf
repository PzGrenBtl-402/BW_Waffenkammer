#include "script_component.hpp"

if (hasInterface) then {
    pbw_mines_isPlacingCable = PLACE_CANCEL;
    ["ace_interactMenuOpened", {pbw_mines_isPlacingCable = PLACE_CANCEL;}] call CBA_fnc_addEventHandler;
    player addEventHandler ["Killed", {pbw_mines_isPlacingCable = PLACE_CANCEL;}];
    ["ace_unconscious", {
        params ["_unit"];

        if (player isEqualTo _unit) exitWith {
            pbw_mines_isPlacingCable = PLACE_CANCEL;
        };
    }] call CBA_fnc_addEventHandler;
};

["pbw_mines_lockDM12", {
    params ["_dm12", "_lock"];

    _dm12 lock ([0, 2] select _lock);

    [_dm12, !_lock] call ace_dragging_fnc_setCarryable;
    [_dm12, !_lock] call ace_dragging_fnc_setDraggable;
}] call CBA_fnc_addEventHandler;

["pbw_mines_armDM12Sensor", {_this call pbw_mines_fnc_startSensorCheck}] call CBA_fnc_addEventHandler;
["pbw_mines_sensorDetectedVehicles", {_this call pbw_mines_fnc_detonateDM12}] call CBA_fnc_addEventHandler;
