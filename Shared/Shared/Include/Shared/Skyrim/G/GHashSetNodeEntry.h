#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T, class HashFunction>
	class GHashSetNodeEntry
	{
	public:
		GHashSetNodeEntry() :
			nextInChain(-2)
		{
		}

		GHashSetNodeEntry(const GHashSetNodeEntry& entry) :
			nextInChain(entry.nextInChain),
			value(entry.value)
		{
		}

		GHashSetNodeEntry(const T& key, SPInt nextInChain) :
			nextInChain(nextInChain),
			value(key)
		{
		}

		GHashSetNodeEntry(const typename T::NodeReference& keyReference, SPInt nextInChain) :
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
