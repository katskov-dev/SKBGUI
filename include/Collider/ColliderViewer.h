#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Collider/ColliderModel.h>
#include <SFML/Graphics.hpp>

class ColliderViewer: public ComponentViewer
{
    public:
        ColliderViewer(pColliderModel model);
        virtual ~ColliderViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pColliderModel Owner();
        virtual void SetOwner(pColliderModel owner);
    protected:

    private:


};
