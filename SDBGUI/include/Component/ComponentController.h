#pragma once
#include <SFML/Graphics.hpp>
#include <base.h>
#include <Component/ComponentModel.h>

const int GUI_IDLE = 1234;

typedef void (*simpleCallback)(pComponentModel model);
typedef void (*MouseButtonCallback)(pComponentModel model, int x, int y, int button);
typedef void (*MouseWheelCallback)(pComponentModel model, int x, int y, int delta);
typedef void (*keyboardCallback)(pComponentModel model, int key);


class ComponentController
{
    public:
        ComponentController(pComponentModel owner);
        virtual ~ComponentController();
        virtual void SetOwner(pComponentModel owner);
        virtual pComponentModel Owner();
        virtual bool Handle(sf::Event event);
        virtual void Update(sf::Time time);
        virtual void RunIdle();

        //setters
        void SetMouseDown(MouseButtonCallback func);
        void SetMouseUp(MouseButtonCallback func);
        void SetMouseMove(simpleCallback func);
        void SetMouseWheel(MouseWheelCallback func);
        void SetKeyDown(keyboardCallback func);
        void SetKeyUp(keyboardCallback func);
        void SetClick(simpleCallback func);
        void SetCreated(simpleCallback func);
        void SetDestroy(simpleCallback func);
        void SetPaint(simpleCallback func);
        void SetIdle(simpleCallback func);

        //getters
        MouseButtonCallback MouseDown();
        MouseButtonCallback MouseUp();
        simpleCallback MouseMove();
        MouseWheelCallback MouseWheel();
        keyboardCallback KeyDown();
        keyboardCallback KeyUp();
        simpleCallback Click();
        simpleCallback Created();
        simpleCallback Destroy();
        simpleCallback Paint();
        simpleCallback Idle();

    protected:

    private:
        pComponentModel __owner;
        MouseButtonCallback __mouseDown;
        MouseButtonCallback __mouseUp;
        simpleCallback __mouseMove;
        MouseWheelCallback __mouseWheel;
        keyboardCallback __keyDown;
        keyboardCallback __keyUp;
        simpleCallback __click;
        simpleCallback __created;
        simpleCallback __destroy;
        simpleCallback __paint;
        simpleCallback __idle;
        void callFunc(simpleCallback func);

};
