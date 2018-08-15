#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Joint/JointModel.h>
#include <SFML/Graphics.hpp>

class JointViewer: public ComponentViewer
{
    public:
        JointViewer(pJointModel model);
        virtual ~JointViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pJointModel Owner();
        virtual void SetOwner(pJointModel owner);
    protected:

    private:


};
