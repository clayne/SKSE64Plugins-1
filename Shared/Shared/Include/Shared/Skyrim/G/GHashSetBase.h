#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashSetCachedEntry.h"
#include "Shared/Skyrim/G/GMath.h"
#include "Shared/Skyrim/G/GMemory.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <
		class T,
		class HashFunction            = GFixedSizeHash<T>,
		class AlternativeHashFunction = HashFunction,
		class Allocator               = GAllocatorGH<T>,
		class Entry                   = GHashSetCachedEntry<T, HashFunction>>
	class GHashSetBase
	{
	private:
		enum
		{
			kHashMinimumSize = 8
		};

	public:
		GFC_MEMORY_REDEFINE_NEW(GHashSetBase, Allocator::kStatisticID)

		using SelfType = GHashSetBase<T, HashFunction, AlternativeHashFunction, Allocator, Entry>;

		GHashSetBase() :
			table_(nullptr)
		{
		}

		GHashSetBase(std::int32_t sizeHint) :
			table_(nullptr)
		{
			this->SetCapacity(this, sizeHint);
		}

		explicit GHashSetBase(void* memoryAddress) :
			table_(nullptr)
		{
		}

		GHashSetBase(void* memoryAddress, std::int32_t sizeHint) :
			table_(nullptr)
		{
			this->SetCapacity(memoryAddress, sizeHint);
		}

		GHashSetBase(const SelfType& source) :
			table_(nullptr)
		{
			this->Assign(this, source);
		}

		~GHashSetBase()
		{
			if (this->table_)
			{
				UPInt sizeMask = this->table_->sizeMask;

				for (UPInt index = 0; index <= sizeMask; ++index)
				{
					Entry* entry = std::addressof(this->E(index));

					if (!entry->IsEmpty())
					{
						entry->Free();
					}
				}

				Allocator::Free(this->table_);

				this->table_ = nullptr;
			}
		}

		void Assign(void* memoryAddress, const SelfType& source)
		{
			this->Clear();

			if (!source.IsEmpty())
			{
				this->SetCapacity(memoryAddress, source.GetSize());

				for (ConstantIterator iterator = source.Begin(); iterator != source.End(); ++iterator)
				{
					this->Add(memoryAddress, *iterator);
				}
			}
		}

		void Clear()
		{
			if (this->table_)
			{
				UPInt sizeMask = this->table_->sizeMask;

				for (UPInt index = 0; index <= sizeMask; ++index)
				{
					Entry* entry = std::addressof(this->E(index));

					if (!entry->IsEmpty())
					{
						entry->Clear();
					}
				}

				Allocator::Free(this->table_);

				this->table_ = nullptr;
			}
		}

		bool IsEmpty() const
		{
			return !this->table_ || this->table_->entryCount == 0;
		}

		template <class TReference>
		void Set(void* memoryAddress, const TReference& key)
		{
			UPInt hashValue = HashFunction()(key);
			SPInt index     = static_cast<SPInt>(-1);

			if (this->table_)
			{
				index = this->FindIndexCore(key, hashValue & this->table_->sizeMask);
			}

			if (index >= 0)
			{
				this->E(index).value = key;
			}
			else
			{
				this->Add(memoryAddress, key, hashValue);
			}
		}

		template <class TReference>
		inline void Add(void* memoryAddress, const TReference& key)
		{
			UPInt hashValue = HashFunction()(key);

			this->Add(memoryAddress, key, hashValue);
		}

		template <class U>
		void RemoveAlternative(const U& key)
		{
			if (!this->table_)
			{
				return;
			}

			UPInt hashValue = AlternativeHashFunction()(key);
			SPInt index     = hashValue & this->table_->sizeMask;

			Entry* entry = std::addressof(this->E(index));

			if (entry->IsEmpty() || entry->GetCachedHash(this->table_->sizeMask) != static_cast<UPInt>(index))
			{
				return;
			}

			SPInt naturalIndex  = index;
			SPInt previousIndex = -1;

			while (entry->GetCachedHash(this->table_->sizeMask) != static_cast<UPInt>(naturalIndex) || entry->value != key)
			{
				previousIndex = index;
				index         = entry->nextInChain;

				if (index == -1)
				{
					return;
				}

				entry = std::addressof(this->E(index));
			}

			if (naturalIndex == index)
			{
				if (!entry->IsEndOfChain())
				{
					Entry* nextEntry = std::addressof(this->E(entry->nextInChain));

					entry->Clear();

					new (entry) Entry(*nextEntry);

					entry = nextEntry;
				}
			}
			else
			{
				this->E(previousIndex).nextInChain = entry->nextInChain;
			}

			entry->Clear();

			--this->table_->entryCount;
		}

		template <class TReference>
		void Remove(const TReference& key)
		{
			this->RemoveAlternative(key);
		}

		template <class U>
		T* Get(const U& key)
		{
			SPInt index = this->FindIndex(key);

			return index >= 0 ? std::addressof(this->E(index).value) : nullptr;
		}

		template <class U>
		const T* Get(const U& key) const
		{
			SPInt index = this->FindIndex(key);

			return index >= 0 ? std::addressof(this->E(index).value) : nullptr;
		}

		template <class U>
		T* GetAlternative(const U& key)
		{
			SPInt index = this->FindIndexAlternative(key);

			return index >= 0 ? std::addressof(this->E(index).value) : nullptr;
		}

		template <class U>
		const T* GetAlternative(const U& key) const
		{
			SPInt index = this->FindIndexAlternative(key);

			return index >= 0 ? std::addressof(this->E(index).value) : nullptr;
		}

		template <class U>
		bool GetAlternative(const U& key, T* valuePointer) const
		{
			SPInt index = this->FindIndexAlternative(key);

			if (index >= 0)
			{
				if (valuePointer)
				{
					*valuePointer = this->E(index).value;
				}

				return true;
			}
			else
			{
				return false;
			}
		}

		/* CommonLibSSE returns the entry count if the table is a null pointer */
		UPInt GetSize() const
		{
			return this->table_ ? this->table_->entryCount : 0;
		}

		void CheckExpand(void* memoryAddress)
		{
			if (!this->table_)
			{
				this->SetRawCapacity(memoryAddress, GHashSetBase::kHashMinimumSize);
			}
			else if (this->table_->entryCount * 5 > (this->table_->sizeMask + 1) * 4)
			{
				this->SetRawCapacity(memoryAddress, (this->table_->sizeMask + 1) * 2);
			}
		}

		void Resize(void* memoryAddress, UPInt size)
		{
			this->SetCapacity(memoryAddress, size);
		}

		void SetCapacity(void* memoryAddress, UPInt size)
		{
			UPInt rawSize = (size * 5) / 4;

			if (rawSize <= this->GetSize())
			{
				return;
			}

			this->SetRawCapacity(memoryAddress, rawSize);
		}

		struct ConstantIterator
		{
		public:
			const T& operator*() const
			{
				return this->hashSet_->E(this->index_).value;
			}

			const T* operator->() const
			{
				return std::addressof(this->operator*());
			}

			void operator++()
			{
				if (this->index_ <= static_cast<SPInt>(this->hashSet_->table_->sizeMask))
				{
					++this->index_;

					while (static_cast<UPInt>(this->index_) <= this->hashSet_->table_->sizeMask && this->hashSet_->E(this->index_).IsEmpty())
					{
						++this->index_;
					}
				}
			}

			bool operator==(const ConstantIterator& iterator) const
			{
				if (this->IsEnd() && iterator.IsEnd())
				{
					return true;
				}
				else
				{
					return (this->hashSet_ == iterator.hashSet_) && (this->index_ == iterator.index_);
				}
			}

			bool operator!=(const ConstantIterator& iterator) const
			{
				return !this->operator==(iterator);
			}

			bool IsEnd() const
			{
				return !this->hashSet_ || !this->hashSet_->table_ || this->index_ > static_cast<SPInt>(this->hashSet_->table_->sizeMask);
			}

			ConstantIterator() :
				hashSet_(nullptr),
				index_(0)
			{
			}

		protected:
			friend class GHashSetBase<T, HashFunction, AlternativeHashFunction, Allocator, Entry>;

			ConstantIterator(const SelfType* hashSet, SPInt index) :
				hashSet_(hashSet),
				index_(index)
			{
			}

			// Member variables
			const SelfType* hashSet_; // 0
			SPInt           index_;   // 8
		};
		static_assert(sizeof(ConstantIterator) == 0x10);

		friend struct ConstantIterator;

		struct Iterator :
			public ConstantIterator
		{
		public:
			T& operator*() const
			{
				return const_cast<SelfType*>(this->hashSet_)->E(this->index_).value;
			}

			T* operator->() const
			{
				return std::addressof(this->operator*());
			}

			Iterator() :
				ConstantIterator(nullptr, 0)
			{
			}

			void Remove()
			{
				SelfType* hashSet = const_cast<SelfType*>(this->hashSet_);
				const T&  key     = hashSet->E(this->index_).value;

				UPInt hashValue = AlternativeHashFunction()(key);
				SPInt index     = hashValue & hashSet->table_->sizeMask;

				Entry* entry = std::addressof(hashSet->E(index));

				if (entry->IsEmpty() || entry->GetCachedHash(hashSet->table_->sizeMask) != static_cast<UPInt>(index))
				{
					return;
				}

				SPInt naturalIndex  = index;
				SPInt previousIndex = -1;

				while (entry->GetCachedHash(hashSet->table_->sizeMask) != static_cast<UPInt>(naturalIndex) || entry->value != key)
				{
					previousIndex = index;
					index         = entry->nextInChain;

					if (index == -1)
					{
						return;
					}

					entry = std::addressof(hashSet->E(index));
				}

				if (index == this->index_)
				{
					if (naturalIndex == index)
					{
						if (!entry->IsEndOfChain())
						{
							Entry* nextEntry = std::addressof(hashSet->E(entry->nextInChain));

							entry->Clear();

							new (entry) Entry(*nextEntry);

							entry = nextEntry;

							--this->index_;
						}
					}
					else
					{
						hashSet->E(previousIndex).nextInChain = entry->nextInChain;
					}

					entry->Clear();

					--hashSet->table_->entryCount;
				}
			}

		private:
			friend class GHashSetBase<T, HashFunction, AlternativeHashFunction, Allocator, Entry>;

			Iterator(SelfType* hashSet, SPInt index) :
				ConstantIterator(hashSet, index)
			{
			}
		};
		static_assert(sizeof(Iterator) == 0x10);

		friend struct Iterator;

		Iterator Begin()
		{
			if (!this->table_)
			{
				return Iterator(nullptr, 0);
			}

			UPInt index = 0;

			while (index <= this->table_->sizeMask && this->E(index).IsEmpty())
			{
				++index;
			}

			return Iterator(this, index);
		}

		Iterator End()
		{
			return Iterator(nullptr, 0);
		}

		ConstantIterator Begin() const
		{
			return const_cast<SelfType*>(this)->Begin();
		}

		ConstantIterator End() const
		{
			return const_cast<SelfType*>(this)->End();
		}

		template <class U>
		Iterator Find(const U& key)
		{
			SPInt index = this->FindIndex(key);

			return index >= 0 ? Iterator(this, index) : Iterator(nullptr, 0);
		}

		template <class U>
		Iterator FindAlternative(const U& key)
		{
			SPInt index = this->FindIndexAlternative(key);

			return index >= 0 ? Iterator(this, index) : Iterator(nullptr, 0);
		}

		template <class U>
		ConstantIterator Find(const U& key) const
		{
			return const_cast<SelfType*>(this)->Find(key);
		}

		template <class U>
		ConstantIterator FindAlternative(const U& key) const
		{
			return const_cast<SelfType*>(this)->FindAlternative(key);
		}

	private:
		template <class U>
		SPInt FindIndex(const U& key) const
		{
			if (!this->table_)
			{
				return -1;
			}

			UPInt hashValue = HashFunction()(key) & this->table_->sizeMask;

			return this->FindIndexCore(key, hashValue);
		}

		template <class U>
		SPInt FindIndexAlternative(const U& key) const
		{
			if (!this->table_)
			{
				return -1;
			}

			UPInt hashValue = AlternativeHashFunction()(key) & this->table_->sizeMask;

			return this->FindIndexCore(key, hashValue);
		}

		template <class U>
		SPInt FindIndexCore(const U& key, UPInt hashValue) const
		{
			UPInt        index = hashValue;
			const Entry* entry = std::addressof(this->E(index));

			if (entry->IsEmpty() || entry->GetCachedHash(this->table_->sizeMask) != index)
			{
				return -1;
			}

			for (;;)
			{
				if (entry->GetCachedHash(this->table_->sizeMask) == hashValue && entry->value == key)
				{
					return index;
				}

				index = entry->nextInChain;

				if (index == static_cast<UPInt>(-1))
				{
					break;
				}

				entry = std::addressof(this->E(index));
			}

			return -1;
		}

		template <class TReference>
		void Add(void* memoryAddress, const TReference& key, UPInt hashValue)
		{
			this->CheckExpand(memoryAddress);

			hashValue &= this->table_->sizeMask;

			++this->table_->entryCount;

			SPInt  index        = hashValue;
			Entry* naturalEntry = std::addressof(this->E(index));

			if (naturalEntry->IsEmpty())
			{
				new (naturalEntry) Entry(key, -1);
			}
			else
			{
				SPInt blankIndex = index;

				do
				{
					blankIndex = (blankIndex + 1) & this->table_->sizeMask;
				} while (!this->E(blankIndex).IsEmpty());

				Entry* blankEntry = std::addressof(this->E(blankIndex));

				if (naturalEntry->GetCachedHash(this->table_->sizeMask) == static_cast<UPInt>(index))
				{
					new (blankEntry) Entry(*naturalEntry);

					naturalEntry->value       = key;
					naturalEntry->nextInChain = blankIndex;
				}
				else
				{
					SPInt collidedIndex = naturalEntry->GetCachedHash(this->table_->sizeMask);

					for (;;)
					{
						Entry* collidedEntry = std::addressof(this->E(collidedIndex));

						if (collidedEntry->nextInChain == index)
						{
							new (blankEntry) Entry(*naturalEntry);

							collidedEntry->nextInChain = blankIndex;

							break;
						}

						collidedIndex = collidedEntry->nextInChain;
					}

					naturalEntry->value       = key;
					naturalEntry->nextInChain = -1;
				}
			}

			naturalEntry->SetCachedHash(hashValue);
		}

		Entry& E(UPInt index)
		{
			return *(reinterpret_cast<Entry*>(this->table_ + 1) + index);
		}

		const Entry& E(UPInt index) const
		{
			return *(reinterpret_cast<Entry*>(this->table_ + 1) + index);
		}

		void SetRawCapacity(void* memoryAddress, UPInt size)
		{
			if (size == 0)
			{
				this->Clear();

				return;
			}

			if (size < GHashSetBase::kHashMinimumSize)
			{
				size = GHashSetBase::kHashMinimumSize;
			}
			else
			{
				std::int32_t bits = Skyrim::gfchop(Skyrim::glog2f(static_cast<float>(size - 1)) + 1);

				size = static_cast<UPInt>(1) << bits;
			}

			SelfType hashSet;

			hashSet.table_ = static_cast<TableType*>(Allocator::Allocate(memoryAddress, sizeof(TableType) + sizeof(Entry) * size));

			hashSet.table_->entryCount = 0;
			hashSet.table_->sizeMask   = size - 1;

			for (UPInt index = 0; index < size; ++index)
			{
				hashSet.E(index).nextInChain = -2;
			}

			if (this->table_)
			{
				UPInt sizeMask = this->table_->sizeMask;

				for (UPInt index = 0; index <= sizeMask; ++index)
				{
					Entry* entry = std::addressof(this->E(index));

					if (!entry->IsEmpty())
					{
						hashSet.Add(memoryAddress, entry->value);

						entry->Clear();
					}
				}

				Allocator::Free(this->table_);
			}

			this->table_   = hashSet.table_;
			hashSet.table_ = nullptr;
		}

		struct TableType
		{
		public:
			// Member variables
			UPInt entryCount; // 0
			UPInt sizeMask;   // 8
		};
		static_assert(offsetof(TableType, entryCount) == 0x0);
		static_assert(offsetof(TableType, sizeMask) == 0x8);
		static_assert(sizeof(TableType) == 0x10);

		// Member variables
		TableType* table_; // 0
	};
}
