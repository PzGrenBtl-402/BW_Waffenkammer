class CfgAmmo {
    class ammo_Penetrator_Base;
    class PBW_DM12_Ammo_Penetrator: ammo_Penetrator_Base {
        caliber = 30;
        warheadName = "HEAT";
        hit = 350;
    };

    class RocketBase;
    class PBW_DM12_Ammo_Rocket: RocketBase {
        warheadName = "HE";
        submunitionAmmo = "PBW_DM12_Ammo_Penetrator";
        submunitionDirectionType = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0,0,-0.2};
        submunitionInitSpeed = 1000;
        submunitionParentSpeedCoef = 0;
        triggerOnImpact = 1;
        deleteParentWhenTriggered = 0;
        
        model = "\A3\Weapons_F_Tank\Launchers\MRAWS\rocket_MRAWS_HEAT_F";
        hit = 2;
        indirectHit = 15;
        indirectHitRange = 4;
        explosive = 0.8;
        cost = 400;
        airFriction = 0.05;
        sideAirFriction = 0;
        maxSpeed = 250;
        initTime = 0;
        thrustTime = 0.05;
        thrust = 2000;
        fuseDistance = 2;
        craterEffects = "ATMissileCrater";
        explosionEffects = "ATMissileExplosion";
        effectsMissileInit = "";
        effectsMissile = "EmptyEffect";
        simulationStep = 0.02;
        airLock = 0;
        aiAmmoUsageFlags = "128 + 512";
        irLock = 0;
        timeToLive = 6;
        maneuvrability = 0;
        allowAgainstInfantry = 0;
        soundHit1[] = {"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_01",2.5118864,1,1800};
        soundHit2[] = {"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_02",2.5118864,1,1800};
        soundHit3[] = {"A3\Sounds_F\arsenal\weapons\Launchers\Titan\Explosion_titan_missile_03",2.5118864,1,1800};
        multiSoundHit[] = {"soundHit1",0.34,"soundHit2",0.33,"soundHit3",0.33};
        soundFly[] = {"A3\Sounds_F\arsenal\weapons\Launchers\RPG32\Fly_RPG32",0.31622776,1.5,900};

        class CamShakeExplode {
            power = "(55*0.2)";
            duration = "((round (55^0.5))*0.2 max 0.2)";
            frequency = 20;
            distance = "((5 + 55^0.5)*8)";
        };
        class CamShakeHit {
            power = 110;
            duration = "((round (110^0.25))*0.2 max 0.2)";
            frequency = 20;
            distance = 1;
        };
        class CamShakeFire {
            power = "(20^0.25)";
            duration = "((round (20^0.5))*0.2 max 0.2)";
            frequency = 20;
            distance = "((20^0.5)*8)";
        };
        class CamShakePlayerFire {
            power = 1;
            duration = 0.1;
            frequency = 20;
            distance = 1;
        };

        SoundSetExplosion[] = {"RocketsLight_Exp_SoundSet","RocketsLight_Tail_SoundSet","Explosion_Debris_SoundSet"};
    };
    
    class SLAMDirectionalMine_Wire_Ammo;
    class PBW_DM12_Ammo: SLAMDirectionalMine_Wire_Ammo {
        explosionEffects = "ATMineExplosion";
        explosionType = "mine";
        hit = 2;
        indirectHit = 2;
        indirectHitRange = 2;
        submunitionAmmo = "PBW_DM12_Ammo_Rocket";
        submunitionModelDirection = "SubmunitionModelDirection";
        submunitionInitialOffset[] = {0, 0, 0.1};
        submunitionParentSpeedCoef = 0;
        submunitionInitSpeed = 200;
        triggerWhenDestroyed = 1;
        mineTrigger = "RemoteTrigger";
    };
};
