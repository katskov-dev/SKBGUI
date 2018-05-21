#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Animation/AnimationModel.h>
#include <SFML/Graphics.hpp>

class AnimationViewer: public ComponentViewer
{
    public:
        AnimationViewer(pAnimationModel model);
        virtual ~AnimationViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pAnimationModel Owner();
        virtual void SetOwner(pAnimationModel owner);


    protected:

    private:
//        int __row;
//        int __col;
//        int __x1;
//        int __x2;
//        int __y1;
//        int __y2;
//        int __tw;
//        int __th;
//        sf::Sprite sprite;

};
