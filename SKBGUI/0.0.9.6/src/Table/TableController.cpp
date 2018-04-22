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
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };

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
