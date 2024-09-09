#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility
{
	// Based on std::bitset
	template <class T, class Underlying = std::underlying_type_t<T>>
		requires(std::conjunction_v<
			std::is_enum<T>,
			std::is_integral<Underlying>>)
	class Enumeration
	{
	public:
		using enumeration_type = T;
		using underlying_type  = Underlying;

		constexpr Enumeration() noexcept                   = default;
		constexpr Enumeration(const Enumeration&) noexcept = default;
		constexpr Enumeration(Enumeration&&) noexcept      = default;

		constexpr ~Enumeration() noexcept = default;

		constexpr Enumeration& operator=(const Enumeration&) noexcept = default;
		constexpr Enumeration& operator=(Enumeration&&) noexcept      = default;

		template <class... Arguments>
			requires(std::conjunction_v<std::is_same<Arguments, enumeration_type>...>)
		constexpr Enumeration(Arguments... arguments) noexcept :
			underlying_((static_cast<underlying_type>(arguments) | ...))
		{
		}

		// Arithmetic operators
		friend constexpr Enumeration operator~(Enumeration left) noexcept { return static_cast<enumeration_type>(~left.underlying()); }

		friend constexpr Enumeration operator&(Enumeration left, Enumeration right) noexcept { return static_cast<enumeration_type>(left.underlying() & right.underlying()); }
		friend constexpr Enumeration operator&(Enumeration left, enumeration_type right) noexcept { return static_cast<enumeration_type>(left.underlying() & static_cast<underlying_type>(right)); }
		friend constexpr Enumeration operator&(enumeration_type left, Enumeration right) noexcept { return static_cast<enumeration_type>(static_cast<underlying_type>(left) & right.underlying()); }
		friend constexpr Enumeration operator&(Enumeration left, underlying_type right) noexcept { return static_cast<enumeration_type>(left.underlying() & right); }
		friend constexpr Enumeration operator&(underlying_type left, Enumeration right) noexcept { return static_cast<enumeration_type>(left & right.underlying()); }

		friend constexpr Enumeration operator|(Enumeration left, Enumeration right) noexcept { return static_cast<enumeration_type>(left.underlying() | right.underlying()); }
		friend constexpr Enumeration operator|(Enumeration left, enumeration_type right) noexcept { return static_cast<enumeration_type>(left.underlying() | static_cast<underlying_type>(right)); }
		friend constexpr Enumeration operator|(enumeration_type left, Enumeration right) noexcept { return static_cast<enumeration_type>(static_cast<underlying_type>(left) | right.underlying()); }
		friend constexpr Enumeration operator|(Enumeration left, underlying_type right) noexcept { return static_cast<enumeration_type>(left.underlying() | right); }
		friend constexpr Enumeration operator|(underlying_type left, Enumeration right) noexcept { return static_cast<enumeration_type>(left | right.underlying()); }

		friend constexpr Enumeration operator^(Enumeration left, Enumeration right) noexcept { return static_cast<enumeration_type>(left.underlying() ^ right.underlying()); }
		friend constexpr Enumeration operator^(Enumeration left, enumeration_type right) noexcept { return static_cast<enumeration_type>(left.underlying() ^ static_cast<underlying_type>(right)); }
		friend constexpr Enumeration operator^(enumeration_type left, Enumeration right) noexcept { return static_cast<enumeration_type>(static_cast<underlying_type>(left) ^ right.underlying()); }
		friend constexpr Enumeration operator^(Enumeration left, underlying_type right) noexcept { return static_cast<enumeration_type>(left.underlying() ^ right); }
		friend constexpr Enumeration operator^(underlying_type left, Enumeration right) noexcept { return static_cast<enumeration_type>(left ^ right.underlying()); }

		friend constexpr Enumeration operator<<(Enumeration left, std::size_t right) noexcept { return static_cast<enumeration_type>(left.underlying() << right); }
		friend constexpr Enumeration operator>>(Enumeration left, std::size_t right) noexcept { return static_cast<enumeration_type>(left.underlying() >> right); }

		// Assignment operators
		constexpr Enumeration& operator=(enumeration_type right) noexcept
		{
			this->underlying_ = static_cast<underlying_type>(right);

			return *this;
		}

		constexpr Enumeration& operator=(underlying_type right) noexcept
		{
			this->underlying_ = right;

			return *this;
		}

		constexpr Enumeration& operator&=(Enumeration right) noexcept
		{
			this->underlying_ &= right.underlying();

			return *this;
		}

		constexpr Enumeration& operator&=(enumeration_type right) noexcept
		{
			this->underlying_ &= static_cast<underlying_type>(right);

			return *this;
		}

		constexpr Enumeration& operator&=(underlying_type right) noexcept
		{
			this->underlying_ &= right;

			return *this;
		}

		constexpr Enumeration& operator|=(Enumeration right) noexcept
		{
			this->underlying_ |= right.underlying();

			return *this;
		}

		constexpr Enumeration& operator|=(enumeration_type right) noexcept
		{
			this->underlying_ |= static_cast<underlying_type>(right);

			return *this;
		}

		constexpr Enumeration& operator|=(underlying_type right) noexcept
		{
			this->underlying_ |= right;

			return *this;
		}

		constexpr Enumeration& operator^=(Enumeration right) noexcept
		{
			this->underlying_ ^= right.underlying();

			return *this;
		}

		constexpr Enumeration& operator^=(enumeration_type right) noexcept
		{
			this->underlying_ ^= static_cast<underlying_type>(right);

			return *this;
		}

		constexpr Enumeration& operator^=(underlying_type right) noexcept
		{
			this->underlying_ ^= right;

			return *this;
		}

		constexpr Enumeration& operator<<=(std::size_t right) noexcept
		{
			this->underlying_ <<= right;

			return *this;
		}

		constexpr Enumeration& operator>>=(std::size_t right) noexcept
		{
			this->underlying_ >>= right;

			return *this;
		}

		// Comparison operators
		friend constexpr bool operator==(Enumeration left, Enumeration right) noexcept { return left.underlying() == right.underlying(); }
		friend constexpr bool operator==(Enumeration left, enumeration_type right) noexcept { return left.underlying() == static_cast<underlying_type>(right); }
		friend constexpr bool operator==(enumeration_type left, Enumeration right) noexcept { return static_cast<underlying_type>(left) == right.underlying(); }
		friend constexpr bool operator==(Enumeration left, underlying_type right) noexcept { return left.underlying() == right; }
		friend constexpr bool operator==(underlying_type left, Enumeration right) noexcept { return left == right.underlying(); }

		friend constexpr bool operator!=(Enumeration left, Enumeration right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(Enumeration left, enumeration_type right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(enumeration_type left, Enumeration right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(Enumeration left, underlying_type right) noexcept { return !(left == right); }
		friend constexpr bool operator!=(underlying_type left, Enumeration right) noexcept { return !(left == right); }

		// Element access
		template <class... Arguments>
			requires(std::conjunction_v<std::is_same<Arguments, enumeration_type>...>)
		constexpr bool all(Arguments... arguments) const noexcept
		{
			return (this->underlying_ & (static_cast<underlying_type>(arguments) | ...)) == (static_cast<underlying_type>(arguments) | ...);
		}

		template <class... Arguments>
			requires(std::conjunction_v<std::is_same<Arguments, enumeration_type>...>)
		constexpr bool any(Arguments... arguments) const noexcept
		{
			return (this->underlying_ & (static_cast<underlying_type>(arguments) | ...)) != static_cast<underlying_type>(0);
		}

		template <class... Arguments>
			requires(std::conjunction_v<std::is_same<Arguments, enumeration_type>...>)
		constexpr bool none(Arguments... arguments) const noexcept
		{
			return (this->underlying_ & (static_cast<underlying_type>(arguments) | ...)) == static_cast<underlying_type>(0);
		}

		// Modifiers
		template <class... Arguments>
			requires(std::conjunction_v<std::is_same<Arguments, enumeration_type>...>)
		constexpr Enumeration& reset(Arguments... arguments) noexcept
		{
			this->underlying_ &= ~(static_cast<underlying_type>(arguments) | ...);

			return *this;
		}

		template <class... Arguments>
			requires(std::conjunction_v<std::is_same<Arguments, enumeration_type>...>)
		constexpr Enumeration& set(Arguments... arguments) noexcept
		{
			this->underlying_ |= (static_cast<underlying_type>(arguments) | ...);

			return *this;
		}

		// Observers
		explicit constexpr operator bool() const noexcept { return this->underlying_ != static_cast<underlying_type>(0); }

		constexpr enumeration_type get() const noexcept { return static_cast<enumeration_type>(this->underlying_); }
		constexpr underlying_type  underlying() const noexcept { return this->underlying_; }

	private:
		underlying_type underlying_{};
	};
}
