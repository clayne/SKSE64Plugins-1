#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashLH.h"
#include "Shared/Skyrim/G/GHashNode.h"
#include "Shared/Skyrim/G/GHashSetNodeEntry.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	template <
		class T,
		class U,
		class HashFunction         = GFixedSizeHash<T>,
		std::uint32_t STATISTIC_ID = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)>
	class GHashUncachedLH :
		public GHashLH<
			T,
			U,
			HashFunction,
			STATISTIC_ID,
			GHashNode<T, U, HashFunction>,
			GHashSetNodeEntry<GHashNode<T, U, HashFunction>, typename GHashNode<T, U, HashFunction>::NodeHashFunction>> // 0
	{
	public:
		using SelfType = GHashUncachedLH<T, U, HashFunction, STATISTIC_ID>;
		using BaseType = GHashLH<
			T,
			U,
			HashFunction,
			STATISTIC_ID,
			GHashNode<T, U, HashFunction>,
			GHashSetNodeEntry<GHashNode<T, U, HashFunction>, typename GHashNode<T, U, HashFunction>::NodeHashFunction>>;

		GHashUncachedLH()
		{
		}

		GHashUncachedLH(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashUncachedLH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashUncachedLH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
