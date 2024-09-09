#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T>
	class GIdentityHash
	{
	public:
		UPInt operator()(const T& data) const
		{
			return (UPInt)data;
		}
	};
}
