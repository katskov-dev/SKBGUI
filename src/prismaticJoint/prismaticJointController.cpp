#include "prismaticJoint/prismaticJointController.h"

prismaticJointController::prismaticJointController(pprismaticJointModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

prismaticJointController::~prismaticJointController()
{
    //dtor
}

bool prismaticJointController::Handle(sf::Event event)
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

void prismaticJointController::Update(sf::Time time)
{
    ComponentController::Update(time);
 
}

pprismaticJointModel prismaticJointController::Owner()
{
    return pprismaticJointModel(ComponentController::Owner());
}

void prismaticJointController::SetOwner(pprismaticJointModel owner)
{
    ComponentController::SetOwner(owner);
}
