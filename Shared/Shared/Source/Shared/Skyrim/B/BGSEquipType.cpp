#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEquipType.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	BGSEquipType* BGSEquipType::GetFormAsEquipType(TESForm* form)
	{
		auto* function{ reinterpret_cast<decltype(BGSEquipType::GetFormAsEquipType)*>(
			Addresses::BGSEquipType::GetFormAsEquipType()) };

		return function(form);
	}
}
