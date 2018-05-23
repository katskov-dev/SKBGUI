#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <SFML/Graphics.hpp>

class GUIController: public ComponentController
{
    public:
        GUIController(pGUIModel model);
        virtual ~GUIController();
        virtual bool Handle(sf::Event event);
        virtual void Update(sf::Time time);

    protected:

    private:
};
