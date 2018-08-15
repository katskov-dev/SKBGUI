#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <RigidBody/RigidBodyModel.h>
#include <SFML/Graphics.hpp>

class RigidBodyController: public ComponentController
{
    public:
        RigidBodyController(pRigidBodyModel model);
        virtual ~RigidBodyController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pRigidBodyModel Owner();
        virtual void SetOwner(pRigidBodyModel owner);

    protected:

    private:
};
