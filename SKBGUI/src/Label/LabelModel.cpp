#include "Label/LabelModel.h"

LabelModel::LabelModel(): ComponentModel()
{
    SetCaption("Label");
    SetSize(sf::Vector2f(100, 35));
    SetLocalCoord(sf::Vector2f(0, 0));
    SetColor(sf::Color(0x000000ff));
    __class = "Label";
}

LabelModel::~LabelModel()
{
    //dtor
}

sf::String LabelModel::Caption()
{
    return __caption;
}

void LabelModel::SetCaption(sf::String caption)
{
    __caption = caption;
}

sf::Color LabelModel::Color()
{
    return __color;
}

void LabelModel::SetColor(sf::Color color)
{
    __color = color;
}
