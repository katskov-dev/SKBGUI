#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>

const int MYCIRCLE_STATE_GREEN = 0;
const int MYCIRCLE_STATE_RED = 1;


class MyCircleModel: public ComponentModel
{
    public:
        MyCircleModel();
        virtual ~MyCircleModel();
        int MyState();
        void SetMyState(int mystate);
    protected:

    private:
        int __mystate;

};
