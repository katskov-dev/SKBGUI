#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <DistanceJoint/DistanceJointModel.h>
#include <SFML/Graphics.hpp>
#include <Joint/JointViewer.h>
class DistanceJointViewer: public JointViewer
{
    public:
        DistanceJointViewer(pDistanceJointModel model);
        virtual ~DistanceJointViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pDistanceJointModel Owner();
        virtual void SetOwner(pDistanceJointModel owner);
    protected:

    private:


};
