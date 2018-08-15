#include "GUI/GUIViewer.h"

GUIViewer::GUIViewer(pGUIModel model): ComponentViewer(pComponentModel(model))
{

}

GUIViewer::~GUIViewer()
{
    //dtor
}

void GUIViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}
