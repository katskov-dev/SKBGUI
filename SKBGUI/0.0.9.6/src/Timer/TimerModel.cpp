#include "Timer/TimerModel.h"

TimerModel::TimerModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(false);
    __onTimer = nullptr;
    __interval = sf::milliseconds(1000);
    __current_time = sf::milliseconds(0);
    SetEnabled(false);

}

TimerModel::~TimerModel()
{
    //dtor
}

sf::Time TimerModel::Interval()
{
    return __interval;
}

void TimerModel::SetInterval(sf::Time interval)
{
    __interval = interval;
}

void TimerModel::SetOnTimer(void (*func)())
{
    __onTimer = func;
}

