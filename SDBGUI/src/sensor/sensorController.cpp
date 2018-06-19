#include "sensor/sensorController.h"

sensorController::sensorController(psensorModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

sensorController::~sensorController()
{
    //dtor
}

bool sensorController::Handle(sf::Event event)
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

void sensorController::Update(sf::Time time)
{
    ComponentController::Update(time);
    if (Owner()->isContact){
        if (Owner()->OnContact() != nullptr){
            CollisionHandler* ch = (CollisionHandler*)Owner()->__body->GetUserData();
            ch->handler(ch->collider);
            Owner()->isContact = false;
        }

    }


}

psensorModel sensorController::Owner()
{
    return psensorModel(ComponentController::Owner());
}

void sensorController::SetOwner(psensorModel owner)
{
    ComponentController::SetOwner(owner);
}
