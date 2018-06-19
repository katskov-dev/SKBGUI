#include "sensor/sensorViewer.h"

sensorViewer::sensorViewer(psensorModel model): ComponentViewer(pComponentModel(model))
{
     shape.setRadius(Owner()->getr());
     shape.setPosition(Owner()->getx(),Owner()->gety());
}

sensorViewer::~sensorViewer()
{
    //dtor
}

void sensorViewer::Render(sf::RenderTarget& target)
{
    //ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);
    sf::Vector2f nc =  Owner()->Size();
    nc.x /= 2.0;
    nc.y /= 2.0;
    shape.setPosition(Owner()->AbsoluteCoord());
    shape.setFillColor(sf::Color(0xffffff88));

    sf::RenderStates rs;
    sf::Vector2f offset = sf::Vector2f(Owner()->Size().x / 2.0, Owner()->Size().y / 2.0);
    rs.transform.translate(Owner()->AbsoluteCoord()+ sf::Vector2f(1, 1));


    target.draw(shape);

	//ComponentViewer::RenderEnd(target);
}

psensorModel sensorViewer::Owner()
{
    return psensorModel(ComponentViewer::Owner());
}

void sensorViewer::SetOwner(psensorModel owner)
{
    ComponentViewer::SetOwner(owner);
}
