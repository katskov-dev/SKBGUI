#include <Panel/Panel.h>


Panel::Panel()
{
    SetModel(new PanelModel());
    SetViewer(new PanelViewer(Model()));
    SetController(new PanelController(Model()));
}

Panel::~Panel()
{

}

pPanelModel Panel::Model()
{
    return pPanelModel(__model);
}

void Panel::SetModel(pPanelModel model)
{
    __model = model;
}

pPanelViewer Panel::Viewer()
{
    return pPanelViewer(__viewer);
}

void Panel::SetViewer(pPanelViewer viewer)
{
    __viewer = viewer;
}

pPanelController Panel::Controller()
{
    return pPanelController(__controller);
}

void Panel::SetController(pPanelController controller)
{
    __controller = controller;
}

