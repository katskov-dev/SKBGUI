#include "ProgressBar/ProgressBarController.h"

ProgressBarController::ProgressBarController(pProgressBarModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

ProgressBarController::~ProgressBarController()
{
    //dtor
}

bool ProgressBarController::Handle(sf::Event event)
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

void ProgressBarController::Update(sf::Time time)
{
    ComponentController::Update(time);
 
}

pProgressBarModel ProgressBarController::Owner()
{
    return pProgressBarModel(ComponentController::Owner());
}

void ProgressBarController::SetOwner(pProgressBarModel owner)
{
    ComponentController::SetOwner(owner);
}
