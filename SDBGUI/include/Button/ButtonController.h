#pragma once
#include <base.h>
#include <Component/ComponentModel.h>
#include <Component/ComponentController.h>
#include <Button/ButtonModel.h>
typedef void (*OnClickEventFunc)();

class ButtonController: public ComponentController
{
    public:
        ButtonController(pButtonModel model);
        virtual ~ButtonController();
        virtual bool Handle(sf::Event event);
        OnClickEventFunc onClick();
        void SetOnClick(OnClickEventFunc func);
//        virtual pButtonModel Owner();
//        virtual void SetOwner(pButtonModel owner);
    protected:

    private:
        OnClickEventFunc __onClick;
};
