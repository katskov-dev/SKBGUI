#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Label/LabelModel.h>
#include <SFML/Graphics.hpp>

class LabelController: public ComponentController
{
    public:
        LabelController(pLabelModel model);
        virtual ~LabelController();
        virtual bool Handle(sf::Event event);
        virtual pLabelModel Owner();
        virtual void SetOwner(pLabelModel owner);

    protected:

    private:
};
