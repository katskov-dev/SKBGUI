#include <World/World.h>


World::World()
{
    SetModel(new WorldModel());
    SetViewer(new WorldViewer(Model()));
    SetController(new WorldController(Model()));
}

World::~World()
{

}

pWorldModel World::Model()
{
    return pWorldModel(__model);
}

void World::SetModel(pWorldModel model)
{
    __model = model;
}

pWorldViewer World::Viewer()
{
    return pWorldViewer(__viewer);
}

void World::SetViewer(pWorldViewer viewer)
{
    __viewer = viewer;
}

pWorldController World::Controller()
{
    return pWorldController(__controller);
}

void World::SetController(pWorldController controller)
{
    __controller = controller;
}

