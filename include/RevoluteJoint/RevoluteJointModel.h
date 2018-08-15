#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Joint/JointModel.h>
#include <RigidBody/RigidBody.h>

class RevoluteJointModel: public JointModel
{
    public:
        RevoluteJointModel(pRigidBody FBody,pRigidBody SBody,pWorld world);
        virtual ~RevoluteJointModel();
        Init();
        Destroy();
        b2RevoluteJointDef* getJointDef();
        b2RevoluteJoint* getJoint();
        void setJointDef(b2RevoluteJointDef* revoluteJointDef);
        void getJoint(b2RevoluteJoint* revoluteJoint);
    protected:

    private:
    b2RevoluteJointDef* jointDef;
    b2RevoluteJoint* joint;
};
