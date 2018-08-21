#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class CameraModel: public ComponentModel
{
    public:
        CameraModel();
        virtual ~CameraModel();

    protected:

    private:
	
	friend Camera;
	friend CameraViewer;
	friend CameraController;

};
