#pragma once

#include "PrecompiledHeader.h"

#include "ScrambledBugsInterface.h"



namespace ScrambledBugs
{
	class Settings final :
		public Interface::Settings<Interface::Version::Version22>
	{
	public:
		class Fixes final :
			public Interface::Settings<Interface::Version::Version22>::Fixes
		{
		public:
			class QuickShot final :
				public Interface::Settings<Interface::Version::Version22>::Fixes::QuickShot
			{
			public:
				virtual ~QuickShot() override = default;

				virtual float& GetPlaybackSpeed() override;
				virtual bool&  GetQuickShot() override;

				QuickShot&     Deserialize(const std::filesystem::path& directory);
				nlohmann::json Serialize() const;

				void Load();
				void PostLoad();

				float playbackSpeed{};
				bool  quickShot{};
			};

			virtual ~Fixes() override = default;

			virtual QuickShot& GetQuickShot() override;
			virtual bool&      GetActivateFurniture() override;
			virtual bool&      GetActorValuePercentage() override;
			virtual bool&      GetEnchantmentCost() override;
			virtual bool&      GetHitEffectRaceCondition() override;
			virtual bool&      GetImpactEffectCrash() override;
			virtual bool&      GetIngredientRespawn() override;
			virtual bool&      GetIsCurrentSpell() override;
			virtual bool&      GetKillCamera() override;
			virtual bool&      GetLeftHandPowerAttacks() override;
			virtual bool&      GetMagicEffectFlags() override;
			virtual bool&      GetModifyArmorWeightPerkEntryPoint() override;
			virtual bool&      GetOpenEffectArchetype() override;
			virtual bool&      GetPowerCooldowns() override;
			virtual bool&      GetProjectileFadeDuration() override;
			virtual bool&      GetScrollEquipState() override;
			virtual bool&      GetTerrainImpactEffects() override;
			virtual bool&      GetTrainingMenu() override;
			virtual bool&      GetWeaponCharge() override;

			Fixes&         Deserialize(const std::filesystem::path& directory);
			nlohmann::json Serialize() const;

			void Load();
			void PostLoad();

			QuickShot quickShot{};
			bool      activateFurniture{};
			bool      actorValuePercentage{};
			bool      enchantmentCost{};
			bool      hitEffectRaceCondition{};
			bool      impactEffectCrash{};
			bool      ingredientRespawn{};
			bool      isCurrentSpell{};
			bool      killCamera{};
			bool      leftHandPowerAttacks{};
			bool      magicEffectFlags{};
			bool      modifyArmorWeightPerkEntryPoint{};
			bool      openEffectArchetype{};
			bool      powerCooldowns{};
			bool      projectileFadeDuration{};
			bool      scrollEquipState{};
			bool      terrainImpactEffects{};
			bool      trainingMenu{};
			bool      weaponCharge{};
		};

		class Patches final :
			public Interface::Settings<Interface::Version::Version22>::Patches
		{
		public:
			class DifficultyMultipliers final :
				public Interface::Settings<Interface::Version::Version22>::Patches::DifficultyMultipliers
			{
			public:
				virtual ~DifficultyMultipliers() override = default;

				virtual bool& GetCommandedActors() override;
				virtual bool& GetTeammates() override;

				DifficultyMultipliers& Deserialize(const std::filesystem::path& directory);
				nlohmann::json         Serialize() const;

				void Load();
				void PostLoad();

				bool commandedActors{};
				bool teammates{};
			};

			class PerkEntryPoints final :
				public Interface::Settings<Interface::Version::Version22>::Patches::PerkEntryPoints
			{
			public:
				virtual ~PerkEntryPoints() override = default;

				virtual bool& GetApplySpells() override;
				virtual bool& GetCastSpells() override;

				PerkEntryPoints& Deserialize(const std::filesystem::path& directory);
				nlohmann::json   Serialize() const;

				void Load();
				void PostLoad();

				bool applySpells{};
				bool castSpells{};
			};

			class SoulGems final :
				public Interface::Settings<Interface::Version::Version22>::Patches::SoulGems
			{
			public:
				virtual ~SoulGems() override = default;

				virtual bool& GetBlack() override;
				virtual bool& GetUnderfilled() override;

				SoulGems&      Deserialize(const std::filesystem::path& directory);
				nlohmann::json Serialize() const;

				void Load();
				void PostLoad();

				bool black{};
				bool underfilled{};
			};

			class StaffExperience final :
				public Interface::Settings<Interface::Version::Version22>::Patches::StaffExperience
			{
			public:
				virtual ~StaffExperience() override = default;

				virtual bool& GetIgnoreEnchantmentCost() override;
				virtual bool& GetStaffExperience() override;

				StaffExperience& Deserialize(const std::filesystem::path& directory);
				nlohmann::json   Serialize() const;

				void Load();
				void PostLoad();

				bool ignoreEnchantmentCost{};
				bool staffExperience{};
			};

			virtual ~Patches() override = default;

			virtual DifficultyMultipliers& GetDifficultyMultipliers() override;
			virtual PerkEntryPoints&       GetPerkEntryPoints() override;
			virtual SoulGems&              GetSoulGems() override;
			virtual StaffExperience&       GetStaffExperience() override;
			virtual bool&                  GetAccumulatingMagnitude() override;
			virtual bool&                  GetAlreadyCaughtPickpocketing() override;
			virtual bool&                  GetAttachHitEffectArt() override;
			virtual bool&                  GetCloakHitEffects() override;
			virtual bool&                  GetDeferredHitEffects() override;
			virtual bool&                  GetEnchantmentEffectPower() override;
			virtual bool&                  GetEquipBestAmmunition() override;
			virtual bool&                  GetLeveledCharacters() override;
			virtual bool&                  GetLockpickingExperience() override;
			virtual bool&                  GetPoisonResistance() override;
			virtual bool&                  GetPowerAttackStamina() override;
			virtual bool&                  GetReflectDamage() override;
			virtual bool&                  GetScrollExperience() override;
			virtual bool&                  GetSteepSlopes() override;

			Patches&       Deserialize(const std::filesystem::path& directory);
			nlohmann::json Serialize() const;

			void Load();
			void PostLoad();

			DifficultyMultipliers difficultyMultipliers{};
			PerkEntryPoints       perkEntryPoints{};
			SoulGems              soulGems{};
			StaffExperience       staffExperience{};
			bool                  accumulatingMagnitude{};
			bool                  alreadyCaughtPickpocketing{};
			bool                  attachHitEffectArt{};
			bool                  cloakHitEffects{};
			bool                  deferredHitEffects{};
			bool                  enchantmentEffectPower{};
			bool                  equipBestAmmunition{};
			bool                  leveledCharacters{};
			bool                  lockpickingExperience{};
			bool                  poisonResistance{};
			bool                  powerAttackStamina{};
			bool                  reflectDamage{};
			bool                  scrollExperience{};
			bool                  steepSlopes{};
		};

		explicit Settings(const std::filesystem::path& directory);

		virtual ~Settings() override = default;

		virtual Fixes&   GetFixes() override;
		virtual Patches& GetPatches() override;

		static Settings& GetSingleton();

		template <class T>
		static T Parse(const std::filesystem::path& path) = delete;

		template <>
		static bool Parse<bool>(const std::filesystem::path& path)
		{
			SPDLOG_INFO("Parsing... \"{}\"", path.string());

			return nlohmann::json::parse(std::ifstream(path)).at("boolean").get<bool>();
		}

		template <>
		static float Parse<float>(const std::filesystem::path& path)
		{
			SPDLOG_INFO("Parsing... \"{}\"", path.string());

			return nlohmann::json::parse(std::ifstream(path)).at("number").get<float>();
		}

		Settings&      Deserialize(const std::filesystem::path& directory);
		nlohmann::json Serialize() const;

		void Load();
		void PostLoad();

		Fixes   fixes{};
		Patches patches{};
	};
}

extern "C" __declspec(dllexport) ScrambledBugs::Interface::Settings<ScrambledBugs::Interface::Version::Version22>* __cdecl GetSettings(ScrambledBugs::Interface::Version version);
