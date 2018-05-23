#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class TimerModel: public ComponentModel
{
    public:
        TimerModel();
        virtual ~TimerModel();
        sf::Time Interval();
        void SetInterval(sf::Time interval);
        void SetOnTimer(void (*func)());


    protected:

    private:


        sf::Time __current_time;
        sf::Time __interval;
        void (*__onTimer)();

        friend TimerController;
        friend TimerViewer;
        friend Timer;
};
