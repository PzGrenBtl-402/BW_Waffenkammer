class CfgAmmo {
    class GrenadeHand;
    class PBW_DM51A1_Frag_Ammo: GrenadeHand {
        model = "\pbw_handgrenades\data\pbw_dm51a1.p3d";
        hit = 10;

        ace_frag_enabled = 1;
        ace_frag_metal = 296;
        ace_frag_charge = 64;
        ace_frag_gurney_c = 2930;
        ace_frag_gurney_k = 1/2;
        ace_frag_classes[] = {"ACE_frag_medium_HD"};
    };

    class PBW_DM51A1_NoFrag_Ammo: GrenadeHand {
        model = "\pbw_handgrenades\data\pbw_dm51a1_nofrag.p3d";
        explosionEffectsRadius = 3;
        hit = 10;

        ace_frag_enabled = 0;
        ace_frag_skip = 1;
    };
};
