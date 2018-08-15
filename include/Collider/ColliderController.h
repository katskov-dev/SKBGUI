#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Collider/ColliderModel.h>
#include <SFML/Graphics.hpp>

class ColliderController: public ComponentController
{
    public:
        ColliderController(pColliderModel model);
        virtual ~ColliderController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pColliderModel Owner();
        virtual void SetOwner(pColliderModel owner);

    protected:

    private:
};
