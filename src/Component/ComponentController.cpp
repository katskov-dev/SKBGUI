#include "Component/ComponentController.h"
#include <SDBGUI_math.h>
#include <math.h>
ComponentController::ComponentController(pComponentModel owner)
{
    SetOwner(owner);
    SetClick(nullptr);
    SetMouseDown(nullptr);
    SetMouseUp(nullptr);
    SetMouseMove(nullptr);
    SetMouseWheel(nullptr);
    SetKeyDown(nullptr);
    SetKeyUp(nullptr);
    SetCreated(nullptr);
    SetDestroy(nullptr);
    SetPaint(nullptr);
    SetIdle(nullptr);
}

ComponentController::~ComponentController()
{
    //dtor
}

void ComponentController::SetOwner(pComponentModel owner)
{
    __owner = owner;
}

pComponentModel ComponentController::Owner()
{
    return __owner;
}

bool ComponentController::Handle(sf::Event event)
{
   // UpdateEvent(event);
    //if (! Owner()->Enabled())
        //return false;



    //обработка событий

    switch (event.type){
        case sf::Event::MouseButtonPressed:{
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
//            sf::Vector2f mc = sf::Vector2f(x,y);
//            sf::Vector2f szh = Owner()->Size();
//            szh.x /= 2.0;
//            szh.y /= 2.0;
//            RotatePointOf(mc, Owner()->AbsoluteCoord()+szh, Owner()->Angle());
//            x = std::floor(mc.x);
//            y = std::floor(mc.y);
            sf::Vector2f pos = Owner()->AbsoluteCoord();
            sf::Vector2f size = Owner()->Size();
            if ((x > pos.x) && (x < pos.x + size.x) && (y > pos.y) && (y < pos.y + size.y)){
                //Owner()->SetFocus(false);

                pComponentModel parent = Owner()->Parent();
                if (parent != nullptr){
                    parent->SetFocus(false);
                    parent->SetFocus(true);
                }
                Owner()->SetFocus(true);

                if (MouseDown() != nullptr){
                    MouseDown()(Owner(), event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
                }

            }
            else
                Owner()->SetFocus(false);
            break;
        }
        case sf::Event::MouseButtonReleased:{

            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            sf::Vector2f pos = Owner()->AbsoluteCoord();
            sf::Vector2f size = Owner()->Size();
            if ((x > pos.x) && (x < pos.x + size.x) && (y > pos.y) && (y < pos.y + size.y)){
                if (MouseUp() != nullptr){
                    MouseUp()(Owner(), event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
                }
                if (Click() != nullptr){
                    Click()(Owner());
                }
                if (event.mouseButton.button == sf::Mouse::Right){
                    //Owner()->SetAngle(Owner()->Angle()+5.0);
                }
            }

            break;
        }
        case sf::Event::MouseMoved:{
            int x = event.mouseMove.x;
            int y = event.mouseMove.y;
            sf::Vector2f pos = Owner()->AbsoluteCoord();
            sf::Vector2f size = Owner()->Size();
            //std::cout << x << std::endl;
            if ((x > pos.x) && (x < pos.x + size.x) && (y > pos.y) && (y < pos.y + size.y)){
                callFunc(MouseMove());

            }
            //callFunc(MouseMove());
            break;
        };

        case sf::Event::MouseWheelScrolled:{
            if (Owner()->Focus()){
                if (MouseWheel() != nullptr){
                    MouseWheel()(Owner(), event.mouseWheelScroll.x, event.mouseWheelScroll.y, event.mouseWheelScroll.delta);
                }
            }
            break;
        }

        case sf::Event::KeyPressed:{
            if ((KeyDown() != nullptr) && (Owner()->Focus()))
                KeyDown()(Owner(), event.key.code);

            break;
        };

        case sf::Event::KeyReleased:{
            if ((KeyUp() != nullptr) && (Owner()->Focus()))
                KeyUp()(Owner(), event.key.code);
            break;
        };

    }

    //обработка потомками

    for (int i = Owner()->Count()-1; i >= 0; i--){
      //  Owner()->Children(i)->Controller()->Handle(event);
        if (Owner()->Children(i)->Controller()->Handle(event))
            return true;
    }

    return false;

}

void ComponentController::Update(sf::Time time)
{
    if (! Owner()->Enabled())
        return;
    //обработка потомками
    for (int i = 0; i < Owner()->Count(); i++){
        Owner()->Children(i)->Controller()->Update(time);
    }
}

void ComponentController::RunIdle()
{
    callFunc(Idle());
    for (int i = 0; i < Owner()->Count(); i++){
        Owner()->Children(i)->Controller()->RunIdle();
    }
}


void ComponentController::SetMouseDown(MouseButtonCallback func)
{
    __mouseDown = func;
}

void ComponentController::SetMouseUp(MouseButtonCallback func)
{
    __mouseUp = func;
}

void ComponentController::SetMouseMove(simpleCallback func)
{
    __mouseMove = func;
}

void ComponentController::SetMouseWheel(MouseWheelCallback func)
{
    __mouseWheel = func;
}

void ComponentController::SetKeyDown(keyboardCallback func)
{
    __keyDown = func;
}

void ComponentController::SetKeyUp(keyboardCallback func)
{
    __keyUp = func;
}

void ComponentController::SetClick(simpleCallback func)
{
    __click = func;
}

void ComponentController::SetCreated(simpleCallback func)
{
    __created = func;
}

void ComponentController::SetDestroy(simpleCallback func)
{
    __destroy = func;
}

void ComponentController::SetPaint(simpleCallback func)
{
    __paint = func;
}

void ComponentController::SetIdle(simpleCallback func)
{
    __idle = func;
}

MouseButtonCallback ComponentController::MouseDown()
{
    return __mouseDown;
}

MouseButtonCallback ComponentController::MouseUp()
{
    return __mouseUp;
}

simpleCallback ComponentController::MouseMove()
{
    return __mouseMove;
}

MouseWheelCallback ComponentController::MouseWheel()
{
    return __mouseWheel;
}

keyboardCallback ComponentController::KeyDown()
{
    return __keyDown;
}

keyboardCallback ComponentController::KeyUp()
{
    return __keyUp;
}

simpleCallback ComponentController::Click()
{
    return __click;
}

simpleCallback ComponentController::Created()
{
    return __created;
}

simpleCallback ComponentController::Destroy()
{
    return __destroy;
}

void ComponentController::callFunc(simpleCallback func)
{
    if (func != nullptr){

        func(Owner());
    }
}

simpleCallback ComponentController::Paint()
{
    return __paint;
}

simpleCallback ComponentController::Idle()
{
    return __idle;
}

