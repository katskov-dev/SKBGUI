#include "ProgressBar/ProgressBarModel.h"

ProgressBarModel::ProgressBarModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    __vertical = false;
    __min = 0.0;
    __max = 100.0;
    __current = 50.0;

}

ProgressBarModel::~ProgressBarModel()
{
    //dtor
}

bool ProgressBarModel::Vertical()
{
    return __vertical;
}

void ProgressBarModel::SetVertical(bool vertical)
{
    __vertical = vertical;
}

double ProgressBarModel::Max()
{
    return __max;
}

double ProgressBarModel::Min()
{
    return __min;
}

double ProgressBarModel::Current()
{
    return __current;
}

void ProgressBarModel::SetMax(double max)
{
    __max = max;
}

void ProgressBarModel::SetMin(double min)
{
    __min = min;
}

void ProgressBarModel::SetCurrent(double current)
{
    if (current > __max)
        current = __max;
    if (current < __min)
        current = __min;
    __current = current;
}

