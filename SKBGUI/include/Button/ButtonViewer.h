#pragma once
#include <base.h>
#include <Button/ButtonModel.h>
#include <SFML/Graphics.hpp>

class ButtonViewer: public ComponentViewer
{
    public:
        ButtonViewer(pButtonModel model);
        virtual ~ButtonViewer();
        virtual void Render(sf::RenderTarget& target);
//        virtual pButtonModel Owner();
//        virtual void SetOwner(pButtonModel owner);
//    protected:

    private:
        sf::RectangleShape __rect;
        sf::Font font;
        sf::Text text;
        sf::FloatRect getViewport(sf::RenderTarget& target);
        sf::Texture __theme[9];


        sf::Sprite __theme_sprite[9];
};
