#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/M/MemoryManager.h"



namespace Skyrim
{
	// Based on std::pair
	template <class T1, class T2>
	struct BSTTuple
	{
	public:
		using first_type  = T1;
		using second_type = T2;

		SKYRIM_MEMORY_REDEFINE_NEW();

		// Member functions
		// 1
		BSTTuple()
			noexcept(std::conjunction_v<
				std::is_nothrow_default_constructible<first_type>,
				std::is_nothrow_default_constructible<second_type>>)
			requires(std::conjunction_v<
						std::is_default_constructible<first_type>,
						std::is_default_constructible<second_type>>)
		= default;

		// 2
		explicit(std::disjunction_v<
			std::negation<std::is_convertible<const first_type&, first_type>>,
			std::negation<std::is_convertible<const second_type&, second_type>>>)
			BSTTuple(const first_type& first, const second_type& second)
				noexcept(std::conjunction_v<
					std::is_nothrow_copy_constructible<first_type>,
					std::is_nothrow_copy_constructible<second_type>>)
			requires(std::conjunction_v<
						std::is_copy_constructible<first_type>,
						std::is_copy_constructible<second_type>>)
			:
			first(first),
			second(second)
		{
		}

		// 3
		template <class U1, class U2>
		explicit(std::disjunction_v<
			std::negation<std::is_convertible<U1&&, first_type>>,
			std::negation<std::is_convertible<U2&&, second_type>>>)
			BSTTuple(U1&& first, U2&& second)
				noexcept(std::conjunction_v<
					std::is_nothrow_constructible<first_type, U1&&>,
					std::is_nothrow_constructible<second_type, U2&&>>)
			requires(std::conjunction_v<
						std::is_constructible<first_type, U1 &&>,
						std::is_constructible<second_type, U2 &&>>)
			:
			first(std::forward<U1>(first)),
			second(std::forward<U2>(second))
		{
		}

		// 4
		template <class U1, class U2>
		explicit(std::disjunction_v<
			std::negation<std::is_convertible<const U1&, first_type>>,
			std::negation<std::is_convertible<const U2&, second_type>>>)
			BSTTuple(const BSTTuple<U1, U2>& right)
				noexcept(std::conjunction_v<
					std::is_nothrow_constructible<first_type, const U1&>,
					std::is_nothrow_constructible<second_type, const U2&>>)
			requires(std::conjunction_v<
						std::is_constructible<first_type, const U1&>,
						std::is_constructible<second_type, const U2&>>)
			:
			first(right.first),
			second(right.second)
		{
		}

		// 5
		template <class U1, class U2>
		explicit(std::disjunction_v<
			std::negation<std::is_convertible<U1&&, first_type>>,
			std::negation<std::is_convertible<U2&&, second_type>>>)
			BSTTuple(BSTTuple<U1, U2>&& right)
				noexcept(std::conjunction_v<
					std::is_nothrow_constructible<first_type, U1&&>,
					std::is_nothrow_constructible<second_type, U2&&>>)
			requires(std::conjunction_v<
						std::is_constructible<first_type, U1 &&>,
						std::is_constructible<second_type, U2 &&>>)
			:
			first(std::forward<U1>(right.first)),
			second(std::forward<U2>(right.second))
		{
		}

		// 7
		BSTTuple(const BSTTuple&) = default;

		// 8
		BSTTuple(BSTTuple&&) = default;

		~BSTTuple() = default;

		// 1
		BSTTuple& operator=(const BSTTuple&)
			noexcept(std::conjunction_v<
				std::is_nothrow_copy_assignable<first_type>,
				std::is_nothrow_copy_assignable<second_type>>)
			requires(std::conjunction_v<
						std::is_copy_assignable<first_type>,
						std::is_copy_assignable<second_type>>)
		= default;

		// 2
		template <class U1, class U2>
		BSTTuple& operator=(const BSTTuple<U1, U2>& right)
			noexcept(std::conjunction_v<
				std::is_nothrow_assignable<first_type&, const U1&>,
				std::is_nothrow_assignable<second_type&, const U2&>>)
			requires(std::conjunction_v<
				std::is_assignable<first_type&, const U1&>,
				std::is_assignable<second_type&, const U2&>>)
		{
			this->first  = right.first;
			this->second = right.second;

			return *this;
		}

		// 3
		BSTTuple& operator=(BSTTuple&&)
			noexcept(std::conjunction_v<
				std::is_nothrow_move_assignable<first_type>,
				std::is_nothrow_move_assignable<second_type>>)
			requires(std::conjunction_v<
						std::is_move_assignable<first_type>,
						std::is_move_assignable<second_type>>)
		= default;

		// 4
		template <class U1, class U2>
		BSTTuple& operator=(BSTTuple<U1, U2>&& right)
			noexcept(std::conjunction_v<
				std::is_nothrow_assignable<first_type&, U1>,
				std::is_nothrow_assignable<second_type&, U2>>)
			requires(std::conjunction_v<
				std::is_assignable<first_type&, U1>,
				std::is_assignable<second_type&, U2>>)
		{
			this->first  = std::move(right.first);
			this->second = std::move(right.second);

			return *this;
		}

		// Member variables
		first_type  first{};  // 0
		second_type second{}; // ?
	};

	// Non-member functions
	template <class T1, class T2>
	bool operator==(const BSTTuple<T1, T2>& left, const BSTTuple<T1, T2>& right)
	{
		return left.first == right.first && left.second == right.second;
	}
}
