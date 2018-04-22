#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Timer/TimerModel.h>
#include <SFML/Graphics.hpp>


class TimerController: public ComponentController
{
    public:
        TimerController(pTimerModel model);
        virtual ~TimerController();
        virtual bool Handle(sf::Event event);
		virtual pTimerModel Owner();
        virtual void SetOwner(pTimerModel owner);
        virtual void Update(sf::Time time);

    protected:

    private:
};
