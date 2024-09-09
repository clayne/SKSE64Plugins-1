#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSource.h"



namespace Skyrim
{
	class Actor;

	namespace Pickpocket
	{
		struct Event
		{
		public:
			// Member variables
			Actor* thief;  // 0
			Actor* target; // 8
		};
		static_assert(offsetof(Event, thief) == 0x0);
		static_assert(offsetof(Event, target) == 0x8);
		static_assert(sizeof(Event) == 0x10);

		// Namespace functions
		BSTEventSource<Pickpocket::Event>* GetEventSource();
	}
}
