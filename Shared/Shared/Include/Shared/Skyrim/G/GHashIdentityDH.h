#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GHashUncachedDH.h"
#include "Shared/Skyrim/G/GIdentityHash.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	template <
		class T,
		class U,
		std::uint32_t STATISTIC_ID = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory),
		class HashFunction         = GIdentityHash<T>>
	class GHashIdentityDH :
		public GHashUncachedDH<T, U, HashFunction, STATISTIC_ID> // 0
	{
	public:
		using SelfType = GHashIdentityDH<T, U, STATISTIC_ID, HashFunction>;
		using BaseType = GHashUncachedDH<T, U, HashFunction, STATISTIC_ID>;

		explicit GHashIdentityDH(void* heap) :
			BaseType(heap)
		{
		}

		GHashIdentityDH(void* heap, std::int32_t sizeHint) :
			BaseType(heap, sizeHint)
		{
		}

		GHashIdentityDH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashIdentityDH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
