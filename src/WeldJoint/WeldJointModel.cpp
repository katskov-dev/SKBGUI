#include "WeldJoint/WeldJointModel.h"
#include <Joint/JointModel.h>
#include <RigidBody/RigidBody.h>
WeldJointModel::WeldJointModel(pRigidBody FBody,pRigidBody SBody,pWorld world): JointModel(FBody, SBody, world)
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    jointDef = new b2WeldJointDef();
    Init();

}
WeldJointModel::Init()//:Init(AnchorOne,AnchorTwo)
{
    jointDef->Initialize(JointModel::FBody()->Model()->myBody() ,JointModel::SBody()->Model()->myBody(),JointModel::FBody()->Model()->myBody()->GetWorldCenter());
    jointDef->collideConnected = true;
    JointModel::World()->Model()->World().CreateJoint(jointDef);
}
WeldJointModel::~WeldJointModel()
{
    //dtor
}
