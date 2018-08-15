#include "Collider/ColliderViewer.h"

ColliderViewer::ColliderViewer(pColliderModel model): ComponentViewer(pComponentModel(model))
{

}

ColliderViewer::~ColliderViewer()
{
    //dtor
}

void ColliderViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}

pColliderModel ColliderViewer::Owner()
{
    return pColliderModel(ComponentViewer::Owner());
}

void ColliderViewer::SetOwner(pColliderModel owner)
{
    ComponentViewer::SetOwner(owner);
}
