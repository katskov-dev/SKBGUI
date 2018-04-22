#include "CheckBox/CheckBoxViewer.h"

CheckBoxViewer::CheckBoxViewer(pCheckBoxModel model): ComponentViewer(pComponentModel(model))
{

}

CheckBoxViewer::~CheckBoxViewer()
{
    //dtor
}

void CheckBoxViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);



	ComponentViewer::RenderEnd(target);
}
