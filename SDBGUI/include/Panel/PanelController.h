#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Panel/PanelModel.h>
#include <SFML/Graphics.hpp>

class PanelController: public ComponentController
{
    public:
        PanelController(pPanelModel model);
        virtual ~PanelController();
        virtual bool Handle(sf::Event event);
		virtual pPanelModel Owner();
        virtual void SetOwner(pPanelModel owner);

    protected:

    private:
};
