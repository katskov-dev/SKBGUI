#include <Joint/Joint.h>
#include <Box2D/box2D.h>
#include <World/World.h>

Joint::Joint(pRigidBody FBody, pRigidBody SBody , pWorld world)
{
//    SetModel(new JointModel(FBody, SBody, world));
//    SetViewer(new JointViewer(Model()));
//    SetController(new JointController(Model()));
}

Joint::~Joint()
{

}

pJointModel Joint::Model()
{
    return pJointModel(__model);
}

void Joint::SetModel(pJointModel model)
{
    __model = model;
}

pJointViewer Joint::Viewer()
{
    return pJointViewer(__viewer);
}

void Joint::SetViewer(pJointViewer viewer)
{
    __viewer = viewer;
}

pJointController Joint::Controller()
{
    return pJointController(__controller);
}

void Joint::SetController(pJointController controller)
{
    __controller = controller;
}

