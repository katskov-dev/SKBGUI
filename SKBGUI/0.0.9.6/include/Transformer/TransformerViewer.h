#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Transformer/TransformerModel.h>

class TransformerViewer: public ComponentViewer
{
    public:
        TransformerViewer(pTransformerModel model);
        virtual ~TransformerViewer();
        virtual void Render(sf::RenderTarget& target);
//        virtual pTransformerModel Owner();
//        virtual void SetOwner(pTransformerModel owner);
    protected:

    private:
        sf::CircleShape __points[9];
};
