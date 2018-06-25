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

pBoxCollider BoxCollider::FastCreate(pComponent parent, pWorld world, sf::Vector2f size, std::string type, sf::Vector2f localcoord)
{
    pBoxCollider col;
    col = new BoxCollider(world, size.x, size.y, type);
    col->Model()->SetLocalCoord(localcoord);
    if (parent != nullptr){
        parent->Model()->Add(col);
    }
    return col;
}
