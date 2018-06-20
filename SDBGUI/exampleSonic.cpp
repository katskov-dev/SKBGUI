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
pAnimation sonic;
pPicture gPic;
pPicture bg;

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
    collider->Body()->ApplyLinearImpulseToCenter(b2Vec2(2000000, 10000000), true);


}
void my_contact_handler3(pCircleColliderModel collider){
    collider->Body()->ApplyLinearImpulseToCenter(b2Vec2(-2000000, 10000000), true);


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
    sf::Vector2f coord_buffer = picture->Model()->LocalCoord();
    picture->Model()->SetLocalCoord(picture1->Model()->LocalCoord());
    picture1->Model()->SetLocalCoord(coord_buffer);
    pb->Model()->SetCurrent(pb->Model()->Current()+5);
}

int main()
{
    //создаем главный компонент, он отвечает за работу окна
    pGUI gui = new GUI(800, 600, "SKBGUI");
    bg = new Picture();
    bg->Model()->LoadFromFile("assets/images/bg.png");
    bg->Model()->SetSize(800,600);
    bg->Model()->SetLocalCoord(0,0);

    gui->Model()->Add(bg);
    QuantEdit= new Edit();
    QuantEdit->Model()->SetLocalCoord(300,0);
    QuantEdit->Model()->SetText("0.25");
    pWorld world = new World();
    gui->Model()->Add(world);
    world->Model()->setUpEdit(QuantEdit);
    ground = new BoxCollider(world, 800, 150, "static");
    ground->Model()->SetLocalCoord(0, 450);
    gui->Model()->Add(ground);
    Sensor2= new sensor(world->Model()->GetWorld(), 100,425,"123",25);
    Sensor2->Model()->SetOnContact(my_contact_handler2);
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
    gui->Model()->Add(Sensor2);
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
    gui->Model()->Add(saveButton);
    gui->Model()->Add(loadButton);
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
    gui->Model()->Add(circleButton);
    MyContactListener contactListener;
    world->Model()->GetWorld()->SetContactListener(&contactListener);
    gui->Model()->Add(QuantEdit);

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
    gPic->Model()->SetSize(ground->Model()->Size() + sf::Vector2f(2,20+2));
    gui->Model()->Add(gPic);

    sonic = new Animation();
    sonic->Model()->setTilesCount(sf::Vector2f(8,1));
    sonic->Model()->SetSize(50,50);
    sonic->Model()->loadFromFile("assets/images/sonic1.png");
    sonic->Model()->setInterval(sf::seconds(0.125));
    MyCircle->Model()->Add(sonic);

    gui->Model()->Add(MyCircle);












    //"Оживить" окно, заставить его реагировать на взаимодействие
    //функция завершит свою работу, когда окно будет закрыто
    gui->loop();
    return 0;
}

