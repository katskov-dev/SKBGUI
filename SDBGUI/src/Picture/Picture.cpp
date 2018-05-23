#include <Picture/Picture.h>


Picture::Picture()
{
    SetModel(new PictureModel());
    SetViewer(new PictureViewer(Model()));
    SetController(new PictureController(Model()));
}

Picture::~Picture()
{

}

pPictureModel Picture::Model()
{
    return pPictureModel(__model);
}

void Picture::SetModel(pPictureModel model)
{
    __model = model;
}

pPictureViewer Picture::Viewer()
{
    return pPictureViewer(__viewer);
}

void Picture::SetViewer(pPictureViewer viewer)
{
    __viewer = viewer;
}

pPictureController Picture::Controller()
{
    return pPictureController(__controller);
}

void Picture::SetController(pPictureController controller)
{
    __controller = controller;
}

