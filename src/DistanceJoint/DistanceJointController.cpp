#include "DistanceJoint/DistanceJointController.h"

DistanceJointController::DistanceJointController(pDistanceJointModel model): JointController(pJointModel(model))
{
    //ctor
}

DistanceJointController::~DistanceJointController()
{
    //dtor
}

bool DistanceJointController::Handle(sf::Event event)
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

void DistanceJointController::Update(sf::Time time)
{
    ComponentController::Update(time);

}

pDistanceJointModel DistanceJointController::Owner()
{
    return pDistanceJointModel(ComponentController::Owner());
}

void DistanceJointController::SetOwner(pDistanceJointModel owner)
{
    ComponentController::SetOwner(owner);
}
