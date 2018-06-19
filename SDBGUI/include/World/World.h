#pragma once

#include <base.h>
#include <Component/Component.h>
#include <World/WorldModel.h>
#include <World/WorldViewer.h>
#include <World/WorldController.h>

class World: public Component
{
    public:
        World();
        ~World();
        virtual pWorldModel Model();
        virtual void SetModel(pWorldModel model);
        virtual pWorldViewer Viewer();
        virtual void SetViewer(pWorldViewer viewer);
        virtual pWorldController Controller();
        virtual void SetController(pWorldController controller);
    private:

};

