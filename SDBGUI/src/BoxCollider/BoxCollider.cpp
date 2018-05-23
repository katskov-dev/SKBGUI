#include <BoxCollider/BoxCollider.h>


BoxCollider::BoxCollider(pWorld world, double width, double height, std::string type)
{
    SetModel(new BoxColliderModel(world, width, height, type));
    SetViewer(new BoxColliderViewer(Model()));
    SetController(new BoxColliderController(Model()));
}

BoxCollider::~BoxCollider()
{

}

pBoxColliderModel BoxCollider::Model()
{
    return pBoxColliderModel(__model);
}

void BoxCollider::SetModel(pBoxColliderModel model)
{
    __model = model;
}

pBoxColliderViewer BoxCollider::Viewer()
{
    return pBoxColliderViewer(__viewer);
}

void BoxCollider::SetViewer(pBoxColliderViewer viewer)
{
    __viewer = viewer;
}

pBoxColliderController BoxCollider::Controller()
{
    return pBoxColliderController(__controller);
}

void BoxCollider::SetController(pBoxColliderController controller)
{
    __controller = controller;
}

