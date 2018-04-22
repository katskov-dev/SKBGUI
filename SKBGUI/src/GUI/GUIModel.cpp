#include "GUI/GUIModel.h"

GUIModel::GUIModel(int width, int height): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(width, height);
    SetFocus(true);
    SetName("gui");
	//SetVisibleBorders(true);

}

GUIModel::~GUIModel()
{
    //dtor
}
