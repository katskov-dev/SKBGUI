#include "RigidBody/RigidBodyModel.h"
#include <Box2D/box2D.h>
#include <World/World.h>

RigidBodyModel::RigidBodyModel(string type,b2BodyDef bodyDef, pWorld world)
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    __type=type;
    __bodyDef= bodyDef;
    if (__type=="dynamic")
    {
        __bodyDef.type = b2_dynamicBody;
        //cout<< __world<< endl<<"w2"<<endl;

    }
    if (__type=="static")
    {
        __bodyDef.type = b2_staticBody;
        //cout<< __world<< endl<<"w2"<<endl;

    }


    __world = world;
    __bodyDef.active = true;
    __body = __world->Model()->GetWorld()->CreateBody(&__bodyDef);




}
b2BodyDef* RigidBodyModel::BodyDef()
{
    return &__bodyDef;
}
string RigidBodyModel::Type()
{
    return __type;
}
pWorld RigidBodyModel::World()
{
    return __world;
}
b2Body* RigidBodyModel::myBody()
{
    return __body;
}
void RigidBodyModel::setBodyDef(b2BodyDef myDef)
{
    __bodyDef=myDef;
}
void RigidBodyModel::setType(string Type)
{
    __type=Type;
}
void RigidBodyModel::setWorld(pWorld settedWorld)
{
    __world=settedWorld;
}
RigidBodyModel::~RigidBodyModel()
{
    //dtor
}
