#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <prismaticJoint/prismaticJointModel.h>
#include <SFML/Graphics.hpp>

class prismaticJointController: public ComponentController
{
    public:
        prismaticJointController(pprismaticJointModel model);
        virtual ~prismaticJointController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pprismaticJointModel Owner();
        virtual void SetOwner(pprismaticJointModel owner);

    protected:

    private:
};
