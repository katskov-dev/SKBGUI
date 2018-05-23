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
    if (Owner()->requestViewerUpdate){
        Owner()->__rect.setFillColor(sf::Color(0xffffffff));
        Owner()->__rect.setOutlineColor(sf::Color(0x000000ff));
        Owner()->__rect.setOutlineThickness(1.0);
    }
    target.draw(Owner()->__rect, rs);
    if (Owner()->Checked()){
        target.draw(Owner()->__line2, 4, sf::Lines, rs);
    }
    Owner()->__caption->Model()->SetAbsoluteCoord(Owner()->AbsoluteCoord()+sf::Vector2f(Owner()->__sz, 2));
    Owner()->__caption->Viewer()->Render(target);


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
