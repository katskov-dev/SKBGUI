#include "DistanceJoint/DistanceJointModel.h"

DistanceJointModel::DistanceJointModel(pRigidBody FBody, pRigidBody SBody , pWorld world): JointModel(FBody, SBody,world )
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    jointDef = new b2DistanceJointDef();
    Init();
}

DistanceJointModel::~DistanceJointModel()
{
    //dtor
}
DistanceJointModel::Init()
{
    jointDef->Initialize(FBody()->Model()->myBody() ,SBody()->Model()->myBody(),FBody()->Model()->myBody()->GetWorldCenter(),SBody()->Model()->myBody()->GetWorldCenter());
    jointDef->collideConnected = true;
    JointModel::World()->Model()->World().CreateJoint(jointDef);
}
