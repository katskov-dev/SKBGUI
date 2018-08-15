#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <RevoluteJoint/RevoluteJointModel.h>
#include <SFML/Graphics.hpp>
#include <Joint/JointViewer.h>
class RevoluteJointViewer: public JointViewer
{
    public:
        RevoluteJointViewer(pRevoluteJointModel model);
        virtual ~RevoluteJointViewer();
        virtual void Render(sf::RenderTarget& target);
    protected:

    private:


};
