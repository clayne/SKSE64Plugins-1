#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class Actor;
	class TESBoundObject;

	namespace AIFormulas
	{
		std::int32_t ComputePickpocketSuccess(float thiefSkill, float targetSkill, std::int32_t value, float weight, Actor* thief, Actor* target, bool detected, TESBoundObject* boundObject);
	}
}
