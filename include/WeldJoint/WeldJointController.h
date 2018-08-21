#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <WeldJoint/WeldJointModel.h>
#include <SFML/Graphics.hpp>
#include <Joint/JointController.h>
class WeldJointController: public JointController
{
    public:
        WeldJointController(pWeldJointModel model);
        virtual ~WeldJointController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pWeldJointModel Owner();
        virtual void SetOwner(pWeldJointModel owner);

    protected:

    private:
};
