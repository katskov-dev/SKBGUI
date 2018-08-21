#include <Collider/Collider.h>


Collider::Collider(float x, float y, pWorld world,string type)
{
//    SetModel(new ColliderModel(x,y,world));
//    SetViewer(new ColliderViewer(Model()));
//    SetController(new ColliderController(Model()));
}

Collider::~Collider()
{

}

pColliderModel Collider::Model()
{
    return pColliderModel(__model);
}

void Collider::SetModel(pColliderModel model)
{
    __model = model;
}

pColliderViewer Collider::Viewer()
{
    return pColliderViewer(__viewer);
}

void Collider::SetViewer(pColliderViewer viewer)
{
    __viewer = viewer;
}

pColliderController Collider::Controller()
{
    return pColliderController(__controller);
}

void Collider::SetController(pColliderController controller)
{
    __controller = controller;
}

