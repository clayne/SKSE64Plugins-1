#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	enum class DetectionPriority : std::uint32_t
	{
		kNormal = 3
	};
	static_assert(sizeof(DetectionPriority) == 0x4);
}
