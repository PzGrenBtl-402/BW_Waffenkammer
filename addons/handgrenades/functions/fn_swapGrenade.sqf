#include "script_component.hpp"
/**
 *  Author: Lemonberries
 *
 *  Description:
 *      Switches the granades between the version with or without fragmentation sleeve.
 *
 *  Parameter(s):
 *      0: OBJECT - Player.
 *      1: STRING - Type of switch: "removeFrag" or "mountFrag"
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      [_player, "removeFrag"] call pbw_handgrenades_fnc_swapGrenade
 *
 */

params [["_unit", objNull, [objNull]], ["_typeOfSwap", "", [""]]];
private ["_itemToAdd", "_itemToRemove", "_text"];

if (_typeOfSwap isEqualTo "removeFrag") then {
    _itemToAdd = "PBW_DM51A1_NoFrag";
    _itemToRemove = "PBW_DM51A1_Frag";
    _text = localize "STR_pbw_handgrenades_DM51A1_RemovingFrag";
} else {
    _itemToAdd = "PBW_DM51A1_Frag";
    _itemToRemove = "PBW_DM51A1_NoFrag";
    _text = localize "STR_pbw_handgrenades_DM51A1_MountingFrag";
};

private _itemLocation = switch true do {
    case (_itemToRemove in ((getMagazineCargo (vestContainer _unit)) select 0)): {
        "vest"
    };
    case (_itemToRemove in ((getMagazineCargo (uniformContainer _unit)) select 0)): {
        "uniform"
    };
    case (_itemToRemove in ((getMagazineCargo (backpackContainer _unit)) select 0)): {
        "backpack"
    };
    default {""};
};

if (_itemLocation isEqualTo "") exitWith {};

private _swapTime = 2;
[_swapTime, [_unit, _itemLocation, _itemToRemove, _itemToAdd], {
    params ["_args"];
    _args params ["_unit", "_itemLocation", "_itemToRemove", "_itemToAdd"];

    switch _itemLocation do {
        case "vest": {
            _unit removeItemFromVest _itemToRemove;
            _unit addItemToVest _itemToAdd;
        };
        case "uniform": {
            _unit removeItemFromUniform _itemToRemove;
            _unit addItemToUniform _itemToAdd;
        };
        case "backpack": {
            _unit removeItemFromBackpack _itemToRemove;
            _unit addItemToBackpack _itemToAdd;
        };
    };
}, {}, _text, {true}, ["isNotInside", "isNotSitting"]] call ace_common_fnc_progressBar;
