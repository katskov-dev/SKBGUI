#include "MyCircle/MyCircleModel.h"

MyCircleModel::MyCircleModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(200, 200);
    SetVisibleBorders(true);
    SetMyState(MYCIRCLE_STATE_RED);

}

MyCircleModel::~MyCircleModel()
{
    //dtor
}

int MyCircleModel::MyState()
{
    return __mystate;
}

void MyCircleModel::SetMyState(int mystate)
{
    __mystate = mystate;
}
