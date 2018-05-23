#include "Button/ButtonController.h"

ButtonController::ButtonController(pButtonModel model): ComponentController(model)
{
    SetOnClick(nullptr);
}

ButtonController::~ButtonController()
{
    //dtor
}


bool ButtonController::Handle(sf::Event event)
{
    if (!Owner()->Enabled())
        return false;
    if (ComponentController::Handle(event))
        return true;
    switch (event.type){
        //Обработка нажатия кнопки мыши
        case sf::Event::MouseButtonPressed:{
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            sf::Vector2f pos = Owner()->AbsoluteCoord();
            sf::Vector2f size = Owner()->Size();
            if ((x >= pos.x) && (x <= pos.x + size.x) && (y >= pos.y) && (y <= pos.y + size.y)){
                Owner()->SetState(BUTTON_STATE_DOWN);
                //std::cout << Owner()->SerializeToString() << std::endl;
                //Owner()->DeserializeFromString(Owner()->SerializeToString());

                return true;

                }

            break;
        }
        case sf::Event::MouseButtonReleased:{
            //Обработка отпускания кнопки мыши
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            sf::Vector2f pos = Owner()->AbsoluteCoord();
            sf::Vector2f size = Owner()->Size();
            if ((x >= pos.x) && (x <= pos.x + size.x) && (y >= pos.y) && (y <= pos.y + size.y)){
                if ((onClick() != nullptr ) && (Owner()->State() != BUTTON_STATE_NORMAL)){
                    onClick()();
                    return true;
                }

            }
            Owner()->SetState(BUTTON_STATE_NORMAL);


            break;
        }
    }
    return false;
}

OnClickEventFunc ButtonController::onClick()
{
    return __onClick;
}

void ButtonController::SetOnClick(OnClickEventFunc func)
{
    __onClick = func;
}
