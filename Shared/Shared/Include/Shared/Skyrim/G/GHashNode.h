#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/S/ScaleformTypes.h"



namespace Skyrim
{
	template <class T, class U, class HashFunction>
	struct GHashNode
	{
	public:
		using SelfType   = GHashNode<T, U, HashFunction>;
		using FirstType  = T;
		using SecondType = U;

		struct NodeReference
		{
		public:
			NodeReference(const FirstType& first, const SecondType& second) :
				first(std::addressof(first)),
				second(std::addressof(second))
			{
			}

			NodeReference(const NodeReference& source) :
				first(source.first),
				second(source.second)
			{
			}

			inline UPInt GetHash() const
			{
				return HashFunction()(*this->first);
			}

			operator const FirstType&() const
			{
				return *this->first;
			}

			// Member variables
			const FirstType*  first;  // 0
			const SecondType* second; // 8
		};
		static_assert(offsetof(NodeReference, first) == 0x0);
		static_assert(offsetof(NodeReference, second) == 0x8);
		static_assert(sizeof(NodeReference) == 0x10);

		GHashNode(const GHashNode& source) :
			first(source.first),
			second(source.second)
		{
		}

		GHashNode(const NodeReference& source) :
			first(*source.first),
			second(*source.second)
		{
		}

		void operator=(const NodeReference& source)
		{
			this->first  = *source.first;
			this->second = *source.second;
		}

		template <class V>
		bool operator==(const V& source) const
		{
			return this->first == source;
		}

		template <class V>
		static UPInt CalculateHash(const V& data)
		{
			return HashFunction()(data);
		}

		inline UPInt GetHash() const
		{
			return HashFunction()(this->first);
		}

		struct NodeHashFunction
		{
		public:
			template <class V>
			UPInt operator()(const V& data) const
			{
				return data.GetHash();
			}
		};
		static_assert(std::is_empty_v<NodeHashFunction>);

		struct NodeAlternativeHashFunction
		{
		public:
			template <class V>
			UPInt operator()(const V& data) const
			{
				return SelfType::CalculateHash(data);
			}
		};
		static_assert(std::is_empty_v<NodeAlternativeHashFunction>);

		// Member variables
		FirstType  first;  // 0
		SecondType second; // ?
	};
}
