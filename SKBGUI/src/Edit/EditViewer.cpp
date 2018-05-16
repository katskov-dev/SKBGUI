#include "Edit/EditViewer.h"
#include <iostream>
#include <cmath>
EditViewer::EditViewer(pEditModel model): ComponentViewer(model)
{
    __rect.setPosition(Owner()->AbsoluteCoord());
    __rect.setSize(Owner()->Size());
    __rect.setFillColor(sf::Color(0xffffffff));

    __rect.setOutlineColor(sf::Color(0x666666ff));
    __rect.setOutlineThickness(0.0);

    pEditModel(Owner())->__clock.restart();
}

EditViewer::~EditViewer()
{

}

void EditViewer::Render(sf::RenderTarget& target)
{
    if (!Owner()->Visible())
        return;
    ComponentViewer::RenderBegin(target);
    ComponentViewer::Render(target);

    sf::Text text = Owner()->__render_text;
    //настраиваем "адаптивный текст" который всегда находится примерно в центре кнопки

    float offset_y = 0; //Owner()->Size().y * 0.05;
    float offset_x = 5;
    text.setPosition(Owner()->AbsoluteCoord()+sf::Vector2f(offset_x, offset_y));
    __rect.setFillColor(Owner()->FillColor());
    if (Owner()->VisibleOutline()){
        __rect.setOutlineColor(sf::Color(0x000000ff));
        __rect.setOutlineThickness(1.0);
        __rect.setPosition(Owner()->AbsoluteCoord()+sf::Vector2f(+1, +1));
        __rect.setSize(Owner()->Size() + sf::Vector2f(-2, -2));
    }
    else{
        __rect.setOutlineColor(sf::Color(0x000000ff));
        __rect.setOutlineThickness(0.0);
        __rect.setPosition(Owner()->AbsoluteCoord());
        __rect.setSize(Owner()->Size());
    }

    //line
    sf::Vector2f cx = text.findCharacterPos(pEditModel(Owner())->CaretPos()) - Owner()->AbsoluteCoord();
    //std::cout << cx.x << std::endl;
//    line[0] = sf::Vertex(sf::Vector2f(cx.x, 3) + Owner()->Coord(), sf::Color(0x00ff00ff));
//    line[1] = sf::Vertex(sf::Vector2f(cx.x, Owner()->Size().y - 3) + Owner()->Coord(), sf::Color(0x00ff00ff));
    line[0] = sf::Vertex(sf::Vector2f(cx.x, 3) + Owner()->AbsoluteCoord(), sf::Color(0x000000ff));
    line[1] = sf::Vertex(sf::Vector2f(cx.x, Owner()->Size().y - 3) + Owner()->AbsoluteCoord() , sf::Color(0x000000ff));

//    switch (Owner()->State()){
//        case BUTTON_STATE_NORMAL:{
//            __rect.setFillColor(sf::Color(0x666666ff));
//            break;
//        };
//        case BUTTON_STATE_DOWN:{
//            __rect.setFillColor(sf::Color(0x333333ff));
//            break;
//        };
//    };

    target.draw(__rect);
    target.draw(text);
    if (Owner()->Focus()){
//        sf::Int64 time = pEditModel(Owner())->__clock.getElapsedTime().asMilliseconds() % 1000;
//
//        if ((time / 500) % 2 == 0)
//            target.draw(line, 2, sf::Lines);

        double angle = ( (3.14159)) * pEditModel(Owner())->__clock.getElapsedTime().asSeconds();
        sf::Color s_color;
        sf::Color color = pEditModel(Owner())->FillColor();
        s_color.r = floor(abs(sin(angle)) * color.r);
        s_color.g = floor(abs(sin(angle)) * color.g);
        s_color.b = floor(abs(sin(angle)) * color.b);
        //s_color.a = floor(abs(sin(angle)) * color.a);
        line[0].color = s_color;
        line[1].color = s_color;
        target.draw(line, 2, sf::Lines);
    }

    ComponentViewer::RenderEnd(target);
}

pEditModel EditViewer::Owner()
{
    return (pEditModel)ComponentViewer::Owner();
}
void EditViewer::SetOwner(pEditModel owner)
{
    ComponentViewer::SetOwner(pComponentModel(owner));
}
