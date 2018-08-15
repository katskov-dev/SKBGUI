#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <DistanceJoint/DistanceJointModel.h>
#include <SFML/Graphics.hpp>
#include <Joint/JointController.h>
class DistanceJointController: public JointController
{
    public:
        DistanceJointController(pDistanceJointModel model);
        virtual ~DistanceJointController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pDistanceJointModel Owner();
        virtual void SetOwner(pDistanceJointModel owner);

    protected:

    private:
};
