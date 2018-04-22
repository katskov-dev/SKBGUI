#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Transformer/TransformerModel.h>
#include <math.h>


class TransformerController: public ComponentController
{
    public:
        TransformerController(pTransformerModel model);
        virtual ~TransformerController();
        virtual bool Handle(sf::Event event);
//        virtual pTransformerModel Owner();
//        virtual void SetOwner(pTransformerModel owner);

    protected:

    private:
        sf::Vector2f __oldMouseCoord;
};
