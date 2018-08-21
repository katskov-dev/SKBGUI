#include "Button/ButtonModel.h"

ButtonModel::ButtonModel(): ComponentModel()
{
    SetCaption("Button");
    SetState(BUTTON_STATE_NORMAL);
    __class = "Button";
    SetVisibleBorders(true);

}

ButtonModel::~ButtonModel()
{
    //dtor
}

sf::String ButtonModel::Caption()
{
    return __caption;
}

void ButtonModel::SetCaption(sf::String caption)
{
    __caption = caption;
}

std::string ButtonModel::SerializeToString()
{
    std::string result = "";


    return result;

}
