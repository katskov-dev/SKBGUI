#include "Camera/CameraController.h"

CameraController::CameraController(pCameraModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

CameraController::~CameraController()
{
    //dtor
}

bool CameraController::Handle(sf::Event event)
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

void CameraController::Update(sf::Time time)
{
    ComponentController::Update(time);
 
}

pCameraModel CameraController::Owner()
{
    return pCameraModel(ComponentController::Owner());
}

void CameraController::SetOwner(pCameraModel owner)
{
    ComponentController::SetOwner(owner);
}
