#include "TransformerRXY/TransformerRXY.h"

TransformerRXY::TransformerRXY()
{
    __model = new TransformerRXYModel();
    __viewer = new TransformerRXYViewer(pTransformerRXYModel(__model));
    __controller = new TransformerRXYController(pTransformerRXYModel(__model));
}

TransformerRXY::~TransformerRXY()
{
    //dtor
}

pTransformerRXYModel TransformerRXY::Model()
{
    return pTransformerRXYModel(__model);
}

void TransformerRXY::SetModel(pTransformerRXYModel model)
{
    __model = model;
}

pTransformerRXYViewer TransformerRXY::Viewer()
{
    return pTransformerRXYViewer(__viewer);
}

void TransformerRXY::SetViewer(pTransformerRXYViewer viewer)
{
    __viewer = viewer;
}

pTransformerRXYController TransformerRXY::Controller()
{
    return pTransformerRXYController(__controller);
}

void TransformerRXY::SetController(pTransformerRXYController controller)
{
    __controller = controller;
}

