#include "PrecompiledHeader.h"

#include "Settings.h"

#include "Fixes/ActivateFurniture.h"
#include "Fixes/ActorValuePercentage.h"
#include "Fixes/EnchantmentCost.h"
#include "Fixes/HitEffectRaceCondition.h"
#include "Fixes/ImpactEffectCrash.h"
#include "Fixes/IngredientRespawn.h"
#include "Fixes/IsCurrentSpell.h"
#include "Fixes/KillCamera.h"
#include "Fixes/LeftHandPowerAttacks.h"
#include "Fixes/MagicEffectFlags.h"
#include "Fixes/ModifyArmorWeightPerkEntryPoint.h"
#include "Fixes/OpenEffectArchetype.h"
#include "Fixes/PowerCooldowns.h"
#include "Fixes/ProjectileFadeDuration.h"
#include "Fixes/QuickShot.h"
#include "Fixes/ScrollEquipState.h"
#include "Fixes/TerrainImpactEffects.h"
#include "Fixes/TrainingMenu.h"
#include "Fixes/WeaponCharge.h"
#include "Patches/AccumulatingMagnitude.h"
#include "Patches/AlreadyCaughtPickpocketing.h"
#include "Patches/AttachHitEffectArt.h"
#include "Patches/CloakHitEffects.h"
#include "Patches/DeferredHitEffects.h"
#include "Patches/DifficultyMultipliers.h"
#include "Patches/EnchantmentEffectPower.h"
#include "Patches/EquipBestAmmunition.h"
#include "Patches/LeveledCharacters.h"
#include "Patches/LockpickingExperience.h"
#include "Patches/PerkEntryPoints/ApplySpells.h"
#include "Patches/PerkEntryPoints/CastSpells.h"
#include "Patches/PoisonResistance.h"
#include "Patches/PowerAttackStamina.h"
#include "Patches/ReflectDamage.h"
#include "Patches/ScrollExperience.h"
#include "Patches/SoulGems.h"
#include "Patches/StaffExperience.h"
#include "Patches/SteepSlopes.h"
#include "Shared/Relocation/Module.h"



namespace ScrambledBugs
{
	float& Settings::Fixes::QuickShot::GetPlaybackSpeed()
	{
		return this->playbackSpeed;
	}

	bool& Settings::Fixes::QuickShot::GetQuickShot()
	{
		return this->quickShot;
	}

	Settings::Fixes::QuickShot& Settings::Fixes::QuickShot::Deserialize(const std::filesystem::path& directory)
	{
		this->playbackSpeed = Settings::Parse<float>(directory / "PlaybackSpeed.json");
		this->quickShot     = Settings::Parse<bool>(directory / "QuickShot.json");

		return *this;
	}

	nlohmann::json Settings::Fixes::QuickShot::Serialize() const
	{
		nlohmann::json json;

		json["playbackSpeed"] = this->playbackSpeed;
		json["quickShot"]     = this->quickShot;

		return json;
	}

	void Settings::Fixes::QuickShot::Load()
	{
		if (this->quickShot)
		{
			ScrambledBugs::Fixes::QuickShot::Load(this->quickShot, this->playbackSpeed);
		}
	}

	void Settings::Fixes::QuickShot::PostLoad()
	{
	}

	Settings::Fixes::QuickShot& Settings::Fixes::GetQuickShot()
	{
		return this->quickShot;
	}

	bool& Settings::Fixes::GetActivateFurniture()
	{
		return this->activateFurniture;
	}

	bool& Settings::Fixes::GetActorValuePercentage()
	{
		return this->actorValuePercentage;
	}

	bool& Settings::Fixes::GetEnchantmentCost()
	{
		return this->enchantmentCost;
	}

	bool& Settings::Fixes::GetHitEffectRaceCondition()
	{
		return this->hitEffectRaceCondition;
	}

	bool& Settings::Fixes::GetImpactEffectCrash()
	{
		return this->impactEffectCrash;
	}

	bool& Settings::Fixes::GetIngredientRespawn()
	{
		return this->ingredientRespawn;
	}

	bool& Settings::Fixes::GetIsCurrentSpell()
	{
		return this->isCurrentSpell;
	}

	bool& Settings::Fixes::GetKillCamera()
	{
		return this->killCamera;
	}

	bool& Settings::Fixes::GetLeftHandPowerAttacks()
	{
		return this->leftHandPowerAttacks;
	}

	bool& Settings::Fixes::GetMagicEffectFlags()
	{
		return this->magicEffectFlags;
	}

	bool& Settings::Fixes::GetModifyArmorWeightPerkEntryPoint()
	{
		return this->modifyArmorWeightPerkEntryPoint;
	}

	bool& Settings::Fixes::GetOpenEffectArchetype()
	{
		return this->openEffectArchetype;
	}

	bool& Settings::Fixes::GetPowerCooldowns()
	{
		return this->powerCooldowns;
	}

	bool& Settings::Fixes::GetProjectileFadeDuration()
	{
		return this->projectileFadeDuration;
	}

	bool& Settings::Fixes::GetScrollEquipState()
	{
		return this->scrollEquipState;
	}

	bool& Settings::Fixes::GetTerrainImpactEffects()
	{
		return this->terrainImpactEffects;
	}

	bool& Settings::Fixes::GetTrainingMenu()
	{
		return this->trainingMenu;
	}

	bool& Settings::Fixes::GetWeaponCharge()
	{
		return this->weaponCharge;
	}

	Settings::Fixes& Settings::Fixes::Deserialize(const std::filesystem::path& directory)
	{
		this->quickShot.Deserialize(directory / "QuickShot");

		this->activateFurniture               = Settings::Parse<bool>(directory / "ActivateFurniture.json");
		this->actorValuePercentage            = Settings::Parse<bool>(directory / "ActorValuePercentage.json");
		this->enchantmentCost                 = Settings::Parse<bool>(directory / "EnchantmentCost.json");
		this->hitEffectRaceCondition          = Settings::Parse<bool>(directory / "HitEffectRaceCondition.json");
		this->impactEffectCrash               = Settings::Parse<bool>(directory / "ImpactEffectCrash.json");
		this->ingredientRespawn               = Settings::Parse<bool>(directory / "IngredientRespawn.json");
		this->isCurrentSpell                  = Settings::Parse<bool>(directory / "IsCurrentSpell.json");
		this->killCamera                      = Settings::Parse<bool>(directory / "KillCamera.json");
		this->leftHandPowerAttacks            = Settings::Parse<bool>(directory / "LeftHandPowerAttacks.json");
		this->magicEffectFlags                = Settings::Parse<bool>(directory / "MagicEffectFlags.json");
		this->modifyArmorWeightPerkEntryPoint = Settings::Parse<bool>(directory / "ModifyArmorWeightPerkEntryPoint.json");
		this->openEffectArchetype             = Settings::Parse<bool>(directory / "OpenEffectArchetype.json");
		this->powerCooldowns                  = Settings::Parse<bool>(directory / "PowerCooldowns.json");
		this->projectileFadeDuration          = Settings::Parse<bool>(directory / "ProjectileFadeDuration.json");
		this->scrollEquipState                = Settings::Parse<bool>(directory / "ScrollEquipState.json");
		this->terrainImpactEffects            = Settings::Parse<bool>(directory / "TerrainImpactEffects.json");
		this->trainingMenu                    = Settings::Parse<bool>(directory / "TrainingMenu.json");
		this->weaponCharge                    = Settings::Parse<bool>(directory / "WeaponCharge.json");

		return *this;
	}

	nlohmann::json Settings::Fixes::Serialize() const
	{
		nlohmann::json json;

		json["quickShot"] = this->quickShot.Serialize();

		json["activateFurniture"]               = this->activateFurniture;
		json["actorValuePercentage"]            = this->actorValuePercentage;
		json["enchantmentCost"]                 = this->enchantmentCost;
		json["hitEffectRaceCondition"]          = this->hitEffectRaceCondition;
		json["impactEffectCrash"]               = this->impactEffectCrash;
		json["ingredientRespawn"]               = this->ingredientRespawn;
		json["isCurrentSpell"]                  = this->isCurrentSpell;
		json["killCamera"]                      = this->killCamera;
		json["leftHandPowerAttacks"]            = this->leftHandPowerAttacks;
		json["magicEffectFlags"]                = this->magicEffectFlags;
		json["modifyArmorWeightPerkEntryPoint"] = this->modifyArmorWeightPerkEntryPoint;
		json["openEffectArchetype"]             = this->openEffectArchetype;
		json["powerCooldowns"]                  = this->powerCooldowns;
		json["projectileFadeDuration"]          = this->projectileFadeDuration;
		json["scrollEquipState"]                = this->scrollEquipState;
		json["terrainImpactEffects"]            = this->terrainImpactEffects;
		json["trainingMenu"]                    = this->trainingMenu;
		json["weaponCharge"]                    = this->weaponCharge;

		return json;
	}

	void Settings::Fixes::Load()
	{
		this->quickShot.Load();

		if (this->activateFurniture)
		{
			ScrambledBugs::Fixes::ActivateFurniture::Load(this->activateFurniture);
		}

		if (this->actorValuePercentage)
		{
			ScrambledBugs::Fixes::ActorValuePercentage::Load(this->actorValuePercentage);
		}

		if (this->enchantmentCost)
		{
			ScrambledBugs::Fixes::EnchantmentCost::Load(this->enchantmentCost);
		}

		if (this->hitEffectRaceCondition)
		{
			ScrambledBugs::Fixes::HitEffectRaceCondition::Load(this->hitEffectRaceCondition);
		}

		if (this->impactEffectCrash)
		{
			ScrambledBugs::Fixes::ImpactEffectCrash::Load(this->impactEffectCrash);
		}

		if (this->ingredientRespawn)
		{
			ScrambledBugs::Fixes::IngredientRespawn::Load(this->ingredientRespawn);
		}

		if (this->isCurrentSpell)
		{
			ScrambledBugs::Fixes::IsCurrentSpell::Load(this->isCurrentSpell);
		}

		if (this->leftHandPowerAttacks)
		{
			ScrambledBugs::Fixes::LeftHandPowerAttacks::Load(this->leftHandPowerAttacks);
		}

		if (this->magicEffectFlags)
		{
			ScrambledBugs::Fixes::MagicEffectFlags::Load(this->magicEffectFlags);
		}

		if (this->modifyArmorWeightPerkEntryPoint)
		{
			ScrambledBugs::Fixes::ModifyArmorWeightPerkEntryPoint::Load(this->modifyArmorWeightPerkEntryPoint);
		}

		if (this->openEffectArchetype)
		{
			ScrambledBugs::Fixes::OpenEffectArchetype::Load(this->openEffectArchetype);
		}

		if (this->powerCooldowns)
		{
			ScrambledBugs::Fixes::PowerCooldowns::Load(this->powerCooldowns);
		}

		if (this->projectileFadeDuration)
		{
			ScrambledBugs::Fixes::ProjectileFadeDuration::Load(this->projectileFadeDuration);
		}

		if (this->scrollEquipState)
		{
			ScrambledBugs::Fixes::ScrollEquipState::Load(this->scrollEquipState);
		}

		if (this->terrainImpactEffects)
		{
			ScrambledBugs::Fixes::TerrainImpactEffects::Load(this->terrainImpactEffects);
		}

		if (this->trainingMenu)
		{
			ScrambledBugs::Fixes::TrainingMenu::Load(this->trainingMenu);
		}

		if (this->weaponCharge)
		{
			ScrambledBugs::Fixes::WeaponCharge::Load(this->weaponCharge);
		}
	}

	void Settings::Fixes::PostLoad()
	{
		this->quickShot.PostLoad();

		// Must be loaded after the Perk Entry Points: Apply Spells fix
		if (this->killCamera)
		{
			ScrambledBugs::Fixes::KillCamera::Load(this->killCamera);
		}
	}

	bool& Settings::Patches::DifficultyMultipliers::GetCommandedActors()
	{
		return this->commandedActors;
	}

	bool& Settings::Patches::DifficultyMultipliers::GetTeammates()
	{
		return this->teammates;
	}

	Settings::Patches::DifficultyMultipliers& Settings::Patches::DifficultyMultipliers::Deserialize(const std::filesystem::path& directory)
	{
		this->commandedActors = Settings::Parse<bool>(directory / "CommandedActors.json");
		this->teammates       = Settings::Parse<bool>(directory / "Teammates.json");

		return *this;
	}

	nlohmann::json Settings::Patches::DifficultyMultipliers::Serialize() const
	{
		nlohmann::json json;

		json["commandedActors"] = this->commandedActors;
		json["teammates"]       = this->teammates;

		return json;
	}

	void Settings::Patches::DifficultyMultipliers::Load()
	{
		if (this->commandedActors || this->teammates)
		{
			ScrambledBugs::Patches::DifficultyMultipliers::Load(this->commandedActors, this->teammates);
		}
	}

	void Settings::Patches::DifficultyMultipliers::PostLoad()
	{
	}

	bool& Settings::Patches::PerkEntryPoints::GetApplySpells()
	{
		return this->applySpells;
	}

	bool& Settings::Patches::PerkEntryPoints::GetCastSpells()
	{
		return this->castSpells;
	}

	Settings::Patches::PerkEntryPoints& Settings::Patches::PerkEntryPoints::Deserialize(const std::filesystem::path& directory)
	{
		this->applySpells = Settings::Parse<bool>(directory / "ApplySpells.json");
		this->castSpells  = Settings::Parse<bool>(directory / "CastSpells.json");

		return *this;
	}

	nlohmann::json Settings::Patches::PerkEntryPoints::Serialize() const
	{
		nlohmann::json json;

		json["applySpells"] = this->applySpells;
		json["castSpells"]  = this->castSpells;

		return json;
	}

	void Settings::Patches::PerkEntryPoints::Load()
	{
		if (this->applySpells)
		{
			ScrambledBugs::Patches::PerkEntryPoints::ApplySpells::Load(this->applySpells, this->castSpells);
		}
		else if (this->castSpells)
		{
			ScrambledBugs::Patches::PerkEntryPoints::CastSpells::Load(this->castSpells);
		}
	}

	void Settings::Patches::PerkEntryPoints::PostLoad()
	{
	}

	bool& Settings::Patches::SoulGems::GetBlack()
	{
		return this->black;
	}

	bool& Settings::Patches::SoulGems::GetUnderfilled()
	{
		return this->underfilled;
	}

	Settings::Patches::SoulGems& Settings::Patches::SoulGems::Deserialize(const std::filesystem::path& directory)
	{
		this->black       = Settings::Parse<bool>(directory / "Black.json");
		this->underfilled = Settings::Parse<bool>(directory / "Underfilled.json");

		return *this;
	}

	nlohmann::json Settings::Patches::SoulGems::Serialize() const
	{
		nlohmann::json json;

		json["black"]       = this->black;
		json["underfilled"] = this->underfilled;

		return json;
	}

	void Settings::Patches::SoulGems::Load()
	{
		if (this->black || this->underfilled)
		{
			ScrambledBugs::Patches::SoulGems::Load(this->black, this->underfilled);
		}
	}

	void Settings::Patches::SoulGems::PostLoad()
	{
	}

	bool& Settings::Patches::StaffExperience::GetIgnoreEnchantmentCost()
	{
		return this->ignoreEnchantmentCost;
	}

	bool& Settings::Patches::StaffExperience::GetStaffExperience()
	{
		return this->staffExperience;
	}

	Settings::Patches::StaffExperience& Settings::Patches::StaffExperience::Deserialize(const std::filesystem::path& directory)
	{
		this->ignoreEnchantmentCost = Settings::Parse<bool>(directory / "IgnoreEnchantmentCost.json");
		this->staffExperience       = Settings::Parse<bool>(directory / "StaffExperience.json");

		return *this;
	}

	nlohmann::json Settings::Patches::StaffExperience::Serialize() const
	{
		nlohmann::json json;

		json["ignoreEnchantmentCost"] = this->ignoreEnchantmentCost;
		json["staffExperience"]       = this->staffExperience;

		return json;
	}

	void Settings::Patches::StaffExperience::Load()
	{
		if (this->staffExperience)
		{
			ScrambledBugs::Patches::StaffExperience::Load(this->staffExperience, this->ignoreEnchantmentCost);
		}
	}

	void Settings::Patches::StaffExperience::PostLoad()
	{
	}

	Settings::Patches::DifficultyMultipliers& Settings::Patches::GetDifficultyMultipliers()
	{
		return this->difficultyMultipliers;
	}

	Settings::Patches::PerkEntryPoints& Settings::Patches::GetPerkEntryPoints()
	{
		return this->perkEntryPoints;
	}

	Settings::Patches::SoulGems& Settings::Patches::GetSoulGems()
	{
		return this->soulGems;
	}

	Settings::Patches::StaffExperience& Settings::Patches::GetStaffExperience()
	{
		return this->staffExperience;
	}

	bool& Settings::Patches::GetAccumulatingMagnitude()
	{
		return this->accumulatingMagnitude;
	}

	bool& Settings::Patches::GetAlreadyCaughtPickpocketing()
	{
		return this->alreadyCaughtPickpocketing;
	}

	bool& Settings::Patches::GetAttachHitEffectArt()
	{
		return this->attachHitEffectArt;
	}

	bool& Settings::Patches::GetCloakHitEffects()
	{
		return this->cloakHitEffects;
	}

	bool& Settings::Patches::GetDeferredHitEffects()
	{
		return this->deferredHitEffects;
	}

	bool& Settings::Patches::GetEnchantmentEffectPower()
	{
		return this->enchantmentEffectPower;
	}

	bool& Settings::Patches::GetEquipBestAmmunition()
	{
		return this->equipBestAmmunition;
	}

	bool& Settings::Patches::GetLeveledCharacters()
	{
		return this->leveledCharacters;
	}

	bool& Settings::Patches::GetLockpickingExperience()
	{
		return this->lockpickingExperience;
	}

	bool& Settings::Patches::GetPoisonResistance()
	{
		return this->poisonResistance;
	}

	bool& Settings::Patches::GetPowerAttackStamina()
	{
		return this->powerAttackStamina;
	}

	bool& Settings::Patches::GetReflectDamage()
	{
		return this->reflectDamage;
	}

	bool& Settings::Patches::GetScrollExperience()
	{
		return this->scrollExperience;
	}

	bool& Settings::Patches::GetSteepSlopes()
	{
		return this->steepSlopes;
	}

	Settings::Patches& Settings::Patches::Deserialize(const std::filesystem::path& directory)
	{
		this->difficultyMultipliers.Deserialize(directory / "DifficultyMultipliers");
		this->perkEntryPoints.Deserialize(directory / "PerkEntryPoints");
		this->soulGems.Deserialize(directory / "SoulGems");
		this->staffExperience.Deserialize(directory / "StaffExperience");

		this->accumulatingMagnitude      = Settings::Parse<bool>(directory / "AccumulatingMagnitude.json");
		this->alreadyCaughtPickpocketing = Settings::Parse<bool>(directory / "AlreadyCaughtPickpocketing.json");
		this->attachHitEffectArt         = Settings::Parse<bool>(directory / "AttachHitEffectArt.json");
		this->cloakHitEffects            = Settings::Parse<bool>(directory / "CloakHitEffects.json");
		this->deferredHitEffects         = Settings::Parse<bool>(directory / "DeferredHitEffects.json");
		this->enchantmentEffectPower     = Settings::Parse<bool>(directory / "EnchantmentEffectPower.json");
		this->equipBestAmmunition        = Settings::Parse<bool>(directory / "EquipBestAmmunition.json");
		this->leveledCharacters          = Settings::Parse<bool>(directory / "LeveledCharacters.json");
		this->lockpickingExperience      = Settings::Parse<bool>(directory / "LockpickingExperience.json");
		this->poisonResistance           = Settings::Parse<bool>(directory / "PoisonResistance.json");
		this->powerAttackStamina         = Settings::Parse<bool>(directory / "PowerAttackStamina.json");
		this->reflectDamage              = Settings::Parse<bool>(directory / "ReflectDamage.json");
		this->scrollExperience           = Settings::Parse<bool>(directory / "ScrollExperience.json");
		this->steepSlopes                = Settings::Parse<bool>(directory / "SteepSlopes.json");

		return *this;
	}

	nlohmann::json Settings::Patches::Serialize() const
	{
		nlohmann::json json;

		json["difficultyMultipliers"] = this->difficultyMultipliers.Serialize();
		json["perkEntryPoints"]       = this->perkEntryPoints.Serialize();
		json["soulGems"]              = this->soulGems.Serialize();
		json["staffExperience"]       = this->staffExperience.Serialize();

		json["accumulatingMagnitude"]      = this->accumulatingMagnitude;
		json["alreadyCaughtPickpocketing"] = this->alreadyCaughtPickpocketing;
		json["attachHitEffectArt"]         = this->attachHitEffectArt;
		json["cloakHitEffects"]            = this->cloakHitEffects;
		json["deferredHitEffects"]         = this->deferredHitEffects;
		json["enchantmentEffectPower"]     = this->enchantmentEffectPower;
		json["equipBestAmmunition"]        = this->equipBestAmmunition;
		json["leveledCharacters"]          = this->leveledCharacters;
		json["lockpickingExperience"]      = this->lockpickingExperience;
		json["poisonResistance"]           = this->poisonResistance;
		json["powerAttackStamina"]         = this->powerAttackStamina;
		json["reflectDamage"]              = this->reflectDamage;
		json["scrollExperience"]           = this->scrollExperience;
		json["steepSlopes"]                = this->steepSlopes;

		return json;
	}

	void Settings::Patches::Load()
	{
		this->difficultyMultipliers.Load();
		this->perkEntryPoints.Load();
		this->soulGems.Load();
		this->staffExperience.Load();

		if (this->accumulatingMagnitude)
		{
			ScrambledBugs::Patches::AccumulatingMagnitude::Load(this->accumulatingMagnitude);
		}

		if (this->alreadyCaughtPickpocketing)
		{
			ScrambledBugs::Patches::AlreadyCaughtPickpocketing::Load(this->alreadyCaughtPickpocketing);
		}

		if (this->attachHitEffectArt)
		{
			ScrambledBugs::Patches::AttachHitEffectArt::Load(this->attachHitEffectArt);
		}

		if (this->cloakHitEffects)
		{
			ScrambledBugs::Patches::CloakHitEffects::Load(this->cloakHitEffects);
		}

		if (this->deferredHitEffects)
		{
			ScrambledBugs::Patches::DeferredHitEffects::Load(this->deferredHitEffects);
		}

		if (this->equipBestAmmunition)
		{
			ScrambledBugs::Patches::EquipBestAmmunition::Load(this->equipBestAmmunition);
		}

		if (this->leveledCharacters)
		{
			ScrambledBugs::Patches::LeveledCharacters::Load(this->leveledCharacters);
		}

		if (this->lockpickingExperience)
		{
			ScrambledBugs::Patches::LockpickingExperience::Load(this->lockpickingExperience);
		}

		if (this->poisonResistance)
		{
			ScrambledBugs::Patches::PoisonResistance::Load(this->poisonResistance);
		}

		if (this->powerAttackStamina)
		{
			ScrambledBugs::Patches::PowerAttackStamina::Load(this->powerAttackStamina);
		}

		if (this->reflectDamage)
		{
			ScrambledBugs::Patches::ReflectDamage::Load(this->reflectDamage);
		}

		if (this->scrollExperience)
		{
			ScrambledBugs::Patches::ScrollExperience::Load(this->scrollExperience);
		}

		if (this->steepSlopes)
		{
			ScrambledBugs::Patches::SteepSlopes::Load(this->steepSlopes);
		}
	}

	void Settings::Patches::PostLoad()
	{
		this->difficultyMultipliers.PostLoad();
		this->perkEntryPoints.PostLoad();
		this->soulGems.PostLoad();
		this->staffExperience.PostLoad();

		// Must be loaded after the Conditions Target Magic Effects plugin
		if (this->enchantmentEffectPower)
		{
			ScrambledBugs::Patches::EnchantmentEffectPower::Load(this->enchantmentEffectPower);
		}
	}

	Settings::Settings(const std::filesystem::path& directory)
	{
		try
		{
			this->Deserialize(directory);
		}
		catch (const std::exception& exception)
		{
			SPDLOG_CRITICAL("{}", exception.what());

			throw;
		}
	}

	Settings::Fixes& Settings::GetFixes()
	{
		return this->fixes;
	}

	Settings::Patches& Settings::GetPatches()
	{
		return this->patches;
	}

	Settings& Settings::GetSingleton()
	{
		static Settings singleton(std::filesystem::path(Relocation::DynamicLinkLibrary::GetSingleton().GetPath()).replace_extension());

		return singleton;
	}

	Settings& Settings::Deserialize(const std::filesystem::path& directory)
	{
		this->fixes.Deserialize(directory / "Fixes");
		this->patches.Deserialize(directory / "Patches");

		return *this;
	}

	nlohmann::json Settings::Serialize() const
	{
		nlohmann::json json;

		json["fixes"]   = this->fixes.Serialize();
		json["patches"] = this->patches.Serialize();

		return json;
	}

	void Settings::Load()
	{
		this->fixes.Load();
		this->patches.Load();
	}

	void Settings::PostLoad()
	{
		this->fixes.PostLoad();
		this->patches.PostLoad();
	}
}

ScrambledBugs::Interface::Settings<ScrambledBugs::Interface::Version::Version22>* __cdecl GetSettings(ScrambledBugs::Interface::Version version)
{
	switch (version)
	{
		case ScrambledBugs::Interface::Version::Version22:
		{
			return std::addressof(ScrambledBugs::Settings::GetSingleton());
		}
		default:
		{
			return nullptr;
		}
	}
}
