#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class prismaticJointModel: public ComponentModel
{
    public:
        prismaticJointModel();
        virtual ~prismaticJointModel();

    protected:

    private:
	
	friend prismaticJoint;
	friend prismaticJointViewer;
	friend prismaticJointController;

};
