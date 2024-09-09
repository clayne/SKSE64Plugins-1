#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T, class HashFunction>
	class GHashSetEntry
	{
	public:
		GHashSetEntry() :
			nextInChain(-2)
		{
		}

		GHashSetEntry(const GHashSetEntry& entry) :
			nextInChain(entry.nextInChain),
			value(entry.value)
		{
		}

		GHashSetEntry(const T& key, SPInt nextInChain) :
			nextInChain(nextInChain),
			value(key)
		{
		}

		bool IsEmpty() const
		{
			return this->nextInChain == -2;
		}

		bool IsEndOfChain() const
		{
			return this->nextInChain == -1;
		}

		UPInt GetCachedHash(UPInt maskValue) const
		{
			return HashFunction()(this->value) & maskValue;
		}

		void SetCachedHash(UPInt hashValue)
		{
		}

		void Clear()
		{
			this->value.~T();

			this->nextInChain = -2;
		}

		void Free()
		{
			this->Clear();
		}

		// Member variables
		SPInt nextInChain; // 0
		T     value;       // 8
	};
}
