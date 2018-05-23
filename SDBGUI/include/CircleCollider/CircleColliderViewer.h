#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <CircleCollider/CircleColliderModel.h>
#include <SFML/Graphics.hpp>

class CircleColliderViewer: public ComponentViewer
{
    public:
        CircleColliderViewer(pCircleColliderModel model);
        virtual ~CircleColliderViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pCircleColliderModel Owner();
        virtual void SetOwner(pCircleColliderModel owner);
    protected:

    private:
        sf::CircleShape __shape;
        sf::Vertex __line[2];


};
