#include <Camera/Camera.h>


Camera::Camera()
{
    SetModel(new CameraModel());
    SetViewer(new CameraViewer(Model()));
    SetController(new CameraController(Model()));
}

Camera::~Camera()
{

}

pCameraModel Camera::Model()
{
    return pCameraModel(__model);
}

void Camera::SetModel(pCameraModel model)
{
    __model = model;
}

pCameraViewer Camera::Viewer()
{
    return pCameraViewer(__viewer);
}

void Camera::SetViewer(pCameraViewer viewer)
{
    __viewer = viewer;
}

pCameraController Camera::Controller()
{
    return pCameraController(__controller);
}

void Camera::SetController(pCameraController controller)
{
    __controller = controller;
}

