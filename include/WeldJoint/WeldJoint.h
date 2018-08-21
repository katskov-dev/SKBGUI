#pragma once

#include <base.h>
#include <Component/Component.h>
#include <WeldJoint/WeldJointModel.h>
#include <WeldJoint/WeldJointViewer.h>
#include <WeldJoint/WeldJointController.h>
#include <Joint/Joint.h>
class WeldJoint: public Joint
{
    public:
        WeldJoint(pRigidBody FBody,pRigidBody SBody,pWorld world);
        ~WeldJoint();
        virtual pWeldJointModel Model();
        virtual void SetModel(pWeldJointModel model);
        virtual pWeldJointViewer Viewer();
        virtual void SetViewer(pWeldJointViewer viewer);
        virtual pWeldJointController Controller();
        virtual void SetController(pWeldJointController controller);
    private:

};
