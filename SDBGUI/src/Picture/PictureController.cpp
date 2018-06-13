#include "Picture/PictureController.h"
#include <math.h>

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
    if (ComponentController::Handle(event))
        return true;
    if (Owner()->Focus()){
        switch (event.type){
            case sf::Event::MouseButtonPressed : {
                if (pPictureModel(Owner())->Mask() != nullptr){
                    sf::Vector2i mc;
                    mc.x = event.mouseButton.x - Owner()->AbsoluteCoord().x;
                    mc.y = event.mouseButton.y - Owner()->AbsoluteCoord().y;
                    sf::Vector2i maskc;
                    maskc.x = floor((mc.x / (double)Owner()->Size().x) * pPictureModel(Owner())->Mask()->getSize().x);
                    maskc.y = floor((mc.y / (double)Owner()->Size().y) * pPictureModel(Owner())->Mask()->getSize().y);
                    sf::Image img = pPictureModel(Owner())->Mask()->copyToImage();
                    if (img.getPixel(maskc.x, maskc.y).a == 0)
                        Owner()->SetFocus(false);
                }
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
