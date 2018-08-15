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
