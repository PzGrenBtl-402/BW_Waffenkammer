#include "script_component.hpp"

class CfgPatches {
    class pbw_interactions {
        name = "PBW - Interactions";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"pbw_main", "ace_interact_menu"};
        author = "$STR_pbw_main_authors";
        authors[] = {"Lemonberries"};
        url = "$STR_pbw_main_url";
        VERSION_CONFIG;
    };
};

#include "CfgFunctions.hpp"
#include "CfgVehicles.hpp"
