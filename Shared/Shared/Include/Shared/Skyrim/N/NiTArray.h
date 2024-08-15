#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Skyrim
{
	template <class T>
	class NiTNewInterface;

	template <class T>
	class NiTMallocInterface;

	template <class T, class Allocator>
	class NiTArray
	{
	public:
		using size_type       = std::uint16_t;
		using value_type      = T;
		using pointer         = value_type*;
		using const_pointer   = const value_type*;
		using reference       = value_type&;
		using const_reference = const value_type&;

		template <class U>
		class iterator
		{
		public:
			using value_type        = std::remove_const_t<U>;
			using pointer           = value_type*;
			using reference         = value_type&;
			using iterator_category = std::forward_iterator_tag;

			constexpr iterator() noexcept                = default;
			constexpr iterator(const iterator&) noexcept = default;
			constexpr iterator(iterator&&) noexcept      = default;

			constexpr ~iterator() noexcept = default;

			constexpr iterator& operator=(const iterator&) noexcept = default;
			constexpr iterator& operator=(iterator&&) noexcept      = default;

			constexpr iterator(pointer head, pointer tail) noexcept :
				begin_(head), end_(tail)
			{
				if (this->iterable() && !*this->begin_)
				{
					this->seek();
				}
			}

			constexpr reference operator*() const noexcept
			{
				return *this->begin_;
			}

			constexpr pointer operator->() const noexcept
			{
				return std::addressof(this->operator*());
			}

			friend constexpr bool operator==(const iterator& left, const iterator& right) noexcept
			{
				return left.begin_ == right.begin_;
			}

			friend constexpr bool operator!=(const iterator& left, const iterator& right) noexcept
			{
				return !(left == right);
			}

			constexpr iterator& operator++() noexcept
			{
				this->seek();

				return *this;
			}

			constexpr iterator operator++(int) noexcept
			{
				iterator iterator(*this);

				this->operator++();

				return iterator;
			}

		private:
			constexpr bool iterable() const noexcept
			{
				return this->begin_ && this->end_ && this->begin_ != this->end_;
			}

			constexpr void seek() noexcept
			{
				do
				{
					++this->begin_;
				} while (this->begin_ != this->end_ && !*this->begin_);
			}

			pointer begin_{ nullptr };
			pointer end_{ nullptr };
		};

		// Add
		virtual ~NiTArray(); // 0

		// Iterators
		constexpr iterator<value_type> begin() noexcept
		{
			return iterator<value_type>(this->data(), this->data() + this->capacity());
		}

		constexpr iterator<const value_type> begin() const noexcept
		{
			return iterator<const value_type>(this->data(), this->data() + this->capacity());
		}

		constexpr iterator<const value_type> cbegin() const noexcept { return this->begin(); }

		constexpr iterator<value_type> end() noexcept
		{
			return iterator<value_type>(this->data() + this->capacity(), this->data() + this->capacity());
		}

		constexpr iterator<const value_type> end() const noexcept
		{
			return iterator<const value_type>(this->data() + this->capacity(), this->data() + this->capacity());
		}

		constexpr iterator<const value_type> cend() const noexcept { return this->end(); }

		// Element access
		constexpr pointer       data() noexcept { return this->data_; }
		constexpr const_pointer data() const noexcept { return this->data_; }

		// Capacity
		constexpr bool empty() const noexcept { return this->size() == 0; }

		constexpr size_type size() const noexcept { return this->size_; }

		constexpr size_type capacity() const noexcept { return this->capacity_; }

	private:
		// Member variables
		pointer   data_;       // 8
		size_type capacity_;   // 10
		size_type free_;       // 12
		size_type size_;       // 14
		size_type growthSize_; // 16
	};
	static_assert(sizeof(NiTArray<void*, void>) == 0x18);

	template <class T>
	class NiTObjectArray :
		public NiTArray<T, NiTNewInterface<T>> // 0
	{
	public:
	};
	static_assert(sizeof(NiTObjectArray<void*>) == 0x18);

	template <class T>
	class NiTPrimitiveArray :
		public NiTArray<T, NiTMallocInterface<T>> // 0
	{
	public:
	};
	static_assert(sizeof(NiTPrimitiveArray<void*>) == 0x18);
}
