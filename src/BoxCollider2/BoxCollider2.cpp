#include <BoxCollider2/BoxCollider2.h>


BoxCollider2::BoxCollider2(float x, float y,float weight, float height, pWorld World, string type):Collider(x,y,World, type)
{
    SetModel(new BoxCollider2Model(x,y,weight,height,World,type));
    SetViewer(new BoxCollider2Viewer(Model()));
    SetController(new BoxCollider2Controller(Model()));
}

BoxCollider2::~BoxCollider2()
{

}

pBoxCollider2Model BoxCollider2::Model()
{
    return pBoxCollider2Model(__model);
}

void BoxCollider2::SetModel(pBoxCollider2Model model)
{
    __model = model;
}

pBoxCollider2Viewer BoxCollider2::Viewer()
{
    return pBoxCollider2Viewer(__viewer);
}

void BoxCollider2::SetViewer(pBoxCollider2Viewer viewer)
{
    __viewer = viewer;
}

pBoxCollider2Controller BoxCollider2::Controller()
{
    return pBoxCollider2Controller(__controller);
}

void BoxCollider2::SetController(pBoxCollider2Controller controller)
{
    __controller = controller;
}

