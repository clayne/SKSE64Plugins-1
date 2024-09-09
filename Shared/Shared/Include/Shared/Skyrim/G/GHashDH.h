#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHash.h"
#include "Shared/Skyrim/G/GHashNode.h"
#include "Shared/Skyrim/G/GHashSetCachedNodeEntry.h"
#include "Shared/Skyrim/G/GHashSetDH.h"
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
	class GHashDH :
		public GHash<
			T,
			U,
			HashFunction,
			GAllocatorDH<T, STATISTIC_ID>,
			HashNode,
			Entry,
			GHashSetDH<
				HashNode,
				typename HashNode::NodeHashFunction,
				typename HashNode::NodeAlternativeHashFunction,
				STATISTIC_ID,
				Entry>> // 0
	{
	public:
		using SelfType = GHashDH<T, U, HashFunction, STATISTIC_ID, HashNode, Entry>;
		using BaseType = GHash<
			T,
			U,
			HashFunction,
			GAllocatorDH<T, STATISTIC_ID>,
			HashNode,
			Entry,
			GHashSetDH<
				HashNode,
				typename HashNode::NodeHashFunction,
				typename HashNode::NodeAlternativeHashFunction,
				STATISTIC_ID,
				Entry>>;

		explicit GHashDH(void* heap) :
			BaseType(heap)
		{
		}

		GHashDH(void* heap, std::int32_t sizeHint) :
			BaseType(heap, sizeHint)
		{
		}

		GHashDH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashDH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
