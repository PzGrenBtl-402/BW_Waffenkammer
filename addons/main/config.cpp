#include "script_component.hpp"

class CfgPatches {
    class pbw_main {
        name = "PBW - Main";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"cba_main", "ace_main"};
        author = "$STR_pbw_main_authors";
        url = "$STR_pbw_main_url";
        VERSION_CONFIG;
    };
};

class CfgMods {
    class pbw_main {
        dir = "@Bundeswehr_Waffenkammer";
        name = "Bundeswehr Waffenkammer";
        picture = "A3\Ui_f\data\Logos\arma3_expansion_alpha_ca";
        hidePicture = "true";
        hideName = "true";
        actionName = "GitHub";
        action = "$STR_pbw_main_url";
        description = "Issue Tracker: ";
    };
};


class CfgSettings {
    class CBA {
        class Versioning {
            class pbw_main {
                class dependencies {
                    CBA[] = {"cba_main", REQUIRED_CBA_VERSION, "true"};
                    ACE[] = {"ace_main", REQUIRED_ACE_VERSION, "true"};
                };
            };
        };
    };
};
