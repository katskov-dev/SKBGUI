#include <CircleCollider/CircleCollider.h>


CircleCollider::CircleCollider(pWorld world, double radius, std::string type)
{
    SetModel(new CircleColliderModel(world, radius, type));
    SetViewer(new CircleColliderViewer(Model()));
    SetController(new CircleColliderController(Model()));
}

CircleCollider::~CircleCollider()
{

}

pCircleColliderModel CircleCollider::Model()
{
    return pCircleColliderModel(__model);
}

void CircleCollider::SetModel(pCircleColliderModel model)
{
    __model = model;
}

pCircleColliderViewer CircleCollider::Viewer()
{
    return pCircleColliderViewer(__viewer);
}

void CircleCollider::SetViewer(pCircleColliderViewer viewer)
{
    __viewer = viewer;
}

pCircleColliderController CircleCollider::Controller()
{
    return pCircleColliderController(__controller);
}

void CircleCollider::SetController(pCircleColliderController controller)
{
    __controller = controller;
}

