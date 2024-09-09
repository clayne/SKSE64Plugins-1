#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T, class HashFunction>
	class GHashSetCachedEntry
	{
	public:
		GHashSetCachedEntry() :
			nextInChain(-2)
		{
		}

		GHashSetCachedEntry(const GHashSetCachedEntry& entry) :
			nextInChain(entry.nextInChain),
			hashValue(entry.hashValue),
			value(entry.value)
		{
		}

		GHashSetCachedEntry(const T& key, SPInt nextInChain) :
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
			return this->hashValue;
		}

		void SetCachedHash(UPInt hashValue)
		{
			this->hashValue = hashValue;
		}

		/* CommonLibSSE destroys class C instead of class T */
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
		UPInt hashValue;   // 8
		T     value;       // 10
	};
}
