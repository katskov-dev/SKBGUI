#pragma once

#include <base.h>
#include <Component/Component.h>
#include <prismaticJoint/prismaticJointModel.h>
#include <prismaticJoint/prismaticJointViewer.h>
#include <prismaticJoint/prismaticJointController.h>

class prismaticJoint: public Component
{
    public:
        prismaticJoint();
        ~prismaticJoint();
        virtual pprismaticJointModel Model();
        virtual void SetModel(pprismaticJointModel model);
        virtual pprismaticJointViewer Viewer();
        virtual void SetViewer(pprismaticJointViewer viewer);
        virtual pprismaticJointController Controller();
        virtual void SetController(pprismaticJointController controller);
    private:

};
