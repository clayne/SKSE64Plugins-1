#pragma once

#include "PrecompiledHeader.h"



namespace PickpocketChanceFix
{
	class QuantitySliderChange :
		public Skyrim::GFxFunctionHandler
	{
	public:
		QuantitySliderChange(Skyrim::ContainerMenu* containerMenu);

		virtual ~QuantitySliderChange() override = default;
		virtual void Call(Parameters& parameters) override;

	private:
		Skyrim::ContainerMenu* containerMenu_{ nullptr };
	};
}
