#include "TransformerRXY/TransformerRXYModel.h"

TransformerRXYModel::TransformerRXYModel()
{
    __radius = 3;
    __defaultColor = sf::Color(0x7777ffff);
    __activeColor = sf::Color(0xddddffff);
    __target = nullptr;
    activePoint = -1;
    SetState(TransformerRXY_STATE_NORMAL);
    SetVisibleBorders(true);
    SetViewLimit(false);

    arrow_x = new Picture();
    arrow_x->Model()->LoadFromFile("assets/images/arrows/arrow-x.png", true);
    arrow_x->Model()->SetSize(150,20);
    arrow_x->Model()->SetLocalCoord(0,0);
   // arrow_x->Model()->SetVisibleBorders(true);

    arrow_x->Model()->Show();
    arrow_x->Model()->SetEnabled(false);
    Add(arrow_x);

    arrow_y = new Picture();
    arrow_y->Model()->LoadFromFile("assets/images/arrows/arrow-y.png", true);
    arrow_y->Model()->SetSize(20,150);
    arrow_y->Model()->SetLocalCoord(0,0);
   // arrow_y->Model()->SetVisibleBorders(true);

    arrow_y->Model()->Show();
    arrow_y->Model()->SetEnabled(false);
    Add(arrow_y);

//    ring = new Picture();
//    ring->Model()->LoadFromFile("assets/images/arrows/ring.png", true);
//    ring->Model()->SetSize(250,250);
//    ring->Model()->SetVisibleBorders(true);
//    ring->Model()->SetLocalCoord(0,0);
//    ring->Model()->Show();
//    Add(ring);

}

TransformerRXYModel::~TransformerRXYModel()
{
    //dtor
}

pComponent TransformerRXYModel::Target()
{
    return __target;
}

void TransformerRXYModel::SetTarget(pComponent target)
{
    __target = target;
    if (target != nullptr){
       UpdatePoints();
    }
}

void TransformerRXYModel::UpdatePoints()
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

sf::Vector2f TransformerRXYModel::Point(int index)
{
    return __points[index];
}

void TransformerRXYModel::SetRadius(double radius)
{
    __radius = radius;
}

double TransformerRXYModel::Radius()
{
    return __radius;
}
