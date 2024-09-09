#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T>
	class GFixedSizeHash
	{
	public:
		/* CommonLibSSE uses the pre-increment operator instead of the post-increment operator */
		static inline UPInt SDBMHash(const void* dataInput, UPInt size, UPInt seed = 5381)
		{
			UPInt hash = seed;

			while (size > 0)
			{
				hash = (hash << 16) + (hash << 6) - hash + static_cast<UPInt>(static_cast<const std::uint8_t*>(dataInput)[--size]);
			}

			return hash;
		}

		UPInt operator()(const T& data) const
		{
			return GFixedSizeHash::SDBMHash(std::addressof(data), sizeof(T));
		}
	};
}
