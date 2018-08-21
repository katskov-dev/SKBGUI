#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Joint/JointModel.h>
#include <Box2D.h>
class WeldJointModel: public JointModel
{
    public:
        WeldJointModel(pRigidBody FBody,pRigidBody SBody,pWorld world);
        virtual ~WeldJointModel();
        Init();
        Destroy();
        b2WeldJointDef* getJointDef();
        b2WeldJoint* getJoint();
        void setJointDef(b2WeldJointDef* weldJointDef);
        void getJoint(b2WeldJoint* weldJoint);
    protected:

    private:

	b2WeldJointDef* jointDef;
    b2WeldJoint* joint;
};
