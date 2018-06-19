#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <World/World.h>

class sensorModel: public ComponentModel
{
    public:
        sensorModel(float x, float y, string type, float r);
        virtual ~sensorModel();
        void setWorld(b2World* myWorld);
        void createBody();
        float getr();
        float getx();
        float gety();
        b2FixtureDef getFixture();
        void setUpContactListener();
    protected:

    private:
    b2World* __world;
    b2Body* __body;
    b2BodyDef bodyDef;
    b2FixtureDef fixtureDef;
    b2CircleShape circleShape;
    float __x,__y,__r;
	friend sensor;
	friend sensorViewer;
	friend sensorController;
    b2ContactListener myContactListener;

};
