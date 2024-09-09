#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/F/FxDelegate.h"
#include "Shared/Skyrim/F/FxDelegateHandler.h"



namespace Skyrim
{
	class RemoveCallbackVisitor :
		public FxDelegateHandler::CallbackProcessor // 0
	{
	public:
		RemoveCallbackVisitor(FxDelegate::CallbackHash* callbackHash) :
			callbackHash_(callbackHash)
		{
		}

		// Override
		virtual ~RemoveCallbackVisitor() override = default; // 0

		// Override (FxDelegateHandler::CallbackProcessor)
		virtual void Process(const GString& methodName, FxDelegateHandler::CallbackFunction* method) // 1
		{
			this->callbackHash_->Remove(methodName);
		}

	private:
		FxDelegate::CallbackHash* callbackHash_; // 8
	};
	static_assert(sizeof(RemoveCallbackVisitor) == 0x10);
}
