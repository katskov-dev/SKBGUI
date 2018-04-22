#include "CheckBox/CheckBoxController.h"

CheckBoxController::CheckBoxController(pCheckBoxModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

CheckBoxController::~CheckBoxController()
{
    //dtor
}

void CheckBoxController::Handle(sf::Event event)
{
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
}
