#include "script_component.hpp"
/**
 *  Author: Timi007
 *
 *  Description:
 *      Event triggered after player placed fiber optic trigger cable. Starts the sensor and checks if it should trigger the mine.
 *
 *  Parameter(s):
 *      0: OBJECT - DM12 which was placed.
 *      1: STRING - DM12 magazine classname.
 *      2: ARRAY - Fibre optic cable end position ATL.
 *
 *  Returns:
 *      Nothing.
 *
 *  Example:
 *      _this call pbw_mines_fnc_startSensorCheck
 *
 */

if (!isServer) exitWith {
    ["pbw_mines_startSensorCheck", _this] call CBA_fnc_serverEvent;
};

[{
    params ["_PFHArgs", "_PFHID"];
    _PFHArgs params ["_dm12", "_magClass", "_endPosATL"];

    if (isNull _dm12 || {!alive _dm12} || {!(_dm12 getVariable ["pbw_mines_isArmed", false])}) exitWith {
        [_PFHID] call CBA_fnc_removePerFrameHandler;
    };

    private _dm12PosATL = getPosATL _dm12;
    private _centerATL = (_dm12PosATL vectorAdd _endPosATL) vectorMultiply 0.5;

    private _nearestVehicles = nearestObjects [_centerATL, ["Car", "Tank"], SENSOR_VEHICLE_RADIUS];
    if (_nearestVehicles isEqualTo []) exitWith {};

    private _xAxis = SENSOR_DEPTH;
    private _yAxis = _centerATL distance2D _dm12PosATL;
    private _zAxis = SENSOR_HEIGHT;
    private _angle = _dm12PosATL getDir _endPosATL;

    // The sensor doesn't trigger in MP when the vehicles drive fast.
    // Probably because inAreaArray checks object pos in simulation time scope.
    // Thats why we get the positions ourselves and pass them to check if they're in the area.
    private _positions = _nearestVehicles apply {getPosATLVisual _x};
    private _positionsInTriggerArea = _positions inAreaArray [_centerATL, _xAxis, _yAxis, _angle, true, _zAxis];

    if (_positionsInTriggerArea isNotEqualTo []) exitWith {
        [_PFHID] call CBA_fnc_removePerFrameHandler;

        ["pbw_mines_sensorDetectedVehicles", [_dm12, _magClass], _dm12] call CBA_fnc_targetEvent;
    };
}, 0, _this] call CBA_fnc_addPerFrameHandler;
