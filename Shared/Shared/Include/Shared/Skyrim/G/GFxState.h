#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Utility/Conversion.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	class GFxState :
		public GRefCountBase<GFxState, Utility::Conversion::ToUnderlying(GStatisticGroup::kGStatisticDefaultMemory)> // 0
	{
	public:
		enum class StateType : std::uint32_t
		{
			kNone,

			// Instance
			kRenderConfiguration,
			kRenderStatistics,
			kTranslator,
			kLog,
			kImageLoader,
			kActionControl,
			kUserEventHandler,
			kFSCommandHandler,
			kExternalInterface,

			// Loading
			kFileOpener,
			kURLBuilder,
			kImageCreator,
			kParseControl,
			kProgressHandler,
			kImportVisitor,
			kMeshCacheManager,
			kFontPackParameters,
			kFontCacheManager,
			kFontLibrary,
			kFontProvider,
			kFontMap,
			kGradientParameters,
			kTaskManager,
			kTextClipboard,
			kTextKeyMap,
			kPreprocessParameters,
			kIMEManager,
			kXMLSupport,
			kJPEGSupport,
			kZLIBSupport,
			kFontCompactorParameters,
			kImagePackerParameters,
			kPNGSupport,
			kAudio,
			kVideo,
			kTestStream,
			kSharedObject,
			kLOCSupport
		};
		static_assert(sizeof(StateType) == 0x4);

		GFxState(Utility::Enumeration<StateType, std::uint32_t> stateType = StateType::kNone) :
			stateType_(stateType)
		{
		}

		// Override
		virtual ~GFxState() override {} // 0

		// Member functions
		inline StateType GetStateType() const
		{
			return this->stateType_.get();
		}

	protected:
		// Member variables
		Utility::Enumeration<StateType, std::uint32_t> stateType_; // 10
	};
	static_assert(sizeof(GFxState) == 0x18);
}
