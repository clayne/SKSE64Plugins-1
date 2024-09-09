#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GHashSetBase.h"
#include "Shared/Skyrim/G/GHashSetCachedEntry.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Utility/Conversion.h"



namespace Skyrim
{
	template <
		class T,
		class HashFunction            = GFixedSizeHash<T>,
		class AlternativeHashFunction = HashFunction,
		std::uint32_t STATISTIC_ID    = Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory),
		class Entry                   = GHashSetCachedEntry<T, HashFunction>>
	class GHashSetDH :
		public GHashSetBase<T, HashFunction, AlternativeHashFunction, GAllocatorDH<T, STATISTIC_ID>, Entry> // 0
	{
	public:
		using SelfType = GHashSetDH<T, HashFunction, AlternativeHashFunction, STATISTIC_ID, Entry>;
		using BaseType = GHashSetBase<T, HashFunction, AlternativeHashFunction, GAllocatorDH<T, STATISTIC_ID>, Entry>;

		explicit GHashSetDH(void* heap) :
			heap_(heap)
		{
		}

		GHashSetDH(void* heap, std::int32_t sizeHint) :
			BaseType(heap, sizeHint),
			heap_(heap)
		{
		}

		GHashSetDH(const SelfType& source) :
			BaseType(source),
			heap_(source.heap_)
		{
		}

		~GHashSetDH()
		{
		}

		void operator=(const SelfType& source)
		{
			this->Assign(source.heap_, source);

			this->heap_ = source.heap_;
		}

		template <class TReference>
		void Set(const TReference& key)
		{
			BaseType::Set(this->heap_, key);
		}

		template <class TReference>
		inline void Add(const TReference& key)
		{
			BaseType::Add(this->heap_, key);
		}

		void CheckExpand()
		{
			BaseType::CheckExpand(this);
		}

		void Resize(UPInt size)
		{
			BaseType::SetCapacity(this->heap_, size);
		}

		void SetCapacity(UPInt size)
		{
			BaseType::SetCapacity(this->heap_, size);
		}

	private:
		// Member variables
		void* heap_;
	};
}
