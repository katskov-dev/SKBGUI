
#include <GUI/GUI.h>
#include <Button/Button.h>
#include <Picture/Picture.h>
#include <Transformer/Transformer.h>
#include <SFML/System.hpp>
#include <Edit/Edit.h>
#include <Label/Label.h>
#include <string>
#include <iostream>

#include <Panel/Panel.h>
#include <Table/Table.h>
#include <Timer/Timer.h>
#include <Animation/Animation.h>

#include <CheckBox/CheckBox.h>

#include <ProgressBar/ProgressBar.h>
#include <CircleCollider/CircleCollider.h>

#include <Scene/Scene.h>
#include <World/World.h>

pGUI gui;
pScene scene;
pWorld world;
pCircleCollider wheel_1;
pPicture wheel_p;

void init()
{
    gui = new GUI(800, 600, "SKBGUI");
    world = new World();
    gui->Model()->Add(world);

    scene = new Scene(gui->Window());
    scene->Model()->SetSize(800, 500);
    gui->Model()->Add(scene);

    wheel_1 = new CircleCollider(world, 10, "dynamic");
    wheel_1->Model()->SetLocalCoord(100, 100);

    wheel_p = new Picture();
    wheel_p->Model()->LoadFromFile("assets/images/wheel.png");
    wheel_p->Model()->SetSize(20,20);
    wheel_1->Model()->Add(wheel_p);

    scene->Model()->Add(wheel_1);
}

int main()
{
    //создаем главный компонент, он отвечает за работу окна

    //-----------Создание компонентов---------

    init();




    //"Оживить" окно, заставить его реагировать на взаимодействие
    //функция завершит свою работу, когда окно будет закрыто
    gui->loop();
    return 0;
}

