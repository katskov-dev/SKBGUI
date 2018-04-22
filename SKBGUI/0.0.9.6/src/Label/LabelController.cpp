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
    ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
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
