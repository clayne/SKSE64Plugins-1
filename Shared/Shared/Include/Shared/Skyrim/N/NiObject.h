#pragma once

#include "Shared/PrecompiledHeader.h"

#include "Shared/Skyrim/N/NiRefObject.h"



namespace Skyrim
{
	class bhkAttachmentCollisionObject;
	class bhkBlendCollisionObject;
	class bhkLimitedHingeConstraint;
	class bhkNiCollisionObject;
	class bhkRigidBody;
	class BSDynamicTriShape;
	class BSFadeNode;
	class BSGeometry;
	class BSLines;
	class BSMultiBoundNode;
	class BSSegmentedTriShape;
	class BSSubIndexTriShape;
	class BSTriShape;
	class NiCloningProcess;
	class NiControllerManager;
	class NiGeometry;
	class NiNode;
	class NiObjectGroup;
	class NiParticles;
	class NiRTTI;
	class NiStream;
	class NiSwitchNode;
	class NiTriBasedGeom;
	class NiTriShape;
	class NiTriStrips;

	class NiObject :
		public NiRefObject // 0
	{
	public:
		// Override
		virtual ~NiObject() override; // 0

		// Add
		virtual const NiRTTI*                 GetRTTI() const;                                // 2
		virtual NiNode*                       AsNetImmerseNode();                             // 3
		virtual NiSwitchNode*                 AsNetImmerseSwitchNode();                       // 4
		virtual BSFadeNode*                   AsFadeNode();                                   // 5
		virtual BSMultiBoundNode*             AsMultipleBoundNode();                          // 6
		virtual BSGeometry*                   AsGeometry();                                   // 7
		virtual NiTriStrips*                  AsNetImmerseTriangleStrips();                   // 8
		virtual BSTriShape*                   AsTriangleShape();                              // 9
		virtual BSSegmentedTriShape*          AsSegmentedTriangleShape();                     // A
		virtual BSSubIndexTriShape*           AsSubIndexTriangleShape();                      // B
		virtual BSDynamicTriShape*            AsDynamicTriangleShape();                       // C
		virtual NiGeometry*                   AsNetImmerseGeometry();                         // D
		virtual NiTriBasedGeom*               AsNetImmerseTriangleBasedGeometry();            // E
		virtual NiTriShape*                   AsNetImmerseTriangleShape();                    // F
		virtual NiParticles*                  AsNetImmerseParticles();                        // 10
		virtual BSLines*                      AsLines();                                      // 11
		virtual bhkNiCollisionObject*         AsNetImmerseCollisionObject();                  // 12
		virtual bhkBlendCollisionObject*      AsBlendCollisionObject();                       // 13
		virtual bhkAttachmentCollisionObject* AsAttachmentCollisionObject();                  // 14
		virtual bhkRigidBody*                 AsRigidBody();                                  // 15
		virtual bhkLimitedHingeConstraint*    AsLimitedHingeConstraint();                     // 16
		virtual NiObject*                     CreateClone(NiCloningProcess& cloningProcess);  // 17
		virtual void                          LoadBinary(NiStream& stream);                   // 18
		virtual void                          LinkObject(NiStream& stream);                   // 19
		virtual bool                          RegisterStreamables(NiStream& stream);          // 1A
		virtual void                          SaveBinary(NiStream& stream);                   // 1B
		virtual bool                          IsEqual(NiObject* object);                      // 1C
		virtual void                          ProcessClone(NiCloningProcess& cloningProcess); // 1D
		virtual void                          PostLinkObject(NiStream& stream);               // 1E
		virtual bool                          StreamCanSkip();                                // 1F
		virtual const NiRTTI*                 GetStreamableRTTI() const;                      // 20
		virtual std::uint32_t                 GetBlockAllocationSize() const;                 // 21
		virtual NiObjectGroup*                GetGroup() const;                               // 22
		virtual void                          SetGroup(NiObjectGroup* group);                 // 23
		virtual NiControllerManager*          AsNetImmerseControllerManager();                // 24
	};
	static_assert(sizeof(NiObject) == 0x10);
}
