#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	// Special Edition
	// Anniversary Edition
	class DifficultyMultipliers
	{
	public:
		static void Load(bool& commandedActors, bool& teammates);

	private:
		class Actor
		{
		public:
			static float DifficultyLevelAdjustHealthModifier(Skyrim::Actor* target, float damage, float onlyReduceDamage);
			static bool  DoDamage(Skyrim::Actor* target, float damage, Skyrim::Actor* attacker, bool onlyReduceDamage);
		};

		static bool commandedActors_;
		static bool teammates_;
	};
}
