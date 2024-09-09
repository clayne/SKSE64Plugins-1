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
	}
}
