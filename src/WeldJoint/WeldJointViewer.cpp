#include "WeldJoint/WeldJointViewer.h"
#include <Joint/JointViewer.h>
WeldJointViewer::WeldJointViewer(pWeldJointModel model): JointViewer(pJointModel(model))
{

}

WeldJointViewer::~WeldJointViewer()
{
    //dtor
}

void WeldJointViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}

pWeldJointModel WeldJointViewer::Owner()
{
    return pWeldJointModel(ComponentViewer::Owner());
}

void WeldJointViewer::SetOwner(pWeldJointModel owner)
{
    ComponentViewer::SetOwner(owner);
}
