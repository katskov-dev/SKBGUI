#include "BoxCollider/BoxColliderController.h"

BoxColliderController::BoxColliderController(pBoxColliderModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

BoxColliderController::~BoxColliderController()
{
    //dtor
}

bool BoxColliderController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
    return false;
}

pBoxColliderModel BoxColliderController::Owner()
{
    return pBoxColliderModel(ComponentController::Owner());
}

void BoxColliderController::SetOwner(pBoxColliderModel owner)
{
    ComponentController::SetOwner(owner);
}

void BoxColliderController::Update(sf::Time time)
{
    ComponentController::Update(time);
    Owner()->setPositionAfterStep();
}
