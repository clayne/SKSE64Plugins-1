#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/ItemList.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	bool ItemList::Item::IsInContainer(std::uint32_t filterFlag)
	{
		auto* function{ reinterpret_cast<decltype(ItemList::Item::IsInContainer)*>(
			Addresses::ItemList::Item::IsInContainer()) };

		return function(filterFlag);
	}

	std::uint32_t ItemList::Item::GetFilterFlag() const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ItemList::Item::GetFilterFlag)>::type>(
			Addresses::ItemList::Item::GetFilterFlag()) };

		return function(this);
	}

	ItemList::Item* ItemList::GetSelectedItem() const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ItemList::GetSelectedItem)>::type>(
			Addresses::ItemList::GetSelectedItem()) };

		return function(this);
	}

	void ItemList::InvalidateListData()
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ItemList::InvalidateListData)>::type>(
			Addresses::ItemList::InvalidateListData()) };

		return function(this);
	}

	void ItemList::Update(TESObjectREFR* owner)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ItemList::Update)>::type>(
			Addresses::ItemList::Update()) };

		function(this, owner);
	}
}
