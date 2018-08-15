#include "Animation/AnimationViewer.h"

AnimationViewer::AnimationViewer(pAnimationModel model): ComponentViewer(pComponentModel(model))
{

}

AnimationViewer::~AnimationViewer()
{
    //dtor
}

void AnimationViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);





    sf::Sprite& sprite = Owner()->sprite;
    sf::Vector2f coord = Owner()->AbsoluteCoord();
    sprite.setPosition(coord);
    target.draw(sprite);



	ComponentViewer::RenderEnd(target);
}

pAnimationModel AnimationViewer::Owner()
{
    return pAnimationModel(ComponentViewer::Owner());
}

void AnimationViewer::SetOwner(pAnimationModel owner)
{
    ComponentViewer::SetOwner(owner);
}
