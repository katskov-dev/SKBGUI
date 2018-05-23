#include "Component/Component.h"

Component::Component()
{
    __model = new ComponentModel();
    __model->SetOwner(this);
    __viewer = new ComponentViewer(__model);
    __controller = new ComponentController(__model);

}

Component::~Component()
{
    delete __controller;
    delete __viewer;
    delete __model;
}

pComponentModel Component::Model()
{
    return __model;
}

void Component::SetModel(pComponentModel model)
{
    __model = model;
}

pComponentViewer Component::Viewer()
{
    return __viewer;
}

void Component::SetViewer(pComponentViewer viewer)
{
    __viewer = viewer;
}

pComponentController Component::Controller()
{
    return __controller;
}

void Component::SetController(pComponentController controller)
{
    __controller = controller;
}
