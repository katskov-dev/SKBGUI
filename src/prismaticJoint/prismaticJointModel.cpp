#include "prismaticJoint/prismaticJointModel.h"

prismaticJointModel::prismaticJointModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);	
	
}

prismaticJointModel::~prismaticJointModel()
{
    //dtor
}
