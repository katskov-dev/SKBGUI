#pragma once

#include <base.h>
#include <Component/Component.h>
#include <ProgressBar/ProgressBarModel.h>
#include <ProgressBar/ProgressBarViewer.h>
#include <ProgressBar/ProgressBarController.h>

class ProgressBar: public Component
{
    public:
        ProgressBar();
        ~ProgressBar();
        virtual pProgressBarModel Model();
        virtual void SetModel(pProgressBarModel model);
        virtual pProgressBarViewer Viewer();
        virtual void SetViewer(pProgressBarViewer viewer);
        virtual pProgressBarController Controller();
        virtual void SetController(pProgressBarController controller);
    private:

};
