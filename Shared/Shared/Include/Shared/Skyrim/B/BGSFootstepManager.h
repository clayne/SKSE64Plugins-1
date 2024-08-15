#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/B/BSTSingleton.h"



namespace Skyrim
{
	struct BGSFootstepEvent;

	class BGSFootstepManager :
		public BSTEventSource<BGSFootstepEvent>,   // 0
		public BSTSingletonSDM<BGSFootstepManager> // 58
	{
	public:
		// Non-member functions
		static BGSFootstepManager* GetSingleton();

		// Member variables
		std::uint8_t  unknown59; // 59
		std::uint16_t unknown5A; // 5A
		std::uint32_t unknown5C; // 5C
		std::uint64_t unknown60; // 60
		std::uint64_t unknown68; // 68
		std::uint64_t unknown70; // 70
		std::uint64_t unknown78; // 78
	};
	static_assert(sizeof(BGSFootstepManager) == 0x80);
}
