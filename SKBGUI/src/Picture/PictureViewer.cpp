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
        sf::Sprite* image = new sf::Sprite(*texture);
        image->setPosition(Owner()->AbsoluteCoord());
        image->setScale(s_x, s_y);
        target.draw(*image);
	}


	ComponentViewer::RenderEnd(target);
}
