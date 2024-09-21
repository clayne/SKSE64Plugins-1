#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/R/RefrInteraction.h"

#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	bool RefrInteraction::GetActor(NiPointer<Actor>& actor) const
	{
		actor = this->actorHandle.get();

		return static_cast<bool>(actor);
	}

	bool RefrInteraction::GetTargetActor(NiPointer<Actor>& targetActor) const
	{
		auto targetReference = this->targetHandle.get();

		if (targetReference && targetReference->formType == FormType::kActor)
		{
			targetActor.reset(static_cast<Actor*>(targetReference.get()));
		}
		else
		{
			targetActor.reset();
		}

		return static_cast<bool>(targetActor);
	}
}
