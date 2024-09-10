#pragma once

#include "PrecompiledHeader.h"



namespace PickpocketChanceFix
{
	class ContainerMenu
	{
	public:
		static void Load();

	private:
		static Skyrim::IMenu* CreateMenu();
		static void           AdvanceMovie(Skyrim::ContainerMenu* containerMenu, float interval, std::uint32_t currentTime);

		static void RequestItemCardInfo(const Skyrim::FxDelegateArguments& delegateArguments);
		static void QuantitySliderOpen(const Skyrim::FxDelegateArguments& delegateArguments);

		static std::optional<std::pair<std::int32_t, bool>> GetPickpocketChance(Skyrim::ContainerMenu* containerMenu);
		static void                                         SetPickpocketChance(Skyrim::ContainerMenu* containerMenu, std::int32_t pickpocketChance, bool isViewingContainer);

		static decltype(ContainerMenu::CreateMenu)*   createMenu_;
		static decltype(ContainerMenu::AdvanceMovie)* advanceMovie_;

		static decltype(ContainerMenu::RequestItemCardInfo)* requestItemCardInfo_;
		static decltype(ContainerMenu::QuantitySliderOpen)*  quantitySliderOpen_;
	};
}
