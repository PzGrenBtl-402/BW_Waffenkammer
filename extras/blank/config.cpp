#include "script_component.hpp"

class CfgPatches {
    class pbw_blank {
        name = "PBW - Blank";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"pbw_main"};
        author = "$STR_pbw_main_authors";
        authors[] = {""};
        url = "$STR_pbw_main_url";
        VERSION_CONFIG;
    };
};

#include "CfgFunctions.hpp"
