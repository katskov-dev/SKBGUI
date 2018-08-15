#include "Label/LabelViewer.h"

LabelViewer::LabelViewer(pLabelModel model): ComponentViewer(pComponentModel(model))
{
    __font.loadFromFile("assets/fonts/Arial.ttf");
    __text.setFont(__font);
}

LabelViewer::~LabelViewer()
{
    //dtor
}

 void LabelViewer::Render(sf::RenderTarget& target)
 {
     if (!Owner()->Visible())
        return;
    ComponentViewer::RenderBegin(target);
    ComponentViewer::Render(target);

    __text.setCharacterSize(Owner()->Size().y * 0.75);
    __text.setString((pLabelModel(Owner()))->Caption());
    __text.setPosition(sf::Vector2f(0, Owner()->Size().y * 0.125) - sf::Vector2f(Owner()->Size().x / 2.0, Owner()->Size().y / 2.0));
    __text.setColor(pLabelModel(Owner())->Color());
    sf::RenderStates rs = Owner()->RenderStates();
    rs.transform.translate(sf::Vector2f(Owner()->Size().x / 2.0, Owner()->Size().y / 2.0));
    rs.transform.rotate(Owner()->Angle());
    target.draw(__text, rs);

    ComponentViewer::RenderEnd(target);
 }

pLabelModel LabelViewer::Owner()
{
    return pLabelModel(ComponentViewer::Owner());
}

void LabelViewer::SetOwner(pLabelModel owner)
{
    ComponentViewer::SetOwner(owner);
}
