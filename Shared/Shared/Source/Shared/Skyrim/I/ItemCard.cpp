#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/ItemCard.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void ItemCard::PopulateInformation(InventoryEntryData* inventoryEntryData, bool isInContainer)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ItemCard::PopulateInformation)>::type>(
			Addresses::ItemCard::PopulateInformation()) };

		function(this, inventoryEntryData, isInContainer);
	}
}
