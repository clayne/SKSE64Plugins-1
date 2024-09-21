#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class HitEffectRaceCondition
	{
	public:
		static void Load(bool& hitEffectRaceCondition);

	private:
		static bool ShouldUpdate(Skyrim::ActiveEffect* activeEffect);
	};
}
