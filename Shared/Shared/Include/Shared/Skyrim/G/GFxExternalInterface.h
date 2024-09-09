#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxState.h"



namespace Skyrim
{
	class GFxMovieView;
	class GFxValue;

	class GFxExternalInterface :
		public GFxState // 0
	{
	public:
		GFxExternalInterface() :
			GFxState(StateType::kExternalInterface)
		{
		}

		// Override
		virtual ~GFxExternalInterface() override {}; // 0

		// Add
		virtual void Callback(GFxMovieView* movieView, const char* methodName, const GFxValue* arguments, std::uint32_t argumentCount) = 0; // 1
	};
	static_assert(sizeof(GFxExternalInterface) == 0x18);
}
