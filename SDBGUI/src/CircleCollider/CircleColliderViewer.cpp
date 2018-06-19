#include "CircleCollider/CircleColliderViewer.h"

CircleColliderViewer::CircleColliderViewer(pCircleColliderModel model): ComponentViewer(pComponentModel(model))
{

}

CircleColliderViewer::~CircleColliderViewer()
{

}

void CircleColliderViewer::Render(sf::RenderTarget& target)
{
	//ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);




	sf::Vector2f offset = sf::Vector2f(Owner()->R(), Owner()->R() );
    __shape.setPosition(- offset);
    __shape.setRadius(pCircleColliderModel(Owner())->R() - 1.0);
    __shape.setFillColor(sf::Color(0x00000000));
    __shape.setOutlineColor(sf::Color(0x0000ffff));
    __shape.setOutlineThickness(1.0);
    double pi = 3.14159;
    double deg = 180 / pi;
    sf::RenderStates rs;


    rs.transform.translate(Owner()->AbsoluteCoord() + offset + sf::Vector2f(1, 1));
    rs.transform.rotate(Owner()->Angle() * deg);

    //sf::View view = target.getView();

    //view.move(-(Owner()->AbsoluteCoord() +  offset + sf::Vector2f(1, 1)));
    //view.rotate(Owner()->Angle() * deg);
	//target.setView(view);

//    cout << pCircleColliderModel(Owner())->X() <<" " << pCircleColliderModel(Owner())->Y() << " " << pCircleColliderModel(Owner())->R() << endl;
    target.draw(__shape, rs);
    sf::Vector2f coord = Owner()->AbsoluteCoord();
    double r = pCircleColliderModel(Owner())->R();
    __line[0] = sf::Vertex(sf::Vector2f(0,0), sf::Color(0xff0000ff));
    __line[1] = sf::Vertex(sf::Vector2f( r  , 0), sf::Color(0xff0000ff));
    target.draw(__line, 2, sf::Lines, rs);


	//ComponentViewer::RenderEnd(target);
}

pCircleColliderModel CircleColliderViewer::Owner()
{
    return pCircleColliderModel(ComponentViewer::Owner());
}

void CircleColliderViewer::SetOwner(pCircleColliderModel owner)
{
    ComponentViewer::SetOwner(owner);
}
