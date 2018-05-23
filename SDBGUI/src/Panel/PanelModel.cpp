#include "Panel/PanelModel.h"

PanelModel::PanelModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(100, 100);
    SetVisibleBorders(true);
    __color = sf::Color(0xaaaaaaff);
    SetName("Panel");
    __class = "Panel";

}

PanelModel::~PanelModel()
{
    //dtor
}

sf::Color PanelModel::Color()
{
    return __color;
}

void PanelModel::SetColor(sf::Color color)
{
    __color = color;
}
