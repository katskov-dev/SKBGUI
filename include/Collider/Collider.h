#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Collider/ColliderModel.h>
#include <Collider/ColliderViewer.h>
#include <Collider/ColliderController.h>

class Collider: public Component
{
    public:
        Collider(float x, float y ,pWorld world);
        ~Collider();
        virtual pColliderModel Model();
        virtual void SetModel(pColliderModel model);
        virtual pColliderViewer Viewer();
        virtual void SetViewer(pColliderViewer viewer);
        virtual pColliderController Controller();
        virtual void SetController(pColliderController controller);
    private:

};
