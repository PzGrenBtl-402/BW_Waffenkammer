#include "script_component.hpp"

class CfgPatches {
    class pbw_handgrenades {
        name = "PBW - Handgranades";
        units[] = {
            "PBW_DM51A1_Box",
            "PBW_DM51A1_Penholder"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "pbw_main",
            "ace_common",
            "ace_frag",
            "ace_interact_menu",
            "ace_dragging",
            "ace_cargo",
            "ace_medical_treatment"
        };
        author = "$STR_pbw_main_authors";
        authors[] = {"Herr_KaLeun", "Lemonberries"};
        url = "$STR_pbw_main_url";
        VERSION_CONFIG;
    };
};

#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgAmmo.hpp"
#include "CfgVehicles.hpp"
#include "CfgFunctions.hpp"
