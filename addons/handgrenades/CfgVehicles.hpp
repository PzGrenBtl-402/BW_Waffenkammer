class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_SelfActions {
            class ACE_Equipment {
                class PBW_Handgrenades {
                    displayName = "$STR_PBW_Action_Frag";
                    icon = "\pbw_handgrenades\ui\pbw_dm51a1_grenade.paa";

                    class PBW_RemoveFrag {
                        displayName = "$STR_PBW_Action_RemoveFrag";
                        condition = "('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                        statement = "[_player, 'removeFrag'] call pbw_handgrenades_fnc_swapGrenade";
                        icon = "\pbw_handgrenades\ui\pbw_dm51a1_remove_frag.paa";
                    };
                    class PBW_MountFrag {
                        displayName = "$STR_PBW_Action_MountFrag";
                        condition = "('PBW_DM51A1_NoFrag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                        statement = "[_player, 'mountFrag'] call pbw_handgrenades_fnc_swapGrenade";
                        icon = "\pbw_handgrenades\ui\pbw_dm51a1_mount_frag.paa";
                    };
                };
            };
        };
    };

    class Items_Base_F;
    class PBW_DM51A1_Penholder: Items_Base_F {
        author = "$STR_pbw_main_authors";
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_PBW_DM51A1_Penholder";
        model = "\pbw_handgrenades\data\pbw_dm51a1_penholder.p3d";
        vehicleClass = "Small_items";
        icon = "iconObject_1x1";
        editorCategory = "EdCat_Things";
        editorSubcategory = "EdSubcat_Office";
        editorPreview = "";
    };

    class PBW_DM51A1_Box: Items_base_F {
        author = "$STR_pbw_main_authors";
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_PBW_DM51A1_Box";
        model = "\pbw_handgrenades\data\pbw_dm51a1_box.p3d";
        vehicleClass = "Ammo";
        icon = "iconObject_1x1";
        editorCategory = "EdCat_Supplies";
        editorPreview = "";

        ace_cargo_size = 1;
        ace_cargo_canLoad = 1;
        ace_dragging_canDrag = 1;
        ace_dragging_canCarry = 1;

        class AnimationSources {
            class Top {
                source = "user";
                animPeriod = 0.7;
                initPhase = 0;
            };

            class Grenade001 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade002 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade003 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade004 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade005 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade006 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade007 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade008 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade009 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade010 {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };
        };
    };
};
