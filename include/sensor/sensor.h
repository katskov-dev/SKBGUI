#pragma once

#include <base.h>
#include <Component/Component.h>
#include <sensor/sensorModel.h>
#include <sensor/sensorViewer.h>
#include <sensor/sensorController.h>

class sensor: public Component
{
    public:
        sensor(b2World* world, float x, float y, string type, float r);
        ~sensor();
        virtual psensorModel Model();
        virtual void SetModel(psensorModel model);
        virtual psensorViewer Viewer();
        virtual void SetViewer(psensorViewer viewer);
        virtual psensorController Controller();
        virtual void SetController(psensorController controller);

    private:

};
