#include <Timer/Timer.h>


Timer::Timer()
{
    SetModel(new TimerModel());
    SetViewer(new TimerViewer(Model()));
    SetController(new TimerController(Model()));
}

Timer::~Timer()
{

}

pTimerModel Timer::Model()
{
    return pTimerModel(__model);
}

void Timer::SetModel(pTimerModel model)
{
    __model = model;
}

pTimerViewer Timer::Viewer()
{
    return pTimerViewer(__viewer);
}

void Timer::SetViewer(pTimerViewer viewer)
{
    __viewer = viewer;
}

pTimerController Timer::Controller()
{
    return pTimerController(__controller);
}

void Timer::SetController(pTimerController controller)
{
    __controller = controller;
}

