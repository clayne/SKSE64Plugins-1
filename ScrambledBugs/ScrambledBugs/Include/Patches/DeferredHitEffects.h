#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class DeferredHitEffects
	{
	public:
		static void Load(bool& deferredHitEffects);

	private:
		static bool AllowHitEffects(Skyrim::ActiveEffect* activeEffect);
	};
}
