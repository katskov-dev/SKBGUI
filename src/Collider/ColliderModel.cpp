#include "Collider/ColliderModel.h"

ColliderModel::ColliderModel(float x, float y, pWorld world): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    b2BD.position.Set(x,y);
    __world =world;
    __body = new RigidBody("dynamic",b2BD,__world); // !!! тип тела не должен быть хардкодом
    __fixtureDef = nullptr;
    __fixtureDef = new b2FixtureDef();
}

ColliderModel::~ColliderModel()
{
    //dtor
}
void ColliderModel::SetWorld(pWorld world)
{
    __world=world;
}
pWorld ColliderModel::getWorld()
{
    return __world;
}
pRigidBody ColliderModel::Body()
{
    return __body;
}
b2FixtureDef* ColliderModel::getFixtureDef()
{
    return __fixtureDef;
}
void ColliderModel::setFixtureDef(b2FixtureDef* fixture)
{
    __fixtureDef=fixture;
}
b2BodyDef* ColliderModel::BD()
{
    return  &b2BD;
}

