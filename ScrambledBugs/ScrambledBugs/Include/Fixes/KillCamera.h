#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	// Special Edition
	// Anniversary Edition
	class KillCamera
	{
	public:
		static void Load(bool& killCamera);

	private:
		static void ApplyCombatHitSpell(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...);

		static decltype(KillCamera::ApplyCombatHitSpell)* applyCombatHitSpell_;
	};
}
