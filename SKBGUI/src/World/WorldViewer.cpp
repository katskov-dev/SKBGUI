#include "World/WorldViewer.h"

WorldViewer::WorldViewer(pWorldModel model): ComponentViewer(pComponentModel(model))
{

}

WorldViewer::~WorldViewer()
{
    //dtor
}

void WorldViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);

	ComponentViewer::RenderEnd(target);
}

pWorldModel WorldViewer::Owner()
{
    return pWorldModel(ComponentViewer::Owner());
}

void WorldViewer::SetOwner(pWorldModel owner)
{
    ComponentViewer::SetOwner(owner);
}
