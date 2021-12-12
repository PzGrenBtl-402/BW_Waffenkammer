class CfgMagazines {
    class HandGrenade;
    class PBW_DM51A1_Frag: HandGrenade {
        author = "$STR_pbw_main_authors";
        scope = 2;
        displayName = "$STR_PBW_DM51A1_Frag_Name";
        displayNameShort = "$STR_PBW_DM51A1_Frag_NameShort";
        descriptionShort = "$STR_PBW_DM51A1_Frag_Desc";
        model = "\pbw_handgrenades\data\pbw_dm51a1.p3d";
        picture = "\pbw_handgrenades\ui\pbw_dm51a1_inv.paa";
        ammo = "PBW_DM51A1_Frag_Ammo";
        value = 1;
        mass = 9;
        initSpeed = 18;
    };

    class PBW_DM51A1_NoFrag: PBW_DM51A1_Frag {
        displayName = "$STR_PBW_DM51A1_NoFrag_Name";
        displayNameShort = "$STR_PBW_DM51A1_NoFrag_NameShort";
        descriptionShort = "$STR_PBW_DM51A1_NoFrag_Desc";
        model = "\pbw_handgrenades\data\pbw_dm51a1_nofrag.p3d";
        picture = "\pbw_handgrenades\ui\pbw_dm51a1_nofrag_inv.paa";
        ammo = "PBW_DM51A1_NoFrag_Ammo";
        mass = 9;
        initSpeed = 20;
    };
};
