#pragma once

#include "PrecompiledHeader.h"



namespace PickpocketChanceFix
{
	class PlayerCharacter
	{
	public:
		static void Load();

	private:
		static bool AttemptPickpocket(
			Skyrim::PlayerCharacter*    playerCharacter,
			Skyrim::TESObjectREFR*      reference,
			Skyrim::InventoryEntryData* inventoryEntryData,
			std::int32_t                count,
			bool                        isViewingContainer);
	};
}
