#include "Label/LabelController.h"

LabelController::LabelController(pLabelModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

LabelController::~LabelController()
{
    //dtor
}

bool LabelController::Handle(sf::Event event)
{
    if (ComponentController::Handle(event))
        return true;
    if (Owner()->Focus()){
        switch (event.type){
            case sf::Event::MouseButtonPressed : {

                return true;
                break;
            };
            case sf::Event::MouseButtonReleased : {

                return true;
                break;
            };
            case sf::Event::KeyPressed : {

                return true;
                break;
            };
            case sf::Event::KeyReleased : {

                return true;
                break;
            };
            case sf::Event::TextEntered : {

                return true;
                break;
            };
            case sf::Event::MouseMoved : {

                return true;
                break;
            };
            case sf::Event::MouseWheelScrolled : {

                return true;
                break;
            };
        };
    }
    return false;
}

pLabelModel LabelController::Owner()
{
    return pLabelModel(ComponentController::Owner());
}

void LabelController::SetOwner(pLabelModel owner)
{
    ComponentController::SetOwner(owner);
}
