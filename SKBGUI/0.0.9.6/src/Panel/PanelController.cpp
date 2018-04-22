#include "Panel/PanelController.h"

PanelController::PanelController(pPanelModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

PanelController::~PanelController()
{
    //dtor
}

bool PanelController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
    return false;
}

pPanelModel PanelController::Owner()
{
    return pPanelModel(ComponentController::Owner());
}

void PanelController::SetOwner(pPanelModel owner)
{
    ComponentController::SetOwner(owner);

}
