#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	// Special Edition
	// Anniversary Edition
	class AttachHitEffectArt
	{
	public:
		static void Load(bool& attachHitEffectArt);

	private:
		class ModelReferenceEffect
		{
		public:
			static bool GetStackable(Skyrim::ModelReferenceEffect* modelReferenceEffect);
			static bool GetStackableMatch(Skyrim::ModelReferenceEffect* modelReferenceEffect, Skyrim::BSTempEffect* temporaryEffect);
			static void Pop(Skyrim::ModelReferenceEffect* modelReferenceEffect);

			static decltype(ModelReferenceEffect::Pop)* pop_;
		};
	};
}
