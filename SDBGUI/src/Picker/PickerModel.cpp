#include "Picker/PickerModel.h"

PickerModel::PickerModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 150);
    SetVisibleBorders(true);


}

PickerModel::~PickerModel()
{
    //dtor
}

sf::Texture& PickerModel::Mask()
{
    return __mask;
}

void PickerModel::SetMask(sf::Texture& mask)
{
    __mask = mask;
}

void PickerModel::LoadMaskFromFile(std::string filename)
{
    __mask.loadFromFile(filename);

}
