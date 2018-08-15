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

pPicture Picture::FastCreate(pComponent parent, std::string filename, sf::Vector2f size, sf::Vector2f localcoord)
{
    pPicture picture;
    picture = new Picture();
    picture->Model()->LoadFromFile(filename);
    picture->Model()->SetSize(size);
    picture->Model()->SetLocalCoord(localcoord);
    if (parent != nullptr){
        parent->Model()->Add(picture);
    }
    return picture;
}
