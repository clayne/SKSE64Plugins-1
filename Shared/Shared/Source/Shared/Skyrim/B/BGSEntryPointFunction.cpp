#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BGSEntryPointFunction.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	namespace BGSEntryPointFunction
	{
		void ExecuteFunction(
			Utility::Enumeration<EntryPointFunction, std::uint32_t>     entryPointFunction,
			TESObjectREFR*                                              perkOwner,
			Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType,
			std::uint8_t                                                entryPointFunctionArgumentCount,
			void**                                                      entryPointFunctionArguments,
			BGSEntryPointFunctionData*                                  entryPointFunctionData)
		{
			auto* function{ reinterpret_cast<decltype(BGSEntryPointFunction::ExecuteFunction)*>(
				Addresses::BGSEntryPointFunction::ExecuteFunction()) };

			function(entryPointFunction, perkOwner, entryPointFunctionType, entryPointFunctionArgumentCount, entryPointFunctionArguments, entryPointFunctionData);
		}

		std::uint32_t GetEntryPointFunctionArgumentCount(Utility::Enumeration<EntryPointFunctionType, std::uint32_t> entryPointFunctionType)
		{
			return BGSEntryPointFunction::GetEntryPointFunctionArgumentCounts()[entryPointFunctionType.underlying()];
		}

		std::uint32_t* GetEntryPointFunctionArgumentCounts()
		{
			auto* singleton{ reinterpret_cast<std::uint32_t*>(Addresses::BGSEntryPointFunction::EntryPointFunctionArgumentCounts()) };

			return singleton;
		}
	}
}
