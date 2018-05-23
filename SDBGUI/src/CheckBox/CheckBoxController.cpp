#include "CheckBox/CheckBoxController.h"

CheckBoxController::CheckBoxController(pCheckBoxModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

CheckBoxController::~CheckBoxController()
{
    //dtor
}

bool CheckBoxController::Handle(sf::Event event)
{
    if (ComponentController::Handle(event))
        return true;
    if (Owner()->Focus()){
        switch (event.type){
            case sf::Event::MouseButtonPressed : {
                bool state = Owner()->Checked();
                Owner()->SetChecked(!state);
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

void CheckBoxController::Update(sf::Time time)
{
    ComponentController::Update(time);

}

pCheckBoxModel CheckBoxController::Owner()
{
    return pCheckBoxModel(ComponentController::Owner());
}

void CheckBoxController::SetOwner(pCheckBoxModel owner)
{
    ComponentController::SetOwner(owner);
}
