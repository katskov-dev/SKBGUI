#include <prismaticJoint/prismaticJoint.h>


prismaticJoint::prismaticJoint()
{
    SetModel(new prismaticJointModel());
    SetViewer(new prismaticJointViewer(Model()));
    SetController(new prismaticJointController(Model()));
}

prismaticJoint::~prismaticJoint()
{

}

pprismaticJointModel prismaticJoint::Model()
{
    return pprismaticJointModel(__model);
}

void prismaticJoint::SetModel(pprismaticJointModel model)
{
    __model = model;
}

pprismaticJointViewer prismaticJoint::Viewer()
{
    return pprismaticJointViewer(__viewer);
}

void prismaticJoint::SetViewer(pprismaticJointViewer viewer)
{
    __viewer = viewer;
}

pprismaticJointController prismaticJoint::Controller()
{
    return pprismaticJointController(__controller);
}

void prismaticJoint::SetController(pprismaticJointController controller)
{
    __controller = controller;
}

