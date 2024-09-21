#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GameplayFormulas.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	namespace GameplayFormulas
	{
		float CalculatePickpocketSkillUse(float stealValue)
		{
			auto* function{ reinterpret_cast<decltype(GameplayFormulas::CalculatePickpocketSkillUse)*>(
				Addresses::GameplayFormulas::CalculatePickpocketSkillUse()) };

			return function(stealValue);
		}

		float GetDifficultyMultiplier(Utility::Enumeration<DifficultyLevel, std::uint32_t> difficultyLevel, Utility::Enumeration<ActorValue, std::uint32_t> actorValue, bool isPlayer)
		{
			auto* function{ reinterpret_cast<decltype(GameplayFormulas::GetDifficultyMultiplier)*>(
				Addresses::GameplayFormulas::GetDifficultyMultiplier()) };

			return function(difficultyLevel, actorValue, isPlayer);
		}
	}
}
