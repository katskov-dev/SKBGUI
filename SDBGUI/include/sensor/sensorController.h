#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <sensor/sensorModel.h>
#include <SFML/Graphics.hpp>

class sensorController: public ComponentController
{
    public:
        sensorController(psensorModel model);
        virtual ~sensorController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual psensorModel Owner();
        virtual void SetOwner(psensorModel owner);

    protected:

    private:
};
