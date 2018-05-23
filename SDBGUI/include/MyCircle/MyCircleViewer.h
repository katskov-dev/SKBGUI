#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <MyCircle/MyCircleModel.h>
#include <SFML/Graphics.hpp>

class MyCircleViewer: public ComponentViewer
{
    public:
        MyCircleViewer(pMyCircleModel model);
        virtual ~MyCircleViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pMyCircleModel Owner();
        virtual void SetOwner(pMyCircleModel owner);
    protected:

    private:
        sf::CircleShape shape;

};
