#include <MyCircle/MyCircle.h>


MyCircle::MyCircle()
{
    SetModel(new MyCircleModel());
    SetViewer(new MyCircleViewer(Model()));
    SetController(new MyCircleController(Model()));
}

MyCircle::~MyCircle()
{

}

pMyCircleModel MyCircle::Model()
{
    return pMyCircleModel(__model);
}

void MyCircle::SetModel(pMyCircleModel model)
{
    __model = model;
}

pMyCircleViewer MyCircle::Viewer()
{
    return pMyCircleViewer(__viewer);
}

void MyCircle::SetViewer(pMyCircleViewer viewer)
{
    __viewer = viewer;
}

pMyCircleController MyCircle::Controller()
{
    return pMyCircleController(__controller);
}

void MyCircle::SetController(pMyCircleController controller)
{
    __controller = controller;
}

