#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Box2D/box2D.h>

class sensorModel;
struct CollisionHandler;
typedef void (*CollisionHandlerFunc)(pCircleColliderModel collider);


class sensorModel: public ComponentModel
{
    public:
        sensorModel(b2World* world,float x, float y, string type, float r);
        virtual ~sensorModel();
        void createBody();
        float getr();
        float getx();
        float gety();
        b2FixtureDef getFixture();
        void setUpContactListener();
        virtual void SetLocalCoord(double x,double y);
        virtual void SetLocalCoord(Vector2f ComCoord);
        void SetOnContact(CollisionHandlerFunc func);
        CollisionHandler* OnContact();
        //virtual void SetAbsoluteCoord(Vector2f ComCoord);

        bool isContact;
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
        //CollisionHandler ch;

};


struct CollisionHandler{
    pCircleColliderModel collider; //сенсор
    psensorModel Sensor; // колайдер
    CollisionHandlerFunc handler;
    CollisionHandler(psensorModel aSensor, CollisionHandlerFunc ahandler)
    {
        collider = nullptr;
        Sensor = aSensor;
        handler = ahandler;

    }
};
