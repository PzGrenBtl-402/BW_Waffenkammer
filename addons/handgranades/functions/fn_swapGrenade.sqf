#include "script_component.hpp"
/**
 *  Author: Lemonberries
 *
 *  Description:
 *      [Description]
 *
 *  Parameter(s):
 *      0: [TYPE] - [argument name]
 *
 *  Returns:
 *      [TYPE] - [return name]
 *
 *  Example:
 *      [[arguments]] call [function name]
 *
 */

params ["_unit", "_typeOfSwap"];
private ["_itemToAdd", "_itemToRemove", "_text"];

if (_typeOfSwap isEqualTo "removeFrag") then {
    _itemToAdd = "PBW_DM51A1_NoFrag";
    _itemToRemove = "PBW_DM51A1_Frag";
    _text = localize "STR_PBW_Action_Removing";
} else {
    _itemToAdd = "PBW_DM51A1_Frag";
    _itemToRemove = "PBW_DM51A1_NoFrag";
    _text = localize "STR_PBW_Action_Mounting";
};

if (_itemToRemove in ((getMagazineCargo (vestContainer _unit)) select 0)) exitWith {
    [2, [_unit, _itemToRemove, _itemToAdd], {
        params ["_args"];
        _args params ["_unit", "_itemToRemove", "_itemToAdd"];

        _unit removeItemFromVest _itemToRemove;
        _unit addItemToVest _itemToAdd;
    }, {}, _text] call ace_common_fnc_progressBar;
};

if (_itemToRemove in ((getMagazineCargo (uniformContainer _unit)) select 0)) exitWith {
    [2, [_unit, _itemToRemove, _itemToAdd], {
        params ["_args"];
        _args params ["_unit", "_itemToRemove", "_itemToAdd"];

        _unit removeItemFromUniform _itemToRemove;
        _unit addItemToUniform _itemToAdd;
    }, {}, _text] call ace_common_fnc_progressBar;
};

if (_itemToRemove in ((getMagazineCargo (backpackContainer _unit)) select 0)) exitWith {
    [2, [_unit, _itemToRemove, _itemToAdd], {
        params ["_args"];
        _args params ["_unit", "_itemToRemove", "_itemToAdd"];

        _unit removeItemFromBackpack _itemToRemove;
        _unit addItemToBackpack _itemToAdd;
    }, {}, _text] call ace_common_fnc_progressBar;
};
