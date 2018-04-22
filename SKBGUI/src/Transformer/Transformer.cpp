#include "Transformer/Transformer.h"

Transformer::Transformer()
{
    __model = new TransformerModel();
    __viewer = new TransformerViewer(pTransformerModel(__model));
    __controller = new TransformerController(pTransformerModel(__model));
}

Transformer::~Transformer()
{
    //dtor
}

pTransformerModel Transformer::Model()
{
    return pTransformerModel(__model);
}

void Transformer::SetModel(pTransformerModel model)
{
    __model = model;
}

pTransformerViewer Transformer::Viewer()
{
    return pTransformerViewer(__viewer);
}

void Transformer::SetViewer(pTransformerViewer viewer)
{
    __viewer = viewer;
}

pTransformerController Transformer::Controller()
{
    return pTransformerController(__controller);
}

void Transformer::SetController(pTransformerController controller)
{
    __controller = controller;
}

