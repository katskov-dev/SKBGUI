#include "RigidBody/RigidBodyViewer.h"

RigidBodyViewer::RigidBodyViewer(pRigidBodyModel model): ComponentViewer(pComponentModel(model))
{

}

RigidBodyViewer::~RigidBodyViewer()
{
    //dtor
}

void RigidBodyViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}

pRigidBodyModel RigidBodyViewer::Owner()
{
    return pRigidBodyModel(ComponentViewer::Owner());
}

void RigidBodyViewer::SetOwner(pRigidBodyModel owner)
{
    ComponentViewer::SetOwner(owner);
}
