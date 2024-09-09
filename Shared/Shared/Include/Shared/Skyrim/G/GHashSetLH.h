#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashSet.h"
#include "Shared/Skyrim/G/GHashSetCachedEntry.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	template <
		class T,
		class HashFunction            = GFixedSizeHash<T>,
		class AlternativeHashFunction = HashFunction,
		std::uint32_t STATISTIC_ID    = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory),
		class Entry                   = GHashSetCachedEntry<T, HashFunction>>
	class GHashSetLH :
		public GHashSet<T, HashFunction, AlternativeHashFunction, GAllocatorLH<T, STATISTIC_ID>, Entry> // 0
	{
	public:
		using SelfType = GHashSetLH<T, HashFunction, AlternativeHashFunction, STATISTIC_ID, Entry>;
		using BaseType = GHashSet<T, HashFunction, AlternativeHashFunction, GAllocatorLH<T, STATISTIC_ID>, Entry>;

		GHashSetLH()
		{
		}

		GHashSetLH(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashSetLH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashSetLH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
