#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Utility/Enumeration.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	// Special Edition
	// Anniversary Edition
	class ApplySpells
	{
	public:
		static void Load(bool& applySpells, bool& castSpells);

	private:
		static void ApplyBashingSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			...);
		static void ApplyCombatHitSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			...);
		static void ApplyReanimateSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			...);
		static void ApplySneakingSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			...);
		static void ApplyWeaponSwingSpell(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			...);
		static std::vector<void*> HandleEntryPoint(
			Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
			Skyrim::Actor*                                                         perkOwner,
			std::vector<Skyrim::TESForm*>                                          conditionFilterArguments);
		static void SelectSpell(
			Skyrim::TESObjectREFR*                                                                     perkOwner,
			Utility::Enumeration<Skyrim::BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
			std::uint8_t                                                                               entryPointFunctionArgumentCount,
			void**                                                                                     entryPointFunctionArguments,
			Skyrim::BGSEntryPointFunctionData*                                                         entryPointFunctionData);

		static bool castSpells_;
	};
}
