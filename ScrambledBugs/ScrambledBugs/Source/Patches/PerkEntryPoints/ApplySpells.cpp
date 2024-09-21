#include "PrecompiledHeader.h"

#include "Patches/PerkEntryPoints/ApplySpells.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches::PerkEntryPoints
{
	void ApplySpells::Load(bool& applySpells, bool& castSpells)
	{
		if (!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyBashingSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpellArrowProjectile() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyReanimateSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplySneakingSpell() ||
			!Patterns::Patches::PerkEntryPoints::ApplySpells::ApplyWeaponSwingSpell())
		{
			applySpells = false;
			castSpells  = false;

			return;
		}

		ApplySpells::castSpells_ = castSpells;

		const auto* trampolineInterface = SKSE::Storage::GetSingleton().GetTrampolineInterface();

		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyBashingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyBashingSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyCombatHitSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyCombatHitSpellArrowProjectile, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyCombatHitSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyReanimateSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyReanimateSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplySneakingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplySneakingSpell)));
		trampolineInterface->RelativeCall5(Addresses::Patches::PerkEntryPoints::ApplySpells::ApplyWeaponSwingSpell, reinterpret_cast<std::uintptr_t>(std::addressof(ApplySpells::ApplyWeaponSwingSpell)));

		*reinterpret_cast<decltype(ApplySpells::SelectSpell)**>(Addresses::Patches::PerkEntryPoints::ApplySpells::SelectSpell) = std::addressof(ApplySpells::SelectSpell);
	}

	/* Apply Bashing Spell
	* Perk Owner
	* Target */
	void ApplySpells::ApplyBashingSpell(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...)
	{
		std::va_list variadicArguments;
		va_start(variadicArguments, perkOwner);

		auto*  target = va_arg(variadicArguments, Skyrim::Actor*);
		auto** result = va_arg(variadicArguments, Skyrim::SpellItem**);

		va_end(variadicArguments);

		auto bashingSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, target });

		for (auto* bashingSpellItem : bashingSpellItems)
		{
			if (bashingSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(bashingSpellItem)->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
			}
		}
	}

	/* Apply Combat Hit Spell
	* Perk Owner
	* Weapon
	* Target */
	void ApplySpells::ApplyCombatHitSpell(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...)
	{
		std::va_list variadicArguments;
		va_start(variadicArguments, perkOwner);

		auto*  weapon = va_arg(variadicArguments, Skyrim::TESObjectWEAP*);
		auto*  target = va_arg(variadicArguments, Skyrim::Actor*);
		auto** result = va_arg(variadicArguments, Skyrim::SpellItem**);

		va_end(variadicArguments);

		auto combatHitSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, weapon, target });

		for (auto* combatHitSpellItem : combatHitSpellItems)
		{
			if (combatHitSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(combatHitSpellItem)->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
			}
		}
	}

	/* Apply Reanimate Spell
	* Perk Owner
	* Spell
	* Target */
	void ApplySpells::ApplyReanimateSpell(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...)
	{
		std::va_list variadicArguments;
		va_start(variadicArguments, perkOwner);

		auto*  spellItem = va_arg(variadicArguments, Skyrim::SpellItem*);
		auto*  target    = va_arg(variadicArguments, Skyrim::Actor*);
		auto** result    = va_arg(variadicArguments, Skyrim::SpellItem**);

		va_end(variadicArguments);

		auto reanimateSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, spellItem, target });

		for (auto* reanimateSpellItem : reanimateSpellItems)
		{
			if (reanimateSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(reanimateSpellItem)->Apply(target, ApplySpells::castSpells_ ? perkOwner : target);
			}
		}
	}

	/* Apply Sneaking Spell
	* Perk Owner */
	void ApplySpells::ApplySneakingSpell(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...)
	{
		std::va_list variadicArguments;
		va_start(variadicArguments, perkOwner);

		auto** result = va_arg(variadicArguments, Skyrim::SpellItem**);

		va_end(variadicArguments);

		auto sneakingSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner });

		for (auto* sneakingSpellItem : sneakingSpellItems)
		{
			if (sneakingSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(sneakingSpellItem)->Apply(perkOwner, perkOwner);
			}
		}
	}

	/* Apply Weapon Swing Spell
	* Perk Owner
	* Attacker
	* Attacker Weapon */
	void ApplySpells::ApplyWeaponSwingSpell(Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint, Skyrim::Actor* perkOwner, ...)
	{
		std::va_list variadicArguments;
		va_start(variadicArguments, perkOwner);

		auto*  attacker       = va_arg(variadicArguments, Skyrim::Actor*);
		auto*  attackerWeapon = va_arg(variadicArguments, Skyrim::TESObjectWEAP*);
		auto** result         = va_arg(variadicArguments, Skyrim::SpellItem**);

		va_end(variadicArguments);

		auto weaponSwingSpellItems = ApplySpells::HandleEntryPoint(entryPoint, perkOwner, std::vector<Skyrim::TESForm*>{ perkOwner, attacker, attackerWeapon });

		for (auto* weaponSwingSpellItem : weaponSwingSpellItems)
		{
			if (weaponSwingSpellItem)
			{
				static_cast<Skyrim::SpellItem*>(weaponSwingSpellItem)->Apply(perkOwner, ApplySpells::castSpells_ ? attacker : perkOwner);
			}
		}
	}

	std::vector<void*> ApplySpells::HandleEntryPoint(
		Utility::Enumeration<Skyrim::BGSEntryPoint::EntryPoint, std::uint32_t> entryPoint,
		Skyrim::Actor*                                                         perkOwner,
		std::vector<Skyrim::TESForm*>                                          conditionFilterArguments)
	{
		if (entryPoint.underlying() < Utility::Conversion::ToUnderlying(Skyrim::BGSEntryPoint::EntryPoint::kTotal))
		{
			if (perkOwner && perkOwner->HasPerkEntries(entryPoint.get()))
			{
				if (conditionFilterArguments.size() == Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint)->conditionFilterArgumentCount)
				{
					std::vector<void*> entryPointFunctionArguments = { std::numeric_limits<std::uint8_t>::max(), nullptr };

					Skyrim::HandleEntryPointVisitor handleEntryPointVisitor(
						Skyrim::BGSEntryPoint::GetEntryPoint(entryPoint)->entryPointFunctionType.get(),
						conditionFilterArguments.empty() ? nullptr : conditionFilterArguments.data(),
						entryPointFunctionArguments.empty() ? nullptr : entryPointFunctionArguments.data(),
						perkOwner,
						static_cast<std::uint8_t>(conditionFilterArguments.size()),
						static_cast<std::uint8_t>(entryPointFunctionArguments.size()));

					perkOwner->ForEachPerkEntry(entryPoint.get(), handleEntryPointVisitor);

					std::erase(entryPointFunctionArguments, nullptr);

					return entryPointFunctionArguments;
				}
			}
		}

		return {};
	}

	void ApplySpells::SelectSpell(
		Skyrim::TESObjectREFR*                                                                     perkOwner,
		Utility::Enumeration<Skyrim::BGSEntryPointFunction::EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
		std::uint8_t                                                                               entryPointFunctionArgumentCount,
		void**                                                                                     entryPointFunctionArguments,
		Skyrim::BGSEntryPointFunctionData*                                                         entryPointFunctionData)
	{
		// perkOwner != nullptr
		// entryPointFunctionArguments != nullptr
		// entryPointFunctionData != nullptr

		if (entryPointFunctionType != Skyrim::BGSEntryPointFunction::EntryPointFunctionType::kSpellItem)
		{
			return;
		}

		if (!entryPointFunctionArguments)
		{
			return;
		}

		if (!entryPointFunctionData || entryPointFunctionData->GetEntryPointFunctionDataType() != Skyrim::BGSEntryPointFunctionData::EntryPointFunctionData::kSpellItem)
		{
			return;
		}

		auto* spellItem = static_cast<Skyrim::BGSEntryPointFunctionDataSpellItem*>(entryPointFunctionData)->spellItem;

		if (!spellItem)
		{
			return;
		}

		std::span<void*> entryPointFunctionArgumentSpan(entryPointFunctionArguments, entryPointFunctionArgumentCount);

		auto entryPointFunctionArgumentIterator = std::find(entryPointFunctionArgumentSpan.begin(), entryPointFunctionArgumentSpan.end(), nullptr);

		if (entryPointFunctionArgumentIterator != entryPointFunctionArgumentSpan.end())
		{
			*entryPointFunctionArgumentIterator = spellItem;
		}
	}

	bool ApplySpells::castSpells_{};
}
