#include "Animation/AnimationController.h"

AnimationController::AnimationController(pAnimationModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

AnimationController::~AnimationController()
{
    //dtor
}

bool AnimationController::Handle(sf::Event event)
{
	if (!Owner()->Enabled())
        return false;
    if (ComponentController::Handle(event))
        return true;
    switch (event.type){
        case sf::Event::MouseButtonPressed : {
            return false;
            break;
        };
    };
    return false;
}

void AnimationController::Update(sf::Time delta)
{

    Owner()->setCurrentTime(Owner()->currentTime() + delta);
    if (Owner()->currentTime() > Owner()->interval())
    {
        Owner()->setCurrentTime(Owner()->currentTime() - Owner()->interval());
        Owner()->nextFrame();
    }
}

pAnimationModel AnimationController::Owner()
{
    return pAnimationModel(ComponentController::Owner());
}

void AnimationController::SetOwner(pAnimationModel owner)
{
    ComponentController::SetOwner(owner);
}
