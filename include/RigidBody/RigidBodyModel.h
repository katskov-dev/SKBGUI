#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Box2D/box2D.h>
#include <World/World.h>

class RigidBodyModel: public ComponentModel
{
    public:
        RigidBodyModel(string type, b2BodyDef bodyDef, pWorld world);
        virtual ~RigidBodyModel();
        b2BodyDef* BodyDef();
        string Type();
        pWorld World();
        b2Body* myBody();
        void setBodyDef(b2BodyDef myDef);
        void setType(string Type);
        void setWorld(pWorld settedWorld);

    protected:

    private:
    string __type;
    pWorld __world;
    b2Body* __body;
    b2BodyDef __bodyDef;
	friend RigidBody;
	friend RigidBodyViewer;
	friend RigidBodyController;

};
