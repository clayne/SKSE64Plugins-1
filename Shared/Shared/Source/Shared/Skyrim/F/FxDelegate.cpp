#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxDelegate.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void FxDelegate::Invoke(GFxMovieView* movieView, const char* methodName, FxResponseArgumentsBase& arguments)
	{
		auto* function{ reinterpret_cast<decltype(FxDelegate::Invoke)*>(
			Addresses::FxDelegate::Invoke()) };

		function(movieView, methodName, arguments);
	}

	void FxDelegate::RegisterDelegateHandler(FxDelegateHandler* callback)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&FxDelegate::RegisterDelegateHandler)>::type>(
			Addresses::FxDelegate::RegisterDelegateHandler()) };

		function(this, callback);
	}

	void FxDelegate::UnregisterDelegateHandler(FxDelegateHandler* callback)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&FxDelegate::UnregisterDelegateHandler)>::type>(
			Addresses::FxDelegate::UnregisterDelegateHandler()) };

		function(this, callback);
	}
}
