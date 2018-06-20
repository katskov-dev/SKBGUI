#include "sensor/sensorModel.h"
#include <Box2D.h>
sensorModel::sensorModel(b2World* world,float x, float y, string type, float r): ComponentModel()
{
    __x=x;
    __y=y;
    __r=r;
    bodyDef.position.Set(x,y);
    __world = world;
    SetVisibleBorders(true);
    circleShape.m_radius = r;
    circleShape.m_p.Set(0, 0);
    fixtureDef.shape = &circleShape;
    fixtureDef.isSensor=true;
    fixtureDef.userData = nullptr;
    createBody();
    SetSize(2*r, 2*r);
    isContact = false;

    SetLocalCoord(x, y);



//    fixtureDef.filter.categoryBits = 0x04; //закоментировать?
//    fixtureDef.filter.maskBits = 0xffff;


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

void sensorModel::SetLocalCoord(double x,double y)
{
    ComponentModel::SetLocalCoord(x, y);

    __body->SetTransform(b2Vec2(x + __r, y  + __r ), __body->GetAngle());
}
void sensorModel::SetLocalCoord(Vector2f ComCoord)
{
    ComponentModel::SetLocalCoord(ComCoord);
    __body->SetTransform(b2Vec2(ComCoord.x  + __r , ComCoord.y  + __r ), __body->GetAngle());
}

void sensorModel::SetAbsoluteCoord(Vector2f ComCoord)
{
    ComponentModel::SetAbsoluteCoord(ComCoord);
    sf::Vector2f cc = LocalCoord();
    __body->SetTransform(b2Vec2(cc.x  + __r, cc.y  + __r), __body->GetAngle());
}

void sensorModel::SetOnContact(CollisionHandlerFunc func)
{
    if (OnContact() != nullptr){
        delete OnContact();
    }
    CollisionHandler* ch = new CollisionHandler(this, func);
    __body->SetUserData((void*)ch);
   // cout << "CH_ADDR: " << (void*)ch << endl;
}

CollisionHandler* sensorModel::OnContact()
{
    return (CollisionHandler*)__body->GetUserData();
}

void sensorModel::setPositionAfterStep()
{
    b2Vec2 position = __body->GetPosition();
    //SetAngle(__body->GetAngle());
    SetLocalCoord(position.x  - __r, position.y - __r);

}
