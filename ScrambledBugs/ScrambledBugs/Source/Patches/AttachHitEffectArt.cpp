#include "PrecompiledHeader.h"

#include "Patches/AttachHitEffectArt.h"

#include "Addresses.h"
#include "Patterns.h"
#include "Shared/Utility/Memory.h"



namespace ScrambledBugs::Patches
{
	void AttachHitEffectArt::Load(bool& attachHitEffectArt)
	{
		if (!Patterns::Patches::AttachHitEffectArt::CastPermanentMagicFunctor::SetFlags())
		{
			attachHitEffectArt = false;

			return;
		}

		/* Reset a CastPermanentMagicFunctor flag that sets an ActiveEffect flag to not attach hit effect art */
		Utility::Memory::SafeWrite(
			Addresses::Patches::AttachHitEffectArt::CastPermanentMagicFunctor::SetFlags,
			std::optional<std::uint8_t>{}, 0xF8ui8, // and al, F8
			std::optional<std::uint8_t>{}, 0x00ui8  // or al, 0
		);

		ModelReferenceEffect::pop_ = reinterpret_cast<decltype(ModelReferenceEffect::pop_)>(Utility::Memory::ReadVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x35));

		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x32, reinterpret_cast<std::uintptr_t>(std::addressof(ModelReferenceEffect::GetStackable)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x33, reinterpret_cast<std::uintptr_t>(std::addressof(ModelReferenceEffect::GetStackableMatch)));
		Utility::Memory::SafeWriteVirtualFunction(Skyrim::Addresses::ModelReferenceEffect::VirtualFunctionTable(), 0x35, reinterpret_cast<std::uintptr_t>(std::addressof(ModelReferenceEffect::Pop)));
	}

	bool AttachHitEffectArt::ModelReferenceEffect::GetStackable(Skyrim::ModelReferenceEffect* modelReferenceEffect)
	{
		return true;
	}

	bool AttachHitEffectArt::ModelReferenceEffect::GetStackableMatch(Skyrim::ModelReferenceEffect* left, Skyrim::BSTempEffect* right)
	{
		return true;
	}

	void AttachHitEffectArt::ModelReferenceEffect::Pop(Skyrim::ModelReferenceEffect* modelReferenceEffect)
	{
		ModelReferenceEffect::pop_(modelReferenceEffect);

		modelReferenceEffect->SwitchFirstThirdPerson();
	}

	decltype(AttachHitEffectArt::ModelReferenceEffect::Pop)* AttachHitEffectArt::ModelReferenceEffect::pop_{ nullptr };
}
