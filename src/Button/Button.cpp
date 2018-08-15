#include "Button/Button.h"

Button::Button()
{
    //create MVC

    __model = new ButtonModel();
    __viewer = new ButtonViewer(pButtonModel(__model));
    __controller = new ButtonController(pButtonModel(__model));
    //
    __model->SetLocalCoord(0, 0);
    __model->SetSize(150, 40);
    pButtonModel(__model)->SetCaption("Button");


}


Button::Button(string caption)
{
    //create MVC
    __model = new ButtonModel();
    __viewer = new ButtonViewer(pButtonModel(__model));
    __controller = new ButtonController(pButtonModel(__model));
    //
    __model->SetLocalCoord(0, 0);
    __model->SetSize(150, 40);
    pButtonModel(__model)->SetCaption(caption);
}

Button::Button(string caption, sf::Vector2f coord)
{
    //create MVC
    __model = new ButtonModel();
    __viewer = new ButtonViewer(pButtonModel(__model));
    __controller = new ButtonController(pButtonModel(__model));
    //
    __model->SetLocalCoord(coord);
    __model->SetSize(150, 40);
    pButtonModel(__model)->SetCaption(caption);

}

Button::Button(string caption, sf::Vector2f coord, sf::Vector2f size)
{
    //create MVC
    __model = new ButtonModel();
    __viewer = new ButtonViewer(pButtonModel(__model));
    __controller = new ButtonController(pButtonModel(__model));
    //
    __model->SetLocalCoord(coord);
    __model->SetSize(size);
    pButtonModel(__model)->SetCaption(caption);
}
Button::~Button()
{

}

pButtonModel Button::Model()
{
    return pButtonModel(__model);
}

void Button::SetModel(pButtonModel model)
{
    __model = model;
}

pButtonViewer Button::Viewer()
{
    return pButtonViewer(__viewer);
}

void Button::SetViewer(pButtonViewer viewer)
{
    __viewer = viewer;
}

pButtonController Button::Controller()
{
    return pButtonController(__controller);
}

void Button::SetController(pButtonController controller)
{
    __controller = controller;
}

