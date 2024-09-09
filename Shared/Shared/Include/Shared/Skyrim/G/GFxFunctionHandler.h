#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GStatistics.h"



namespace Skyrim
{
	class GFxMovieView;
	class GFxValue;

	class GFxFunctionHandler :
		public GRefCountBase<GFxFunctionHandler, Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 0
	{
	public:
		struct Parameters
		{
		public:
			// Member variables
			GFxValue*     returnValue;              // 0
			GFxMovieView* movieView;                // 8
			GFxValue*     thisPointer;              // 10
			GFxValue*     argumentsWithThisPointer; // 18
			GFxValue*     arguments;                // 20
			std::uint32_t argumentCount;            // 28
			std::uint32_t padding2C;                // 2C
			void*         userData;                 // 30
		};
		static_assert(offsetof(Parameters, returnValue) == 0x0);
		static_assert(offsetof(Parameters, movieView) == 0x8);
		static_assert(offsetof(Parameters, thisPointer) == 0x10);
		static_assert(offsetof(Parameters, argumentsWithThisPointer) == 0x18);
		static_assert(offsetof(Parameters, arguments) == 0x20);
		static_assert(offsetof(Parameters, argumentCount) == 0x28);
		static_assert(offsetof(Parameters, userData) == 0x30);
		static_assert(sizeof(Parameters) == 0x38);

		// Override
		virtual ~GFxFunctionHandler() override = default; // 0

		// Add
		virtual void Call(Parameters& parameters) = 0; // 1
	};
	static_assert(sizeof(GFxFunctionHandler) == 0x10);
}
