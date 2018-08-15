#include "Arrow/ArrowViewer.h"

ArrowViewer::ArrowViewer(pArrowModel model): ComponentViewer(pComponentModel(model))
{

}

ArrowViewer::~ArrowViewer()
{
    //dtor
}

void ArrowViewer::Render(sf::RenderTarget& target)
{
	//ComponentViewer::RenderBegin(target);
	//ComponentViewer::Render(target);

    sf::Vertex v[2];
    v[0].color = sf::Color(0x000000ff);
    v[1].color = sf::Color(0x000000ff);
    v[0].position = Owner()->__start->Model()->AbsoluteCoord() + sf::Vector2f(10,10);
    v[1].position = Owner()->__end->Model()->AbsoluteCoord() + sf::Vector2f(10,10);

    target.draw(v, 2, sf::Lines);


	//ComponentViewer::RenderEnd(target);
}

pArrowModel ArrowViewer::Owner()
{
    return pArrowModel(ComponentViewer::Owner());
}

void ArrowViewer::SetOwner(pArrowModel owner)
{
    ComponentViewer::SetOwner(owner);
}
