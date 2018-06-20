#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <TransformerRXY/TransformerRXYModel.h>
#include <math.h>


class TransformerRXYController: public ComponentController
{
    public:
        TransformerRXYController(pTransformerRXYModel model);
        virtual ~TransformerRXYController();
        virtual bool Handle(sf::Event event);
//        virtual pTransformerRXYModel Owner();
//        virtual void SetOwner(pTransformerRXYModel owner);

    protected:

    private:
        sf::Vector2f __oldMouseCoord;
};
