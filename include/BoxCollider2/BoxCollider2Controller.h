#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <BoxCollider2/BoxCollider2Model.h>
#include <SFML/Graphics.hpp>
#include <Collider/ColliderController.h>
class BoxCollider2Controller: public ColliderController
{
    public:
        BoxCollider2Controller(pBoxCollider2Model model);
        virtual ~BoxCollider2Controller();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pBoxCollider2Model Owner();
        virtual void SetOwner(pBoxCollider2Model owner);

    protected:

    private:
};
