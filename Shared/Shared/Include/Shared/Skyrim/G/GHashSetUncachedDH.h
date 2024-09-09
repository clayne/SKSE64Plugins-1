#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashSetDH.h"
#include "Shared/Skyrim/G/GHashSetEntry.h"
#include "Shared/Skyrim/G/GStatistics.h"



namespace Skyrim
{
	template <
		class T,
		class HashFunction            = GFixedSizeHash<T>,
		class AlternativeHashFunction = HashFunction,
		std::uint32_t STATISTIC_ID    = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	class GHashSetUncachedDH :
		public GHashSetDH<T, HashFunction, AlternativeHashFunction, STATISTIC_ID, GHashSetEntry<T, HashFunction>> // 0
	{
	public:
		using SelfType = GHashSetUncachedDH<T, HashFunction, AlternativeHashFunction, STATISTIC_ID>;
		using BaseType = GHashSetDH<T, HashFunction, AlternativeHashFunction, STATISTIC_ID, GHashSetEntry<T, HashFunction>>;

		explicit GHashSetUncachedDH(void* heap) :
			BaseType(heap)
		{
		}

		GHashSetUncachedDH(void* heap, std::int32_t sizeHint) :
			BaseType(heap, sizeHint)
		{
		}

		GHashSetUncachedDH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashSetUncachedDH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
