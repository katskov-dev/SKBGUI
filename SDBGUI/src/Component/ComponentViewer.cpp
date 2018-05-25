#include "Component/ComponentViewer.h"
#include <cmath>
#include <stdlib.h>
ComponentViewer::ComponentViewer(pComponentModel owner)
{
    SetOwner(owner);
    __border.setPosition(Owner()->LocalCoord());
    __border.setSize(Owner()->Size());
    __border.setFillColor(sf::Color(0x00000000));
    __border.setOutlineColor(sf::Color(0x00ff00ff));
    __border.setOutlineThickness(1.0);
}

ComponentViewer::~ComponentViewer()
{

}

void ComponentViewer::Render(sf::RenderTarget& target)
{
    if (!Owner()->Visible())
        return;
    __view = getView(target);

    if (Owner()->VisibleBorders()){
        __border.setPosition(sf::Vector2f(1, 1) + Owner()->AbsoluteCoord());
        __border.setSize(__owner->Size() + sf::Vector2f(-2, -2));
        if (__owner->Focus())
            __border.setOutlineColor(sf::Color(0x00ff00ff));
        else
            __border.setOutlineColor(sf::Color(0xaaaaaaff));
        target.draw(__border);

    }
}

pComponentModel ComponentViewer::Owner()
{
    return pComponentModel(__owner);
}

void ComponentViewer::SetOwner(pComponentModel owner)
{
    __owner = pComponentModel(owner);
}

void ComponentViewer::RenderBegin(sf::RenderTarget& target)
{
    if (!Owner()->Visible())
        return;
//    __view= target.getView();
//    __view.reset(sf::FloatRect(0, 0, 400, 600));
//    __view.setViewport(sf::FloatRect(0.0, 0.0, 0.5, 1.0));
//    target.setView(__view);
    __oldView = target.getView();
    //target.setView(target.getDefaultView());
    __view = getView(target);
    target.setView(__view);
}

void ComponentViewer::RenderEnd(sf::RenderTarget& target)
{
    if (!Owner()->Visible())
        return;
    //pComponentController c= Owner()->__owner->Controller();
    //pComponentModel m= Owner();
    //if (c->Paint() != nullptr){
        //std::cout << c->Paint();
    //}


    for (int i = 0; i < Owner()->Count(); i++){
        Owner()->Children(i)->Viewer()->Render(target);
    }
    //target.setView(target.getDefaultView());
    target.setView(__oldView);
}

sf::View ComponentViewer::getView(sf::RenderTarget& target)
{
    sf::View v= target.getDefaultView();
    sf::Vector2f sz = v.getSize();

    //std::cout << sz.x << " " << sz.y << std::endl;
    sf::FloatRect viewport;
    sf::Vector2f size = Owner()->Size();
    sf::Vector2f coord = Owner()->AbsoluteCoord();
    viewport.left = coord.x / sz.x;
    viewport.top = coord.y / sz.y;
    viewport.height = (size.y) / sz.y;
    viewport.width = (size.x) / sz.x;
    sf::FloatRect view_border;
    view_border.left = coord.x;
    view_border.top = coord.y;
    view_border.width = size.x;
    view_border.height =  size.y;
    //merge with parent view
    v.getViewport().left;


    viewport.left = std::max(viewport.left, __oldView.getViewport().left);
    viewport.width = std::fmin(viewport.width, __oldView.getViewport().width - viewport.left + __oldView.getViewport().left);
    viewport.top = std::max(viewport.top, __oldView.getViewport().top);
    viewport.height = std::fmin(viewport.height, __oldView.getViewport().height - viewport.top + __oldView.getViewport().top);

    view_border.left = std::fmax(view_border.left, __oldView.getCenter().x - __oldView.getSize().x / 2);
    view_border.width = std::fmin(view_border.width, __oldView.getCenter().x + __oldView.getSize().x / 2 - view_border.left);
    view_border.top = std::fmax(view_border.top, __oldView.getCenter().y - __oldView.getSize().y / 2);
    view_border.height = std::fmin(view_border.height, __oldView.getCenter().y + __oldView.getSize().y / 2 - view_border.top);
    v.reset(view_border);
    v.setViewport(viewport);
    return v;
}
