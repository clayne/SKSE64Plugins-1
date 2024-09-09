#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GHashUncachedLH.h"
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
	class GHashIdentityLH :
		public GHashUncachedLH<T, U, HashFunction, STATISTIC_ID> // 0
	{
	public:
		using SelfType = GHashIdentityLH<T, U, STATISTIC_ID, HashFunction>;
		using BaseType = GHashUncachedLH<T, U, HashFunction, STATISTIC_ID>;

		GHashIdentityLH()
		{
		}

		GHashIdentityLH(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashIdentityLH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashIdentityLH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
