#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/P/Pickpocket.h"



namespace Skyrim
{
	struct PickpocketToMiscStatHandler :
		public BSTEventSink<Pickpocket::Event> // 0
	{
	public:
		// Override
		virtual ~PickpocketToMiscStatHandler() override; // 0

		// Override (BSTEventSink<Pickpocket::Event>)
		virtual EventNotifyControl ProcessEvent(const Pickpocket::Event* eventArguments, BSTEventSource<Pickpocket::Event>* eventSource) override; // 1
	};
	static_assert(sizeof(PickpocketToMiscStatHandler) == 0x8);
}
