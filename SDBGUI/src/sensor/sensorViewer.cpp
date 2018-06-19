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
    shape.setPosition(-nc + Owner()->AbsoluteCoord());
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
