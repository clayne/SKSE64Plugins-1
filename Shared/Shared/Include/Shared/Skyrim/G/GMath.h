#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	constexpr double GFC_MATH_EPSILON          = 1.0e-12;                // epsilon
	constexpr double GFC_MATH_E                = 2.7182818284590452354;  // e
	constexpr double GFC_MATH_LOG2E            = 1.4426950408889634074;  // log_2 e
	constexpr double GFC_MATH_LOG10E           = 0.43429448190325182765; // log_10 e
	constexpr double GFC_MATH_LN2              = 0.69314718055994530942; // log_e 2
	constexpr double GFC_MATH_LN10             = 2.30258509299404568402; // log_e 10
	constexpr double GFC_MATH_PI               = 3.14159265358979323846; // pi
	constexpr double GFC_MATH_PI_2             = 1.57079632679489661923; // pi/2
	constexpr double GFC_MATH_PI_3             = 1.04719755119659774615; // pi/3
	constexpr double GFC_MATH_PI_4             = 0.78539816339744830962; // pi/4
	constexpr double GFC_MATH_1_PI             = 0.31830988618379067154; // 1/pi
	constexpr double GFC_MATH_2_PI             = 0.63661977236758134308; // 2/pi
	constexpr double GFC_MATH_2_SQRTPI         = 1.12837916709551257390; // 2/sqrt(pi)
	constexpr double GFC_MATH_SQRT2            = 1.41421356237309504880; // sqrt(2)
	constexpr double GFC_MATH_1_SQRT2          = 0.70710678118654752440; // 1/sqrt(2)
	constexpr double GFC_MATH_DEGREESTORADIANS = 0.01745329251994329577; // pi/180

#define GFC_DEGREESTORADIANS(degrees) ((degrees) * Skyrim::GFC_MATH_PI / 180.0)
#define GFC_RADIANSTODEGREES(radians) ((radians) * 180.0 / Skyrim::GFC_MATH_PI)

	constexpr std::int32_t gfchop(float value)
	{
		return static_cast<std::int32_t>(value);
	}

	constexpr std::int32_t gfround(float value)
	{
		return Skyrim::gfchop(value + 0.5F);
	}

	constexpr float gflerp(float pointA, float pointB, float fraction)
	{
		return (pointB - pointA) * fraction + pointA;
	}

	inline float glog2f(float value)
	{
		return std::logf(value) / static_cast<float>(Skyrim::GFC_MATH_LN2);
	}

	template <class T>
	T HorizontalFOVToVerticalFOV(T horizontalFOV, T aspectRatio)
	{
		return T(2.0 * std::atanf(std::tanf(horizontalFOV * T(0.5)) / static_cast<double>(aspectRatio)));
	}

	template <class T>
	T VerticalFOVToHorizontalFOV(T verticalFOV, T aspectRatio)
	{
		return T(2.0 * std::atanf(std::tanf(verticalFOV * T(0.5)) * static_cast<double>(aspectRatio)));
	}

#define GFC_ISFINITE(value)        (sizeof(value) == sizeof(float) ? GFC_ISFINITE_FLOAT(value) : GFC_ISFINITE_DOUBLE(value))
#define GFC_ISFINITE_FLOAT(value)  ((value) >= -std::numeric_limits<float>::max() && (value) <= std::numeric_limits<float>::max())
#define GFC_ISFINITE_DOUBLE(value) ((value) >= -std::numeric_limits<double>::max() && (value) <= std::numeric_limits<double>::max())
}
