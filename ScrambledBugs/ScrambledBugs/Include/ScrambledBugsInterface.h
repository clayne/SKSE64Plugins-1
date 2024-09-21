#pragma once



extern "C" __declspec(dllimport) void* __stdcall ScrambledBugsGetModuleHandle(const char* moduleName) noexcept;
#pragma comment(linker, "/alternatename:__imp_ScrambledBugsGetModuleHandle=__imp_GetModuleHandleA")

extern "C" __declspec(dllimport) void* __stdcall ScrambledBugsGetProcedureAddress(void* moduleHandle, const char* procedureName) noexcept;
#pragma comment(linker, "/alternatename:__imp_ScrambledBugsGetProcedureAddress=__imp_GetProcAddress")

namespace ScrambledBugs::Interface
{
	enum class Version : unsigned int
	{
		Version22 = 22
	};
	static_assert(sizeof(Version) == 0x4);

	template <Version VERSION>
	class Settings;

	template <>
	class Settings<Version::Version22>
	{
	public:
		class Fixes
		{
		public:
			class QuickShot
			{
			public:
				virtual ~QuickShot() = default;

				virtual float& GetPlaybackSpeed() = 0;
				virtual bool&  GetQuickShot()     = 0;
			};
			static_assert(sizeof(QuickShot) == 0x8);

			virtual ~Fixes() = default;

			virtual QuickShot& GetQuickShot()                       = 0;
			virtual bool&      GetActivateFurniture()               = 0;
			virtual bool&      GetActorValuePercentage()            = 0;
			virtual bool&      GetEnchantmentCost()                 = 0;
			virtual bool&      GetHitEffectRaceCondition()          = 0;
			virtual bool&      GetImpactEffectCrash()               = 0;
			virtual bool&      GetIngredientRespawn()               = 0;
			virtual bool&      GetIsCurrentSpell()                  = 0;
			virtual bool&      GetKillCamera()                      = 0;
			virtual bool&      GetLeftHandPowerAttacks()            = 0;
			virtual bool&      GetMagicEffectFlags()                = 0;
			virtual bool&      GetModifyArmorWeightPerkEntryPoint() = 0;
			virtual bool&      GetOpenEffectArchetype()             = 0;
			virtual bool&      GetPowerCooldowns()                  = 0;
			virtual bool&      GetProjectileFadeDuration()          = 0;
			virtual bool&      GetScrollEquipState()                = 0;
			virtual bool&      GetTerrainImpactEffects()            = 0;
			virtual bool&      GetTrainingMenu()                    = 0;
			virtual bool&      GetWeaponCharge()                    = 0;
		};
		static_assert(sizeof(Fixes) == 0x8);

		class Patches
		{
		public:
			class DifficultyMultipliers
			{
			public:
				virtual ~DifficultyMultipliers() = default;

				virtual bool& GetCommandedActors() = 0;
				virtual bool& GetTeammates()       = 0;
			};
			static_assert(sizeof(DifficultyMultipliers) == 0x8);

			class PerkEntryPoints
			{
			public:
				virtual ~PerkEntryPoints() = default;

				virtual bool& GetApplySpells() = 0;
				virtual bool& GetCastSpells()  = 0;
			};
			static_assert(sizeof(PerkEntryPoints) == 0x8);

			class SoulGems
			{
			public:
				virtual ~SoulGems() = default;

				virtual bool& GetBlack()       = 0;
				virtual bool& GetUnderfilled() = 0;
			};
			static_assert(sizeof(SoulGems) == 0x8);

			class StaffExperience
			{
			public:
				virtual ~StaffExperience() = default;

				virtual bool& GetIgnoreEnchantmentCost() = 0;
				virtual bool& GetStaffExperience()       = 0;
			};
			static_assert(sizeof(StaffExperience) == 0x8);

			virtual ~Patches() = default;

			virtual DifficultyMultipliers& GetDifficultyMultipliers()      = 0;
			virtual PerkEntryPoints&       GetPerkEntryPoints()            = 0;
			virtual SoulGems&              GetSoulGems()                   = 0;
			virtual StaffExperience&       GetStaffExperience()            = 0;
			virtual bool&                  GetAccumulatingMagnitude()      = 0;
			virtual bool&                  GetAlreadyCaughtPickpocketing() = 0;
			virtual bool&                  GetAttachHitEffectArt()         = 0;
			virtual bool&                  GetCloakHitEffects()            = 0;
			virtual bool&                  GetDeferredHitEffects()         = 0;
			virtual bool&                  GetEnchantmentEffectPower()     = 0;
			virtual bool&                  GetEquipBestAmmunition()        = 0;
			virtual bool&                  GetLeveledCharacters()          = 0;
			virtual bool&                  GetLockpickingExperience()      = 0;
			virtual bool&                  GetPoisonResistance()           = 0;
			virtual bool&                  GetPowerAttackStamina()         = 0;
			virtual bool&                  GetReflectDamage()              = 0;
			virtual bool&                  GetScrollExperience()           = 0;
			virtual bool&                  GetSteepSlopes()                = 0;
		};
		static_assert(sizeof(Patches) == 0x8);

		virtual ~Settings() = default;

		virtual Fixes&   GetFixes()   = 0;
		virtual Patches& GetPatches() = 0;
	};
	static_assert(sizeof(Settings<Version::Version22>) == 0x8);

	template <Version VERSION>
	Settings<VERSION>* GetSettings()
	{
		auto* moduleHandle = ::ScrambledBugsGetModuleHandle("ScrambledBugs.dll");

		if (moduleHandle)
		{
			auto* procedureAddress = static_cast<Settings<VERSION>* (*)(Version)>(::ScrambledBugsGetProcedureAddress(moduleHandle, "GetSettings"));

			if (procedureAddress)
			{
				return procedureAddress(VERSION);
			}
		}

		return nullptr;
	}
}
