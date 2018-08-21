#include "Camera/CameraViewer.h"

CameraViewer::CameraViewer(pCameraModel model): ComponentViewer(pComponentModel(model))
{

}

CameraViewer::~CameraViewer()
{
    //dtor
}

void CameraViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);
	ComponentViewer::Render(target);
    sf::RectangleShape frame;
    frame.setPosition(Owner()->AbsoluteCoord());
    frame.setSize(Owner()->Size());
    frame.setFillColor(sf::Color(0xff000033));
    frame.setOutlineColor(sf::Color(0xff000088));
    frame.setOutlineThickness(1);

    target.draw(frame);


	ComponentViewer::RenderEnd(target);
}

pCameraModel CameraViewer::Owner()
{
    return pCameraModel(ComponentViewer::Owner());
}

void CameraViewer::SetOwner(pCameraModel owner)
{
    ComponentViewer::SetOwner(owner);
}
