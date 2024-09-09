#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxDelegateArguments.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	void FxDelegateArguments::Respond(FxResponseArgumentsBase& parameters) const
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&FxDelegateArguments::Respond)>::type>(
			Addresses::FxDelegateArguments::Respond()) };

		function(this, parameters);
	}
}
