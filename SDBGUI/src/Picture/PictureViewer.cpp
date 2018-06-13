#include "Picture/PictureViewer.h"
#include <iostream>
#include <cmath>
PictureViewer::PictureViewer(pPictureModel model): ComponentViewer(pComponentModel(model))
{

}

PictureViewer::~PictureViewer()
{
    //dtor
}

void PictureViewer::Render(sf::RenderTarget& target)
{
    if (!Owner()->Visible())
        return;
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);
	sf::Texture* texture = pPictureModel(Owner())->Texture();
	if (texture != nullptr){
        double x = Owner()->Size().x;
        double y = Owner()->Size().y;
        sf::Vector2u size = texture->getSize();
        double s_x = x / size.x;
        double s_y = y / size.y;
        double scale = std::fmin(s_x, s_y);

        sf::Vector2f szh= Owner()->Size();
        szh.x /= 2.0;
        szh.y /= 2.0;

        sf::Sprite* image = new sf::Sprite(*texture);
        image->setPosition(Owner()->AbsoluteCoord());
        image->setScale(s_x, s_y);

        sf::RenderStates rs = Owner()->RenderStates();
        //rs.transform.translate(-Owner()->AbsoluteCoord() - sf::Vector2f(Owner()->Size().x / 2.0, Owner()->Size().y / 2.0));
        //rs.transform.translate(sf::Vector2f(Owner()->Size().x / 2.0, Owner()->Size().y / 2.0));
        //rs.transform.rotate(Owner()->Angle());

        target.draw(*image);
	}


	ComponentViewer::RenderEnd(target);
}
