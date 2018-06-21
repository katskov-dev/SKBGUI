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

 pGUI gui;

pEdit edit;
pLabel label;
pPicture picture;
pPicture picture1;
pProgressBar pb;
pAnimation animation;
pAnimation portal;
pWorld world;
pCircleCollider MyCircle;
pCircleCollider MyCircle2;
pBoxCollider ground;
pButton saveButton;
pButton loadButton;
pButton circleButton;
pEdit QuantEdit;
psensor Sensor2;
pTransformer t;
pBoxCollider leftLow;
pBoxCollider rightLow;
pBoxCollider leftUp;
pBoxCollider rightUp;
pBoxCollider roof;
pPicture gPic;
pPicture bg;
pPicture wood[5];
pAnimation ball;


void my_contact_handler(pCircleColliderModel collider){
    collider->Body()->ApplyLinearImpulseToCenter(b2Vec2(100000, 100000), true);
    ground->Model()->SetAngle(ground->Model()->Angle() - 3.0);
}

void my_contact_handler1(pCircleColliderModel collider){
    collider->Body()->SetLinearVelocity(b2Vec2(0,0));
    MyCircle2->Model()->SetLocalCoord(100,75);
    ground->Model()->SetAngle(ground->Model()->Angle() + 3.0);

}
void my_contact_handler2(pCircleColliderModel collider){
    collider->Body()->ApplyLinearImpulseToCenter(b2Vec2(9000000, 10000000), true);


}
void my_contact_handler3(pCircleColliderModel collider){
    collider->Body()->ApplyLinearImpulseToCenter(b2Vec2(-9000000, 10000000), true);


}

void my_keydown(pComponentModel model, int key)
{
    if (key == sf::Keyboard::Num1){
        std::cout << "num1" << std::endl;
        pBoxCollider box = new BoxCollider(world, 50, 50, "dynamic");
        box->Model()->SetLocalCoord(100, 100);
        gui->Model()->Add(box);

        pTransformerRXY t = new TransformerRXY();
        t->Model()->SetTarget(box);
        gui->Model()->Add(t);

        pPicture wood = new Picture();
        wood->Model()->LoadFromFile("assets/images/wood.png");
        wood->Model()->SetSize(50,50);
        box->Model()->Add(wood);
    }
}

//обработчик для кнопки
void my_button_handler(pComponentModel model, int x, int y, int button)
{
    //вытаскиваем текст из поля ввода
    sf::String text = edit->Model()->Text();
    //устанавливаем его в label
    label->Model()->SetCaption(text);
}

void swap_chairs()
{


}

int main()
{
    //создаем главный компонент, он отвечает за работу окна
    gui = new GUI(800, 600, "SKBGUI");
    gui->Controller()->SetKeyDown(my_keydown);
     bg = new Picture();
    bg->Model()->LoadFromFile("assets/images/bg.png");
    bg->Model()->SetSize(800,600);
    bg->Model()->SetLocalCoord(0,0);

    gui->Model()->Add(bg);

    QuantEdit= new Edit();
    QuantEdit->Model()->SetLocalCoord(300,0);
    QuantEdit->Model()->SetText("0.25");
    world = new World();
    gui->Model()->Add(world);
    world->Model()->setUpEdit(QuantEdit);
     ground = new BoxCollider(world, 800, 150, "static");
    ground->Model()->SetLocalCoord(0, 450);
    leftLow = new BoxCollider(world, 50, 50, "dynamic");
    leftLow->Model()->SetLocalCoord(100, 400);
    rightLow = new BoxCollider(world, 50, 50, "dynamic");
    rightLow->Model()->SetLocalCoord(200, 400);
    rightUp = new BoxCollider(world, 50, 50, "dynamic");
    rightUp->Model()->SetLocalCoord(200, 350);
    leftUp = new BoxCollider(world, 50, 50, "dynamic");
    leftUp->Model()->SetLocalCoord(100, 350);
    roof = new BoxCollider(world, 150, 10, "dynamic");
    roof->Model()->SetLocalCoord(100, 350);
    gui->Model()->Add(ground);
    gui->Model()->Add(leftLow);
    gui->Model()->Add(leftUp);
    gui->Model()->Add(rightLow);
    gui->Model()->Add(rightUp);
    gui->Model()->Add(roof);
//    Sensor2= new sensor(world->Model()->GetWorld(), 100,425,"123",25);
//    Sensor2->Model()->SetOnContact(my_contact_handler2);
    psensor Sensor3= new sensor(world->Model()->GetWorld(), 500,425,"123",25);
    Sensor3->Model()->SetOnContact(my_contact_handler3);
//    psensor Sensor1= new sensor(world->Model()->GetWorld(), 700,440,"123",25);
//    Sensor1->Model()->SetOnContact(my_contact_handler1);
//    gui->Model()->Add(Sensor1);

    //Sensor->Model()->SetLocalCoord(79,300);
    pButton saveButton = new Button();
    pButton circleButton = new Button();
    circleButton->Model()->SetCaption("CircleCollider");
    circleButton->Model()->SetLocalCoord(450,0);
    saveButton->Model()->SetCaption("Save");
    saveButton->Model()->SetLocalCoord(0,0);
    pButton loadButton = new Button();
    loadButton->Model()->SetCaption("Load");
    loadButton->Model()->SetLocalCoord(150,0);
//    gui->Model()->Add(Sensor2);
    gui->Model()->Add(Sensor3);
    //psensor Sensor = new sensor(50,50,"circle",50);
    //Создадим таймер
    pTimer timer = new Timer();
    //Установить интервал
    timer->Model()->SetInterval(sf::milliseconds(500));
    //Установить обработчик на таймер
    //timer->Model()->SetOnTimer(swap_chairs);
    //Добавить таймер
    gui->Model()->Add(timer);
   // gui->Model()->Add(saveButton);
   // gui->Model()->Add(loadButton);
//    gui->Model()->Add(Sensor2);
    //запускаем таймер
    timer->Model()->SetEnabled(true);

//    Sensor->Model()->setWorld(world->Model()->GetWorld());
//    Sensor->Model()->createBody();
    //MyCircle = new CircleCollider(world,25,"dynamic");
    //MyCircle->Model()->SetLocalCoord(200,150);
//    MyCircle2 = new CircleCollider(world,25,"dynamic");
//    MyCircle2->Model()->SetLocalCoord(100,75);
    MyCircle = new CircleCollider(world,25,"dynamic");
    MyCircle->Model()->SetLocalCoord(500,75);
    //gui->Model()->Add(MyCircle);
//    gui->Model()->Add(MyCircle2);
   // gui->Model()->Add(circleButton);
    MyContactListener contactListener;
    world->Model()->GetWorld()->SetContactListener(&contactListener);
    gui->Model()->Add(QuantEdit);
    //gui->Model()->Add(MyCircle);
//    t = new Transformer();
//   // t->Model()->SetTarget(MyCircle2);
//    gui->Model()->Add(t);

//    pTransformerRXY t1 = new TransformerRXY();
//    t1->Model()->SetTarget(Sensor1);
//    gui->Model()->Add(t1);
//
//    animation = new Animation();
//    animation->Model()->setTilesCount(sf::Vector2f(8,4));
//
//    animation->Model()->setInterval(sf::seconds(0.05));
//    animation->Model()->SetSize(sf::Vector2f(100,200));
//    animation->Model()->loadFromFile("assets/images/fire.png");
//    animation->Model()->SetLocalCoord(Sensor1->Model()->LocalCoord()+sf::Vector2f(-25,-120));
//
//    gui->Model()->Add(animation);
//
//    portal = new Animation();
//    portal->Model()->setTilesCount(sf::Vector2f(5,5));
//
//    portal->Model()->setInterval(sf::seconds(0.05));
//    portal->Model()->SetSize(sf::Vector2f(100,100));
//    portal->Model()->loadFromFile("assets/images/portal.png");
//    portal->Model()->SetLocalCoord(Sensor2->Model()->LocalCoord()+sf::Vector2f(-25,-25));
//
//    gui->Model()->Add(portal);

    //MyCircle2->Model()->Body()->SetTransform(b2Vec2(400,300), 0.0);

//    pCheckBox checkbox = new CheckBox();
//    checkbox->Model()->SetLocalCoord(10, 180);
//    std::string s = "Test";
//    s[0] = 0x04;
//    s[1] = 0x1b;
//    checkbox->Model()->SetCaption(s);
//    panel->Model()->Add(checkbox);

    gPic = new Picture();
    gPic->Model()->LoadFromFile("assets/images/ground.png");
    gPic->Model()->SetLocalCoord(0,430);
    gPic->Model()->SetSize(ground->Model()->Size() + sf::Vector2f(2,2+20));
    gui->Model()->Add(gPic);


    gui->Model()->Add(MyCircle);

    wood[0] = new Picture();
    wood[0]->Model()->LoadFromFile("assets/images/wood.png");
    wood[0]->Model()->SetSize(50,50);
    leftUp->Model()->Add(wood[0]);

    wood[1] = new Picture();
    wood[1]->Model()->LoadFromFile("assets/images/wood.png");
    wood[1]->Model()->SetSize(50,50);
    leftLow->Model()->Add(wood[1]);

    wood[2] = new Picture();
    wood[2]->Model()->LoadFromFile("assets/images/wood.png");
    wood[2]->Model()->SetSize(50,50);
    rightUp->Model()->Add(wood[2]);

    wood[3] = new Picture();
    wood[3]->Model()->LoadFromFile("assets/images/wood.png");
    wood[3]->Model()->SetSize(50,50);
    rightLow->Model()->Add(wood[3]);

    wood[4] = new Picture();
    wood[4]->Model()->LoadFromFile("assets/images/wood.png");
    wood[4]->Model()->SetSize(150, 10);
    roof->Model()->Add(wood[4]);

    ball = new Animation();
    ball->Model()->setTilesCount(sf::Vector2f(10,1));
    ball->Model()->SetSize(62.5,50);
    ball->Model()->SetLocalCoord(-6.25,0);
    ball->Model()->loadFromFile("assets/images/ball.png");
    ball->Model()->setInterval(sf::seconds(0.1));
    MyCircle->Model()->Add(ball);










    //"Оживить" окно, заставить его реагировать на взаимодействие
    //функция завершит свою работу, когда окно будет закрыто
    gui->loop();
    return 0;
}

