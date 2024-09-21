#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	// Special Edition
	// Anniversary Edition
	class CastSpells
	{
	public:
		static void Load(bool& castSpells);

	private:
		static void ApplySpellItem(Skyrim::Actor* target, Skyrim::SpellItem* spellItem, Skyrim::Actor* caster);
	};
}
