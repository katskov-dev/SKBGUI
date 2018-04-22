#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Panel/PanelModel.h>
#include <Panel/PanelViewer.h>
#include <Panel/PanelController.h>

class Panel: public Component
{
    public:
        Panel();
        ~Panel();
        virtual pPanelModel Model();
        virtual void SetModel(pPanelModel model);
        virtual pPanelViewer Viewer();
        virtual void SetViewer(pPanelViewer viewer);
        virtual pPanelController Controller();
        virtual void SetController(pPanelController controller);
      //  virtual std::string Class();
    private:

};
