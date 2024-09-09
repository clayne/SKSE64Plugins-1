#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AIFormulas.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	namespace AIFormulas
	{
		std::int32_t ComputePickpocketSuccess(float thiefSkill, float targetSkill, std::int32_t value, float weight, Actor* thief, Actor* target, bool detected, TESBoundObject* boundObject)
		{
			auto* function{ reinterpret_cast<decltype(AIFormulas::ComputePickpocketSuccess)*>(
				Addresses::AIFormulas::ComputePickpocketSuccess()) };

			return function(thiefSkill, targetSkill, value, weight, thief, target, detected, boundObject);
		}
	}
}
