#include <RigidBody/RigidBody.h>
#include <Box2D/box2D.h>
#include <World/World.h>

RigidBody::RigidBody(string type, b2BodyDef bodyDef, pWorld world)
{
    SetModel(new RigidBodyModel(type, bodyDef, world));
    SetViewer(new RigidBodyViewer(Model()));
    SetController(new RigidBodyController(Model()));
}

RigidBody::~RigidBody()
{

}

pRigidBodyModel RigidBody::Model()
{
    return pRigidBodyModel(__model);
}

void RigidBody::SetModel(pRigidBodyModel model)
{
    __model = model;
}

pRigidBodyViewer RigidBody::Viewer()
{
    return pRigidBodyViewer(__viewer);
}

void RigidBody::SetViewer(pRigidBodyViewer viewer)
{
    __viewer = viewer;
}

pRigidBodyController RigidBody::Controller()
{
    return pRigidBodyController(__controller);
}

void RigidBody::SetController(pRigidBodyController controller)
{
    __controller = controller;
}

