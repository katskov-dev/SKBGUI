#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <TransformerRXY/TransformerRXYModel.h>

class TransformerRXYViewer: public ComponentViewer
{
    public:
        TransformerRXYViewer(pTransformerRXYModel model);
        virtual ~TransformerRXYViewer();
        virtual void Render(sf::RenderTarget& target);
//        virtual pTransformerRXYModel Owner();
//        virtual void SetOwner(pTransformerRXYModel owner);
    protected:

    private:
        sf::CircleShape __points[9];
};
