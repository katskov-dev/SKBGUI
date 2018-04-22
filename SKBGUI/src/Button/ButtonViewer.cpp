#include "Button/ButtonViewer.h"
#include <cmath>

ButtonViewer::ButtonViewer(pButtonModel model): ComponentViewer(model)
{
    __rect.setPosition(Owner()->LocalCoord());
    __rect.setSize(Owner()->Size());
    __rect.setFillColor(sf::Color(0x666666ff));
    __rect.setOutlineColor(sf::Color(0xddddddff));
    __rect.setOutlineThickness(2.0);
    //загружаем шрифт и устанавливаем его для надписи на кнопке
    font.loadFromFile("assets/fonts/OpenSans-Regular.ttf");
    text.setFont(font);
    text.setColor(sf::Color(0x000000ff));
    __theme[0].loadFromFile("assets/images/buttons/body.png");

    __theme[1].loadFromFile("assets/images/buttons/angle-l-t.png");
    __theme[2].loadFromFile("assets/images/buttons/angle-r-t.png");
    __theme[3].loadFromFile("assets/images/buttons/angle-r-b.png");
    __theme[4].loadFromFile("assets/images/buttons/angle-l-b.png");

    __theme[5].loadFromFile("assets/images/buttons/side-t.png");
    __theme[6].loadFromFile("assets/images/buttons/side-r.png");
    __theme[7].loadFromFile("assets/images/buttons/side-b.png");
    __theme[8].loadFromFile("assets/images/buttons/side-l.png");

}

ButtonViewer::~ButtonViewer()
{
    //dtor
}

void ButtonViewer::Render(sf::RenderTarget& target)
{
    ComponentViewer::RenderBegin(target);
    ComponentViewer::Render(target);
    sf::Vector2f coord = Owner()->AbsoluteCoord();
    //std::cout << coord.x << " " << coord.y << std::endl;

    //настраиваем "адаптивный текст" который всегда находится примерно в центре кнопки
    text.setCharacterSize(std::floor(Owner()->Size().y * 0.50));
    float offset_y = Owner()->Size().y * 0.25;
    text.setString((pButtonModel(Owner()))->Caption());
    float offset_x = (Owner()->Size().x - text.getGlobalBounds().width) / 2.0;
    text.setPosition(coord+sf::Vector2f(offset_x, offset_y));
    if (Owner()->Size().x < Owner()->Size().y){
        double text_scale = (Owner()->Size().x-20) / text.getLocalBounds().width;
        text.setScale(text_scale, text_scale);
    }

    __rect.setPosition(coord + sf::Vector2f(2, 2));
    __rect.setSize(Owner()->Size() + sf::Vector2f(-4, -4));
    switch (Owner()->State()){
        case BUTTON_STATE_NORMAL:{
            __rect.setFillColor(sf::Color(0x666666ff));
            for (int i = 0; i < 9; i++)
                __theme_sprite[i].setColor(sf::Color(0xffffffff));
            break;
        };
        case BUTTON_STATE_DOWN:{
            __rect.setFillColor(sf::Color(0x333333ff));
            for (int i = 0; i < 9; i++)
                __theme_sprite[i].setColor(sf::Color(0xddddddff));
            break;
        };
    };

    //THEME
    double scale_x = (Owner()->Size().x-6.0) / 26.0;
    double scale_y = (Owner()->Size().y-6.0) / 26.0;
    //body
    __theme_sprite[0].setScale(scale_x, scale_y);
    __theme_sprite[0].setPosition(coord + sf::Vector2f(3,3));
    __theme_sprite[0].setTexture(__theme[0]);
    //angles
    __theme_sprite[1].setPosition(coord);
    __theme_sprite[1].setTexture(__theme[1]);

    __theme_sprite[2].setPosition(coord +  sf::Vector2f(Owner()->Size().x -3, 0));
    __theme_sprite[2].setTexture(__theme[2]);

    __theme_sprite[3].setPosition(coord + Owner()->Size() + sf::Vector2f(-3, -3));
    __theme_sprite[3].setTexture(__theme[3]);

    __theme_sprite[4].setPosition(coord + sf::Vector2f(0, Owner()->Size().y -3));
    __theme_sprite[4].setTexture(__theme[4]);

    //sides
    __theme_sprite[5].setPosition(coord + sf::Vector2f(3, 0));
    __theme_sprite[5].setScale(scale_x, 1.0);
    __theme_sprite[5].setTexture(__theme[5]);

    __theme_sprite[6].setPosition(coord + sf::Vector2f(Owner()->Size().x-3, 3));
    __theme_sprite[6].setScale(1.0, scale_y);
    __theme_sprite[6].setTexture(__theme[6]);

    __theme_sprite[7].setPosition(coord + sf::Vector2f(3, Owner()->Size().y-3));
    __theme_sprite[7].setScale(scale_x, 1.0);
    __theme_sprite[7].setTexture(__theme[7]);

    __theme_sprite[8].setPosition(coord + sf::Vector2f(0, 3));
    __theme_sprite[8].setScale(1.0, scale_y);
    __theme_sprite[8].setTexture(__theme[8]);




    //
//
//    target.draw(__rect);
//    target.draw(text);

    //theme draw
    target.draw(__theme_sprite[0]);

    target.draw(__theme_sprite[1]);
    target.draw(__theme_sprite[2]);
    target.draw(__theme_sprite[3]);
    target.draw(__theme_sprite[4]);

    target.draw(__theme_sprite[5]);
    target.draw(__theme_sprite[6]);
    target.draw(__theme_sprite[7]);
    target.draw(__theme_sprite[8]);

    target.draw(text);



    ComponentViewer::RenderEnd(target);
}
