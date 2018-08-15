#pragma once
#include <Joint/Joint.h>
#include <base.h>
#include <Component/Component.h>
#include <RevoluteJoint/RevoluteJointModel.h>
#include <RevoluteJoint/RevoluteJointViewer.h>
#include <RevoluteJoint/RevoluteJointController.h>

class RevoluteJoint: public Joint
{
    public:
        RevoluteJoint(pRigidBody FBody, pRigidBody SBody , pWorld world);
        ~RevoluteJoint();
        virtual pRevoluteJointModel Model();
        virtual void SetModel(pRevoluteJointModel model);
        virtual pRevoluteJointViewer Viewer();
        virtual void SetViewer(pRevoluteJointViewer viewer);
        virtual pRevoluteJointController Controller();
        virtual void SetController(pRevoluteJointController controller);
    private:

};
