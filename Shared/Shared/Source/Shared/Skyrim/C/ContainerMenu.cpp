#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/C/ContainerMenu.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"



namespace Skyrim
{
	ContainerMenu::ContainerMode ContainerMenu::GetContainerMode()
	{
		auto* singleton{ reinterpret_cast<ContainerMode*>(Addresses::ContainerMenu::ContainerMode()) };

		return *singleton;
	}

	const char* ContainerMenu::GetMenuName()
	{
		auto* singleton{ reinterpret_cast<const char*>(Addresses::ContainerMenu::MenuName()) };

		return singleton;
	}

	NiPointer<TESObjectREFR> ContainerMenu::GetTargetReference()
	{
		return ContainerMenu::GetTargetReferenceHandle().get();
	}

	ObjectReferenceHandle ContainerMenu::GetTargetReferenceHandle()
	{
		auto* singleton{ reinterpret_cast<ObjectReferenceHandle*>(Addresses::ContainerMenu::TargetReferenceHandle()) };

		return *singleton;
	}
}
