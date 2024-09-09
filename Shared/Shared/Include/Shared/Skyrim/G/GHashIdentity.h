#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GHashUncached.h"
#include "Shared/Skyrim/G/GIdentityHash.h"



namespace Skyrim
{
	template <
		class T,
		class U,
		class Allocator    = GAllocatorGH<T>,
		class HashFunction = GIdentityHash<T>>
	class GHashIdentity :
		public GHashUncached<T, U, HashFunction, Allocator> // 0
	{
	public:
		using SelfType = GHashIdentity<T, U, Allocator, HashFunction>;
		using BaseType = GHashUncached<T, U, HashFunction, Allocator>;

		GHashIdentity()
		{
		}

		GHashIdentity(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		GHashIdentity(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashIdentity()
		{
		}

		void operator=(const SelfType& source)
		{
			BaseType::operator=(source);
		}
	};
}
