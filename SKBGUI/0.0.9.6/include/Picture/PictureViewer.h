#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Picture/PictureModel.h>
#include <SFML/Graphics.hpp>

class PictureViewer: public ComponentViewer
{
    public:
        PictureViewer(pPictureModel model);
        virtual ~PictureViewer();
        virtual void Render(sf::RenderTarget& target);
//        virtual pPictureModel Owner();
//        virtual void SetOwner(pPictureModel owner);
    protected:

    private:


};
