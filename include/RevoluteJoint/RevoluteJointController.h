#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <RevoluteJoint/RevoluteJointModel.h>
#include <SFML/Graphics.hpp>
#include <Joint/JointController.h>
class RevoluteJointController: public JointController
{
    public:
        RevoluteJointController(pRevoluteJointModel model);
        virtual ~RevoluteJointController();
        virtual bool Handle(sf::Event event);

    protected:

    private:
};
