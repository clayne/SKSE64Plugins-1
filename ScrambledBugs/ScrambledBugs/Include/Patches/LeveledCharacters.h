#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class LeveledCharacters
	{
	public:
		static void Load(bool& leveledCharacters);

	private:
		static Skyrim::TESLeveledList::AllBelowForce GetAllBelowForce(Skyrim::ExtraLevCreaModifier* extraLeveledCreatureModifier);
	};
}
