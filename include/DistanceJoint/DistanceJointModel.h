#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Joint/JointModel.h>
#include <RigidBody/RigidBody.h>

class DistanceJointModel: public JointModel
{
    public:
        DistanceJointModel(pRigidBody FBody,pRigidBody SBody,pWorld world);
        virtual ~DistanceJointModel();
        Init();
        Destroy();
        b2DistanceJointDef* getJointDef();
        b2DistanceJoint* getJoint();
    protected:

    private:

	b2DistanceJointDef* jointDef;
    b2DistanceJoint* joint;

};
