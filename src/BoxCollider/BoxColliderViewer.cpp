#include "BoxCollider/BoxColliderViewer.h"

BoxColliderViewer::BoxColliderViewer(pBoxColliderModel model): ComponentViewer(pComponentModel(model))
{

}

BoxColliderViewer::~BoxColliderViewer()
{
    //dtor
}

void BoxColliderViewer::Render(sf::RenderTarget& target)
{
//	ComponentViewer::RenderBegin(target);
    for (int i = 0; i < Owner()->Count(); i++){
        Owner()->Children(i)->Viewer()->Render(target);
	}


    sf::Vector2f offset = sf::Vector2f(Owner()->Size().x / 2.0, Owner()->Size().y / 2.0);
    __shape.setPosition(sf::Vector2f(0, 0) - offset);
    __shape.setSize(Owner()->Size());
    __shape.setFillColor(sf::Color(0x00000000));
    __shape.setOutlineColor(sf::Color(0x0000ffff));
    __shape.setOutlineThickness(1.0);
    double pi = 3.14159;
    double deg = 180 / pi;
    sf::RenderStates rs;

    rs.transform.translate(Owner()->AbsoluteCoord() + offset );
    rs.transform.rotate(Owner()->Angle() * deg);
//    cout << pCircleColliderModel(Owner())->X() <<" " << pCircleColliderModel(Owner())->Y() << " " << pCircleColliderModel(Owner())->R() << endl;
    target.draw(__shape, rs);
    sf::Vector2f coord = Owner()->AbsoluteCoord();
    double hw = Owner()->Size().x / 2.0;
    __line[0] = sf::Vertex(sf::Vector2f(0,0), sf::Color(0xff0000ff));
    __line[1] = sf::Vertex(sf::Vector2f( hw  , 0), sf::Color(0xff0000ff));
    target.draw(__line, 2, sf::Lines, rs);
    ComponentViewer::Render(target);

	//ComponentViewer::RenderEnd(target);

}

pBoxColliderModel BoxColliderViewer::Owner()
{
    return pBoxColliderModel(ComponentViewer::Owner());
}

void BoxColliderViewer::SetOwner(pBoxColliderModel owner)
{
    ComponentViewer::SetOwner(owner);
}
