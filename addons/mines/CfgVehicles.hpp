class CfgVehicles {
    class LandVehicle;
    class StaticWeapon: LandVehicle {
        class Turrets;
        class ACE_Actions {
            class ACE_MainActions;
        };
    };
    class StaticATWeapon: StaticWeapon {
        class Turrets: Turrets {
            class MainTurret;
        };
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {};
        };
    };

    class PBW_DM12_Static: StaticATWeapon {
        author = "$STR_pbw_main_authors";
        scope = 1;
        side = 1;
        displayName = "$STR_pbw_mines_DM12_Name";
        displayNameShort = "$STR_pbw_mines_DM12_NameShort";
        description = "$STR_pbw_mines_DM12_Desc";
        model = "\pbw_mines\data\pbw_dm12.p3d";
        picture = "\pbw_mines\ui\pbw_dm12_picture_ca.paa";
        editorPreview = "\pbw_mines\editorpreview\pbw_dm12.jpg";
        icon = "iconExplosiveAT";
        mapSize = 0.5;
        transportSoldier = 0;
        typicalCargo[] = {"Soldier"};
        getInAction = "PlayerCrouch";
        getOutAction = "PlayerCrouch";
        editorSubcategory = "EdSubcat_Turrets";

        threat[] = {0.7, 0.3, 0};
        accuracy = 0.12;
        cost = 10000;

        armor = 400;

        // ACE
        ace_dragging_canCarry = 1;

        ace_dragging_canDrag = 1;
        ace_dragging_dragPosition[] = {0, 1, 0};
        ace_dragging_dragDirection = 0;

        ace_cargo_canLoad = 0;
        ace_cargo_noRename = 1;

        class ace_csw {
            enabled = 0;
        };

        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                selection = "main_turret_axis";
                exceptions[] = {"isNotSwimming"};
                icon = "\pbw_mines\ui\pbw_dm12_ca.paa";

                class PBW_Pickup {
                    displayName = "$STR_pbw_mines_DM12_Pickup";
                    distance = 1.5;
                    condition = "[_target] call pbw_mines_fnc_canPickupDM12";
                    statement = "[_target, _player] call pbw_mines_fnc_pickupDM12;";
                    showDisabled = 0;
                    icon = "\pbw_mines\ui\pbw_dm12_pickup_ca.paa";
                };

                class PBW_PlaceFiberOpticCable {
                    displayName = "$STR_pbw_mines_DM12_PlaceFiberOpticCable";
                    distance = 1.5;
                    condition = "[_target] call pbw_mines_fnc_canSetTrigger";
                    statement = "[_player, _target, 'PBW_DM12'] call pbw_mines_fnc_placeFiberOpticCable;";
                    showDisabled = 0;
                    icon = "\pbw_mines\ui\pbw_fibreOpticCable_ca.paa";
                };

                class PBW_PickupFiberOpticCable {
                    displayName = "$STR_pbw_mines_DM12_PickupFiberOpticCable";
                    distance = 1.5;
                    condition = "[_target] call pbw_mines_fnc_canPickupFiberOpticCable";
                    statement = "[_target] call pbw_mines_fnc_pickupFiberOpticCable";
                    showDisabled = 0;
                    icon = "\pbw_mines\ui\pbw_fibreOpticCable_pickup_ca.paa";
                };

                class PBW_ArmDM12 {
                    displayName = "$STR_pbw_mines_DM12_Arm";
                    distance = 1.5;
                    condition = "[_target] call pbw_mines_fnc_canArmDM12";
                    statement = "[_target] call pbw_mines_fnc_armDM12;";
                    showDisabled = 0;
                    icon = "\pbw_mines\ui\pbw_dm12_arm_ca.paa";
                };

                class PBW_DefuseDM12 {
                    displayName = "$STR_pbw_mines_DM12_Defuse";
                    distance = 1.5;
                    condition = "[_target] call pbw_mines_fnc_canDefuseDM12";
                    statement = "[_target] call pbw_mines_fnc_defuseDM12;";
                    showDisabled = 0;
                    icon = "\pbw_mines\ui\pbw_dm12_defuse_ca.paa";
                };
            };
        };

        class AnimationSources {
            class hideCap {
                source = "user";
                animPeriod = 0;
                initPhase = 0;
            };
        };

        class Turrets: Turrets {
            class MainTurret: MainTurret {
                minTurn = -45;
                maxTurn = 45;
                initTurn = 0;
                minElev = -30;
                maxElev = 50;
                initElev = 0;

                class ViewGunner {
                    initAngleX = 0;
                    minAngleX = -30;
                    maxAngleX = 30;
                    initAngleY = 0;
                    minAngleY = -100;
                    maxAngleY = 100;
                    minFov = 0.8; // max zoom
                    maxFov = 0.42; // min zoom
                    initFov= 0.7;
                };

                weapons[] = {};
                magazines[] = {};
                gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty.p3d";
                gunnerOpticsEffect[] = {"OpticsCHAbera1","OpticsBlur2"};
                gunnerOutOpticsShowCursor = 0;
                gunnerOpticsShowCursor = 0;
                gunnerAction = "gunner_static_low01";
                gunnerGetInAction = "PlayerCrouch";
                gunnerGetOutAction = "PlayerCrouch";
                ejectDeadGunner = 1;
            };
        };

        class Damage {
            tex[] = {};
            mat[] = {
                "pbw_mines\data\pbw_dm12.rvmat",
                "pbw_mines\data\pbw_dm12_damage.rvmat",
                "pbw_mines\data\pbw_dm12_destruct.rvmat",

                "pbw_mines\data\pbw_dm12_metal.rvmat",
                "pbw_mines\data\pbw_dm12_metal_damage.rvmat",
                "pbw_mines\data\pbw_dm12_metal_destruct.rvmat"
            };
        };
    };

    class PBW_B_DM12: PBW_DM12_Static {
        _generalMacro = "PBW_B_DM12";
        scope = 2;
        side = 1;
        faction = "BLU_F";
        crew = "B_soldier_exp_F";
    };

    class PBW_O_DM12: PBW_DM12_Static {
        _generalMacro = "PBW_O_DM12";
        scope = 2;
        side = 0;
        faction = "OPF_F";
        crew = "O_soldier_exp_F";
    };

    class PBW_I_DM12: PBW_DM12_Static {
        _generalMacro = "PBW_I_DM12";
        scope = 2;
        side = 2;
        faction = "IND_F";
        crew = "I_soldier_exp_F";
    };

    class PBW_B_T_DM12: PBW_DM12_Static {
        _generalMacro = "PBW_B_T_DM12";
        scope = 2;
        side = 1;
        faction = "BLU_T_F";
        crew = "B_T_soldier_exp_F";
    };

    class PBW_O_T_DM12: PBW_DM12_Static {
        _generalMacro = "PBW_O_T_DM12";
        scope = 2;
        side = 0;
        faction = "OPF_T_F";
        crew = "O_T_soldier_exp_F";
    };

    class Item_Base_F;
    class PBW_Item_DM12: Item_Base_F {
        author = "$STR_pbw_main_authors";
        scope = 2;
        scopeCurator = 2;
        displayName = "$STR_pbw_mines_DM12_Name";
        displayNameShort = "$STR_pbw_mines_DM12_NameShort";
        vehicleClass = "Items";
        editorCategory = "EdCat_Equipment";
        editorSubcategory = "EdSubcat_InventoryItems";
        editorPreview = "\pbw_mines\editorpreview\pbw_dm12.jpg";
        class TransportItems {
            class _xx_PBW_DM12 {
                name = "PBW_DM12";
                count = 1;
            };
        };
    };
};
