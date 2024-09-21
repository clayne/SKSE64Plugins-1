#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class LeftHandPowerAttacks
	{
	public:
		static void Load(bool& leftHandPowerAttacks);

	private:
		static float GetAttackStamina(Skyrim::ActorValueOwner* actorValueOwner, Skyrim::BGSAttackData* attackData);
	};
}
