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
    sf::Vector2f coord = Owner()->AbsoluteCoord();
    sf::RenderStates rs;
    rs.transform.translate(coord);
    if (Owner()->Checked())
        Owner()->__rect.setFillColor(sf::Color(0x00ff00ff));
    else
        Owner()->__rect.setFillColor(sf::Color(0x777777ff));
    target.draw(Owner()->__rect, rs);


	ComponentViewer::RenderEnd(target);
}

pCheckBoxModel CheckBoxViewer::Owner()
{
    return pCheckBoxModel(ComponentViewer::Owner());
}

void CheckBoxViewer::SetOwner(pCheckBoxModel owner)
{
    ComponentViewer::SetOwner(owner);
}
