#include "Joint/JointController.h"

JointController::JointController(pJointModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

JointController::~JointController()
{
    //dtor
}

bool JointController::Handle(sf::Event event)
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

void JointController::Update(sf::Time time)
{
    ComponentController::Update(time);
 
}

pJointModel JointController::Owner()
{
    return pJointModel(ComponentController::Owner());
}

void JointController::SetOwner(pJointModel owner)
{
    ComponentController::SetOwner(owner);
}
