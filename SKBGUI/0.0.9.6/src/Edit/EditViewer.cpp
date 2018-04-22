#include "Edit/EditViewer.h"
#include <iostream>
EditViewer::EditViewer(pEditModel model): ComponentViewer(model)
{
    __rect.setPosition(Owner()->AbsoluteCoord());
    __rect.setSize(Owner()->Size());
    __rect.setFillColor(sf::Color(0xffffffff));
    __rect.setOutlineColor(sf::Color(0x666666ff));
    __rect.setOutlineThickness(1.0);
    //загружаем шрифт и устанавливаем его для надписи на кнопке
    font.loadFromFile("assets/fonts/OpenSans-Regular.ttf");
    text.setFont(font);
    text.setColor(sf::Color(0x000000ff));
    pEditModel(Owner())->__clock.restart();
}

EditViewer::~EditViewer()
{

}

void EditViewer::Render(sf::RenderTarget& target)
{
    ComponentViewer::RenderBegin(target);
    ComponentViewer::Render(target);


    //настраиваем "адаптивный текст" который всегда находится примерно в центре кнопки
    text.setCharacterSize(Owner()->Size().y * 0.8);
    float offset_y = 0; //Owner()->Size().y * 0.05;
    text.setString((pEditModel(Owner()))->Text());
    text.setColor(Owner()->TextColor());
    float offset_x = 5;
    text.setPosition(Owner()->AbsoluteCoord()+sf::Vector2f(offset_x, offset_y));
    __rect.setPosition(Owner()->AbsoluteCoord()+sf::Vector2f(+1, +1));
    __rect.setSize(Owner()->Size() + sf::Vector2f(-2, -2));
    __rect.setFillColor(Owner()->FillColor());

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
        sf::Int64 time = pEditModel(Owner())->__clock.getElapsedTime().asMilliseconds() % 1000;

        if ((time / 500) % 2 == 0)
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
