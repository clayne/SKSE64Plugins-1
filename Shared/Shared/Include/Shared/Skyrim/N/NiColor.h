#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	class NiColor
	{
	public:
		constexpr NiColor() noexcept               = default;
		constexpr NiColor(const NiColor&) noexcept = default;
		constexpr NiColor(NiColor&&) noexcept      = default;

		constexpr ~NiColor() noexcept = default;

		constexpr NiColor& operator=(const NiColor&) noexcept = default;
		constexpr NiColor& operator=(NiColor&&) noexcept      = default;

		constexpr NiColor(float red, float green, float blue) noexcept :
			red(red), green(green), blue(blue)
		{
		}

		friend constexpr bool operator==(const NiColor& left, const NiColor& right) noexcept { return (left.red == right.red) && (left.green == right.green) && (left.blue == right.blue); }
		friend constexpr bool operator!=(const NiColor& left, const NiColor& right) noexcept { return !(left == right); }

		// Member variables
		float red{ 0.0F };   // 0
		float green{ 0.0F }; // 4
		float blue{ 0.0F };  // 8
	};
	static_assert(offsetof(NiColor, red) == 0x0);
	static_assert(offsetof(NiColor, green) == 0x4);
	static_assert(offsetof(NiColor, blue) == 0x8);
	static_assert(sizeof(NiColor) == 0xC);

	class NiColorA
	{
	public:
		constexpr NiColorA() noexcept                = default;
		constexpr NiColorA(const NiColorA&) noexcept = default;
		constexpr NiColorA(NiColorA&&) noexcept      = default;

		constexpr ~NiColorA() noexcept = default;

		constexpr NiColorA& operator=(const NiColorA&) noexcept = default;
		constexpr NiColorA& operator=(NiColorA&&) noexcept      = default;

		constexpr NiColorA(float red, float green, float blue, float alpha) noexcept :
			red(red), green(green), blue(blue), alpha(alpha)
		{
		}

		friend constexpr bool operator==(const NiColorA& left, const NiColorA& right) noexcept { return (left.red == right.red) && (left.green == right.green) && (left.blue == right.blue) && (left.alpha == right.alpha); }
		friend constexpr bool operator!=(const NiColorA& left, const NiColorA& right) noexcept { return !(left == right); }

		// Member variables
		float red{ 0.0F };   // 0
		float green{ 0.0F }; // 4
		float blue{ 0.0F };  // 8
		float alpha{ 0.0F }; // C
	};
	static_assert(offsetof(NiColorA, red) == 0x0);
	static_assert(offsetof(NiColorA, green) == 0x4);
	static_assert(offsetof(NiColorA, blue) == 0x8);
	static_assert(offsetof(NiColorA, alpha) == 0xC);
	static_assert(sizeof(NiColorA) == 0x10);
}
