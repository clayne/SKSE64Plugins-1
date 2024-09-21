#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	// Special Edition
	// Anniversary Edition
	class ScrollEquipState
	{
	public:
		static void Load(bool& scrollEquipState);

	private:
		class Actor
		{
		public:
			static Skyrim::EquipState GetEquipState(Skyrim::Actor* actor, Skyrim::TESForm* form, Skyrim::ExtraDataList* rightHandExtraDataList, Skyrim::ExtraDataList* leftHandExtraDataList);
		};

		class StandardItemData
		{
		public:
			static Skyrim::EquipState GetEquipState(Skyrim::StandardItemData* standardItemData);
		};
	};
}
