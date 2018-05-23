#include "Arrow/ArrowController.h"

ArrowController::ArrowController(pArrowModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

ArrowController::~ArrowController()
{
    //dtor
}

bool ArrowController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
    return false;
}

void ArrowController::Update(sf::Time time)
{
    ComponentController::Update(time);

}

pArrowModel ArrowController::Owner()
{
    return pArrowModel(ComponentController::Owner());
}

void ArrowController::SetOwner(pArrowModel owner)
{
    ComponentController::SetOwner(owner);
}
