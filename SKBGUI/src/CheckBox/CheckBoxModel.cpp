#include "CheckBox/CheckBoxModel.h"

CheckBoxModel::CheckBoxModel(): ComponentModel()
{
    SetCoord(0, 0);
    SetSize(150, 25);
	SetVisibleBorders(true);
}

CheckBoxModel::~CheckBoxModel()
{
    //dtor
}
