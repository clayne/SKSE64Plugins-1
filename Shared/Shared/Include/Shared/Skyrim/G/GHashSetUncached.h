#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashSet.h"
#include "Shared/Skyrim/G/GHashSetEntry.h"



namespace Skyrim
{
	template <
		class T,
		class HashFunction            = GFixedSizeHash<T>,
		class AlternativeHashFunction = HashFunction,
		class Allocator               = GAllocatorGH<T>>
	class GHashSetUncached :
		public GHashSet<T, HashFunction, AlternativeHashFunction, Allocator, GHashSetEntry<T, HashFunction>> // 0
	{
	public:
		using SelfType = GHashSetUncached<T, HashFunction, AlternativeHashFunction, Allocator>;
		using BaseType = GHashSet<T, HashFunction, AlternativeHashFunction, Allocator, GHashSetEntry<T, HashFunction>>;

		GHashSetUncached()
		{
		}

		GHashSetUncached(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashSetUncached(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashSetUncached()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
