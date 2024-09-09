#include "PrecompiledHeader.h"

#include "PlayerCharacter.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace PickpocketChanceFix
{
	void PlayerCharacter::Load()
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::PlayerCharacter::AttemptPickpocket,
			reinterpret_cast<std::uintptr_t>(std::addressof(PlayerCharacter::AttemptPickpocket)));
	}

	bool PlayerCharacter::AttemptPickpocket(
		Skyrim::PlayerCharacter*    playerCharacter,
		Skyrim::TESObjectREFR*      targetReference,
		Skyrim::InventoryEntryData* inventoryEntryData,
		std::int32_t                count,
		bool                        isViewingContainer)
	{
		if (!targetReference || targetReference->formType != Skyrim::FormType::kActor)
		{
			return true;
		}

		auto* targetActor = static_cast<Skyrim::Actor*>(targetReference);

		if (targetActor->IsKnockedOut())
		{
			return true;
		}

		auto stealValue = targetActor->GetStealValue(inventoryEntryData, count, isViewingContainer);

		if (stealValue < 1)
		{
			stealValue = 1;
		}

		auto* boundObject = inventoryEntryData ? inventoryEntryData->boundObject : nullptr;
		auto  formWeight  = boundObject ? boundObject->GetFormWeight() : 0.0F;

		// PlayerCharacter::AttemptPickpocket does not set a minimum weight
		if (formWeight < 0.0F)
		{
			formWeight = 0.0F;
		}

		auto detected = targetActor->RequestDetectionLevel(playerCharacter, Skyrim::DetectionPriority::kNormal) > 0;

		auto pickpocketChance = Skyrim::AIFormulas::ComputePickpocketSuccess(
			playerCharacter->GetClampedActorValue(Skyrim::ActorValue::kPickpocket),
			targetActor->GetActorValue(Skyrim::ActorValue::kPickpocket),
			stealValue,
			formWeight * static_cast<float>(count),
			playerCharacter,
			targetActor,
			detected,
			boundObject);

		std::random_device                          randomDevice;
		std::mt19937                                mersenneTwister(randomDevice());
		std::uniform_int_distribution<std::int32_t> uniformIntegerDistribution(0, 100);

		if (uniformIntegerDistribution(mersenneTwister) < pickpocketChance)
		{
			Skyrim::Pickpocket::Event event;

			event.thief  = playerCharacter;
			event.target = targetActor;

			Skyrim::Pickpocket::GetEventSource()->Notify(std::addressof(event));

			playerCharacter->stolenValue += stealValue;

			playerCharacter->UseSkill(
				Skyrim::ActorValue::kPickpocket,
				Skyrim::GameplayFormulas::CalculatePickpocketSkillUse(static_cast<float>(stealValue)),
				nullptr,
				0);

			return true;
		}
		else
		{
			if (playerCharacter->currentJailFaction && playerCharacter->currentJailFaction->trackCrime.crimeGold.escape)
			{
				targetActor->ForceDetect(playerCharacter);

				playerCharacter->playerCharacterFlags.escaping = true;
			}
			else
			{
				playerCharacter->PickpocketAlarm(targetActor, nullptr, 0);
			}

			static auto* pickpocketFail = Skyrim::GameSettingCollection::InitializeSetting("sPickpocketFail");

			Skyrim::UI::ShowNotification(pickpocketFail->GetString(), nullptr, true);

			return false;
		}
	}
}
