class CfgWeapons {
    class Default;
    class Put: Default {
        class PutMuzzle;
        class MineMuzzle: PutMuzzle {
            magazines[] += {"PBW_DM12"};
        };
    };
};
