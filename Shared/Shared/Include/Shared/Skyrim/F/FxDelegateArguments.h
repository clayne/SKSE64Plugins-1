#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class FxDelegateHandler;
	class FxResponseArgumentsBase;
	class GFxMovieView;

	class FxDelegateArguments
	{
	public:
		FxDelegateArguments(
			GFxValue           responseID,
			FxDelegateHandler* delegateHandler,
			GFxMovieView*      movieView,
			const GFxValue*    arguments,
			std::uint32_t      argumentCount) :
			responseID_(responseID),
			delegateHandler_(delegateHandler),
			movieView_(movieView),
			arguments_(arguments),
			argumentCount_(argumentCount)
		{
		}

		// Member functions
		const GFxValue& operator[](UPInt index) const
		{
			return this->arguments_[index];
		}

		std::uint32_t GetArgumentCount() const
		{
			return this->argumentCount_;
		}

		FxDelegateHandler* GetDelegateHandler() const
		{
			return this->delegateHandler_;
		}

		GFxMovieView* GetMovieView() const
		{
			return this->movieView_;
		}

		void Respond(FxResponseArgumentsBase& parameters) const;

	private:
		// Member variables
		GFxValue           responseID_;      // 0
		FxDelegateHandler* delegateHandler_; // 18
		GFxMovieView*      movieView_;       // 20
		const GFxValue*    arguments_;       // 28
		std::uint32_t      argumentCount_;   // 30
	};
	static_assert(sizeof(FxDelegateArguments) == 0x38);
}
