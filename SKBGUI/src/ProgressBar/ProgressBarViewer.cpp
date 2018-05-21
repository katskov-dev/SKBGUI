#include "ProgressBar/ProgressBarViewer.h"

ProgressBarViewer::ProgressBarViewer(pProgressBarModel model): ComponentViewer(pComponentModel(model))
{

}

ProgressBarViewer::~ProgressBarViewer()
{
    //dtor
}

void ProgressBarViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);
    sf::Vector2f coord = Owner()->AbsoluteCoord();
    sf::Vector2f size = Owner()->Size();
    double current = Owner()->Current() / (Owner()->Max() - Owner()->Min());


    if (!Owner()->Vertical()){
        sf::RectangleShape rect;
        rect.setPosition(coord+sf::Vector2f(1,1));
        rect.setSize(size+sf::Vector2f(-2,-2));
        //frame
        rect.setFillColor(sf::Color(0xffffffff));
        rect.setOutlineColor(sf::Color(0x000000ff));
        rect.setOutlineThickness(1.0);
        rect.setScale(1.0, 1.0);
        target.draw(rect);
        //frame
        rect.setFillColor(sf::Color(0x00000000));
        rect.setOutlineColor(sf::Color(0x000000ff));
        rect.setOutlineThickness(1.0);
        rect.setScale(1.0, 1.0);
        target.draw(rect);
        //progress
        rect.setFillColor(sf::Color(0x99ffccff));
        rect.setOutlineColor(sf::Color(0x00000000));
        rect.setScale(current, 1.0);
        target.draw(rect);
    }
    else{
        sf::RectangleShape rect;
        rect.setPosition(coord+sf::Vector2f(1,size.y-1));
        rect.setSize(sf::Vector2f(size.x-2,-size.y+2));
        //frame
        rect.setFillColor(sf::Color(0xffffffff));
        rect.setOutlineColor(sf::Color(0x000000ff));
        rect.setOutlineThickness(1.0);
        rect.setScale(1.0, 1.0);
        target.draw(rect);
        //frame
        rect.setFillColor(sf::Color(0x00000000));
        rect.setOutlineColor(sf::Color(0x000000ff));
        rect.setOutlineThickness(1.0);
        rect.setScale(1.0, 1.0);
        target.draw(rect);
        //progress
        rect.setFillColor(sf::Color(0x99ffccff));
        rect.setOutlineColor(sf::Color(0x00000000));
        rect.setScale(1.0, current);
        target.draw(rect);
    }



	ComponentViewer::RenderEnd(target);
}

pProgressBarModel ProgressBarViewer::Owner()
{
    return pProgressBarModel(ComponentViewer::Owner());
}

void ProgressBarViewer::SetOwner(pProgressBarModel owner)
{
    ComponentViewer::SetOwner(owner);
}
