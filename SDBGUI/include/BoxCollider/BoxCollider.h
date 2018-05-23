#pragma once

#include <base.h>
#include <Component/Component.h>
#include <BoxCollider/BoxColliderModel.h>
#include <BoxCollider/BoxColliderViewer.h>
#include <BoxCollider/BoxColliderController.h>

class BoxCollider: public Component
{
    public:
        BoxCollider(pWorld world, double width, double height, std::string type);
        ~BoxCollider();
        virtual pBoxColliderModel Model();
        virtual void SetModel(pBoxColliderModel model);
        virtual pBoxColliderViewer Viewer();
        virtual void SetViewer(pBoxColliderViewer viewer);
        virtual pBoxColliderController Controller();
        virtual void SetController(pBoxColliderController controller);
    private:

};
