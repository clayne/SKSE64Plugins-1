#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashDH.h"
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
	class GHashUncachedDH :
		public GHashDH<
			T,
			U,
			HashFunction,
			STATISTIC_ID,
			GHashNode<T, U, HashFunction>,
			GHashSetNodeEntry<GHashNode<T, U, HashFunction>, typename GHashNode<T, U, HashFunction>::NodeHashFunction>> // 0
	{
	public:
		using SelfType = GHashUncachedDH<T, U, HashFunction, STATISTIC_ID>;
		using BaseType = GHashDH<
			T,
			U,
			HashFunction,
			STATISTIC_ID,
			GHashNode<T, U, HashFunction>,
			GHashSetNodeEntry<GHashNode<T, U, HashFunction>, typename GHashNode<T, U, HashFunction>::NodeHashFunction>>;

		explicit GHashUncachedDH(void* heap) :
			BaseType(heap)
		{
		}

		GHashUncachedDH(void* heap, std::int32_t sizeHint) :
			BaseType(heap, sizeHint)
		{
		}

		GHashUncachedDH(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashUncachedDH()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
