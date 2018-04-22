#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Panel/PanelModel.h>
#include <SFML/Graphics.hpp>

class PanelViewer: public ComponentViewer
{
    public:
        PanelViewer(pPanelModel model);
        virtual ~PanelViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pPanelModel Owner();
        virtual void SetOwner(pPanelModel owner);
    protected:

    private:
        sf::RectangleShape __rect;

};
