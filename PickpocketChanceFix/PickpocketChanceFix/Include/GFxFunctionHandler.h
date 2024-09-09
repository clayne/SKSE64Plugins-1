#pragma once

#include "PrecompiledHeader.h"



namespace PickpocketChanceFix
{
	class QuantitySliderChange :
		public Skyrim::GFxFunctionHandler
	{
	public:
		virtual ~QuantitySliderChange() override = default;
		virtual void Call(Parameters& parameters) override;
	};
}
