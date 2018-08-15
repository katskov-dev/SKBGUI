#include "RevoluteJoint/RevoluteJointController.h"

RevoluteJointController::RevoluteJointController(pRevoluteJointModel model): JointController(pJointModel(model))
{
    //ctor
}

RevoluteJointController::~RevoluteJointController()
{
    //dtor
}

bool RevoluteJointController::Handle(sf::Event event)
{
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
    return false;
}
