#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Joint/JointModel.h>
#include <SFML/Graphics.hpp>

class JointController: public ComponentController
{
    public:
        JointController(pJointModel model);
        virtual ~JointController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pJointModel Owner();
        virtual void SetOwner(pJointModel owner);

    protected:

    private:
};
