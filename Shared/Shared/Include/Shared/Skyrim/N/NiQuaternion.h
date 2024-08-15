#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class NiQuaternion
	{
	public:
		// Member variables
		float w; // 0
		float x; // 4
		float y; // 8
		float z; // C
	};
	static_assert(offsetof(NiQuaternion, w) == 0x0);
	static_assert(offsetof(NiQuaternion, x) == 0x4);
	static_assert(offsetof(NiQuaternion, y) == 0x8);
	static_assert(offsetof(NiQuaternion, z) == 0xC);
	static_assert(sizeof(NiQuaternion) == 0x10);
}
