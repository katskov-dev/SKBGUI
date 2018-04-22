#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <World/WorldModel.h>
#include <SFML/Graphics.hpp>

class WorldViewer: public ComponentViewer
{
    public:
        WorldViewer(pWorldModel model);
        virtual ~WorldViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pWorldModel Owner();
        virtual void SetOwner(pWorldModel owner);
    protected:

    private:


};
