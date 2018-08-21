#include "prismaticJoint/prismaticJointViewer.h"

prismaticJointViewer::prismaticJointViewer(pprismaticJointModel model): ComponentViewer(pComponentModel(model))
{

}

prismaticJointViewer::~prismaticJointViewer()
{
    //dtor
}

void prismaticJointViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}

pprismaticJointModel prismaticJointViewer::Owner()
{
    return pprismaticJointModel(ComponentViewer::Owner());
}

void prismaticJointViewer::SetOwner(pprismaticJointModel owner)
{
    ComponentViewer::SetOwner(owner);
}
