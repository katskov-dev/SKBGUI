#include "Joint/JointModel.h"
#include <Box2D/box2D.h>
#include <World/World.h>
JointModel::JointModel(pRigidBody FBody, pRigidBody SBody, pWorld world): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    __FBody=FBody;
    __SBody=SBody;
    __World=world;

}
void JointModel:: Destroy()
{

}
void JointModel:: Init(b2Vec2 AnchorOne, b2Vec2 AnchorTwo)
{

}
pWorld JointModel:: World()
{
    return __World;
}
pRigidBody JointModel::FBody()
{
    return __FBody;
}
pRigidBody JointModel::SBody()
{
    return __SBody;
}
JointModel::~JointModel()
{
    //dtor
}
