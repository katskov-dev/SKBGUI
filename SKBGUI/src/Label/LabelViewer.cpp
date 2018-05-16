#include "Label/LabelViewer.h"

LabelViewer::LabelViewer(pLabelModel model): ComponentViewer(pComponentModel(model))
{
    __font.loadFromFile("assets/fonts/OpenSans-Regular.ttf");
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
    __text.setPosition(Owner()->AbsoluteCoord()+sf::Vector2f(0, Owner()->Size().y * 0.125));
    __text.setColor(pLabelModel(Owner())->Color());

    target.draw(__text);

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
