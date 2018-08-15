#include "Collider/ColliderController.h"

ColliderController::ColliderController(pColliderModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

ColliderController::~ColliderController()
{
    //dtor
}

bool ColliderController::Handle(sf::Event event)
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

void ColliderController::Update(sf::Time time)
{
    ComponentController::Update(time);
 
}

pColliderModel ColliderController::Owner()
{
    return pColliderModel(ComponentController::Owner());
}

void ColliderController::SetOwner(pColliderModel owner)
{
    ComponentController::SetOwner(owner);
}
