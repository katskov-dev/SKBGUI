#include <DistanceJoint/DistanceJoint.h>


DistanceJoint::DistanceJoint(pRigidBody FBody, pRigidBody SBody , pWorld world):Joint( FBody,  SBody ,  world)
{
    SetModel(new DistanceJointModel(FBody,SBody ,world));
    SetViewer(new DistanceJointViewer(Model()));
    SetController(new DistanceJointController(Model()));
}

DistanceJoint::~DistanceJoint()
{

}

pDistanceJointModel DistanceJoint::Model()
{
    return pDistanceJointModel(__model);
}

void DistanceJoint::SetModel(pDistanceJointModel model)
{
    __model = model;
}

pDistanceJointViewer DistanceJoint::Viewer()
{
    return pDistanceJointViewer(__viewer);
}

void DistanceJoint::SetViewer(pDistanceJointViewer viewer)
{
    __viewer = viewer;
}

pDistanceJointController DistanceJoint::Controller()
{
    return pDistanceJointController(__controller);
}

void DistanceJoint::SetController(pDistanceJointController controller)
{
    __controller = controller;
}

