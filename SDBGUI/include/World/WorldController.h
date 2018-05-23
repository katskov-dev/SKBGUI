#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <World/WorldModel.h>
#include <SFML/Graphics.hpp>

class WorldController: public ComponentController
{
    public:
        WorldController(pWorldModel model);
        virtual ~WorldController();
        virtual bool Handle(sf::Event event);
		virtual pWorldModel Owner();
        virtual void SetOwner(pWorldModel owner);
        virtual void Update(sf::Time time);

    protected:

    private:
};
