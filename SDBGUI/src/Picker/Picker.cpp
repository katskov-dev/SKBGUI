#include <Picker/Picker.h>


Picker::Picker()
{
    SetModel(new PickerModel());
    SetViewer(new PickerViewer(Model()));
    SetController(new PickerController(Model()));
}

Picker::~Picker()
{

}

pPickerModel Picker::Model()
{
    return pPickerModel(__model);
}

void Picker::SetModel(pPickerModel model)
{
    __model = model;
}

pPickerViewer Picker::Viewer()
{
    return pPickerViewer(__viewer);
}

void Picker::SetViewer(pPickerViewer viewer)
{
    __viewer = viewer;
}

pPickerController Picker::Controller()
{
    return pPickerController(__controller);
}

void Picker::SetController(pPickerController controller)
{
    __controller = controller;
}

