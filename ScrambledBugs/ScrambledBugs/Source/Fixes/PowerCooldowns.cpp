#include "PrecompiledHeader.h"

#include "Fixes/PowerCooldowns.h"

#include "Addresses.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Fixes
{
	void PowerCooldowns::Fix(bool& powerCooldowns)
	{
		Utility::Memory::SafeWriteAbsoluteJump(Addresses::Fixes::PowerCooldowns::SaveCastPowerItems, reinterpret_cast<std::uintptr_t>(std::addressof(PowerCooldowns::SaveCastPowerItems)));
	}

	void PowerCooldowns::SaveCastPowerItems(Skyrim::Actor* actor, Skyrim::BGSSaveFormBuffer* saveFormBuffer)
	{
		// actor != nullptr
		// saveFormBuffer != nullptr

		std::uint32_t castPowerItemCount{ 0 };
		auto*         castPowerItems = actor->castPowerItems;

		if (castPowerItems)
		{
			for (const auto& castPowerItem : *castPowerItems)
			{
				++castPowerItemCount;
			}

			saveFormBuffer->SaveData(std::addressof(castPowerItemCount), sizeof(std::uint32_t), sizeof(std::uint32_t));

			for (const auto& castPowerItem : *castPowerItems)
			{
				saveFormBuffer->SaveFormID(castPowerItem.power, 0);
				saveFormBuffer->SaveData(std::addressof(castPowerItem.cooldown), sizeof(float), sizeof(float));
			}
		}
		else
		{
			saveFormBuffer->SaveData(std::addressof(castPowerItemCount), sizeof(std::uint32_t), sizeof(std::uint32_t));
		}
	}
}
