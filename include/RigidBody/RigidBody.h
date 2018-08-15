#pragma once
#include <Box2D/box2D.h>
#include <World/World.h>
#include <base.h>
#include <Component/Component.h>
#include <RigidBody/RigidBodyModel.h>
#include <RigidBody/RigidBodyViewer.h>
#include <RigidBody/RigidBodyController.h>

class RigidBody: public Component
{
    public:
        RigidBody(string type, b2BodyDef bodyDef, pWorld world);
        ~RigidBody();
        virtual pRigidBodyModel Model();
        virtual void SetModel(pRigidBodyModel model);
        virtual pRigidBodyViewer Viewer();
        virtual void SetViewer(pRigidBodyViewer viewer);
        virtual pRigidBodyController Controller();
        virtual void SetController(pRigidBodyController controller);
    private:

};
