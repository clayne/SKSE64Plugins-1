#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/D/DifficultyLevel.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	namespace GameplayFormulas
	{
		float CalculatePickpocketSkillUse(float stealValue);
		float GetDifficultyMultiplier(Utility::Enumeration<DifficultyLevel, std::uint32_t> difficultyLevel, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, bool isPlayer);
	}
}
