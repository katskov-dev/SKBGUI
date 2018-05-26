#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <SFML/Graphics.hpp>
#include <Picture/PictureModel.h>

class PictureController: public ComponentController
{
    public:
        PictureController(pPictureModel model);
        virtual ~PictureController();
        virtual bool Handle(sf::Event event);
//        virtual pPictureModel Owner();
//        virtual void SetOwner(pPictureModel owner);
    protected:

    private:
};
