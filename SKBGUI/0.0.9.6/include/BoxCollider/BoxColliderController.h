#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <BoxCollider/BoxColliderModel.h>
#include <SFML/Graphics.hpp>

class BoxColliderController: public ComponentController
{
    public:
        BoxColliderController(pBoxColliderModel model);
        virtual ~BoxColliderController();
        virtual bool Handle(sf::Event event);
		virtual pBoxColliderModel Owner();
        virtual void SetOwner(pBoxColliderModel owner);
        virtual void Update(sf::Time time);

    protected:

    private:
};
