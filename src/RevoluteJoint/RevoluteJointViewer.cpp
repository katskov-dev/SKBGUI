#include "RevoluteJoint/RevoluteJointViewer.h"

RevoluteJointViewer::RevoluteJointViewer(pRevoluteJointModel model): JointViewer(pJointModel(model))
{

}

RevoluteJointViewer::~RevoluteJointViewer()
{
    //dtor
}

void RevoluteJointViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}
