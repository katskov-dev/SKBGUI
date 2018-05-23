#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Timer/TimerModel.h>
#include <SFML/Graphics.hpp>

class TimerViewer: public ComponentViewer
{
    public:
        TimerViewer(pTimerModel model);
        virtual ~TimerViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pTimerModel Owner();
        virtual void SetOwner(pTimerModel owner);
    protected:

    private:


};
