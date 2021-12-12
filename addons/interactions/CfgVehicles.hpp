class CfgVehicles {
	class Man;
	class CAManBase: Man {
		class ACE_Actions {
			class ACE_MainActions {
				class PBW_PassGrenade {
					displayName = "$STR_pbw_interactions_PassGrenade";
					condition = "";
					statement = "";
					icon = "\pbw_interactions\ui\pbw_grenade.paa";

					class PBW_PassLethal {
						displayName = "$STR_pbw_interactions_PassLethal";
						condition = "[_player, _target] call pbw_interactions_fnc_canPassLethal";
						statement = "[_player, _target] call pbw_interactions_fnc_passLethal";
						icon = "\pbw_interactions\ui\pbw_lethal.paa";
					};

					class PBW_PassNonLethal {
						displayName = "$STR_pbw_interactions_PassNonLethal";
						condition = "[_player, _target] call pbw_interactions_fnc_canPassNonLethal";
						statement = "[_player, _target] call pbw_interactions_fnc_passNonLethal";
						icon = "\pbw_interactions\ui\pbw_non_lethal.paa";
					};
				};
			};
		};
	};
};
