#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <GUI/GUIModel.h>
#include <SFML/Graphics.hpp>

class GUIViewer: public ComponentViewer
{
    public:
        GUIViewer(pGUIModel model);
        virtual ~GUIViewer();
        virtual void Render(sf::RenderTarget& target);
    protected:

    private:
        sf::Clock __fps_clock;


};
