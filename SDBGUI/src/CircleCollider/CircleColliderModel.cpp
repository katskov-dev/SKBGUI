#include <CircleCollider/CircleColliderModel.h>
#include <Box2D/box2D.h>
#include <World/World.h>
#include <CircleCollider/CircleCollider.h>




CircleColliderModel::CircleColliderModel(pWorld world, double radius, std::string type): ComponentModel()
{
    SetR(radius);
    __type = type;
    __world = world->Model()->GetWorld();
    CreateBody();
    SetSize(2*R(), 2*R());
    SetLocalCoord(0, 0);
    SetAngle(0);
    SetVisibleBorders(true);
    std::cout << Body()->GetPosition().x << " " << Body()->GetPosition().y << std::endl;
}

CircleColliderModel::~CircleColliderModel()
{

   __world->DestroyBody(__body);
}


void CircleColliderModel::SetLocalCoord(double x,double y)
{
    ComponentModel::SetLocalCoord(x, y);
    __body->SetTransform(b2Vec2(x + R(), y  + R()), __body->GetAngle());
}
void CircleColliderModel::SetLocalCoord(Vector2f ComCoord)
{
    ComponentModel::SetLocalCoord(ComCoord);
    __body->SetTransform(b2Vec2(ComCoord.x  + R(), ComCoord.y  + R()), __body->GetAngle());
}



b2Body* CircleColliderModel::Body()
{
    return __body;
}
double CircleColliderModel::R()
{
    return __r;
}
void CircleColliderModel::setPositionAfterStep()
{
    b2Vec2 position = __body->GetPosition();
    SetLocalCoord(position.x  - R(), position.y - R());
    SetAngle(__body->GetAngle());
}
double CircleColliderModel::Angle()
{
    return Body()->GetAngle();
}



void CircleColliderModel::SetR(double r)
{
    __r = r;
}

void CircleColliderModel::SetAngle(double angle)
{
    Body()->SetTransform(Body()->GetPosition(), angle);
}

sf::Vector2f CircleColliderModel::GetCenter()
{
    b2Vec2 pos = Body()->GetPosition();
    return sf::Vector2f(pos.x, pos.y);
}

void CircleColliderModel::SetWorld(b2World* world)
{
    __world = world;


}
void CircleColliderModel::CreateBody()
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
    b2MassData mass;
    mass.center = b2Vec2(0,0);
    mass.I = 0.0;
    mass.mass = 1.0;
    __body->SetMassData(&mass);
//    b2PolygonShape dynamicBox;
//    dynamicBox.SetAsBox(Size().x / 2.0,Size().y / 2.0);

    b2CircleShape circleShape;
    circleShape.m_p.Set(0, 0); //position, relative to body position
    circleShape.m_radius = R(); //radius


    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.1f;
    fixtureDef.friction = 0.3f;
    fixtureDef.userData = this;
    cout << "CC_ADDR: " << (void*)this << endl;
    __body->CreateFixture(&fixtureDef);

}



