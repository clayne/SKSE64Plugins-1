#include "PrecompiledHeader.h"

#include "GFxFunctionHandler.h"



namespace PickpocketChanceFix
{
	void QuantitySliderChange::Call(Parameters& parameters)
	{
		if (parameters.argumentCount < 1 || !parameters.arguments[0].IsObject())
		{
			return;
		}

		const auto& event = parameters.arguments[0];

		Skyrim::GFxValue value;

		if (!event.GetMember("value", std::addressof(value)) || !value.IsNumber())
		{
			return;
		}

		std::array<Skyrim::GFxValue, 2> arguments = { /* methodName */ "QuantitySliderChange", /* parameters */ {} };

		parameters.movieView->CreateArray(std::addressof(arguments[1]));
		arguments[1].PushBack(value);

		parameters.movieView->Invoke("gfx.io.GameDelegate.call", nullptr, arguments.data(), static_cast<std::uint32_t>(arguments.size()));
	}
}
