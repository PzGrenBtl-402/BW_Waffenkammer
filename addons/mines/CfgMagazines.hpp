class CfgMagazines {
    class CA_Magazine;
    class PBW_DM12: CA_Magazine {
        author = "$STR_pbw_main_authors";
        scope = 2;
        displayName = "$STR_pbw_mines_DM12_Name";
        displayNameShort = "$STR_pbw_mines_DM12_NameShort";
        descriptionShort = "$STR_pbw_mines_DM12_Desc";
        descriptionUse = "$STR_pbw_mines_DM12_Desc";
        model = "\pbw_mines\data\pbw_dm12.p3d";
        picture = "\pbw_mines\ui\pbw_dm12_picture_ca.paa";
        ammo = "PBW_DM12_Ammo";
        initSpeed = 0;
        type = "2 * 256";
        count = 1;
        mass = 80; // real mine is 9.6kg but this is too big for normal backpacks

        useAction = 0;
        ACE_explosives_Placeable = 1;
        ACE_explosives_SetupObject = "PBW_DM12_Static";

        class ACE_Triggers {
            SupportedTriggers[] = {"FibreOpticCable"};
            class FibreOpticCable {
                maxCableLength = 40;
            };
        };
    };
};
