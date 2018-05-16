#include "Neuron/NeuronViewer.h"
#include <math.h>

NeuronViewer::NeuronViewer(pNeuronModel model): ComponentViewer(pComponentModel(model))
{

}

NeuronViewer::~NeuronViewer()
{
    //dtor
}

void NeuronViewer::Render(sf::RenderTarget& target)
{
    if (!Owner()->Visible())
        return;
	//ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);

	sf::CircleShape shape;
	shape.setRadius(Owner()->Size().x / 2.0 - 1);
    shape.setPosition(Owner()->AbsoluteCoord() + sf::Vector2f(1,1));
    shape.setPointCount(10);
    sf::Uint8 c = std::floor(Owner()->signal * 255);
    shape.setFillColor(sf::Color(255-c, 255, 255-c));

    shape.setOutlineColor(sf::Color(0x000000ff));
    shape.setOutlineThickness(1.0);
    target.draw(shape);


	//ComponentViewer::RenderEnd(target);
}

pNeuronModel NeuronViewer::Owner()
{
    return pNeuronModel(ComponentViewer::Owner());
}

void NeuronViewer::SetOwner(pNeuronModel owner)
{
    ComponentViewer::SetOwner(owner);
}
