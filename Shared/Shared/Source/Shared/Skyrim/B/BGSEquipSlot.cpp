#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEquipSlot.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool BGSEquipSlot::CheckForSlotConflict(const BGSEquipSlot* right) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BGSEquipSlot::CheckForSlotConflict)>::type>(
			Addresses::BGSEquipSlot::CheckForSlotConflict()) };

		return function(this, right);
	}
}
