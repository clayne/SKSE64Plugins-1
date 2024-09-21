#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class PowerCooldowns
	{
	public:
		static void Load(bool& powerCooldowns);

	private:
		static void SaveCastPowerItems(Skyrim::Actor* actor, Skyrim::BGSSaveFormBuffer* saveFormBuffer);
	};
}
