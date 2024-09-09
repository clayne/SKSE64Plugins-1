#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiRefObject.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	NiRefObject::NiRefObject()
	{
		std::atomic_ref referenceObjectCount(const_cast<std::uint32_t&>(NiRefObject::GetReferenceObjectCount()));

		++referenceObjectCount;
	}

	NiRefObject::~NiRefObject()
	{
		std::atomic_ref referenceObjectCount(const_cast<std::uint32_t&>(NiRefObject::GetReferenceObjectCount()));

		--referenceObjectCount;
	}

	void NiRefObject::DeleteThis()
	{
		delete this;
	}

	void NiRefObject::DecrementReferenceCount()
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		if (--referenceCount == 0)
		{
			this->DeleteThis();
		}
	}

	void NiRefObject::IncrementReferenceCount()
	{
		std::atomic_ref referenceCount(const_cast<std::uint32_t&>(this->referenceCount_));

		++referenceCount;
	}

	volatile std::uint32_t& NiRefObject::GetReferenceObjectCount()
	{
		auto* singleton{ reinterpret_cast<volatile std::uint32_t*>(Addresses::NiRefObject::ReferenceObjectCount()) };

		return *singleton;
	}
}
