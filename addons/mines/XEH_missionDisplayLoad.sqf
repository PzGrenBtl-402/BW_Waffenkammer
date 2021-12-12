#include "script_component.hpp"

if (!hasInterface) exitWith {};

params ["_display"];

_display displayAddEventHandler ["MouseButtonDown", {
    params ["", "_button"];
    
    if (pbw_mines_isPlacingCable isNotEqualTo PLACE_WAITING) exitWith {false};
    if (_button isNotEqualTo 1) exitWith {false};
    
    pbw_mines_isPlacingCable = PLACE_CANCEL;
}];