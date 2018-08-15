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
