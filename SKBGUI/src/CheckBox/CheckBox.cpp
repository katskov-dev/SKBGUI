#include <CheckBox/CheckBox.h>
#include <math.h>

CheckBox::CheckBox()
{
    SetModel(new CheckBoxModel());
    SetViewer(new CheckBoxViewer(Model()));
    SetController(new CheckBoxController(Model()));
}

CheckBox::~CheckBox()
{

}

pCheckBoxModel CheckBox::Model()
{
    return pCheckBoxModel(__model);
}

void CheckBox::SetModel(pCheckBoxModel model)
{
    __model = model;
}

pCheckBoxViewer CheckBox::Viewer()
{
    return pCheckBoxViewer(__viewer);
}

void CheckBox::SetViewer(pCheckBoxViewer viewer)
{
    __viewer = viewer;
}

pCheckBoxController CheckBox::Controller()
{
    return pCheckBoxController(__controller);
}

void CheckBox::SetController(pCheckBoxController controller)
{
    __controller = controller;
}

