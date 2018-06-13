#include "Picker/PickerViewer.h"

PickerViewer::PickerViewer(pPickerModel model): ComponentViewer(pComponentModel(model))
{

}

PickerViewer::~PickerViewer()
{
    //dtor
}

void PickerViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);

    __sprite.setTexture(Owner()->Mask());
    __sprite.setPosition(Owner()->AbsoluteCoord());
    sf::Vector2f scale;
    scale.x = Owner()->Size().x / (double)Owner()->Mask().getSize().x;
    scale.y = Owner()->Size().y / (double)Owner()->Mask().getSize().y;
    __sprite.setScale(scale);
    target.draw(__sprite);

	ComponentViewer::RenderEnd(target);
}

pPickerModel PickerViewer::Owner()
{
    return pPickerModel(ComponentViewer::Owner());
}

void PickerViewer::SetOwner(pPickerModel owner)
{
    ComponentViewer::SetOwner(owner);
}
