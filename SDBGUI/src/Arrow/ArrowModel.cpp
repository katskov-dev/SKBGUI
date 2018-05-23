#include "Arrow/ArrowModel.h"
#include <math.h>
ArrowModel::ArrowModel(pComponent start, pComponent end): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    __start = start;
    __end = end;
    sf::Vector2f cn1 = __start->Model()->AbsoluteCoord();
    sf::Vector2f cn2 = __end->Model()->AbsoluteCoord();

    distance = sqrt((cn1.x - cn2.x) * (cn1.x - cn2.x) + (cn1.y - cn2.y) * (cn1.y - cn2.y));

}

ArrowModel::~ArrowModel()
{
    //dtor
}
