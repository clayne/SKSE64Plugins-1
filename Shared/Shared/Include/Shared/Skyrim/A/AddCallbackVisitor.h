#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxDelegate.h"
#include "Shared/Skyrim/F/FxDelegateHandler.h"



namespace Skyrim
{
	class AddCallbackVisitor :
		public FxDelegateHandler::CallbackProcessor // 0
	{
	public:
		AddCallbackVisitor(FxDelegateHandler* delegateHandler, FxDelegate::CallbackHash* callbackHash) :
			delegateHandler_(delegateHandler),
			callbackHash_(callbackHash)
		{
		}

		// Override
		virtual ~AddCallbackVisitor() override = default; // 0

		// Override (FxDelegateHandler::CallbackProcessor)
		virtual void Process(const GString& methodName, FxDelegateHandler::CallbackFunction* method) // 1
		{
			FxDelegate::CallbackDefinition callbackDefinition;

			callbackDefinition.delegateHandler.reset(this->delegateHandler_);
			callbackDefinition.callbackFunction = method;

			this->callbackHash_->Add(methodName, callbackDefinition);
		}

	private:
		// Member variables
		FxDelegateHandler*        delegateHandler_; // 0
		FxDelegate::CallbackHash* callbackHash_;    // 8
	};
	static_assert(sizeof(AddCallbackVisitor) == 0x18);
}
