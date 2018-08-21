#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <WeldJoint/WeldJointModel.h>
#include <SFML/Graphics.hpp>
#include <Joint/JointViewer.h>
class WeldJointViewer: public JointViewer
{
    public:
        WeldJointViewer(pWeldJointModel model);
        virtual ~WeldJointViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pWeldJointModel Owner();
        virtual void SetOwner(pWeldJointModel owner);
    protected:

    private:


};
