#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxDelegateHandler.h"
#include "Shared/Skyrim/G/GFxExternalInterface.h"
#include "Shared/Skyrim/G/GHash.h"
#include "Shared/Skyrim/G/GPointer.h"
#include "Shared/Skyrim/G/GString.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	class FxResponseArgumentsBase;
	class GFxMovieView;

	class FxDelegate :
		GFxExternalInterface // 0
	{
	public:
		struct CallbackDefinition
		{
		public:
			// Member variables
			GPointer<FxDelegateHandler>          delegateHandler;  // 0
			FxDelegateHandler::CallbackFunction* callbackFunction; // 8
		};
		static_assert(offsetof(CallbackDefinition, delegateHandler) == 0x0);
		static_assert(offsetof(CallbackDefinition, callbackFunction) == 0x8);
		static_assert(sizeof(CallbackDefinition) == 0x10);

		struct CallbackHashFunctor
		{
		public:
			UPInt operator()(const GString& data) const
			{
				return GString::BernsteinHashFunction(data.data(), data.size());
			}
		};

		using CallbackHash = GHash<GString, CallbackDefinition, CallbackHashFunctor>;

		FxDelegate() = default;

		// Override
		virtual ~FxDelegate() override = default; // 0

		// Override (GFxExternalInterface)
		virtual void Callback(GFxMovieView* movieView, const char* methodName, const GFxValue* arguments, std::uint32_t argumentCount) override; // 1

		// Non-member functions
		static void Invoke(GFxMovieView* movieView, const char* methodName, FxResponseArgumentsBase& arguments);

		// Member functions
		void RegisterDelegateHandler(FxDelegateHandler* callback);
		void UnregisterDelegateHandler(FxDelegateHandler* callback);

		// Member variables
		CallbackHash callbackHashes; // 18
	};
	static_assert(offsetof(FxDelegate, callbackHashes) == 0x18);
	static_assert(sizeof(FxDelegate) == 0x20);
}
