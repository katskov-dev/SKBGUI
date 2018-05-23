#include <Arrow/Arrow.h>


Arrow::Arrow(pComponent start, pComponent end)
{
    SetModel(new ArrowModel(start, end));
    SetViewer(new ArrowViewer(Model()));
    SetController(new ArrowController(Model()));
}

Arrow::~Arrow()
{

}

pArrowModel Arrow::Model()
{
    return pArrowModel(__model);
}

void Arrow::SetModel(pArrowModel model)
{
    __model = model;
}

pArrowViewer Arrow::Viewer()
{
    return pArrowViewer(__viewer);
}

void Arrow::SetViewer(pArrowViewer viewer)
{
    __viewer = viewer;
}

pArrowController Arrow::Controller()
{
    return pArrowController(__controller);
}

void Arrow::SetController(pArrowController controller)
{
    __controller = controller;
}

