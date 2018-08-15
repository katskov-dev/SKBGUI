#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <RigidBody/RigidBody.h>
#include <World/World.h>

class ColliderModel: public ComponentModel
{
    public:
        ColliderModel(float x, float y,pWorld world);
        virtual ~ColliderModel();
        void SetWorld(pWorld world);
        pWorld getWorld();
        void CreateBody();
        pRigidBody Body();
        void setPositionAfterStep();
        void ApplyMomentum(float dx, float dy);
        void setFixtureDef(b2FixtureDef* getFixtureDef);
        b2FixtureDef* getFixtureDef();
        b2BodyDef* BD();
    protected:

    private:
    pWorld __world;
    pRigidBody __body;
    b2FixtureDef* __fixtureDef;
    b2BodyDef b2BD;


};
