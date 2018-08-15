#include "RevoluteJoint/RevoluteJointModel.h"
#include <Joint/JointModel.h>
RevoluteJointModel::RevoluteJointModel(pRigidBody first, pRigidBody second, pWorld World) :JointModel(first,second,World)
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    jointDef = new b2RevoluteJointDef();
    Init();

}
RevoluteJointModel::Init()//:Init(AnchorOne,AnchorTwo)
{
    jointDef->Initialize(JointModel::FBody()->Model()->myBody() ,JointModel::SBody()->Model()->myBody(),JointModel::FBody()->Model()->myBody()->GetWorldCenter());
    jointDef->collideConnected = false;
    JointModel::World()->Model()->World().CreateJoint(jointDef);
}
RevoluteJointModel::~RevoluteJointModel()
{
    //dtor
}
