#include "Picture/PictureModel.h"

PictureModel::PictureModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);

	__texture = nullptr;
	__class = "Picture";
}

PictureModel::~PictureModel()
{
    //dtor
}

sf::Texture* PictureModel::Texture()
{
    return __texture;
}

void PictureModel::SetTexture(sf::Texture* texture)
{
    __texture = texture;
}

void PictureModel::LoadFromFile(std::string filename)
{
    __texture = new sf::Texture();
    __texture->loadFromFile(filename);
    SetSize(__texture->getSize().x, __texture->getSize().y);
}
