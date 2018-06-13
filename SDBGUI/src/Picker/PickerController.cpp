#include "Picker/PickerController.h"
#include <math.h>

PickerController::PickerController(pPickerModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

PickerController::~PickerController()
{
    //dtor
}

bool PickerController::Handle(sf::Event event)
{
    if (ComponentController::Handle(event))
        return true;
    if (Owner()->Focus()){
        switch (event.type){
            case sf::Event::MouseButtonPressed : {
                sf::Vector2i mc;
                mc.x = event.mouseButton.x - Owner()->AbsoluteCoord().x;
                mc.y = event.mouseButton.y - Owner()->AbsoluteCoord().y;
                sf::Vector2i maskc;
                maskc.x = floor((mc.x / (double)Owner()->Size().x) * Owner()->Mask().getSize().x);
                maskc.y = floor((mc.y / (double)Owner()->Size().y) * Owner()->Mask().getSize().y);
                sf::Image img = Owner()->Mask().copyToImage();
                if (img.getPixel(maskc.x, maskc.y).a == 0)
                    Owner()->SetFocus(false);
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

void PickerController::Update(sf::Time time)
{
    ComponentController::Update(time);

}

pPickerModel PickerController::Owner()
{
    return pPickerModel(ComponentController::Owner());
}

void PickerController::SetOwner(pPickerModel owner)
{
    ComponentController::SetOwner(owner);
}
