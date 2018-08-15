#include <sensor/sensor.h>


sensor::sensor(b2World* world, float x, float y, string type, float r)
{
    SetModel(new sensorModel(world, x,y,type, r));
    SetViewer(new sensorViewer(Model()));
    SetController(new sensorController(Model()));

}

sensor::~sensor()
{

}

psensorModel sensor::Model()
{
    return psensorModel(__model);
}

void sensor::SetModel(psensorModel model)
{
    __model = model;
}

psensorViewer sensor::Viewer()
{
    return psensorViewer(__viewer);
}

void sensor::SetViewer(psensorViewer viewer)
{
    __viewer = viewer;
}

psensorController sensor::Controller()
{
    return psensorController(__controller);
}

void sensor::SetController(psensorController controller)
{
    __controller = controller;
}

