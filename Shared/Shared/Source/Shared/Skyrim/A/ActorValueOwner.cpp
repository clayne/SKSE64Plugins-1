#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValueOwner.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	float ActorValueOwner::GetClampedActorValue(Utility::Enumeration<ActorValue, std::uint32_t> actorValue) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ActorValueOwner::GetClampedActorValue)>::type>(
			Addresses::ActorValueOwner::GetClampedActorValue()) };

		return function(this, actorValue);
	}

	float ActorValueOwner::GetDualCastingEffectiveness(float cost) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&ActorValueOwner::GetDualCastingEffectiveness)>::type>(
			Addresses::ActorValueOwner::GetDualCastingEffectiveness()) };

		return function(this, cost);
	}
}
