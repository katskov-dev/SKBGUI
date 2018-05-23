#pragma once

#include <base.h>
#include <Component/Component.h>
#include <MyCircle/MyCircleModel.h>
#include <MyCircle/MyCircleViewer.h>
#include <MyCircle/MyCircleController.h>

class MyCircle: public Component
{
    public:
        MyCircle();
        ~MyCircle();
        virtual pMyCircleModel Model();
        virtual void SetModel(pMyCircleModel model);
        virtual pMyCircleViewer Viewer();
        virtual void SetViewer(pMyCircleViewer viewer);
        virtual pMyCircleController Controller();
        virtual void SetController(pMyCircleController controller);
    private:

};
