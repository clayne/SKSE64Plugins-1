#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashSetBase.h"
#include "Shared/Skyrim/G/GHashSetCachedEntry.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <
		class T,
		class HashFunction            = GFixedSizeHash<T>,
		class AlternativeHashFunction = HashFunction,
		class Allocator               = GAllocatorGH<T>,
		class Entry                   = GHashSetCachedEntry<T, HashFunction>>
	class GHashSet :
		public GHashSetBase<T, HashFunction, AlternativeHashFunction, Allocator, Entry> // 0
	{
	public:
		using SelfType = GHashSet<T, HashFunction, AlternativeHashFunction, Allocator, Entry>;
		using BaseType = GHashSetBase<T, HashFunction, AlternativeHashFunction, Allocator, Entry>;

		GHashSet()
		{
		}

		GHashSet(std::int32_t sizeHint) :
			BaseType(sizeHint)
		{
		}

		explicit GHashSet(void* memoryAddress) :
			BaseType(memoryAddress)
		{
		}

		GHashSet(void* memoryAddress, std::int32_t sizeHint) :
			BaseType(memoryAddress, sizeHint)
		{
		}

		GHashSet(const SelfType& source) :
			BaseType(source)
		{
		}

		~GHashSet()
		{
		}

		void operator=(const SelfType& source)
		{
			this->Assign(this, source);
		}

		template <class TReference>
		void Set(const TReference& key)
		{
			BaseType::Set(this, key);
		}

		template <class TReference>
		inline void Add(const TReference& key)
		{
			BaseType::Add(this, key);
		}

		void CheckExpand()
		{
			BaseType::CheckExpand(this);
		}

		void Resize(UPInt size)
		{
			BaseType::SetCapacity(this, size);
		}

		void SetCapacity(UPInt size)
		{
			BaseType::SetCapacity(this, size);
		}
	};
}
