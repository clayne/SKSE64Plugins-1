#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/I/IFormFactory.h"



namespace Skyrim
{
	template <class T, FormType FORM_TYPE>
	class ConcreteFormFactory :
		public IFormFactory // 0
	{
	public:
		// Override
		virtual ~ConcreteFormFactory() override; // 0

	protected:
		// Override (IFormFactory)
		virtual TESForm* CreateImplementation() override; // 1

	public:
		// Override (IFormFactory)
		virtual const char* GetFormName() const override; // 2
		virtual FormType    GetFormType() const override; // 3

		// Non-member functions
		static ConcreteFormFactory* GetFormFactory()
		{
			return static_cast<ConcreteFormFactory*>(IFormFactory::GetFormFactory(FORM_TYPE));
		}

		// Member functions
		T* Create()
		{
			return static_cast<T*>(this->CreateImplementation());
		}

	protected:
		// Member variables
		const char* name_; // 8
	};
	static_assert(sizeof(ConcreteFormFactory<TESForm, FormType::kNone>) == 0x10);
}
