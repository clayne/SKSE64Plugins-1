#pragma once

#include "PrecompiledHeader.h"



namespace ScrambledBugs::Patches
{
	class EnchantmentEffectPower
	{
	public:
		static void Load(bool& enchantmentEffectPower);

	private:
		static Skyrim::ForEachResult FunctionCallOperator(Skyrim::CraftingSubMenus::EnchantConstructMenu::CreateEffectFunctor* createEffectFunctor, Skyrim::EffectItem* effectItem);
	};
}
