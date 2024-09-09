#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	class NiRefObject
	{
	public:
		SKYRIM_MEMORY_REDEFINE_NEW();

		NiRefObject();

		// Add
		virtual ~NiRefObject();    // 0
		virtual void DeleteThis(); // 1

		// Member functions
		void                    DecrementReferenceCount();
		constexpr std::uint32_t GetReferenceCount() const { return this->referenceCount_; }
		void                    IncrementReferenceCount();

	private:
		// Member functions
		static volatile std::uint32_t& GetReferenceObjectCount();

	protected:
		// Member variables
		volatile std::uint32_t referenceCount_{ 0 }; // 8
	};
	static_assert(sizeof(NiRefObject) == 0x10);
}
