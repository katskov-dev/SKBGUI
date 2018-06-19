#include "sensor/sensorModel.h"
#include <Box2D.h>
sensorModel::sensorModel(float x, float y, string type, float r): ComponentModel()
{

    bodyDef.position.Set(x,y);
    SetLocalCoord(x, y);
    SetSize(2*r, 2*r);
    SetVisibleBorders(true);
    circleShape.m_radius = r;
    circleShape.m_p.Set(0, 0);
    fixtureDef.shape = &circleShape;
    fixtureDef.isSensor=true;
    fixtureDef.userData = this;


//    fixtureDef.filter.categoryBits = 0x04; //закоментировать?
//    fixtureDef.filter.maskBits = 0xffff;

    __x=x;
    __y=y;
    __r=r;
}
void sensorModel::setWorld(b2World* myWorld)
{
    __world = myWorld;
}
float sensorModel::getr()
{
    return __r;
}
float sensorModel::getx()
{
    return __x;
}
float sensorModel::gety()
{
    return __y;
}
void sensorModel::createBody()
{
    __body = __world->CreateBody(&bodyDef);

    __body->CreateFixture(&fixtureDef);
}
b2FixtureDef sensorModel::getFixture()
{
    return fixtureDef;
}

sensorModel::~sensorModel()
{
    //dtor
}
