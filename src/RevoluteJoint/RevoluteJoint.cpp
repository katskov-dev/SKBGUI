#include <RevoluteJoint/RevoluteJoint.h>
#include <Joint/Joint.h>

RevoluteJoint::RevoluteJoint(pRigidBody FBody,pRigidBody SBody,pWorld world):Joint(FBody,SBody, world)
{
//    SetModel(new RevoluteJointModel(FBody,SBody,world));
//
//    SetViewer(new RevoluteJointViewer(Model()));
//    SetController(new RevoluteJointController(Model()));
}

RevoluteJoint::~RevoluteJoint()
{

}

pRevoluteJointModel RevoluteJoint::Model()
{
    return pRevoluteJointModel(__model);
}

void RevoluteJoint::SetModel(pRevoluteJointModel model)
{
    __model = model;
}

pRevoluteJointViewer RevoluteJoint::Viewer()
{
    return pRevoluteJointViewer(__viewer);
}

void RevoluteJoint::SetViewer(pRevoluteJointViewer viewer)
{
    __viewer = viewer;
}

pRevoluteJointController RevoluteJoint::Controller()
{
    return pRevoluteJointController(__controller);
}

void RevoluteJoint::SetController(pRevoluteJointController controller)
{
    __controller = controller;
}

