#pragma once

#include <base.h>
#include <Component/Component.h>
#include <CircleCollider/CircleColliderModel.h>
#include <CircleCollider/CircleColliderViewer.h>
#include <CircleCollider/CircleColliderController.h>

class CircleCollider: public Component
{
    public:
        CircleCollider(pWorld world, double radius, std::string type);
        ~CircleCollider();
        virtual pCircleColliderModel Model();
        virtual void SetModel(pCircleColliderModel model);
        virtual pCircleColliderViewer Viewer();
        virtual void SetViewer(pCircleColliderViewer viewer);
        virtual pCircleColliderController Controller();
        virtual void SetController(pCircleColliderController controller);
    private:

};
