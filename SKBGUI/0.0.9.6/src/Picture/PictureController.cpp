#include "Picture/PictureController.h"

PictureController::PictureController(pPictureModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

PictureController::~PictureController()
{
    //dtor
}

bool PictureController::Handle(sf::Event event)
{
    ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };

    return false;
}
