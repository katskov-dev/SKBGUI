#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Picker/PickerModel.h>
#include <Picker/PickerViewer.h>
#include <Picker/PickerController.h>

class Picker: public Component
{
    public:
        Picker();
        ~Picker();
        virtual pPickerModel Model();
        virtual void SetModel(pPickerModel model);
        virtual pPickerViewer Viewer();
        virtual void SetViewer(pPickerViewer viewer);
        virtual pPickerController Controller();
        virtual void SetController(pPickerController controller);
    private:

};
