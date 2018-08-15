#include "RigidBody/RigidBodyController.h"

RigidBodyController::RigidBodyController(pRigidBodyModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

RigidBodyController::~RigidBodyController()
{
    //dtor
}

bool RigidBodyController::Handle(sf::Event event)
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

void RigidBodyController::Update(sf::Time time)
{
    ComponentController::Update(time);
 
}

pRigidBodyModel RigidBodyController::Owner()
{
    return pRigidBodyModel(ComponentController::Owner());
}

void RigidBodyController::SetOwner(pRigidBodyModel owner)
{
    ComponentController::SetOwner(owner);
}
