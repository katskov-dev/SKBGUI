#include "Transformer/TransformerModel.h"

TransformerModel::TransformerModel()
{
    __radius = 3;
    __defaultColor = sf::Color(0x7777ffff);
    __activeColor = sf::Color(0xddddffff);
    __target = nullptr;
    activePoint = -1;
    SetState(TRANSFORMER_STATE_NORMAL);
    SetVisibleBorders(true);
    SetViewLimit(false);

    arrow_x = new Picture();
    arrow_x->Model()->LoadFromFile("assets/images/arrows/arrow-x.png");
    arrow_x->Model()->SetLocalCoord(0,0);
    arrow_x->Model()->Hide();
    Add(arrow_x);
}

TransformerModel::~TransformerModel()
{
    //dtor
}

pComponent TransformerModel::Target()
{
    return __target;
}

void TransformerModel::SetTarget(pComponent target)
{
    __target = target;
    if (target != nullptr){
       UpdatePoints();
    }
}

void TransformerModel::UpdatePoints()
{
    SetAbsoluteCoord(Target()->Model()->AbsoluteCoord());
    SetSize(Target()->Model()->Size());
    sf::Vector2f half_size = Size();
    half_size.x /= 2.0;
    half_size.y /= 2.0;
    arrow_x->Model()->SetLocalCoord(half_size);


    pComponentModel c = Target()->Model();
    sf::Vector2f coord[9];
    double r = Radius();
    coord[0] = sf::Vector2f(r,r);
    coord[1] = sf::Vector2f( c->Size().x / 2.0, 0) + sf::Vector2f(0,r);
    coord[2] =  sf::Vector2f( c->Size().x, 0) + sf::Vector2f(-r,r);
    coord[3] =  sf::Vector2f( c->Size().x, c->Size().y / 2.0) + sf::Vector2f(-r,0);
    coord[4] = sf::Vector2f( c->Size().x, c->Size().y) + sf::Vector2f(-r,-r);
    coord[5] =  sf::Vector2f( c->Size().x / 2.0, c->Size().y) + sf::Vector2f(0,-r);
    coord[6] =  sf::Vector2f( 0, c->Size().y) + sf::Vector2f(r,-r);
    coord[7] =  sf::Vector2f( 0, c->Size().y / 2.0) + sf::Vector2f(r,0);
    coord[8] =  sf::Vector2f( c->Size().x / 2.0, c->Size().y / 2.0);

    for (int i = 0; i < 9; i++)
        __points[i] = coord[i];

}

sf::Vector2f TransformerModel::Point(int index)
{
    return __points[index];
}

void TransformerModel::SetRadius(double radius)
{
    __radius = radius;
}

double TransformerModel::Radius()
{
    return __radius;
}
