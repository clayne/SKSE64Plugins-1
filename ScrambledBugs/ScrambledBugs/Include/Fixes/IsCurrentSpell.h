#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Fixes
{
	class IsCurrentSpell
	{
	public:
		static void Load(bool& isCurrentSpell);

	private:
		static Skyrim::ScriptFunction::ConditionFunction IsCurrentSpellConditionFunction;
		static Skyrim::ScriptFunction::ExecuteFunction   IsCurrentSpellFunction;

		static decltype(IsCurrentSpell::IsCurrentSpellConditionFunction)* isCurrentSpellConditionFunction_;
	};
}
