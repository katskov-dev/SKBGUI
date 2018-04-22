#include "MyCircle/MyCircleViewer.h"

MyCircleViewer::MyCircleViewer(pMyCircleModel model): ComponentViewer(pComponentModel(model))
{

}

MyCircleViewer::~MyCircleViewer()
{
    //dtor
}

void MyCircleViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);

	shape.setRadius(Owner()->Size().x / 2.0);
	shape.setPointCount(50);
	shape.setPosition(Owner()->AbsoluteCoord());
	int state = Owner()->MyState();
	if (state == MYCIRCLE_STATE_RED)
        shape.setFillColor(sf::Color(0xff0000ff));
    else
        shape.setFillColor(sf::Color(0x00ff00ff));

    target.draw(shape);

	ComponentViewer::RenderEnd(target);
}

pMyCircleModel MyCircleViewer::Owner()
{
    return pMyCircleModel(ComponentViewer::Owner());
}

void MyCircleViewer::SetOwner(pMyCircleModel owner)
{
    ComponentViewer::SetOwner(owner);
}
