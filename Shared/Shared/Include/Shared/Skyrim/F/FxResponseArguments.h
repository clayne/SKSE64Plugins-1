#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxResponseArgumentsBase.h"
#include "Shared/Skyrim/G/GFxValue.h"



namespace Skyrim
{
	template <std::int32_t COUNT>
	class FxResponseArguments :
		public FxResponseArgumentsBase // 0
	{
	public:
		FxResponseArguments() :
			index_(1)
		{
		}

		// Override
		virtual ~FxResponseArguments() override = default; // 0

		// Override (FxResponseArgumentsBase)
		virtual std::uint32_t GetValues(GFxValue** parameters) override // 1
		{
			*parameters = this->values_;

			return this->index_;
		}

		// Member functions
		void Add(const GFxValue& value)
		{
			if (this->index_ <= COUNT)
			{
				this->values_[this->index_++] = value;
			}
		}

	private:
		// Member variables
		GFxValue      values_[COUNT + 1]; // 0
		std::uint32_t index_;             // ?
	};
	static_assert(sizeof(FxResponseArguments<1>) == 0x40);
}
