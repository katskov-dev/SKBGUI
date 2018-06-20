#include "BoxCollider/BoxColliderModel.h"

BoxColliderModel::BoxColliderModel(pWorld world, double width, double height, std::string type): ComponentModel()
{
    SetSize(width , height);
    __type = type;
    __world = world->Model()->GetWorld();
    CreateBody();
    SetLocalCoord(0, 0);
    SetAngle(0);

}

BoxColliderModel::~BoxColliderModel()
{
    //dtor
}

void BoxColliderModel::SetLocalCoord(double x,double y)
{
    ComponentModel::SetLocalCoord(x , y);
    __body->SetTransform(b2Vec2(x + Size().x / 2.0, y  + Size().y / 2.0), __body->GetAngle());
}
void BoxColliderModel::SetLocalCoord(Vector2f ComCoord)
{
    ComponentModel::SetLocalCoord(ComCoord );
    __body->SetTransform(b2Vec2(ComCoord.x  + Size().x / 2.0, ComCoord.y  + Size().y / 2.0), __body->GetAngle());
}



b2Body* BoxColliderModel::Body()
{
    return __body;
}

void BoxColliderModel::setPositionAfterStep()
{
    b2Vec2 position = __body->GetPosition();
    SetLocalCoord(position.x  - Size().x / 2.0, position.y - Size().y / 2.0);
    SetAngle(__body->GetAngle());
}
double BoxColliderModel::Angle()
{
    return Body()->GetAngle();
}





void BoxColliderModel::SetAngle(double angle)
{
    Body()->SetTransform(Body()->GetPosition(), angle);
}

void BoxColliderModel::SetWorld(b2World* world)
{
    __world = world;


}
void BoxColliderModel::CreateBody()
{
    b2BodyDef bodyDef;
    if (__type == "dynamic")
        bodyDef.type = b2_dynamicBody;
    else
    if (__type == "static")
        bodyDef.type = b2_staticBody;
    else
        return;
    bodyDef.position.Set(LocalCoord().x,LocalCoord().y);

    __body = __world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;

    dynamicBox.SetAsBox(Size().x / 2.0, Size().y / 2.0);
    b2MassData mass;
    mass.center = b2Vec2(LocalCoord().x,LocalCoord().y);
    mass.I = 0.0;
    mass.mass = 10000.0;
    __body->SetMassData(&mass);




    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 0.5f;
    fixtureDef.friction = 1.0f;
    __body->CreateFixture(&fixtureDef);

}



