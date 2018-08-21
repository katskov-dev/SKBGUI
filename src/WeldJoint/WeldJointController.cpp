#include "WeldJoint/WeldJointController.h"
#include <Joint/JointController.h>
WeldJointController::WeldJointController(pWeldJointModel model): JointController(pJointModel(model))
{
    //ctor
}

WeldJointController::~WeldJointController()
{
    //dtor
}

bool WeldJointController::Handle(sf::Event event)
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

void WeldJointController::Update(sf::Time time)
{
    ComponentController::Update(time);

}

pWeldJointModel WeldJointController::Owner()
{
    return pWeldJointModel(ComponentController::Owner());
}

void WeldJointController::SetOwner(pWeldJointModel owner)
{
    ComponentController::SetOwner(owner);
}
