#include "Panel/PanelViewer.h"

PanelViewer::PanelViewer(pPanelModel model): ComponentViewer(pComponentModel(model))
{

}

PanelViewer::~PanelViewer()
{
    //dtor
}

void PanelViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);

    __rect.setPosition(Owner()->AbsoluteCoord() + sf::Vector2f(1, 1));
    __rect.setFillColor(Owner()->Color());
    __rect.setSize(Owner()->Size() + sf::Vector2f(-2, -2));
    __rect.setOutlineColor(sf::Color(0x000000ff));
    __rect.setOutlineThickness(1.0);

    target.draw(__rect);

	ComponentViewer::RenderEnd(target);
}

pPanelModel PanelViewer::Owner()
{
    return pPanelModel(ComponentViewer::Owner());
}

void PanelViewer::SetOwner(pPanelModel owner)
{
    ComponentViewer::SetOwner(owner);
}
