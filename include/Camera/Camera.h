#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Camera/CameraModel.h>
#include <Camera/CameraViewer.h>
#include <Camera/CameraController.h>

class Camera: public Component
{
    public:
        Camera();
        ~Camera();
        virtual pCameraModel Model();
        virtual void SetModel(pCameraModel model);
        virtual pCameraViewer Viewer();
        virtual void SetViewer(pCameraViewer viewer);
        virtual pCameraController Controller();
        virtual void SetController(pCameraController controller);
    private:

};
