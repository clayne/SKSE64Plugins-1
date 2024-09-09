#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/P/Pickpocket.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	namespace Pickpocket
	{
		BSTEventSource<Pickpocket::Event>* GetEventSource()
		{
			auto* function{ reinterpret_cast<decltype(Pickpocket::GetEventSource)*>(
				Addresses::Pickpocket::GetEventSource()) };

			return function();
		}
	}
}
