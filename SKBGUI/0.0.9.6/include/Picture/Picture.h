#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Picture/PictureModel.h>
#include <Picture/PictureViewer.h>
#include <Picture/PictureController.h>

class Picture: public Component
{
    public:
        Picture();
        ~Picture();
        virtual pPictureModel Model();
        virtual void SetModel(pPictureModel model);
        virtual pPictureViewer Viewer();
        virtual void SetViewer(pPictureViewer viewer);
        virtual pPictureController Controller();
        virtual void SetController(pPictureController controller);
       // virtual std::string Class();
    private:

};
