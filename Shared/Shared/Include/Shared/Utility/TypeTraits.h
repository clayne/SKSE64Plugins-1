#pragma once

#include "Shared/PrecompiledHeader.h"



namespace Utility
{
	namespace TypeTraits
	{
		namespace Implementation
		{
			template <class T>
			struct AddVariadicArguments;

			template <class Result, class Class, class... Arguments>
			struct AddVariadicArguments<Result (Class::*)(Arguments...)>
			{
			public:
				using type = Result (Class::*)(Arguments..., ...);
			};

			template <class Result, class Class, class... Arguments>
			struct AddVariadicArguments<Result (Class::*)(Arguments...) const>
			{
			public:
				using type = Result (Class::*)(Arguments..., ...) const;
			};

			template <class Result, class... Arguments>
			struct AddVariadicArguments<Result (*)(Arguments...)>
			{
			public:
				using type = Result (*)(Arguments..., ...);
			};

			template <class T>
			struct MakeFunctionPointer;

			template <class Result, class Class, class... Arguments>
			struct MakeFunctionPointer<Result (Class::*)(Arguments...)>
			{
			public:
				using type = Result (*)(Class*, Arguments...);
			};

			template <class Result, class Class, class... Arguments>
			struct MakeFunctionPointer<Result (Class::*)(Arguments..., ...)>
			{
			public:
				using type = Result (*)(Class*, Arguments..., ...);
			};

			template <class Result, class Class, class... Arguments>
			struct MakeFunctionPointer<Result (Class::*)(Arguments...) const>
			{
			public:
				using type = Result (*)(const Class*, Arguments...);
			};

			template <class Result, class Class, class... Arguments>
			struct MakeFunctionPointer<Result (Class::*)(Arguments..., ...) const>
			{
			public:
				using type = Result (*)(const Class*, Arguments..., ...);
			};
		}

		template <class T>
		struct AddVariadicArguments;

		template <class T>
			requires(std::disjunction_v<
				std::is_member_function_pointer<T>,
				std::conjunction<
					std::is_pointer<T>,
					std::is_function<std::remove_pointer_t<T>>>>)
		struct AddVariadicArguments<T> :
			Implementation::AddVariadicArguments<T>
		{
		public:
		};

		template <class T>
		struct MakeFunctionPointer;

		template <class T>
			requires(std::is_member_function_pointer_v<T>)
		struct MakeFunctionPointer<T> :
			Implementation::MakeFunctionPointer<T>
		{
		public:
		};
	}
}
