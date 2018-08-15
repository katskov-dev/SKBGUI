#include "Picture/PictureModel.h"

PictureModel::PictureModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetTexture(nullptr);
	__texture = nullptr;
	__class = "Picture";
	SetVisibleBorders(false);
	SetViewLimit(false);
	SetMask(nullptr);
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

void PictureModel::LoadFromFile(std::string filename, bool useSelectMask)
{
    __texture = new sf::Texture();
    __texture->loadFromFile(filename);
    SetSize(__texture->getSize().x, __texture->getSize().y);
    if (useSelectMask)
        LoadMaskFromFile(filename);
}

sf::Texture* PictureModel::Mask()
{
    return __mask;
}

void PictureModel::SetMask(sf::Texture* mask)
{
    __mask = mask;
}

void PictureModel::LoadMaskFromFile(std::string filename)
{
    __mask = new sf::Texture();
    __mask->loadFromFile(filename);
    SetSize(__texture->getSize().x, __texture->getSize().y);

}
