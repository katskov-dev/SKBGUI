#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Box2D/box2D.h>
#include <sensor/sensorModel.h>

class MyContactListener : public b2ContactListener
  {

    void BeginContact(b2Contact* contact) {

    if ((contact->GetFixtureA()->IsSensor()||contact->GetFixtureB()->IsSensor()))
        {
            if (contact->GetFixtureA()->IsSensor()){
                pCircleColliderModel col = pCircleColliderModel(contact->GetFixtureB()->GetUserData());

                //cout << "Begin" << endl;
                CollisionHandler* ch = (CollisionHandler*)contact->GetFixtureA()->GetBody()->GetUserData();
                ch->Sensor->isContact = true;
                ch->collider = col;
            }
        }
    }

    void EndContact(b2Contact* contact) {
        if ((contact->GetFixtureA()->IsSensor()||contact->GetFixtureB()->IsSensor()))
        {
            //cout << "End" << endl;
        }
    }
  };



class WorldModel: public ComponentModel
{
    public:
        WorldModel();
        virtual ~WorldModel();
        b2World& World();
        virtual void Add(pCircleCollider child);
        virtual void Add(pBoxCollider child);
        void Step();
        void SetTime(float32 Time);
        void SetVelocity(float32 Velocity);
        void SetIterations(float32 Iterations);
        b2World* GetWorld();
        void createGroundBody();
        void setUpEdit(pEdit edit);
        pEdit getEdit();
    protected:

    private:
        b2World* __world;
        float32 __timeStep;
        float32 __velocityIterations;
        float32 __positionIterations;
        b2BodyDef groundBodyDef;
        b2PolygonShape groundBox;
        b2Body* groundBody;
        pEdit myQuantEdit;
        int Quant;
        MyContactListener contactListener;
};
