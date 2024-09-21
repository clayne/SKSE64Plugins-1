#include "PrecompiledHeader.h"

#include "Patches/DifficultyMultipliers.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void DifficultyMultipliers::Load(bool& commandedActors, bool& teammates)
	{
		DifficultyMultipliers::commandedActors_ = commandedActors;
		DifficultyMultipliers::teammates_       = teammates;

		Utility::Memory::SafeWriteAbsoluteJump(Skyrim::Addresses::Actor::DifficultyLevelAdjustHealthModifier(), reinterpret_cast<std::uintptr_t>(std::addressof(Actor::DifficultyLevelAdjustHealthModifier)));

#ifdef SKYRIM_ANNIVERSARY_EDITION
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Patches::DifficultyMultipliers::Actor::DoDamage, reinterpret_cast<std::uintptr_t>(std::addressof(Actor::DoDamage)));
#endif
	}

	float DifficultyMultipliers::Actor::DifficultyLevelAdjustHealthModifier(Skyrim::Actor* target, float damage, float onlyReduceDamage)
	{
		auto* playerCharacter      = Skyrim::PlayerCharacter::GetSingleton();
		auto  difficultyMultiplier = Skyrim::GameplayFormulas::GetDifficultyMultiplier(
            playerCharacter->difficultyLevel,
            Skyrim::ActorValue::kHealth,
            target == playerCharacter ||
                (DifficultyMultipliers::teammates_ && target->IsPlayerTeammate()) ||
                (DifficultyMultipliers::commandedActors_ && (target->GetCommandingActorHandle().get().get() == playerCharacter)));

		return std::abs(onlyReduceDamage) <= 0.0001F || difficultyMultiplier < 1.0F ? difficultyMultiplier * damage : damage;
	}

	bool DifficultyMultipliers::Actor::DoDamage(Skyrim::Actor* target, float damage, Skyrim::Actor* attacker, bool onlyReduceDamage)
	{
		// target != nullptr
		// attacker != nullptr

		if (target->IsInvulnerable() || target->booleanFlags.all(Skyrim::Actor::BooleanFlags::kInKillMove))
		{
			return false;
		}

		if (target->actorState1.actorLifeState == Skyrim::ActorState::ActorState1::ActorLifeState::kEssentialDown && target->CanKillMe(attacker))
		{
			target->actorState1.actorLifeState = Skyrim::ActorState::ActorState1::ActorLifeState::kAlive;
		}

		auto adjustedDamage = -target->DifficultyLevelAdjustHealthModifier(-damage, static_cast<float>(onlyReduceDamage));

		if (adjustedDamage > 0.0F)
		{
			auto* targetCombatController = target->combatController;

			if (targetCombatController)
			{
				targetCombatController->DamagedByAttacker(attacker, adjustedDamage);
			}

			if (target != Skyrim::PlayerCharacter::GetSingleton())
			{
				auto* targetCurrentProcess = target->currentProcess;

				if (targetCurrentProcess && target->booleanFlags.none(Skyrim::Actor::BooleanFlags::kEssential) && target->CanKillMe(attacker))
				{
					targetCurrentProcess->ModifyTrackedDamage(attacker, adjustedDamage);
				}
			}

			target->ModifyActorValue(Skyrim::ActorValueModifier::kDamage, Skyrim::ActorValue::kHealth, -adjustedDamage, attacker);

			if (Skyrim::TaskQueueInterface::ShouldQueueTask())
			{
				Skyrim::TaskQueueInterface::GetSingleton()->QueueScriptFunctionCall(Skyrim::ScriptOutput::kDamageObject, target, damage);
			}
			else
			{
				target->DamageObject(damage, false);
			}
		}

		return target->IsDead(false);
	}

	bool DifficultyMultipliers::commandedActors_{};
	bool DifficultyMultipliers::teammates_{};
}
