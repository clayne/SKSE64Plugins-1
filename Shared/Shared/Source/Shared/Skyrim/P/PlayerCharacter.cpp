#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/P/PlayerCharacter.h"

#include "Shared/Skyrim/Addresses.h"



namespace Skyrim
{
	PlayerCharacter* PlayerCharacter::GetSingleton()
	{
		auto** singleton{ reinterpret_cast<PlayerCharacter**>(Addresses::PlayerCharacter::Singleton()) };

		return *singleton;
	}

	NiPointer<Actor> PlayerCharacter::GetActorDoingPlayerCommand() const
	{
		return this->actorDoingPlayerCommandHandle.get();
	}

	bool PlayerCharacter::GetAutomaticAimActor(NiPointer<Actor>& automaticAimActor) const
	{
		auto temporary = this->automaticAimActorHandle.get();

		if (temporary && temporary->GetThirdPerson3D())
		{
			automaticAimActor = temporary;
		}
		else
		{
			automaticAimActor.reset();
		}

		return static_cast<bool>(automaticAimActor);
	}

	void PlayerCharacter::ResetInsufficientChargeMessage(bool leftHand)
	{
		if (leftHand)
		{
			this->playerCharacterFlags.shownInsufficientChargeMessageLeftHand = false;
		}
		else
		{
			this->playerCharacterFlags.shownInsufficientChargeMessageRightHand = false;
		}
	}
}
