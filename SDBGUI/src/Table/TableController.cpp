#include "Table/TableController.h"

TableController::TableController(pTableModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

TableController::~TableController()
{
    //dtor
}

bool TableController::Handle(sf::Event event)
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

pTableModel TableController::Owner()
{
    return pTableModel(ComponentController::Owner());
}

void TableController::SetOwner(pTableModel owner)
{
    ComponentController::SetOwner(owner);
}
