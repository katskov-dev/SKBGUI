#pragma once

#include <base.h>
#include <Component/Component.h>
#include <DistanceJoint/DistanceJointModel.h>
#include <DistanceJoint/DistanceJointViewer.h>
#include <DistanceJoint/DistanceJointController.h>
#include <Joint/Joint.h>
class DistanceJoint: public Joint
{
    public:
        DistanceJoint(pRigidBody FBody, pRigidBody SBody , pWorld world);
        ~DistanceJoint();
        virtual pDistanceJointModel Model();
        virtual void SetModel(pDistanceJointModel model);
        virtual pDistanceJointViewer Viewer();
        virtual void SetViewer(pDistanceJointViewer viewer);
        virtual pDistanceJointController Controller();
        virtual void SetController(pDistanceJointController controller);
    private:

};
