#include "CircleCollider/CircleColliderController.h"

CircleColliderController::CircleColliderController(pCircleColliderModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

CircleColliderController::~CircleColliderController()
{
    //dtor
}

bool CircleColliderController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
    return false;
}

pCircleColliderModel CircleColliderController::Owner()
{
    return pCircleColliderModel(ComponentController::Owner());
}

void CircleColliderController::SetOwner(pCircleColliderModel owner)
{
    ComponentController::SetOwner(owner);
}

void CircleColliderController::Update(sf::Time time)
{
    ComponentController::Update(time);
    Owner()->setPositionAfterStep();
}
