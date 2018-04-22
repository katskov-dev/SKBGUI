#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Timer/TimerModel.h>
#include <Timer/TimerViewer.h>
#include <Timer/TimerController.h>

class Timer: public Component
{
    public:
        Timer();
        ~Timer();
        virtual pTimerModel Model();
        virtual void SetModel(pTimerModel model);
        virtual pTimerViewer Viewer();
        virtual void SetViewer(pTimerViewer viewer);
        virtual pTimerController Controller();
        virtual void SetController(pTimerController controller);
    private:

};
