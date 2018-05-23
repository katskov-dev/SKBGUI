#include "MyCircle/MyCircleController.h"

MyCircleController::MyCircleController(pMyCircleModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

MyCircleController::~MyCircleController()
{
    //dtor
}

bool MyCircleController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {
            Owner()->SetMyState(MYCIRCLE_STATE_GREEN);
            break;
        };
        case sf::Event::MouseButtonReleased:{
            Owner()->SetMyState(MYCIRCLE_STATE_RED);
            break;

        };
    };

    return false;
}

void MyCircleController::Update(sf::Time time)
{
    ComponentController::Update(time);

}

pMyCircleModel MyCircleController::Owner()
{
    return pMyCircleModel(ComponentController::Owner());
}

void MyCircleController::SetOwner(pMyCircleModel owner)
{
    ComponentController::SetOwner(owner);
}
