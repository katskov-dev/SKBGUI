#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <locale>

#include <Component/Component.h>
#include <Button/Button.h>
#include <Transformer/Transformer.h>
#include <Label/Label.h>
#include <Edit/Edit.h>
//---------------------
#include <CircleCollider/CircleCollider.h>
#include <BoxCollider/BoxCollider.h>
#include <Picture/Picture.h>
#include <GUI/GUI.h>
//---------------------------

using namespace std;
//using namespace sf;
pTransformer t;
pTransformerModel m;
pButton button1;
pButton button2;
pButton button3;
pLabel label1;
pEdit edit1;
pCircleCollider collider;
pBoxCollider box;
pPicture pic;

pGUI gui;

void button_handler1()
{
    pTransformerModel(t->Model())->SetTarget(button1);

}

void button_handler2()
{
     pTransformerModel(t->Model())->SetTarget(label1);

}

void button_handler3()
{
    //pTransformerModel(t->Model())->SetTarget(pic);
    pLabelModel(label1)->SetCaption(pEditModel(edit1)->Text());
}

int main()
{
    setlocale(LC_ALL,"russian");
    gui = new GUI(800, 600, "Title");
    button1 = new Button("Button1 ", sf::Vector2f(100, 160));
    button2 = new Button("Button2", sf::Vector2f(300, 160));
    button3 = new Button("Button3", sf::Vector2f(500, 160));
    pButtonController(button1->Controller())->SetOnClick(button_handler1);
    pButtonController(button2->Controller())->SetOnClick(button_handler2);
    pButtonController(button3->Controller())->SetOnClick(button_handler3);
    t = new Transformer();
    label1 = new Label();
    collider = new CircleCollider();
    box = new BoxCollider();
    box->Model()->SetCoord(200, 100);
    edit1 = new Edit();
    pEditModel(edit1->Model())->SetCoord(200, 20);
    pEditModel(edit1->Model())->SetText("Hello world");
    pic = new Picture();
    pic->Model()->SetCoord(20, 300);
    pic->Model()->SetSize(300, 200);


    gui->Model()->Add(pic);
    gui->Model()->Add(button1);
    gui->Model()->Add(button2);
    gui->Model()->Add(button3);
    gui->Model()->Add(t);
    gui->Model()->Add(label1);
    gui->Model()->Add(collider);
    gui->Model()->Add(box);
    gui->Model()->Add(edit1);


  gui->loop();

    return 0;
}
