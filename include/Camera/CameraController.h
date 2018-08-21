#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Camera/CameraModel.h>
#include <SFML/Graphics.hpp>

class CameraController: public ComponentController
{
    public:
        CameraController(pCameraModel model);
        virtual ~CameraController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pCameraModel Owner();
        virtual void SetOwner(pCameraModel owner);

    protected:

    private:
};
