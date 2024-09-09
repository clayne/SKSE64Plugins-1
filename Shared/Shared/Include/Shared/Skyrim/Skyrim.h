#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/A/AccumulatingValueModifierEffect.h"
#include "Shared/Skyrim/A/ActivateHandler.h"
#include "Shared/Skyrim/A/ActiveEffect.h"
#include "Shared/Skyrim/A/ActiveEffectFactory.h"
#include "Shared/Skyrim/A/Actor.h"
#include "Shared/Skyrim/A/ActorEquipManager.h"
#include "Shared/Skyrim/A/ActorRelativeToPlayer.h"
#include "Shared/Skyrim/A/ActorState.h"
#include "Shared/Skyrim/A/ActorValue.h"
#include "Shared/Skyrim/A/ActorValueInfo.h"
#include "Shared/Skyrim/A/ActorValueOwner.h"
#include "Shared/Skyrim/A/AddCallbackVisitor.h"
#include "Shared/Skyrim/A/AIFormulas.h"
#include "Shared/Skyrim/A/AIProcess.h"
#include "Shared/Skyrim/A/AITimer.h"
#include "Shared/Skyrim/A/AITimestamp.h"
#include "Shared/Skyrim/A/AlchemyItem.h"
#include "Shared/Skyrim/A/ArrowProjectile.h"
#include "Shared/Skyrim/A/AssociationType.h"
#include "Shared/Skyrim/A/Atmosphere.h"
#include "Shared/Skyrim/A/AttachTechniqueInput.h"
#include "Shared/Skyrim/A/AttackAnimationArrayMap.h"
#include "Shared/Skyrim/A/Attribute.h"
#include "Shared/Skyrim/Addresses.h"
#include "Shared/Skyrim/B/BaseExtraList.h"
#include "Shared/Skyrim/B/BaseFormComponent.h"
#include "Shared/Skyrim/B/BGSAbilityPerkEntry.h"
#include "Shared/Skyrim/B/BGSAddonNode.h"
#include "Shared/Skyrim/B/BGSArtObject.h"
#include "Shared/Skyrim/B/BGSAssociationType.h"
#include "Shared/Skyrim/B/BGSAttackData.h"
#include "Shared/Skyrim/B/BGSAttackDataForm.h"
#include "Shared/Skyrim/B/BGSAttackDataMap.h"
#include "Shared/Skyrim/B/BGSBehaviorGraphModel.h"
#include "Shared/Skyrim/B/BGSBipedObjectForm.h"
#include "Shared/Skyrim/B/BGSBlockBashData.h"
#include "Shared/Skyrim/B/BGSBodyPartData.h"
#include "Shared/Skyrim/B/BGSBodyPartDefinitions.h"
#include "Shared/Skyrim/B/BGSCollisionLayer.h"
#include "Shared/Skyrim/B/BGSColorForm.h"
#include "Shared/Skyrim/B/BGSConstructibleObject.h"
#include "Shared/Skyrim/B/BGSCreatedObjectManager.h"
#include "Shared/Skyrim/B/BGSDecalGroup.h"
#include "Shared/Skyrim/B/BGSDecalManager.h"
#include "Shared/Skyrim/B/BGSDefaultObjectManager.h"
#include "Shared/Skyrim/B/BGSDestructibleObjectForm.h"
#include "Shared/Skyrim/B/BGSEntryPoint.h"
#include "Shared/Skyrim/B/BGSEntryPointFunction.h"
#include "Shared/Skyrim/B/BGSEntryPointFunctionData.h"
#include "Shared/Skyrim/B/BGSEntryPointFunctionDataActivateChoice.h"
#include "Shared/Skyrim/B/BGSEntryPointFunctionDataSpellItem.h"
#include "Shared/Skyrim/B/BGSEntryPointPerkEntry.h"
#include "Shared/Skyrim/B/BGSEquipSlot.h"
#include "Shared/Skyrim/B/BGSEquipType.h"
#include "Shared/Skyrim/B/BGSExplosion.h"
#include "Shared/Skyrim/B/BGSFootstep.h"
#include "Shared/Skyrim/B/BGSFootstepEvent.h"
#include "Shared/Skyrim/B/BGSFootstepManager.h"
#include "Shared/Skyrim/B/BGSFootstepSet.h"
#include "Shared/Skyrim/B/BGSHazard.h"
#include "Shared/Skyrim/B/BGSHeadPart.h"
#include "Shared/Skyrim/B/BGSImpactData.h"
#include "Shared/Skyrim/B/BGSImpactDataSet.h"
#include "Shared/Skyrim/B/BGSImpactManager.h"
#include "Shared/Skyrim/B/BGSKeyword.h"
#include "Shared/Skyrim/B/BGSKeywordForm.h"
#include "Shared/Skyrim/B/BGSLensFlare.h"
#include "Shared/Skyrim/B/BGSListForm.h"
#include "Shared/Skyrim/B/BGSLocalizedStringDL.h"
#include "Shared/Skyrim/B/BGSMaterialObject.h"
#include "Shared/Skyrim/B/BGSMaterialType.h"
#include "Shared/Skyrim/B/BGSMenuDisplayObject.h"
#include "Shared/Skyrim/B/BGSMessageIcon.h"
#include "Shared/Skyrim/B/BGSMovementType.h"
#include "Shared/Skyrim/B/BGSOpenCloseForm.h"
#include "Shared/Skyrim/B/BGSOutfit.h"
#include "Shared/Skyrim/B/BGSOverridePackCollection.h"
#include "Shared/Skyrim/B/BGSPerk.h"
#include "Shared/Skyrim/B/BGSPerkEntry.h"
#include "Shared/Skyrim/B/BGSPerkRankArray.h"
#include "Shared/Skyrim/B/BGSPickupPutdownSounds.h"
#include "Shared/Skyrim/B/BGSPreloadable.h"
#include "Shared/Skyrim/B/BGSProjectile.h"
#include "Shared/Skyrim/B/BGSReferenceEffect.h"
#include "Shared/Skyrim/B/BGSRelationship.h"
#include "Shared/Skyrim/B/BGSSaveFormBuffer.h"
#include "Shared/Skyrim/B/BGSSaveGameBuffer.h"
#include "Shared/Skyrim/B/BGSShaderParticleGeometryData.h"
#include "Shared/Skyrim/B/BGSSkinForm.h"
#include "Shared/Skyrim/B/BGSSoundDescriptorForm.h"
#include "Shared/Skyrim/B/BGSTextureModel.h"
#include "Shared/Skyrim/B/BGSTextureSet.h"
#include "Shared/Skyrim/B/BGSVoiceType.h"
#include "Shared/Skyrim/B/BGSVolumetricLighting.h"
#include "Shared/Skyrim/B/BGSWorldLocation.h"
#include "Shared/Skyrim/B/bhkCharacterController.h"
#include "Shared/Skyrim/B/bhkCollisionObject.h"
#include "Shared/Skyrim/B/bhkConstraint.h"
#include "Shared/Skyrim/B/bhkEntity.h"
#include "Shared/Skyrim/B/bhkNiCollisionObject.h"
#include "Shared/Skyrim/B/bhkPickData.h"
#include "Shared/Skyrim/B/bhkRefObject.h"
#include "Shared/Skyrim/B/bhkRigidBody.h"
#include "Shared/Skyrim/B/bhkSerializable.h"
#include "Shared/Skyrim/B/bhkShape.h"
#include "Shared/Skyrim/B/bhkShapeCollection.h"
#include "Shared/Skyrim/B/bhkWorld.h"
#include "Shared/Skyrim/B/bhkWorldObject.h"
#include "Shared/Skyrim/B/BipedAnim.h"
#include "Shared/Skyrim/B/BipedObject.h"
#include "Shared/Skyrim/B/BipedObjectSlot.h"
#include "Shared/Skyrim/B/BSAnimationGraphChannel.h"
#include "Shared/Skyrim/B/BSAnimationGraphEvent.h"
#include "Shared/Skyrim/B/BSAtomic.h"
#include "Shared/Skyrim/B/BSAudioManager.h"
#include "Shared/Skyrim/B/BSBound.h"
#include "Shared/Skyrim/B/BSCoreTypes.h"
#include "Shared/Skyrim/B/BSCRC32.h"
#include "Shared/Skyrim/B/BSExtraData.h"
#include "Shared/Skyrim/B/BSFadeNode.h"
#include "Shared/Skyrim/B/BSFile.h"
#include "Shared/Skyrim/B/BSFixedString.h"
#include "Shared/Skyrim/B/BSGeometry.h"
#include "Shared/Skyrim/B/BSHandleRefObject.h"
#include "Shared/Skyrim/B/BSInputDeviceManager.h"
#include "Shared/Skyrim/B/BSIntrusiveRefCounted.h"
#include "Shared/Skyrim/B/BSInvMarker.h"
#include "Shared/Skyrim/B/BSISoundDescriptor.h"
#include "Shared/Skyrim/B/BSLensFlareRenderData.h"
#include "Shared/Skyrim/B/BSMaterialObject.h"
#include "Shared/Skyrim/B/BSMultiBoundNode.h"
#include "Shared/Skyrim/B/BSNiNode.h"
#include "Shared/Skyrim/B/BSPackedTaskQueue.h"
#include "Shared/Skyrim/B/BSPointerHandle.h"
#include "Shared/Skyrim/B/BSSimpleList.h"
#include "Shared/Skyrim/B/BSSoundHandle.h"
#include "Shared/Skyrim/B/BSString.h"
#include "Shared/Skyrim/B/BSStringPool.h"
#include "Shared/Skyrim/B/BSTArray.h"
#include "Shared/Skyrim/B/BSTempEffect.h"
#include "Shared/Skyrim/B/BSTempEffectSimpleDecal.h"
#include "Shared/Skyrim/B/BSTEventSink.h"
#include "Shared/Skyrim/B/BSTEventSource.h"
#include "Shared/Skyrim/B/BSTextureSet.h"
#include "Shared/Skyrim/B/BSTHashMap.h"
#include "Shared/Skyrim/B/BSThread.h"
#include "Shared/Skyrim/B/BSTMessageQueue.h"
#include "Shared/Skyrim/B/BSTPoint.h"
#include "Shared/Skyrim/B/BSTriShape.h"
#include "Shared/Skyrim/B/BSTSingleton.h"
#include "Shared/Skyrim/B/BSTSmartPointer.h"
#include "Shared/Skyrim/B/BSTTuple.h"
#include "Shared/Skyrim/B/BSVolumetricLightingRenderData.h"
#include "Shared/Skyrim/B/ButtonEvent.h"
#include "Shared/Skyrim/C/CameraState.h"
#include "Shared/Skyrim/C/CastPowerItem.h"
#include "Shared/Skyrim/C/Character.h"
#include "Shared/Skyrim/C/CharEvent.h"
#include "Shared/Skyrim/C/Clouds.h"
#include "Shared/Skyrim/C/CollisionLayer.h"
#include "Shared/Skyrim/C/Color.h"
#include "Shared/Skyrim/C/CombatController.h"
#include "Shared/Skyrim/C/CombatReaction.h"
#include "Shared/Skyrim/C/CombatState.h"
#include "Shared/Skyrim/C/CommandTable.h"
#include "Shared/Skyrim/C/ConcreteFormFactory.h"
#include "Shared/Skyrim/C/ConcussionEffect.h"
#include "Shared/Skyrim/C/ConfirmLevelUpAttributeCallback.h"
#include "Shared/Skyrim/C/Console.h"
#include "Shared/Skyrim/C/ConsoleLog.h"
#include "Shared/Skyrim/C/ContainerItemExtra.h"
#include "Shared/Skyrim/C/ContainerMenu.h"
#include "Shared/Skyrim/C/CraftingSubMenu.h"
#include "Shared/Skyrim/D/DecalData.h"
#include "Shared/Skyrim/D/DetectionPriority.h"
#include "Shared/Skyrim/D/DeviceConnectEvent.h"
#include "Shared/Skyrim/D/Difficulty.h"
#include "Shared/Skyrim/D/DirectionalAmbientLighting.h"
#include "Shared/Skyrim/D/DualValueModifierEffect.h"
#include "Shared/Skyrim/E/EffectArchetypes.h"
#include "Shared/Skyrim/E/EffectItem.h"
#include "Shared/Skyrim/E/EffectItemReplaceTagsFunctor.h"
#include "Shared/Skyrim/E/EffectSetting.h"
#include "Shared/Skyrim/E/EnchantConstructMenu.h"
#include "Shared/Skyrim/E/EnchantmentItem.h"
#include "Shared/Skyrim/E/EventNotifyControl.h"
#include "Shared/Skyrim/E/ExtraCharge.h"
#include "Shared/Skyrim/E/ExtraCount.h"
#include "Shared/Skyrim/E/ExtraDataList.h"
#include "Shared/Skyrim/E/ExtraDataType.h"
#include "Shared/Skyrim/E/ExtraEnchantment.h"
#include "Shared/Skyrim/E/ExtraHealth.h"
#include "Shared/Skyrim/E/ExtraInteraction.h"
#include "Shared/Skyrim/E/ExtraLevCreaModifier.h"
#include "Shared/Skyrim/E/ExtraLock.h"
#include "Shared/Skyrim/E/ExtraLockList.h"
#include "Shared/Skyrim/E/ExtraOwnership.h"
#include "Shared/Skyrim/E/ExtraPoison.h"
#include "Shared/Skyrim/E/ExtraSoul.h"
#include "Shared/Skyrim/E/ExtraWorn.h"
#include "Shared/Skyrim/E/ExtraWornLeft.h"
#include "Shared/Skyrim/Events.h"
#include "Shared/Skyrim/F/FactionRank.h"
#include "Shared/Skyrim/F/FileID.h"
#include "Shared/Skyrim/F/FindAppropriateDisplaceEffect.h"
#include "Shared/Skyrim/F/FindMaxMagnitudeVisitor.h"
#include "Shared/Skyrim/F/FirstPersonState.h"
#include "Shared/Skyrim/F/FixedStrings.h"
#include "Shared/Skyrim/F/ForEachResult.h"
#include "Shared/Skyrim/F/FormType.h"
#include "Shared/Skyrim/F/FxDelegate.h"
#include "Shared/Skyrim/F/FxDelegateArguments.h"
#include "Shared/Skyrim/F/FxDelegateHandler.h"
#include "Shared/Skyrim/F/FxResponseArguments.h"
#include "Shared/Skyrim/F/FxResponseArgumentsBase.h"
#include "Shared/Skyrim/F/FxResponseArgumentsList.h"
#include "Shared/Skyrim/G/GAllocator.h"
#include "Shared/Skyrim/G/GAllocatorBaseDH.h"
#include "Shared/Skyrim/G/GAllocatorBaseGH.h"
#include "Shared/Skyrim/G/GAllocatorBaseLH.h"
#include "Shared/Skyrim/G/GameplayFormulas.h"
#include "Shared/Skyrim/G/GameSettingCollection.h"
#include "Shared/Skyrim/G/GArray.h"
#include "Shared/Skyrim/G/GArrayBase.h"
#include "Shared/Skyrim/G/GArrayCC.h"
#include "Shared/Skyrim/G/GArrayConstantPolicy.h"
#include "Shared/Skyrim/G/GArrayCPP.h"
#include "Shared/Skyrim/G/GArrayData.h"
#include "Shared/Skyrim/G/GArrayDataBase.h"
#include "Shared/Skyrim/G/GArrayDataCC.h"
#include "Shared/Skyrim/G/GArrayDataDH.h"
#include "Shared/Skyrim/G/GArrayDefaultPolicy.h"
#include "Shared/Skyrim/G/GArrayDH.h"
#include "Shared/Skyrim/G/GArrayDHPOD.h"
#include "Shared/Skyrim/G/GArrayLH.h"
#include "Shared/Skyrim/G/GArrayLHPOD.h"
#include "Shared/Skyrim/G/GArrayPOD.h"
#include "Shared/Skyrim/G/GAtomic.h"
#include "Shared/Skyrim/G/GColor.h"
#include "Shared/Skyrim/G/GConstructorCPP.h"
#include "Shared/Skyrim/G/GConstructorMovable.h"
#include "Shared/Skyrim/G/GConstructorPOD.h"
#include "Shared/Skyrim/G/GetMagicItemDescriptionFunctor.h"
#include "Shared/Skyrim/G/GFixedSizeHash.h"
#include "Shared/Skyrim/G/GFxExporterInformation.h"
#include "Shared/Skyrim/G/GFxExternalInterface.h"
#include "Shared/Skyrim/G/GFxFileConstants.h"
#include "Shared/Skyrim/G/GFxFunctionHandler.h"
#include "Shared/Skyrim/G/GFxMovie.h"
#include "Shared/Skyrim/G/GFxMovieDef.h"
#include "Shared/Skyrim/G/GFxMovieView.h"
#include "Shared/Skyrim/G/GFxPlayerStatistics.h"
#include "Shared/Skyrim/G/GFxResource.h"
#include "Shared/Skyrim/G/GFxResourceID.h"
#include "Shared/Skyrim/G/GFxResourceKey.h"
#include "Shared/Skyrim/G/GFxResourceLibBase.h"
#include "Shared/Skyrim/G/GFxState.h"
#include "Shared/Skyrim/G/GFxStateBag.h"
#include "Shared/Skyrim/G/GFxValue.h"
#include "Shared/Skyrim/G/GHash.h"
#include "Shared/Skyrim/G/GHashDH.h"
#include "Shared/Skyrim/G/GHashIdentity.h"
#include "Shared/Skyrim/G/GHashIdentityDH.h"
#include "Shared/Skyrim/G/GHashIdentityLH.h"
#include "Shared/Skyrim/G/GHashLH.h"
#include "Shared/Skyrim/G/GHashNode.h"
#include "Shared/Skyrim/G/GHashSet.h"
#include "Shared/Skyrim/G/GHashSetBase.h"
#include "Shared/Skyrim/G/GHashSetCachedEntry.h"
#include "Shared/Skyrim/G/GHashSetCachedNodeEntry.h"
#include "Shared/Skyrim/G/GHashSetDH.h"
#include "Shared/Skyrim/G/GHashSetEntry.h"
#include "Shared/Skyrim/G/GHashSetLH.h"
#include "Shared/Skyrim/G/GHashSetNodeEntry.h"
#include "Shared/Skyrim/G/GHashSetUncached.h"
#include "Shared/Skyrim/G/GHashSetUncachedDH.h"
#include "Shared/Skyrim/G/GHashSetUncachedLH.h"
#include "Shared/Skyrim/G/GHashUncached.h"
#include "Shared/Skyrim/G/GHashUncachedDH.h"
#include "Shared/Skyrim/G/GHashUncachedLH.h"
#include "Shared/Skyrim/G/GIdentityHash.h"
#include "Shared/Skyrim/G/GImage.h"
#include "Shared/Skyrim/G/GImageBase.h"
#include "Shared/Skyrim/G/GList.h"
#include "Shared/Skyrim/G/GMath.h"
#include "Shared/Skyrim/G/GMatrix2D.h"
#include "Shared/Skyrim/G/GMatrix3D.h"
#include "Shared/Skyrim/G/GMemory.h"
#include "Shared/Skyrim/G/GMemoryHeap.h"
#include "Shared/Skyrim/G/GNewOverrideBase.h"
#include "Shared/Skyrim/G/GPoint.h"
#include "Shared/Skyrim/G/GPoint3.h"
#include "Shared/Skyrim/G/GPointer.h"
#include "Shared/Skyrim/G/GRectangle.h"
#include "Shared/Skyrim/G/GRefCountBase.h"
#include "Shared/Skyrim/G/GRefCountBaseNTS.h"
#include "Shared/Skyrim/G/GRefCountBaseStatImpl.h"
#include "Shared/Skyrim/G/GRefCountImpl.h"
#include "Shared/Skyrim/G/GRefCountImplCore.h"
#include "Shared/Skyrim/G/GRefCountNTSImpl.h"
#include "Shared/Skyrim/G/GRenderer.h"
#include "Shared/Skyrim/G/GRendererEventHandler.h"
#include "Shared/Skyrim/G/GRenderTarget.h"
#include "Shared/Skyrim/G/GridArray.h"
#include "Shared/Skyrim/G/GridCellArray.h"
#include "Shared/Skyrim/G/GStatistics.h"
#include "Shared/Skyrim/G/GString.h"
#include "Shared/Skyrim/G/GSysAlloc.h"
#include "Shared/Skyrim/G/GSysAllocBase.h"
#include "Shared/Skyrim/G/GSysAllocPaged.h"
#include "Shared/Skyrim/G/GTexture.h"
#include "Shared/Skyrim/G/GViewport.h"
#include "Shared/Skyrim/H/HandleEntryPointVisitor.h"
#include "Shared/Skyrim/H/HeldStateHandler.h"
#include "Shared/Skyrim/H/HighProcessData.h"
#include "Shared/Skyrim/H/HitData.h"
#include "Shared/Skyrim/H/hkArray.h"
#include "Shared/Skyrim/H/hkBaseObject.h"
#include "Shared/Skyrim/H/hkBaseTypes.h"
#include "Shared/Skyrim/H/hkEnumeration.h"
#include "Shared/Skyrim/H/hkMultipleThreadCheck.h"
#include "Shared/Skyrim/H/hkpBroadPhaseHandle.h"
#include "Shared/Skyrim/H/hkpCdBody.h"
#include "Shared/Skyrim/H/hkpCharacterContext.h"
#include "Shared/Skyrim/H/hkpCharacterState.h"
#include "Shared/Skyrim/H/hkpCharacterStateManager.h"
#include "Shared/Skyrim/H/hkpCharacterStateType.h"
#include "Shared/Skyrim/H/hkpClosestRayHitCollector.h"
#include "Shared/Skyrim/H/hkpCollidable.h"
#include "Shared/Skyrim/H/hkpCollidableCollidableFilter.h"
#include "Shared/Skyrim/H/hkpCollisionFilter.h"
#include "Shared/Skyrim/H/hkpGroupFilter.h"
#include "Shared/Skyrim/H/hkpLinkedCollidable.h"
#include "Shared/Skyrim/H/hkpRayCollidableFilter.h"
#include "Shared/Skyrim/H/hkpRayHitCollector.h"
#include "Shared/Skyrim/H/hkpRayShapeCollectionFilter.h"
#include "Shared/Skyrim/H/hkpShape.h"
#include "Shared/Skyrim/H/hkpShapeCollectionFilter.h"
#include "Shared/Skyrim/H/hkpShapeRayCastCollectorOutput.h"
#include "Shared/Skyrim/H/hkpShapeRayCastOutput.h"
#include "Shared/Skyrim/H/hkpShapeType.h"
#include "Shared/Skyrim/H/hkpSurfaceInformation.h"
#include "Shared/Skyrim/H/hkpTypedBroadPhaseHandle.h"
#include "Shared/Skyrim/H/hkpWorldObject.h"
#include "Shared/Skyrim/H/hkpWorldRayCastInput.h"
#include "Shared/Skyrim/H/hkpWorldRayCastOutput.h"
#include "Shared/Skyrim/H/hkReferencedObject.h"
#include "Shared/Skyrim/H/hkReferencePointer.h"
#include "Shared/Skyrim/H/hkSimpleProperty.h"
#include "Shared/Skyrim/H/hkStepInformation.h"
#include "Shared/Skyrim/H/hkStringPointer.h"
#include "Shared/Skyrim/H/hkVector4.h"
#include "Shared/Skyrim/H/hkVector4Comparison.h"
#include "Shared/Skyrim/I/IAnimationGraphManagerHolder.h"
#include "Shared/Skyrim/I/ICellAttachDetachEventSource.h"
#include "Shared/Skyrim/I/ID.h"
#include "Shared/Skyrim/I/IDEvent.h"
#include "Shared/Skyrim/I/IFormFactory.h"
#include "Shared/Skyrim/I/IMemoryStore.h"
#include "Shared/Skyrim/I/IMemoryStoreBase.h"
#include "Shared/Skyrim/I/IMenu.h"
#include "Shared/Skyrim/I/IMessageBoxCallback.h"
#include "Shared/Skyrim/I/IMovementInterface.h"
#include "Shared/Skyrim/I/IMovementState.h"
#include "Shared/Skyrim/I/ImpactResult.h"
#include "Shared/Skyrim/I/IngredientItem.h"
#include "Shared/Skyrim/I/INIPrefSettingCollection.h"
#include "Shared/Skyrim/I/INISettingCollection.h"
#include "Shared/Skyrim/I/InitTESThread.h"
#include "Shared/Skyrim/I/InputDevice.h"
#include "Shared/Skyrim/I/InputEvent.h"
#include "Shared/Skyrim/I/InterfaceStrings.h"
#include "Shared/Skyrim/I/Inventory3DManager.h"
#include "Shared/Skyrim/I/InventoryChanges.h"
#include "Shared/Skyrim/I/InventoryEntryData.h"
#include "Shared/Skyrim/I/IPostAnimationChannelUpdateFunctor.h"
#include "Shared/Skyrim/I/ItemCard.h"
#include "Shared/Skyrim/I/ItemList.h"
#include "Shared/Skyrim/K/KinectEvent.h"
#include "Shared/Skyrim/L/LevelUpMenu.h"
#include "Shared/Skyrim/M/MagicCaster.h"
#include "Shared/Skyrim/M/MagicItem.h"
#include "Shared/Skyrim/M/MagicItemTraversalFunctor.h"
#include "Shared/Skyrim/M/MagicSystem.h"
#include "Shared/Skyrim/M/MagicTarget.h"
#include "Shared/Skyrim/M/Main.h"
#include "Shared/Skyrim/M/MemoryManager.h"
#include "Shared/Skyrim/M/MenuEventHandler.h"
#include "Shared/Skyrim/M/MiddleHighProcessData.h"
#include "Shared/Skyrim/M/MissileProjectile.h"
#include "Shared/Skyrim/M/ModelReferenceEffect.h"
#include "Shared/Skyrim/M/Moon.h"
#include "Shared/Skyrim/M/MountInteraction.h"
#include "Shared/Skyrim/M/MouseMoveEvent.h"
#include "Shared/Skyrim/N/NiAVObject.h"
#include "Shared/Skyrim/N/NiBillboardNode.h"
#include "Shared/Skyrim/N/NiBinaryStream.h"
#include "Shared/Skyrim/N/NiBooleanExtraData.h"
#include "Shared/Skyrim/N/NiBound.h"
#include "Shared/Skyrim/N/NiCollisionObject.h"
#include "Shared/Skyrim/N/NiColor.h"
#include "Shared/Skyrim/N/NiDirectionalLight.h"
#include "Shared/Skyrim/N/NiExtraData.h"
#include "Shared/Skyrim/N/NiFile.h"
#include "Shared/Skyrim/N/NiFloatExtraData.h"
#include "Shared/Skyrim/N/NiFloatsExtraData.h"
#include "Shared/Skyrim/N/NiIntegerExtraData.h"
#include "Shared/Skyrim/N/NiIntegersExtraData.h"
#include "Shared/Skyrim/N/NiLight.h"
#include "Shared/Skyrim/N/NiMatrix33.h"
#include "Shared/Skyrim/N/NiNode.h"
#include "Shared/Skyrim/N/NiObject.h"
#include "Shared/Skyrim/N/NiObjectNET.h"
#include "Shared/Skyrim/N/NiPoint2.h"
#include "Shared/Skyrim/N/NiPoint3.h"
#include "Shared/Skyrim/N/NiPointer.h"
#include "Shared/Skyrim/N/NiProperty.h"
#include "Shared/Skyrim/N/NiQuaternion.h"
#include "Shared/Skyrim/N/NiRefObject.h"
#include "Shared/Skyrim/N/NiStringExtraData.h"
#include "Shared/Skyrim/N/NiStringsExtraData.h"
#include "Shared/Skyrim/N/NiTArray.h"
#include "Shared/Skyrim/N/NiTexture.h"
#include "Shared/Skyrim/N/NiTList.h"
#include "Shared/Skyrim/N/NiTransform.h"
#include "Shared/Skyrim/P/PerkEntryVisitor.h"
#include "Shared/Skyrim/P/Pickpocket.h"
#include "Shared/Skyrim/P/PickpocketToMiscStatHandler.h"
#include "Shared/Skyrim/P/PlayerCamera.h"
#include "Shared/Skyrim/P/PlayerCharacter.h"
#include "Shared/Skyrim/P/PlayerInputHandler.h"
#include "Shared/Skyrim/P/PoisonedWeapon.h"
#include "Shared/Skyrim/P/Precipitation.h"
#include "Shared/Skyrim/P/ProcessLists.h"
#include "Shared/Skyrim/P/Projectile.h"
#include "Shared/Skyrim/R/RefAttachTechniqueInput.h"
#include "Shared/Skyrim/R/ReferenceEffect.h"
#include "Shared/Skyrim/R/ReferenceEffectController.h"
#include "Shared/Skyrim/R/RefrInteraction.h"
#include "Shared/Skyrim/R/RegSettingCollection.h"
#include "Shared/Skyrim/R/RemoveCallbackVisitor.h"
#include "Shared/Skyrim/R/ResetElapsedTimeMatchingEffects.h"
#include "Shared/Skyrim/S/ScaleformTypes.h"
#include "Shared/Skyrim/S/ScrapHeap.h"
#include "Shared/Skyrim/S/Script.h"
#include "Shared/Skyrim/S/ScriptCompiler.h"
#include "Shared/Skyrim/S/ScriptEffect.h"
#include "Shared/Skyrim/S/ScriptEventSourceHolder.h"
#include "Shared/Skyrim/S/ScriptOutput.h"
#include "Shared/Skyrim/S/ScrollItem.h"
#include "Shared/Skyrim/S/SetEventData.h"
#include "Shared/Skyrim/S/Setting.h"
#include "Shared/Skyrim/S/SettingCollection.h"
#include "Shared/Skyrim/S/SettingCollectionList.h"
#include "Shared/Skyrim/S/SettingCollectionMap.h"
#include "Shared/Skyrim/S/SettingT.h"
#include "Shared/Skyrim/S/Sex.h"
#include "Shared/Skyrim/S/SimpleAnimationGraphManagerHolder.h"
#include "Shared/Skyrim/S/SimpleArray.h"
#include "Shared/Skyrim/S/Skill.h"
#include "Shared/Skyrim/S/Sky.h"
#include "Shared/Skyrim/S/SkyEffectController.h"
#include "Shared/Skyrim/S/SkyObject.h"
#include "Shared/Skyrim/S/SlowTimeEffect.h"
#include "Shared/Skyrim/S/SoulLevel.h"
#include "Shared/Skyrim/S/SoundLevel.h"
#include "Shared/Skyrim/S/SpellItem.h"
#include "Shared/Skyrim/S/StandardItemData.h"
#include "Shared/Skyrim/S/Stars.h"
#include "Shared/Skyrim/S/Sun.h"
#include "Shared/Skyrim/S/SyncQueueObj.h"
#include "Shared/Skyrim/T/TaskQueueInterface.h"
#include "Shared/Skyrim/T/TES.h"
#include "Shared/Skyrim/T/TESActorBase.h"
#include "Shared/Skyrim/T/TESActorBaseData.h"
#include "Shared/Skyrim/T/TESAIForm.h"
#include "Shared/Skyrim/T/TESAmmo.h"
#include "Shared/Skyrim/T/TESAttackDamageForm.h"
#include "Shared/Skyrim/T/TESBipedModelForm.h"
#include "Shared/Skyrim/T/TESBoundAnimObject.h"
#include "Shared/Skyrim/T/TESBoundObject.h"
#include "Shared/Skyrim/T/TESCamera.h"
#include "Shared/Skyrim/T/TESCameraState.h"
#include "Shared/Skyrim/T/TESClass.h"
#include "Shared/Skyrim/T/TESClimate.h"
#include "Shared/Skyrim/T/TESCombatStyle.h"
#include "Shared/Skyrim/T/TESCondition.h"
#include "Shared/Skyrim/T/TESContainer.h"
#include "Shared/Skyrim/T/TESDataHandler.h"
#include "Shared/Skyrim/T/TESDescription.h"
#include "Shared/Skyrim/T/TESEffectShader.h"
#include "Shared/Skyrim/T/TESEnchantableForm.h"
#include "Shared/Skyrim/T/TESFaction.h"
#include "Shared/Skyrim/T/TESFile.h"
#include "Shared/Skyrim/T/TESFlora.h"
#include "Shared/Skyrim/T/TESForm.h"
#include "Shared/Skyrim/T/TESFullName.h"
#include "Shared/Skyrim/T/TESFurniture.h"
#include "Shared/Skyrim/T/TESGlobal.h"
#include "Shared/Skyrim/T/TESHitEvent.h"
#include "Shared/Skyrim/T/TESIcon.h"
#include "Shared/Skyrim/T/TESImageSpace.h"
#include "Shared/Skyrim/T/TESImageSpaceModifiableForm.h"
#include "Shared/Skyrim/T/TESImageSpaceModifier.h"
#include "Shared/Skyrim/T/TESLeveledList.h"
#include "Shared/Skyrim/T/TESLevItem.h"
#include "Shared/Skyrim/T/TESLevSpell.h"
#include "Shared/Skyrim/T/TESLoadGameEvent.h"
#include "Shared/Skyrim/T/TESMagicCasterForm.h"
#include "Shared/Skyrim/T/TESMagicTargetForm.h"
#include "Shared/Skyrim/T/TESModel.h"
#include "Shared/Skyrim/T/TESModelPSA.h"
#include "Shared/Skyrim/T/TESModelRDT.h"
#include "Shared/Skyrim/T/TESModelTextureSwap.h"
#include "Shared/Skyrim/T/TESModelTri.h"
#include "Shared/Skyrim/T/TESNPC.h"
#include "Shared/Skyrim/T/TESObject.h"
#include "Shared/Skyrim/T/TESObjectACTI.h"
#include "Shared/Skyrim/T/TESObjectARMA.h"
#include "Shared/Skyrim/T/TESObjectARMO.h"
#include "Shared/Skyrim/T/TESObjectCELL.h"
#include "Shared/Skyrim/T/TESObjectCONT.h"
#include "Shared/Skyrim/T/TESObjectDOOR.h"
#include "Shared/Skyrim/T/TESObjectLIGH.h"
#include "Shared/Skyrim/T/TESObjectMISC.h"
#include "Shared/Skyrim/T/TESObjectREFR.h"
#include "Shared/Skyrim/T/TESObjectREFRFactory.h"
#include "Shared/Skyrim/T/TESObjectSTAT.h"
#include "Shared/Skyrim/T/TESObjectTREE.h"
#include "Shared/Skyrim/T/TESObjectWEAP.h"
#include "Shared/Skyrim/T/TESProduceForm.h"
#include "Shared/Skyrim/T/TESQuestStageItem.h"
#include "Shared/Skyrim/T/TESRace.h"
#include "Shared/Skyrim/T/TESRaceForm.h"
#include "Shared/Skyrim/T/TESReactionForm.h"
#include "Shared/Skyrim/T/TESRegion.h"
#include "Shared/Skyrim/T/TESShout.h"
#include "Shared/Skyrim/T/TESSoulGem.h"
#include "Shared/Skyrim/T/TESSpellList.h"
#include "Shared/Skyrim/T/TESTexture.h"
#include "Shared/Skyrim/T/TESTexture1024.h"
#include "Shared/Skyrim/T/TESValueForm.h"
#include "Shared/Skyrim/T/TESWaitStartEvent.h"
#include "Shared/Skyrim/T/TESWaitStopEvent.h"
#include "Shared/Skyrim/T/TESWaterForm.h"
#include "Shared/Skyrim/T/TESWeather.h"
#include "Shared/Skyrim/T/TESWeightForm.h"
#include "Shared/Skyrim/T/TESWordOfPower.h"
#include "Shared/Skyrim/T/TESWorldSpace.h"
#include "Shared/Skyrim/T/ThumbstickEvent.h"
#include "Shared/Skyrim/U/UI.h"
#include "Shared/Skyrim/U/UIMessage.h"
#include "Shared/Skyrim/U/UIMessageQueue.h"
#include "Shared/Skyrim/U/UnreachableLocation.h"
#include "Shared/Skyrim/U/UserEvents.h"
#include "Shared/Skyrim/V/ValueModifierEffect.h"
#include "Shared/Skyrim/V/VATS.h"
#include "Shared/Skyrim/V/VATSCommand.h"
