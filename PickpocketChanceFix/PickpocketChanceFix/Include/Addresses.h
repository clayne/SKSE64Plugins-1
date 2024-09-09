#pragma once

#include "PrecompiledHeader.h"

#include "Shared/Relocation/AddressLibrary.h"
#include "Shared/Relocation/PreprocessorDirectives.h"



namespace PickpocketChanceFix::Addresses
{
	namespace PlayerCharacter
	{
		/// <summary>1.5.97.0: SkyrimSE.exe + 0x6B2530, 1.6.318.0: SkyrimSE.exe + 0x6DACF0</summary>
		inline const std::uintptr_t AttemptPickpocket{ Relocation::AddressLibrary::GetSingleton().GetAddress(SKYRIM_RELOCATE(39568, 40654)) };
	}
}
