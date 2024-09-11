#include "PrecompiledHeader.h"

#include "Fixes/ScrollEquipState.h"

#include "Addresses.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void ScrollEquipState::Fix(bool& scrollEquipState)
	{
		Utility::Memory::SafeWriteAbsoluteJump(
			Addresses::Fixes::ScrollEquipState::Actor::GetEquipState,
			reinterpret_cast<std::uintptr_t>(std::addressof(ScrollEquipState::Actor::GetEquipState)));

#ifdef SKYRIM_ANNIVERSARY_EDITION
		Utility::Memory::SafeWriteVirtualFunction(
			Skyrim::Addresses::StandardItemData::VirtualFunctionTable(),
			0x3,
			reinterpret_cast<std::uintptr_t>(std::addressof(ScrollEquipState::StandardItemData::GetEquipState)));
#endif
	}

	Skyrim::EquipState ScrollEquipState::Actor::GetEquipState(Skyrim::Actor* actor, Skyrim::TESForm* form, Skyrim::ExtraDataList* rightHandExtraDataList, Skyrim::ExtraDataList* leftHandExtraDataList)
	{
		auto* currentProcess = actor ? actor->currentProcess : nullptr;

		if (!currentProcess)
		{
			return Skyrim::EquipState::kNone;
		}

		switch (form->formType.get())
		{
			case Skyrim::FormType::kScroll:
			case Skyrim::FormType::kSpell:
			{
				auto leftEquip  = actor->selectedMagicItems[Utility::Conversion::ToUnderlying(Skyrim::Actor::SlotType::kLeftHand)] == form;
				auto rightEquip = actor->selectedMagicItems[Utility::Conversion::ToUnderlying(Skyrim::Actor::SlotType::kRightHand)] == form;

				if (leftEquip)
				{
					return rightEquip ? Skyrim::EquipState::kLeftAndRightEquip : Skyrim::EquipState::kLeftEquip;
				}
				else if (rightEquip)
				{
					return Skyrim::EquipState::kRightEquip;
				}
				else if (actor->selectedPower == form)
				{
					return Skyrim::EquipState::kEquipped;
				}
				else
				{
					return Skyrim::EquipState::kNone;
				}
			}
			case Skyrim::FormType::kWeapon:
			{
				if (leftHandExtraDataList)
				{
					return rightHandExtraDataList ? Skyrim::EquipState::kLeftAndRightEquip : Skyrim::EquipState::kLeftEquip;
				}
				else if (rightHandExtraDataList)
				{
					auto* equipType = Skyrim::BGSEquipType::GetFormAsEquipType(form);
					auto* equipSlot = equipType->GetEquipSlot();

					auto* leftHandEquipSlot  = static_cast<Skyrim::BGSEquipSlot*>(Skyrim::BGSDefaultObjectManager::GetSingleton()->GetDefaultObject(Skyrim::DefaultObject::kLeftHandEquipSlot));
					auto* rightHandEquipSlot = static_cast<Skyrim::BGSEquipSlot*>(Skyrim::BGSDefaultObjectManager::GetSingleton()->GetDefaultObject(Skyrim::DefaultObject::kRightHandEquipSlot));

					if (equipSlot->equipSlotFlags.all(Skyrim::BGSEquipSlot::Flags::kUseAllParents) &&
						equipSlot->CheckForSlotConflict(leftHandEquipSlot) &&
						equipSlot->CheckForSlotConflict(rightHandEquipSlot))
					{
						return Skyrim::EquipState::kLeftAndRightEquip;
					}
					else
					{
						return Skyrim::EquipState::kRightEquip;
					}
				}
				else
				{
					return Skyrim::EquipState::kNone;
				}
			}
			case Skyrim::FormType::kShout:
			{
				return actor->GetEquippedShout() == form ? Skyrim::EquipState::kEquipped : Skyrim::EquipState::kNone;
			}
			default:
			{
				return rightHandExtraDataList || leftHandExtraDataList ? Skyrim::EquipState::kEquipped : Skyrim::EquipState::kNone;
			}
		}
	}

	Skyrim::EquipState ScrollEquipState::StandardItemData::GetEquipState(Skyrim::StandardItemData* standardItemData)
	{
		auto equipState{ Skyrim::EquipState::kNone };

		auto ownerReference = standardItemData->ownerHandle.get();

		if (ownerReference && ownerReference->formType == Skyrim::FormType::kActor)
		{
			auto* ownerActor             = static_cast<Skyrim::Actor*>(ownerReference.get());
			auto* inventoryEntryData     = standardItemData->inventoryEntryData;
			auto* rightHandExtraDataList = inventoryEntryData->GetWornExtraDataList(false, false);
			auto* leftHandExtraDataList  = inventoryEntryData->GetWornExtraDataList(false, true);

			equipState = Actor::GetEquipState(ownerActor, inventoryEntryData->boundObject, rightHandExtraDataList, leftHandExtraDataList);
		}

		return equipState;
	}
}
