#include "CheckBox/CheckBoxModel.h"

CheckBoxModel::CheckBoxModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    SetChecked(false);

}

CheckBoxModel::~CheckBoxModel()
{
    //dtor
}

bool CheckBoxModel::Checked()
{
    return __checked;
}

void CheckBoxModel::SetChecked(bool checked)
{
    __checked = checked;
}
