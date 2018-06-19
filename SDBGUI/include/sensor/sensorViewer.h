#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <sensor/sensorModel.h>
#include <SFML/Graphics.hpp>

class sensorViewer: public ComponentViewer
{
    public:
        sensorViewer(psensorModel model);
        virtual ~sensorViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual psensorModel Owner();
        virtual void SetOwner(psensorModel owner);
    protected:

    private:
    sf::CircleShape shape;

};
