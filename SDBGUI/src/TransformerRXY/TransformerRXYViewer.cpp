#include "TransformerRXY/TransformerRXYViewer.h"

TransformerRXYViewer::TransformerRXYViewer(pTransformerRXYModel model): ComponentViewer(model)
{

}

TransformerRXYViewer::~TransformerRXYViewer()
{
    //dtor
}

void TransformerRXYViewer::Render(sf::RenderTarget& target)
{

    if (!Owner()->Visible())
        return;
    if (pTransformerRXYModel(Owner())->Target() != nullptr){
        ComponentViewer::RenderBegin(target);
        ComponentViewer::Render(target);

        sf::Vector2f size = Owner()->Size();
        size.x/=2;
        size.y/=2;
        sf::Vector2f offset;

        pTransformerRXYModel(Owner())->arrow_x->Model()->SetAbsoluteCoord(size + Owner()->AbsoluteCoord());

        offset.x=-7;
        offset.y=-138;
        pTransformerRXYModel(Owner())->arrow_y->Model()->SetAbsoluteCoord(size + Owner()->AbsoluteCoord()+offset);

//        offset.x=-125;
//        offset.y=-125;
//        pTransformerRXYModel(Owner())->ring->Model()->SetAbsoluteCoord(size + Owner()->AbsoluteCoord()+offset);

        ComponentViewer::RenderEnd(target);
    }
}
