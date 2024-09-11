#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class EquipState : std::uint32_t
	{
		kNone              = 0,
		kEquipped          = 1,
		kLeftEquip         = 2,
		kRightEquip        = 3,
		kLeftAndRightEquip = 4
	};
	static_assert(sizeof(EquipState) == 0x4);
}
