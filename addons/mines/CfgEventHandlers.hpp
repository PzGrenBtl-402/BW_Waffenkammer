class Extended_PostInit_EventHandlers {
    class pbw_mines {
        init = "call compile preprocessFileLineNumbers '\pbw_mines\XEH_postInit.sqf'";
    };
};

class Extended_DisplayLoad_EventHandlers {
    class RscDisplayMission {
        pbw_mines = "call compile preprocessFileLineNumbers '\pbw_mines\XEH_missionDisplayLoad.sqf'";
    };
};

class Extended_InitPost_EventHandlers {
    class PBW_DM12_Static {
        class RotationFix {
            init = "call pbw_mines_fnc_fixDM12Rotation;";
        };
    };
};