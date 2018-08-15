#include "Joint/JointViewer.h"

JointViewer::JointViewer(pJointModel model): ComponentViewer(pComponentModel(model))
{

}

JointViewer::~JointViewer()
{
    //dtor
}

void JointViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}

pJointModel JointViewer::Owner()
{
    return pJointModel(ComponentViewer::Owner());
}

void JointViewer::SetOwner(pJointModel owner)
{
    ComponentViewer::SetOwner(owner);
}
