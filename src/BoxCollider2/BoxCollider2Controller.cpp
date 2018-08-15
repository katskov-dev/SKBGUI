#include "BoxCollider2/BoxCollider2Controller.h"

BoxCollider2Controller::BoxCollider2Controller(pBoxCollider2Model model): ColliderController(pColliderModel(model))
{
    //ctor
}

BoxCollider2Controller::~BoxCollider2Controller()
{
    //dtor
}

bool BoxCollider2Controller::Handle(sf::Event event)
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

void BoxCollider2Controller::Update(sf::Time time)
{
    ComponentController::Update(time);
    Owner()->setPositionAfterStep();
}

pBoxCollider2Model BoxCollider2Controller::Owner()
{
    return pBoxCollider2Model(ComponentController::Owner());
}

void BoxCollider2Controller::SetOwner(pBoxCollider2Model owner)
{
    ComponentController::SetOwner(owner);



}
