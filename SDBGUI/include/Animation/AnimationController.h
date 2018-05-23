#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Animation/AnimationModel.h>
#include <SFML/Graphics.hpp>

class AnimationController: public ComponentController
{
    public:
        AnimationController(pAnimationModel model);
        virtual ~AnimationController();
        virtual bool Handle(sf::Event event);
		virtual pAnimationModel Owner();
        virtual void SetOwner(pAnimationModel owner);
        virtual void Update(sf::Time delta);

    protected:

    private:
};
