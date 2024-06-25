#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Utility/Enumeration.h"



namespace Skyrim
{
	struct EffectItem;

	class Actor;
	class MagicItemTraversalFunctor;

	class MagicItem :
		public TESBoundObject, // 0
		public TESFullName,    // 30
		public BGSKeywordForm  // 40
	{
	public:
		enum class Flags : std::uint32_t
		{
			kNone           = 0,
			kCostOverridden = 1U << 0,
		};
		static_assert(sizeof(Flags) == 0x4);

		struct SkillUsageData
		{
		public:
			// Member variables
			EffectItem*                                     costliestEffectItem;  // 0
			Utility::Enumeration<ActorValue, std::uint32_t> magicSkill;           // 8
			float                                           magnitude;            // C
			bool                                            customSkillUseReward; // 10
			std::uint8_t                                    padding11;            // 11
			std::uint16_t                                   padding12;            // 12
			std::uint32_t                                   padding14;            // 14
		};
		static_assert(offsetof(SkillUsageData, costliestEffectItem) == 0x0);
		static_assert(offsetof(SkillUsageData, magicSkill) == 0x8);
		static_assert(offsetof(SkillUsageData, magnitude) == 0xC);
		static_assert(offsetof(SkillUsageData, customSkillUseReward) == 0x10);
		static_assert(sizeof(SkillUsageData) == 0x18);

		struct Data
		{
		public:
			// Member variables
			std::int32_t                               costOverride;   // 0
			Utility::Enumeration<Flags, std::uint32_t> magicItemFlags; // 4
		};
		static_assert(offsetof(Data, costOverride) == 0x0);
		static_assert(offsetof(Data, magicItemFlags) == 0x4);
		static_assert(sizeof(Data) == 0x8);

		// Override
		virtual ~MagicItem() override; // 0

		// Override (TESBoundObject)
		virtual void InitializeData() override;                  // 4
		virtual bool Load(TESFile* file) override;               // 6
		virtual void Unknown13(TESForm*) override;               // 13
		virtual void Unknown29(TESForm*) override;               // 29
		virtual void Unknown2F(TESForm*) override;               // 2F
		virtual bool IsAutomaticallyCalculated() const override; // 3E

		// Override (BGSKeywordForm)
		virtual bool HasKeyword(const BGSKeyword* keyword) const override; // 4

		// Add
		virtual MagicSystem::SpellType   GetSpellType() const = 0;                                // 53
		virtual void                     Unknown54(MagicItem*);                                   // 54
		virtual MagicSystem::CastingType GetCastingType() const = 0;                              // 55
		virtual void                     Unknown56(MagicItem*);                                   // 56
		virtual MagicSystem::Delivery    GetDelivery() const = 0;                                 // 57
		virtual void                     Unknown58(MagicItem*);                                   // 58
		virtual void                     Unknown59(MagicItem*);                                   // 59
		virtual void                     Unknown5A(MagicItem*);                                   // 5A
		virtual void                     Unknown5B(MagicItem*);                                   // 5B
		virtual void                     Unknown5C(MagicItem*);                                   // 5C
		virtual bool                     IsFood() const;                                          // 5D
		virtual void                     Unknown5E(MagicItem*);                                   // 5E
		virtual void                     Unknown5F(MagicItem*);                                   // 5F
		virtual bool                     GetSkillUsageData(SkillUsageData& skillUsageData) const; // 60
		virtual bool                     IsPoison() const;                                        // 61
		virtual void                     Unknown62(MagicItem*);                                   // 62
		virtual void                     Unknown63(MagicItem*);                                   // 63
		virtual void                     Unknown64(MagicItem*);                                   // 64
		virtual void                     Unknown65(MagicItem*);                                   // 65
		virtual void                     Unknown66(MagicItem*);                                   // 66
		virtual void                     Unknown67(MagicItem*);                                   // 67
		virtual void                     Unknown68(MagicItem*) = 0;                               // 68
		virtual void                     Unknown69(MagicItem*) = 0;                               // 69
		virtual void                     Unknown6A(MagicItem*);                                   // 6A
		virtual void                     Unknown6B(MagicItem*);                                   // 6B
		virtual const Data*              GetConstantData() const = 0;                             // 6C
		virtual Data*                    GetData()               = 0;                             // 6D
		virtual std::uint32_t            GetDataSize() const     = 0;                             // 6E
		virtual void                     Unknown6F(MagicItem*)   = 0;                             // 6F
		virtual void                     Unknown70(MagicItem*)   = 0;                             // 70

		// Member functions
		bool        Adjustable() const;
		float       GetCost(Actor* caster) const;
		ActorValue  GetCostActorValue(Utility::Enumeration<MagicSystem::CastingSource, std::uint32_t> castingSource) const;
		EffectItem* GetCostliestEffectItem(Utility::Enumeration<MagicSystem::Delivery, std::uint32_t> delivery, bool areaOfEffect) const;
		bool        IsPermanent() const;
		void        Traverse(MagicItemTraversalFunctor& magicItemTraversalFunctor) const;

		// Member variables
		BSTArray<EffectItem*> effectItems;  // 58
		std::int32_t          hostileCount; // 70
		std::uint32_t         padding74;    // 74
		std::uint64_t         unknown78;    // 78
		std::uint64_t         unknown80;    // 80
		std::uint64_t         unknown88;    // 88
	};
	static_assert(offsetof(MagicItem, effectItems) == 0x58);
	static_assert(offsetof(MagicItem, hostileCount) == 0x70);
	static_assert(sizeof(MagicItem) == 0x90);
}
