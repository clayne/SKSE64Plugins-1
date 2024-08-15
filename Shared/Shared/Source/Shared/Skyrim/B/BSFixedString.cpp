#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/B/BSFixedString.h"

#include "Shared/Skyrim/Addresses.h"
#include "Shared/Utility/TypeTraits.h"



namespace Skyrim
{
	BSFixedString::BSFixedString(const BSFixedString& right) :
		data_(right.data_)
	{
		this->Acquire();
	}

	BSFixedString::BSFixedString(const_pointer right)
	{
		if (right)
		{
			this->Initialize(right);
		}
	}

	BSFixedString::BSFixedString(const std::basic_string<value_type>& right)
	{
		if (!right.empty())
		{
			this->Initialize(right.c_str());
		}
	}

	BSFixedString::BSFixedString(std::basic_string_view<value_type> right)
	{
		if (!right.empty())
		{
			this->Initialize(right.data());
		}
	}

	BSFixedString::~BSFixedString()
	{
		this->Release();
	}

	BSFixedString& BSFixedString::operator=(const BSFixedString& right)
	{
		if (this != std::addressof(right))
		{
			this->Release();
			this->data_ = right.data_;
			this->Acquire();
		}

		return *this;
	}

	BSFixedString& BSFixedString::operator=(BSFixedString&& right)
	{
		if (this != std::addressof(right))
		{
			this->Release();
			this->data_ = right.data_;
			right.data_ = nullptr;
		}

		return *this;
	}

	BSFixedString& BSFixedString::operator=(const_pointer right)
	{
		this->Release();

		if (right)
		{
			this->Initialize(right);
		}

		return *this;
	}

	BSFixedString& BSFixedString::operator=(const std::basic_string<value_type>& right)
	{
		this->Release();

		if (!right.empty())
		{
			this->Initialize(right.c_str());
		}

		return *this;
	}

	BSFixedString& BSFixedString::operator=(std::basic_string_view<value_type> right)
	{
		this->Release();

		if (!right.empty())
		{
			this->Initialize(right.data());
		}

		return *this;
	}

	void BSFixedString::Acquire()
	{
		auto* proxy = this->GetProxy();

		if (proxy)
		{
			proxy->Acquire();
		}
	}

	BSFixedString* BSFixedString::Initialize(const_pointer string)
	{
		auto* function{ reinterpret_cast<
			Utility::TypeTraits::MakeFunctionPointer<decltype(&BSFixedString::Initialize)>::type>(
			Addresses::BSFixedString::Initialize()) };

		return function(this, string);
	}

	void BSFixedString::Release()
	{
		BSStringPool::Entry::Release(this->data_);
	}
}
