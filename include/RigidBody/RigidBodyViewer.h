#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <RigidBody/RigidBodyModel.h>
#include <SFML/Graphics.hpp>

class RigidBodyViewer: public ComponentViewer
{
    public:
        RigidBodyViewer(pRigidBodyModel model);
        virtual ~RigidBodyViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pRigidBodyModel Owner();
        virtual void SetOwner(pRigidBodyModel owner);
    protected:

    private:


};
