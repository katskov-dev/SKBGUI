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
    std::string parent_name = Parent()->Name();
    result += "button_create('"+Name()+"', '"+parent_name+"')\n";
    result += "component_model_setlocalcoord('"+Name()+"', "+std::to_string(LocalCoord().x)+", "+std::to_string(LocalCoord().y) + ")\n";
    result += "component_model_setsize('"+Name()+"', "+std::to_string(Size().x)+", "+std::to_string(Size().y) + ")\n";
    result += "button_model_setcaption('"+Name()+"', '"+Caption()+"')\n";


    return result;

}
