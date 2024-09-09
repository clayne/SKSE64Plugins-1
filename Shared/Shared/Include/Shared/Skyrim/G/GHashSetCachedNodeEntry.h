#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T, class HashFunction>
	class GHashSetCachedNodeEntry
	{
	public:
		GHashSetCachedNodeEntry() :
			nextInChain(-2)
		{
		}

		GHashSetCachedNodeEntry(const GHashSetCachedNodeEntry& entry) :
			nextInChain(entry.nextInChain),
			hashValue(entry.hashValue),
			value(entry.value)
		{
		}

		GHashSetCachedNodeEntry(const T& key, SPInt nextInChain) :
			nextInChain(nextInChain),
			value(key)
		{
		}

		GHashSetCachedNodeEntry(const typename T::NodeReference& keyReference, SPInt nextInChain) :
			nextInChain(nextInChain),
			value(keyReference)
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
