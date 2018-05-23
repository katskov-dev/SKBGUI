#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <CircleCollider/CircleColliderModel.h>
#include <SFML/Graphics.hpp>

class CircleColliderController: public ComponentController
{
    public:
        CircleColliderController(pCircleColliderModel model);
        virtual ~CircleColliderController();
        virtual bool Handle(sf::Event event);
		virtual pCircleColliderModel Owner();
        virtual void SetOwner(pCircleColliderModel owner);
        virtual void Update(sf::Time time);

    protected:

    private:
};
