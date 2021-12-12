class CfgVehicles
{
    class Man;
    class CAManBase: Man
    {
        class ACE_SelfActions
        {
            class ACE_Equipment
            {
                class PBW_Waffenkammer_BaseAction
                {
                    displayName = "$STR_PBW_Action_WaKaBase";
                    condition = "true";
                    statement = "";
                    icon = "\pbw_main\WaKa.paa";

                    class PBW_Action_RemoveFrag
                    {
                        displayName = "$STR_PBW_Action_RemoveFrag";
                        condition = "('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                        statement = "[_player, 'removeFrag'] call pbw_handgrenades_fnc_swapGrenade";
                        icon = "\pbw_handgrenades\ui\Remove.paa";
                    };
                    class PBW_Action_MountFrag
                    {
                        displayName = "$STR_PBW_Action_MountFrag";
                        condition = "('PBW_DM51A1_NoFrag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                        statement = "[_player, 'mountFrag'] call pbw_handgrenades_fnc_swapGrenade";
                        icon = "\pbw_handgrenades\ui\Mount.paa";
                    };
                };
            };
        };
    };

    class Items_Base_F;
    class PBW_DM51A1_Penholder: Items_Base_F
    {
        author = "$STR_pbw_main_authors"
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

    class ThingX;
    class Items_base_F: ThingX
    {
        class EventHandlers;
    };

    class PBW_DM51A1_Box: Items_base_F
    {
        author = "$STR_pbw_main_authors"
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

        class EventHandlers: EventHandlers
        {
            init = "_this call pbw_handgrenades_fnc_boxInit";
        };

        class AnimationSources
        {
            class Top
            {
                source = "user";
                animPeriod = 0.7;
                initPhase = 0;
            };

            class Grenade001
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade002
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade003
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade004
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade005
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade006
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade007
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade008
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade009
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };

            class Grenade010
            {
                source = "user";
                animPeriod = 0;
                initPhase = 1;
            };
        };

        class ACE_Actions: ACE_Actions
        {
            class ACE_MainActions: ACE_MainActions
            {
                condition = "true";
                distance = 3;
                selection = "";

                class PBW_Action_Box_Open
                {
                    displayName = "$STR_PBW_Action_Box_Open";
                    condition = "!(_target getVariable 'isOpen')";
                    statement = "_target animateSource ['Top', 1]; _target setVariable ['isOpen', true, true]";
                };

                class PBW_Action_Box_Close
                {
                    displayName = "$STR_PBW_Action_Box_Close";
                    condition = "_target getVariable 'isOpen'";
                    statement = "_target animateSource ['Top', 0]; _target setVariable ['isOpen', false, true]";
                };
            };

            class PBW_Action_Box_Take01
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is01Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade001', 0]; _target setVariable ['is01Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G0";
            };

            class PBW_Action_Box_Take02
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is02Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade002', 0]; _target setVariable ['is02Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G1";
            };

            class PBW_Action_Box_Take03
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is03Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade003', 0]; _target setVariable ['is03Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G2";
            };

            class PBW_Action_Box_Take04
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is04Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade004', 0]; _target setVariable ['is04Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G3";
            };

            class PBW_Action_Box_Take05
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is05Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade005', 0]; _target setVariable ['is05Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G4";
            };

            class PBW_Action_Box_Take06
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is06Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade006', 0]; _target setVariable ['is06Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G5";
            };

            class PBW_Action_Box_Take07
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is07Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade007', 0]; _target setVariable ['is07Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G6";
            };

            class PBW_Action_Box_Take08
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is08Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade008', 0]; _target setVariable ['is08Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G7";
            };

            class PBW_Action_Box_Take09
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is09Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade009', 0]; _target setVariable ['is09Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G8";
            };

            class PBW_Action_Box_Take10
            {
                displayName = "$STR_PBW_Action_Box_Take";
                condition = "_target getVariable 'isOpen' && _target getVariable 'is10Present' && _player canAdd 'PBW_DM51A1_Frag'";
                statement = "_target animateSource ['Grenade010', 0]; _target setVariable ['is10Present', false, true]; _player addItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G9";
            };

            class PBW_Action_Box_Stow01
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is01Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade001', 1]; _target setVariable ['is01Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G0";
            };

            class PBW_Action_Box_Stow02
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is02Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade002', 1]; _target setVariable ['is02Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G1";
            };

            class PBW_Action_Box_Stow03
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is03Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade003', 1]; _target setVariable ['is03Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G2";
            };

            class PBW_Action_Box_Stow04
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is04Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade004', 1]; _target setVariable ['is04Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G3";
            };

            class PBW_Action_Box_Stow05
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is05Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade005', 1]; _target setVariable ['is05Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G4";
            };

            class PBW_Action_Box_Stow06
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is06Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade006', 1]; _target setVariable ['is06Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G5";
            };

            class PBW_Action_Box_Stow07
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is07Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade007', 1]; _target setVariable ['is07Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G6";
            };

            class PBW_Action_Box_Stow08
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is08Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade008', 1]; _target setVariable ['is08Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G7";
            };

            class PBW_Action_Box_Stow09
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is09Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade009', 1]; _target setVariable ['is09Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G8";
            };

            class PBW_Action_Box_Stow10
            {
                displayName = "$STR_PBW_Action_Box_Stow";
                condition = "_target getVariable 'isOpen' && !(_target getVariable 'is10Present') && ('PBW_DM51A1_Frag' in ([_player, false, true, true, true, false, true] call CBA_fnc_uniqueUnitItems))";
                statement = "_target animateSource ['Grenade010', 1]; _target setVariable ['is10Present', true, true]; _player removeItem 'PBW_DM51A1_Frag'";
                distance = 2;
                selection = "G9";
            };
        };
    };
};
