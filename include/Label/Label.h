#pragma once
#include <base.h>
#include <Label/LabelModel.h>
#include <Label/LabelViewer.h>
#include <Label/LabelController.h>
#include <Component/Component.h>



class Label: public Component
{
    public:
        Label();
        virtual ~Label();
        virtual pLabelModel Model();
        virtual void SetModel(pLabelModel model);
        virtual pLabelViewer Viewer();
        virtual void SetViewer(pLabelViewer viewer);
        virtual pLabelController Controller();
        virtual void SetController(pLabelController controller);
     //   virtual std::string Class();
    protected:

    private:
};
