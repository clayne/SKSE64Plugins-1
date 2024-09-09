#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHash.h"
#include "Shared/Skyrim/G/GHashNode.h"
#include "Shared/Skyrim/G/GHashSetCachedNodeEntry.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	template <
		class T,
		class U,
		class HashFunction         = GFixedSizeHash<T>,
		std::uint32_t STATISTIC_ID = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory),
		class HashNode             = GHashNode<T, U, HashFunction>,
		class Entry                = GHashSetCachedNodeEntry<HashNode, typename HashNode::NodeHashFunction>>
	class GHashLH :
		public GHash<T, U, HashFunction, GAllocatorLH<T, STATISTIC_ID>, HashNode, Entry> // 0
	{
	public:
		using SelfType = GHashLH<T, U, HashFunction, STATISTIC_ID, HashNode, Entry>;
		using BaseType = GHash<T, U, HashFunction, GAllocatorLH<T, STATISTIC_ID>, HashNode, Entry>;

		GHashLH()
		{
		}

		GHashLH(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashLH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashLH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
