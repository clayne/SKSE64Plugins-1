#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHash.h"
#include "Shared/Skyrim/G/GHashNode.h"
#include "Shared/Skyrim/G/GHashSetNodeEntry.h"



namespace Skyrim
{
	template <
		class T,
		class U,
		class HashFunction = GFixedSizeHash<T>,
		class Allocator    = GAllocatorGH<T>>
	class GHashUncached :
		public GHash<
			T,
			U,
			HashFunction,
			Allocator,
			GHashNode<T, U, HashFunction>,
			GHashSetNodeEntry<GHashNode<T, U, HashFunction>, typename GHashNode<T, U, HashFunction>::NodeHashFunction>> // 0
	{
	public:
		using SelfType = GHashUncached<T, U, HashFunction, Allocator>;
		using BaseType = GHash<
			T,
			U,
			HashFunction,
			Allocator,
			GHashNode<T, U, HashFunction>,
			GHashSetNodeEntry<GHashNode<T, U, HashFunction>, typename GHashNode<T, U, HashFunction>::NodeHashFunction>>;

		GHashUncached()
		{
		}

		GHashUncached(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashUncached(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashUncached()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
