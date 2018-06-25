#include <GUI/GUI.h>
#include <Button/Button.h>
#include <Picture/Picture.h>
#include <Transformer/Transformer.h>
#include <TransformerRXY/TransformerRXY.h>
#include <SFML/System.hpp>
#include <Edit/Edit.h>
#include <Label/Label.h>
#include <string>
#include <iostream>
#include <sensor/sensor.h>
#include <Panel/Panel.h>
#include <Table/Table.h>
#include <Timer/Timer.h>
#include <Animation/Animation.h>
#include <CircleCollider/CircleCollider.h>
#include <BoxCollider/BoxCollider.h>
#include <CheckBox/CheckBox.h>

#include <ProgressBar/ProgressBar.h>


pWorld world;
pBoxCollider player;
pGUI gui;

void add_platform_1()
{
    sf::Vector2f lc;
    lc.x = sf::Mouse::getPosition(*gui->Window()).x;
    lc.y = sf::Mouse::getPosition(*gui->Window()).y;
    pBoxCollider box = BoxCollider::FastCreate(gui, world, sf::Vector2f(25,25), "static", lc);
    Picture::FastCreate(box, "assets/images/tiles/block_p_solo1.png", sf::Vector2f(25,25), sf::Vector2f(0,0));
}

void player_controller(pComponentModel model, int key)
{
    if (key == sf::Keyboard::W){
        player->Model()->ApplyMomentum(0, -10000 * 5);

    }
    if (key == sf::Keyboard::D){
        player->Model()->ApplyMomentum(10000, 20);

    }
    if (key == sf::Keyboard::A){
        player->Model()->ApplyMomentum(-10000, 20);

    }
    if(key == sf::Keyboard::Num1){
        add_platform_1();
        std::cout << "1 ";
    }

}



int main()
{
    //создаем главный компонент, он отвечает за работу окна
    gui = new GUI(800, 600, "SKBGUI");
    //block size = 25x25
    gui->Controller()->SetKeyDown(player_controller);
    world = new World();
    gui->Model()->Add(world);
    //background
    Picture::FastCreate(gui, "assets/images/bg.png", sf::Vector2f(800,600), sf::Vector2f(0,0));
    //блоки земли
    for (int i = 0; i < 32; i++){
        pBoxCollider box = BoxCollider::FastCreate(gui, world, sf::Vector2f(25,25), "static", sf::Vector2f(25*i, 550));
        Picture::FastCreate(box, "assets/images/tiles/block1.png", sf::Vector2f(25,25), sf::Vector2f(0,0));
    }
    player = BoxCollider::FastCreate(gui, world, sf::Vector2f(25,25), "dynamic", sf::Vector2f(400, 524));
    Animation::FastCreate(player, "assets/images/ball1.png", sf::Vector2f(10,1), sf::seconds(0.125), sf::Vector2f(25,25), sf::Vector2f(0,0));



    gui->loop();
    return 0;
}

