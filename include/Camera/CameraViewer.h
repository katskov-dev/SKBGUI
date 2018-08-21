#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Camera/CameraModel.h>
#include <SFML/Graphics.hpp>

class CameraViewer: public ComponentViewer
{
    public:
        CameraViewer(pCameraModel model);
        virtual ~CameraViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pCameraModel Owner();
        virtual void SetOwner(pCameraModel owner);
    protected:

    private:


};
