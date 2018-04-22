#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Label/LabelModel.h>
#include <SFML/Graphics.hpp>

class LabelViewer: public ComponentViewer
{
    public:
        LabelViewer(pLabelModel model);
        virtual ~LabelViewer();
        virtual void Render(sf::RenderTarget& target);
        virtual pLabelModel Owner();
        virtual void SetOwner(pLabelModel owner);
    protected:

    private:
        sf::Font __font;
        sf::Text __text;

};
