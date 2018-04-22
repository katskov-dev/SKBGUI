#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <BoxCollider/BoxColliderModel.h>
#include <SFML/Graphics.hpp>

class BoxColliderViewer: public ComponentViewer
{
    public:
        BoxColliderViewer(pBoxColliderModel model);
        virtual ~BoxColliderViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pBoxColliderModel Owner();
        virtual void SetOwner(pBoxColliderModel owner);
    protected:

    private:
        sf::RectangleShape __shape;
        sf::Vertex __line[2];

};
