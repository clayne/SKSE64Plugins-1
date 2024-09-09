#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashSet.h"
#include "Shared/Skyrim/G/GHashSetEntry.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	template <
		class T,
		class HashFunction            = GFixedSizeHash<T>,
		class AlternativeHashFunction = HashFunction,
		std::uint32_t STATISTIC_ID    = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	class GHashSetUncachedLH :
		public GHashSet<T, HashFunction, AlternativeHashFunction, GAllocatorLH<T, STATISTIC_ID>, GHashSetEntry<T, HashFunction>> // 0
	{
	public:
		using SelfType = GHashSetUncachedLH<T, HashFunction, AlternativeHashFunction, STATISTIC_ID>;
		using BaseType = GHashSet<T, HashFunction, AlternativeHashFunction, GAllocatorLH<T, STATISTIC_ID>, GHashSetEntry<T, HashFunction>>;

		GHashSetUncachedLH()
		{
		}

		GHashSetUncachedLH(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashSetUncachedLH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashSetUncachedLH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
