#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Arrow/ArrowModel.h>
#include <Arrow/ArrowViewer.h>
#include <Arrow/ArrowController.h>

class Arrow: public Component
{
    public:
        Arrow(pComponent start, pComponent end);
        ~Arrow();
        virtual pArrowModel Model();
        virtual void SetModel(pArrowModel model);
        virtual pArrowViewer Viewer();
        virtual void SetViewer(pArrowViewer viewer);
        virtual pArrowController Controller();
        virtual void SetController(pArrowController controller);
    private:

};
