#include "Timer/TimerViewer.h"

TimerViewer::TimerViewer(pTimerModel model): ComponentViewer(pComponentModel(model))
{

}

TimerViewer::~TimerViewer()
{
    //dtor
}

void TimerViewer::Render(sf::RenderTarget& target)
{
	//ComponentViewer::RenderBegin(target);
	//ComponentViewer::Render(target);



	//ComponentViewer::RenderEnd(target);
}

pTimerModel TimerViewer::Owner()
{
    return pTimerModel(ComponentViewer::Owner());
}

void TimerViewer::SetOwner(pTimerModel owner)
{
    ComponentViewer::SetOwner(owner);
}
