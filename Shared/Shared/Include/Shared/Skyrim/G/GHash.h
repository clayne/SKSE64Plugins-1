#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashNode.h"
#include "Shared/Skyrim/G/GHashSet.h"
#include "Shared/Skyrim/G/GHashSetCachedNodeEntry.h"
#include "Shared/Skyrim/G/GMemory.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <
		class T,
		class U,
		class HashFunction = GFixedSizeHash<T>,
		class Allocator    = GAllocatorGH<T>,
		class HashNode     = GHashNode<T, U, HashFunction>,
		class Entry        = GHashSetCachedNodeEntry<HashNode, typename HashNode::NodeHashFunction>,
		class Container    = GHashSet<
			   HashNode,
			   typename HashNode::NodeHashFunction,
			   typename HashNode::NodeAlternativeHashFunction,
			   Allocator,
			   Entry>>
	class GHash
	{
	public:
		GFC_MEMORY_REDEFINE_NEW(GHash, Allocator::kStatisticID)

		using SelfType = GHash<T, U, HashFunction, Allocator, HashNode, Entry, Container>;

		GHash()
		{
		}

		GHash(std::int32_t sizeHint) :
			hashSet(sizeHint)
		{
		}

		explicit GHash(void* heap) :
			hashSet(heap)
		{
		}

		GHash(void* heap, std::int32_t sizeHint) :
			hashSet(heap, sizeHint)
		{
		}

		GHash(const SelfType& source) :
			hashSet(source.hashSet)
		{
		}

		~GHash()
		{
		}

		void operator=(const SelfType& source)
		{
			this->hashSet = source.hashSet;
		}

		inline void Clear()
		{
			this->hashSet.Clear();
		}

		inline bool IsEmpty() const
		{
			return this->hashSet.IsEmpty();
		}

		inline void Set(const T& key, const U& value)
		{
			typename HashNode::NodeReference entry(key, value);

			this->hashSet.Set(entry);
		}

		inline void Add(const T& key, const U& value)
		{
			typename HashNode::NodeReference entry(key, value);

			this->hashSet.Add(entry);
		}

		inline void Remove(const T& key)
		{
			this->hashSet.RemoveAlternative(key);
		}

		template <class V>
		inline void RemoveAlternative(const V& key)
		{
			this->hashSet.RemoveAlternative(key);
		}

		bool Get(const T& key, U* valuePointer) const
		{
			const HashNode* value = this->hashSet.GetAlternative(key);

			if (value)
			{
				if (valuePointer)
				{
					*valuePointer = value->second;
				}

				return true;
			}
			else
			{
				return false;
			}
		}

		template <class V>
		bool GetAlternative(const V& key, U* valuePointer) const
		{
			const HashNode* value = this->hashSet.GetAlternative(key);

			if (value)
			{
				if (valuePointer)
				{
					*valuePointer = value->second;
				}

				return true;
			}
			else
			{
				return false;
			}
		}

		inline U* Get(const T& key)
		{
			HashNode* value = this->hashSet.GetAlternative(key);

			return value ? std::addressof(value->second) : nullptr;
		}

		inline const U* Get(const T& key) const
		{
			const HashNode* value = this->hashSet.GetAlternative(key);

			return value ? std::addressof(value->second) : nullptr;
		}

		template <class V>
		inline U* GetAlternative(const V& key)
		{
			HashNode* value = this->hashSet.GetAlternative(key);

			return value ? std::addressof(value->second) : nullptr;
		}

		template <class V>
		inline const U* GetAlternative(const V& key) const
		{
			const HashNode* value = this->hashSet.GetAlternative(key);

			return value ? std::addressof(value->second) : nullptr;
		}

		inline UPInt GetSize() const
		{
			return this->hashSet.GetSize();
		}

		inline void Resize(UPInt size)
		{
			this->hashSet.Resize(size);
		}

		inline void SetCapacity(UPInt size)
		{
			this->hashSet.SetCapacity(size);
		}

		using ConstantIterator = typename Container::ConstantIterator;
		using Iterator         = typename Container::Iterator;

		inline Iterator Begin()
		{
			return this->hashSet.Begin();
		}

		inline Iterator End()
		{
			return this->hashSet.End();
		}

		inline ConstantIterator Begin() const
		{
			return this->hashSet.Begin();
		}

		inline ConstantIterator End() const
		{
			return this->hashSet.End();
		}

		Iterator Find(const T& key)
		{
			return this->hashSet.FindAlternative(key);
		}

		ConstantIterator Find(const T& key) const
		{
			return this->hashSet.FindAlternative(key);
		}

		template <class V>
		Iterator FindAlternative(const V& key)
		{
			return this->hashSet.FindAlternative(key);
		}

		template <class V>
		ConstantIterator FindAlternative(const V& key) const
		{
			return this->hashSet.FindAlternative(key);
		}

		// Member variables
		Container hashSet; // 0
	};
}
