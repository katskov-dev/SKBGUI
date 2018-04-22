#include "Edit/Edit.h"

Edit::Edit()
{
    __model = new EditModel();
    __viewer = new EditViewer(pEditModel(__model));
    __controller = new EditController(pEditModel(__model));
}

Edit::~Edit()
{
    //dtor
}

pEditModel Edit::Model()
{
    return pEditModel(__model);
}

void Edit::SetModel(pEditModel model)
{
    __model = model;
}

pEditViewer Edit::Viewer()
{
    return pEditViewer(__viewer);
}

void Edit::SetViewer(pEditViewer viewer)
{
    __viewer = viewer;
}

pEditController Edit::Controller()
{
    return pEditController(__controller);
}

void Edit::SetController(pEditController controller)
{
    __controller = controller;
}

