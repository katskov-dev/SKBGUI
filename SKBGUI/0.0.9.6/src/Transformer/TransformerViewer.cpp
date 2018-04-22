#include "Transformer/TransformerViewer.h"

TransformerViewer::TransformerViewer(pTransformerModel model): ComponentViewer(model)
{

}

TransformerViewer::~TransformerViewer()
{
    //dtor
}

void TransformerViewer::Render(sf::RenderTarget& target)
{
    if (pTransformerModel(Owner())->Target() != nullptr){
        ComponentViewer::Render(target);
        pTransformerModel(Owner())->UpdatePoints();
        double r = pTransformerModel(Owner())->Radius();
        int activePoint = pTransformerModel(Owner())->activePoint;
        for (int i = 0; i < 9; i++){
            if (activePoint == i)
                __points[i].setFillColor(pTransformerModel(Owner())->__activeColor);
            else
                __points[i].setFillColor(pTransformerModel(Owner())->__defaultColor);
            __points[i].setPosition(pTransformerModel(Owner())->Point(i) + sf::Vector2f(- r, - r));
            __points[i].setRadius(r);
            __points[i].setOutlineColor(sf::Color(0xffffffff));
            __points[i].setOutlineThickness(1.0);
            target.draw(__points[i]);
        }
    }
}
