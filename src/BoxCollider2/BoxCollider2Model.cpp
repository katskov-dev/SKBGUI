#include "BoxCollider2/BoxCollider2Model.h"

BoxCollider2Model::BoxCollider2Model(float x, float y,float weight, float height, pWorld World, string type): ColliderModel(x,y,World)
{
    SetLocalCoord(x, y);
    SetSize(weight, height);
    SetVisibleBorders(false);
    SetAngle(0);
    __dynamicBox.SetAsBox(Size().x / 2.0, Size().y / 2.0);
    ColliderModel::getFixtureDef()->shape = &__dynamicBox;
    ColliderModel::getFixtureDef()->density = 0.3f;
    ColliderModel::getFixtureDef()->friction = 0.1f;
    Body()->Model()->myBody()->CreateFixture(ColliderModel::getFixtureDef());
//    b2MassData mass;
//    mass.center = b2Vec2(LocalCoord().x,LocalCoord().y);
//    mass.I = 0.0;
//    mass.mass = 10000.0;
//    Body()->Model()->myBody()->SetMassData(&mass);
    cout << ":"<<World << endl<< "w1"<<endl;
    cout << "ebanyi addres is: "<<Body()->Model()->myBody()<<endl;
    cout << "ebanyi addres2 is: "<<ColliderModel::Body()->Model()->myBody()<<endl;
}

BoxCollider2Model::~BoxCollider2Model()
{
    //dtor
}
void BoxCollider2Model::CreateBody()
{


}
void BoxCollider2Model::SetLocalCoord(double x,double y)
{
    ComponentModel::SetLocalCoord(x , y);
    Body()->Model()->myBody()->SetTransform(b2Vec2(x + Size().x / 2.0, y  + Size().y / 2.0), Body()->Model()->myBody()->GetAngle());
}
void BoxCollider2Model::setPositionAfterStep()
{
    b2Vec2 position = Body()->Model()->myBody()->GetPosition();
//    cout << Body()->Model()->BodyDef()->position.x << endl<< Body()->Model()->BodyDef()->position.y<<endl;
    //Body()->Model()->myBody()->SetTransform()
//    Body()->Model()->myBody()->SetTransform(b2Vec2(position.x + Size().x / 2.0, position.y  + Size().y / 2.0), Body()->Model()->myBody()->GetAngle());
//    cout << Body()->Model()->myBody()->GetPosition().x << endl << Body()->Model()->myBody()->GetPosition().y<< endl;
    SetLocalCoord(position.x  - Size().x / 2.0, position.y - Size().y / 2.0);
    SetAngle(Body()->Model()->myBody()->GetAngle());
    //Body()->Model()->myBody()->SetTransform(position, angle);
    //ApplyMomentum(0,10000000);
//    SetAngle(Body()->Model()->myBody()->GetAngle());

}
void BoxCollider2Model::ApplyMomentum(float dx, float dy)
{
    Body()->Model()->myBody()->ApplyLinearImpulse(b2Vec2(dx,dy), Body()->Model()->myBody()->GetWorldCenter(),true );
}
