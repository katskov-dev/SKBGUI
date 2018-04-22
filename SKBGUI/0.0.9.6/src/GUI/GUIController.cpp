#include "GUI/GUIController.h"

GUIController::GUIController(pGUIModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

GUIController::~GUIController()
{
    //dtor
}

bool GUIController::Handle(sf::Event event)
{

    ComponentController::Handle(event);

    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
        case sf::Event::Resized:{


            break;
        }
    };
}

void GUIController::Update(sf::Time time)
{
    ComponentController::Update(time);

}
