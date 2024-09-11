#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class ScrollEquipState
	{
	public:
		static void Fix(bool& scrollEquipState);

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
