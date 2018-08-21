#include <WeldJoint/WeldJoint.h>
#include <Joint/Joint.h>

WeldJoint::WeldJoint(pRigidBody FBody,pRigidBody SBody,pWorld world):Joint(FBody,SBody, world)
{
//    SetModel(new WeldJointModel());
//    SetViewer(new WeldJointViewer(Model()));
//    SetController(new WeldJointController(Model()));
}

WeldJoint::~WeldJoint()
{

}

pWeldJointModel WeldJoint::Model()
{
    return pWeldJointModel(__model);
}

void WeldJoint::SetModel(pWeldJointModel model)
{
    __model = model;
}

pWeldJointViewer WeldJoint::Viewer()
{
    return pWeldJointViewer(__viewer);
}

void WeldJoint::SetViewer(pWeldJointViewer viewer)
{
    __viewer = viewer;
}

pWeldJointController WeldJoint::Controller()
{
    return pWeldJointController(__controller);
}

void WeldJoint::SetController(pWeldJointController controller)
{
    __controller = controller;
}

