#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	class AlchemyItem;
	class MagicItem;

	class BGSCreatedObjectManager :
		public BSTSingletonSDM<BGSCreatedObjectManager>
	{
	public:
		struct CreatedMagicItemData
		{
		public:
			// Member variables
			MagicItem*             magicItem;      // 0
			volatile std::uint32_t referenceCount; // 8
			std::uint32_t          paddingC;       // C
		};
		static_assert(offsetof(CreatedMagicItemData, magicItem) == 0x0);
		static_assert(offsetof(CreatedMagicItemData, referenceCount) == 0x8);
		static_assert(sizeof(CreatedMagicItemData) == 0x10);

		// Non-member functions
		static BGSCreatedObjectManager* GetSingleton();

		// Member functions
		void DecrementReference(AlchemyItem* alchemyItem);

		// Member variables
		std::uint8_t                                    padding1;               // 1
		std::uint16_t                                   padding2;               // 2
		std::uint32_t                                   padding4;               // 4
		BSTArray<CreatedMagicItemData>                  weaponEnchantmentItems; // 8
		BSTArray<CreatedMagicItemData>                  armorEnchantmentItems;  // 20
		BSTHashMap<std::uint32_t, CreatedMagicItemData> potionAlchemyItems;     // 38
		BSTHashMap<std::uint32_t, CreatedMagicItemData> poisonAlchemyItems;     // 68
		BSTSet<MagicItem*>                              magicItemDeleteQueue;   // 98
		mutable BSSpinLock                              lock;                   // C8
	};
	static_assert(offsetof(BGSCreatedObjectManager, weaponEnchantmentItems) == 0x8);
	static_assert(offsetof(BGSCreatedObjectManager, armorEnchantmentItems) == 0x20);
	static_assert(offsetof(BGSCreatedObjectManager, potionAlchemyItems) == 0x38);
	static_assert(offsetof(BGSCreatedObjectManager, poisonAlchemyItems) == 0x68);
	static_assert(offsetof(BGSCreatedObjectManager, magicItemDeleteQueue) == 0x98);
	static_assert(offsetof(BGSCreatedObjectManager, lock) == 0xC8);
	static_assert(sizeof(BGSCreatedObjectManager) == 0xD0);
}
