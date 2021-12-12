class CfgWeapons {
    class GrenadeLauncher;
    class Throw: GrenadeLauncher {
        class ThrowMuzzle;
        class PBW_DM51A1_Frag_Muzzle: ThrowMuzzle {
            magazines[] = { "PBW_DM51A1_Frag"};
        };
        class PBW_DM51A1_NoFrag_Muzzle: ThrowMuzzle {
            magazines[] = {"PBW_DM51A1_NoFrag"};
        };

        muzzles[] += {
            "PBW_DM51A1_Frag_Muzzle",
            "PBW_DM51A1_NoFrag_Muzzle"
        };
    };
};
