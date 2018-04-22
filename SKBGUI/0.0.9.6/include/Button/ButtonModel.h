#pragma once
#include <base.h>
#include <Component/ComponentModel.h>
#include <string>
const int BUTTON_STATE_NORMAL = 0;
const int BUTTON_STATE_MOVE = 1;
const int BUTTON_STATE_DOWN = 2;
class ButtonModel: public ComponentModel
{
    public:
        ButtonModel();
        virtual ~ButtonModel();
        std::string Caption();
        void SetCaption(std::string caption);
        virtual std::string SerializeToString();
    protected:

    private:
        std::string __caption;

};
