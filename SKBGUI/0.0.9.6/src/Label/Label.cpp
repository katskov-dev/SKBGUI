#include "Label/Label.h"

Label::Label()
{
    __model = new LabelModel();
    __viewer = new LabelViewer(pLabelModel(__model));
    __controller = new LabelController(pLabelModel(__model));
}

Label::~Label()
{
    //dtor
}

pLabelModel Label::Model()
{
    return pLabelModel(__model);
}

void Label::SetModel(pLabelModel model)
{
    __model = model;
}

pLabelViewer Label::Viewer()
{
    return pLabelViewer(__viewer);
}

void Label::SetViewer(pLabelViewer viewer)
{
    __viewer = viewer;
}

pLabelController Label::Controller()
{
    return pLabelController(__controller);
}

void Label::SetController(pLabelController controller)
{
    __controller = controller;
}

