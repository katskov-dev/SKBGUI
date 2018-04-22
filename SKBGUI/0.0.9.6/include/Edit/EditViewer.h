#pragma once
#include <base.h>
#include <Edit/EditModel.h>
#include <Component/ComponentViewer.h>
#include <SFML/Graphics.hpp>

class EditViewer: public ComponentViewer
{
    public:
        EditViewer(pEditModel model);
        virtual ~EditViewer();
        virtual void Render(sf::RenderTarget& target);
        virtual pEditModel Owner();
        virtual void SetOwner(pEditModel owner);

    protected:

    private:
        sf::RectangleShape __rect;
        sf::Font font;
        sf::Text text;
        sf::Vertex line[2];

};
