#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Box2D/box2D.h>

class WorldModel: public ComponentModel
{
    public:
        WorldModel();
        virtual ~WorldModel();
        b2World World();
        virtual void Add(pCircleCollider child);
        virtual void Add(pBoxCollider child);
        void Step();
        void SetTime(float32 Time);
        void SetVelocity(float32 Velocity);
        void SetIterations(float32 Iterations);
        b2World* GetWorld();


    protected:

    private:
        b2World* __world;
        float32 __timeStep;
        float32 __velocityIterations;
        float32 __positionIterations;

};
