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

pPanelModel PanelController::Owner()
{
    return pPanelModel(ComponentController::Owner());
}

void PanelController::SetOwner(pPanelModel owner)
{
    ComponentController::SetOwner(owner);

}
