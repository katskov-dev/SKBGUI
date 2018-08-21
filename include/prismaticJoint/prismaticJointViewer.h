#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <prismaticJoint/prismaticJointModel.h>
#include <SFML/Graphics.hpp>

class prismaticJointViewer: public ComponentViewer
{
    public:
        prismaticJointViewer(pprismaticJointModel model);
        virtual ~prismaticJointViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pprismaticJointModel Owner();
        virtual void SetOwner(pprismaticJointModel owner);
    protected:

    private:


};
