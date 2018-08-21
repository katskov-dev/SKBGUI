#include "Camera/CameraModel.h"

CameraModel::CameraModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    SetViewLimit(false);

}

CameraModel::~CameraModel()
{
    //dtor
}
