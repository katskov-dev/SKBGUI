#pragma once
#include <SFML/Graphics.hpp>
#include <base.h>
#include <Component/ComponentModel.h>
#include <iostream>

class ComponentViewer
{
    public:
        ComponentViewer(pComponentModel owner);
        virtual ~ComponentViewer();
        virtual void RenderBegin(sf::RenderTarget& target);
        virtual void RenderEnd(sf::RenderTarget& target);
        virtual void Render(sf::RenderTarget& target);
        virtual pComponentModel Owner();
        virtual void SetOwner(pComponentModel owner);
    protected:
        sf::View getView(sf::RenderTarget& target);
    private:
        sf::RectangleShape __border;
        pComponentModel __owner;
        sf::View __view, __oldView;



};

