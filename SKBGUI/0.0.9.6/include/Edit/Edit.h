#pragma once
#include <base.h>
#include <Edit/EditModel.h>
#include <Edit/EditViewer.h>
#include <Edit/EditController.h>
#include <Component/Component.h>

class Edit: public Component
{
    public:
        Edit();
        virtual ~Edit();
        virtual pEditModel Model();
        virtual void SetModel(pEditModel model);
        virtual pEditViewer Viewer();
        virtual void SetViewer(pEditViewer viewer);
        virtual pEditController Controller();
        virtual void SetController(pEditController controller);
     //   virtual std::string Class();
    protected:

    private:
};
