#include "Timer/TimerController.h"

TimerController::TimerController(pTimerModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

TimerController::~TimerController()
{
    //dtor
}

bool TimerController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
    return false;
}

pTimerModel TimerController::Owner()
{
    return pTimerModel(ComponentController::Owner());
}

void TimerController::SetOwner(pTimerModel owner)
{
    ComponentController::SetOwner(owner);
}

void TimerController::Update(sf::Time time)
{
    ComponentController::Update(time);
    if (Owner()->Enabled()){
        Owner()->__current_time += time;
        if (Owner()->__current_time >= Owner()->__interval){
            if (Owner()->__onTimer != nullptr)
                Owner()->__onTimer();
            Owner()->__current_time -= Owner()->__interval;
        }
    }
}
