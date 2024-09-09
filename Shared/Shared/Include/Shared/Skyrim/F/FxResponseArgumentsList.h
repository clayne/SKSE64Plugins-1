#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxResponseArgumentsBase.h"
#include "Shared/Skyrim/G/GArray.h"
#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class FxResponseArgumentsList :
		public FxResponseArgumentsBase // 0
	{
	public:
		FxResponseArgumentsList()
		{
			this->arguments_.PushBack(Utility::Enumeration<GFxValue::ValueType, std::uint32_t>(GFxValue::ValueType::kNull));
		}

		// Override
		virtual ~FxResponseArgumentsList() override = default; // 0

		// Override (FxResponseArgumentsBase)
		virtual std::uint32_t GetValues(GFxValue** parameters) override // 1
		{
			*parameters = std::addressof(this->arguments_[0]);

			return static_cast<std::uint32_t>(this->arguments_.GetSize());
		}

		void Add(const GFxValue& value)
		{
			this->arguments_.PushBack(value);
		}

	private:
		// Member variables
		GArray<GFxValue> arguments_; // 8
	};
	static_assert(sizeof(FxResponseArgumentsList) == 0x20);
}
