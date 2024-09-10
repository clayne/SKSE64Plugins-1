#include "PrecompiledHeader.h"

#include "GFxFunctionHandler.h"



namespace PickpocketChanceFix
{
	QuantitySliderChange::QuantitySliderChange(Skyrim::ContainerMenu* containerMenu) :
		containerMenu_(containerMenu)
	{
	}

	void QuantitySliderChange::Call(Parameters& parameters)
	{
		if (this->containerMenu_ && this->containerMenu_->itemCard)
		{
			if (parameters.argumentCount >= 1 && parameters.arguments[0].IsObject())
			{
				const auto& event = parameters.arguments[0];

				Skyrim::GFxValue value;

				if (event.GetMember("value", std::addressof(value)) && value.IsNumber())
				{
					this->containerMenu_->itemCard->object.SetMember("quantitySliderChange", value);
				}
			}
		}
	}
}
