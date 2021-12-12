#include "script_component.hpp"

class CfgPatches {
    class pbw_mines {
        name = "PBW - Mines";
        units[] = {
            "PBW_B_DM12",
            "PBW_O_DM12",
            "PBW_I_DM12",
            "PBW_B_T_DM12",
            "PBW_O_T_DM12",
            "PBW_Item_DM12"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"pbw_main", "ace_interact_menu", "ace_explosives", "ace_dragging"};
        author = "$STR_pbw_main_authors";
        authors[] = {"Timi007", "Herr_KaLeun"};
        url = "$STR_pbw_main_url";
        VERSION_CONFIG;
    };
};

#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"
#include "CfgFunctions.hpp"
#include "CfgEventHandlers.hpp"

#include "ACE_Triggers.hpp"
