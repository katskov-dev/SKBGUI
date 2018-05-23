#pragma once

#include <base.h>
#include <Component/Component.h>
#include <CheckBox/CheckBoxModel.h>
#include <CheckBox/CheckBoxViewer.h>
#include <CheckBox/CheckBoxController.h>

class CheckBox: public Component
{
    public:
        CheckBox();
        ~CheckBox();
        virtual pCheckBoxModel Model();
        virtual void SetModel(pCheckBoxModel model);
        virtual pCheckBoxViewer Viewer();
        virtual void SetViewer(pCheckBoxViewer viewer);
        virtual pCheckBoxController Controller();
        virtual void SetController(pCheckBoxController controller);
    private:

};
