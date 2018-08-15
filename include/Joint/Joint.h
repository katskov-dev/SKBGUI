#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Joint/JointModel.h>
#include <Joint/JointViewer.h>
#include <Joint/JointController.h>
#include <Box2D/box2D.h>
#include <World/World.h>
class Joint: public Component
{
    public:
        Joint(pRigidBody FBody, pRigidBody SBody, pWorld world);
        ~Joint();
        virtual pJointModel Model();
        virtual void SetModel(pJointModel model);
        virtual pJointViewer Viewer();
        virtual void SetViewer(pJointViewer viewer);
        virtual pJointController Controller();
        virtual void SetController(pJointController controller);
    private:

};
