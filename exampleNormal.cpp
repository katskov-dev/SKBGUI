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
#include <RevoluteJoint/RevoluteJoint.h>
#include <ProgressBar/ProgressBar.h>
#include <BoxCollider2/BoxCollider2.h>
#include <DistanceJoint/DistanceJoint.h>
#include <WeldJoint/WeldJoint.h>
#include <Camera/Camera.h>
#include <Scene/Scene.h>

pWorld world;

pBoxCollider ground;

pRevoluteJoint revolutejoint;
pDistanceJoint distancejointFL;
pDistanceJoint distancejointFR;
pDistanceJoint distancejointML;
pDistanceJoint distancejointMR;
pDistanceJoint distancejointFLwithML;
pDistanceJoint distancejointFRwithMR;
pDistanceJoint distancejointMLwithRL;
pDistanceJoint distancejointMRwithRR;
pDistanceJoint distancejointFRwithFL;
pDistanceJoint distancejointRRwithRL;
pDistanceJoint distancejointRL;
pDistanceJoint distancejointRR;
pWeldJoint weldJointFL;
pWeldJoint weldJointFR;
pBoxCollider2 Box;
pBoxCollider2 BoxFL;     //front left
pBoxCollider2 BoxML;    //middle left
pBoxCollider2 BoxRL;    //rear left
pBoxCollider2 BoxFR;    //front right
pBoxCollider2 BoxMR;    //middle right
pBoxCollider2 BoxRR;    //rear right
pTimer timer;
pCamera camera;
pScene scene;
void my_contact_handler(pCircleColliderModel collider){
    //collider->Body()->ApplyLinearImpulseToCenter(b2Vec2(100000, 100000), true);
    collider->ApplyMomentum(100000,100000);
    //collider->ApplyForce(100000,100000);
    ground->Model()->SetAngle(ground->Model()->Angle() - 3.0);
}

void my_contact_handler1(pCircleColliderModel collider){
    collider->Body()->SetLinearVelocity(b2Vec2(0,0));

    ground->Model()->SetAngle(ground->Model()->Angle() + 3.0);
    //ground->Model()->Move(sf::Vector2f(5,0));
}





void swap_chairs()
{

    //wheel->Model()->Rotate(1.0);
    //std::cout << wheel->Model()->Angle() << std::endl;
    b2Vec2 coord = Box->Model()->Body()->Model()->myBody()->GetPosition();
    std::cout << "Coord: x = " << coord.x << " " << coord.y << std::endl;
}

const int DIR_DOWN = 0;
const int DIR_LEFT = 1;
const int DIR_RIGHT = 2;
const int DIR_UP = 3;
void platform_move(int dir)
{
    switch (dir){
    case DIR_UP: //forward
        BoxFL->Model()->turn(0.0f,-100.0f);
        BoxML->Model()->turn(0.0f,-100.0f);
        BoxRL->Model()->turn(0.0f,-100.0f);
        BoxFR->Model()->turn(0.0f,-100.0f);
        BoxMR->Model()->turn(0.0f,-100.0f);
        BoxRR->Model()->turn(0.0f,-100.0f);
        break;
    case DIR_RIGHT: //right
        BoxFR->Model()->turn(0.0f,100.0f);
        BoxMR->Model()->turn(0.0f,100.0f);
        BoxRR->Model()->turn(0.0f,100.0f);
        BoxFL->Model()->turn(0.0f,-100.0f);
        BoxML->Model()->turn(0.0f,-100.0f);
        BoxRL->Model()->turn(0.0f,-100.0f);
        break;
    case DIR_LEFT: //left
        BoxFR->Model()->turn(0.0f,-100.0f);
        BoxMR->Model()->turn(0.0f,-100.0f);
        BoxRR->Model()->turn(0.0f,-100.0f);
        BoxFL->Model()->turn(0.0f,100.0f);
        BoxML->Model()->turn(0.0f,100.0f);
        BoxRL->Model()->turn(0.0f,100.0f);
        break;
    case DIR_DOWN: //back
        BoxFR->Model()->turn(0.0f,100.0f);
        BoxMR->Model()->turn(0.0f,100.0f);
        BoxRR->Model()->turn(0.0f,100.0f);
        BoxFL->Model()->turn(0.0f,100.0f);
        BoxML->Model()->turn(0.0f,100.0f);
        BoxRL->Model()->turn(0.0f,100.0f);
        break;
    }
}
void my_keyboard_handler(pComponentModel model, int key)
{
    //cout << key;
    switch (key){
    case 22: //forward
        platform_move(DIR_UP);
        break;
    case 3: //right
        platform_move(DIR_RIGHT);
        break;
    case 0: //left
        platform_move(DIR_LEFT);
        break;
    case 18: //back
        platform_move(DIR_DOWN);
        break;
    }
}
sf::RenderTexture rt;
void timer_on_timer()
{

}
int main()
{
    //создаем главный компонент, он отвечает за работу окна
    pGUI gui = new GUI(1366, 768, "SKBGUI");
    scene = new Scene(gui->Window());
    scene->Model()->SetSize(1366,768);
    gui->Model()->Add(scene);




    pPicture lintex = new Picture();
    lintex->Model()->LoadFromFile("assets/images/linoleum.jpg");
    scene->Model()->Add(lintex);
    lintex->Model()->SetLocalCoord(-1366*3, -768*3);
    lintex->Model()->SetSize(1366*6, 768*6);

    pWorld world = new World();
    gui->Controller()->SetKeyDown(my_keyboard_handler);
    gui->Model()->Add(world);
    ground = new BoxCollider(world, 600, 10, "static");
    ground->Model()->SetLocalCoord(150, 450);
    scene->Model()->Add(ground);










    BoxFL = new BoxCollider2(193,112,12,25,world,"dynamic");
    scene->Model()->Add(BoxFL);
    BoxFR = new BoxCollider2(257,112,12,25,world,"dynamic");
    scene->Model()->Add(BoxFR);
    BoxML = new BoxCollider2(193,150,12,25,world,"dynamic");
    scene->Model()->Add(BoxML);
    BoxMR = new BoxCollider2(257,150,12,25,world,"dynamic");
    scene->Model()->Add(BoxMR);
    BoxRL = new BoxCollider2(193,187,12,25,world,"dynamic");
    scene->Model()->Add(BoxRL);
    BoxRR = new BoxCollider2(257,187,12,25,world,"dynamic");
    scene->Model()->Add(BoxRR);
    Box = new BoxCollider2(225,150,50,100,world,"dynamic");
    scene->Model()->Add(Box);
    Box->Controller()->SetKeyUp(my_keyboard_handler);

    pPicture wood = new Picture();
    wood->Model()->LoadFromFile("assets/images/wood.png");
    wood->Model()->SetSize(sf::Vector2f(50,100));
    Box->Model()->Add(wood);

    pPicture tireFL = new Picture();
    tireFL->Model()->LoadFromFile("assets/images/tire12x25.png");
    tireFL->Model()->SetSize(sf::Vector2f(12,25));
    BoxFL->Model()->Add(tireFL);

    pPicture tireFR = new Picture();
    tireFR->Model()->LoadFromFile("assets/images/tire12x25.png");
    tireFR->Model()->SetSize(sf::Vector2f(12,25));
    BoxFR->Model()->Add(tireFR);

    pPicture tireMR = new Picture();
    tireMR->Model()->LoadFromFile("assets/images/tire12x25.png");
    tireMR->Model()->SetSize(sf::Vector2f(12,25));
    BoxMR->Model()->Add(tireMR);

    pPicture tireML = new Picture();
    tireML->Model()->LoadFromFile("assets/images/tire12x25.png");
    tireML->Model()->SetSize(sf::Vector2f(12,25));
    BoxML->Model()->Add(tireML);

    pPicture tireRR = new Picture();
    tireRR->Model()->LoadFromFile("assets/images/tire12x25.png");
    tireRR->Model()->SetSize(sf::Vector2f(12,25));
    BoxRR->Model()->Add(tireRR);

    pPicture tireRL = new Picture();
    tireRL->Model()->LoadFromFile("assets/images/tire12x25.png");
    tireRL->Model()->SetSize(sf::Vector2f(12,25));
    BoxRL->Model()->Add(tireRL);

    //psensor Sensor = new sensor(50,50,"circle",50);
    //Создадим таймер


//    Sensor->Model()->setWorld(world->Model()->GetWorld());
//    Sensor->Model()->createBody();
//    MyCircle = new BoxCollider(world,100,50,"dynamic");
//    MyCircle->Model()->SetLocalCoord(90,80);
//    MyCircle2 = new CircleCollider(world,25,"dynamic");
//    MyCircle2->Model()->SetLocalCoord(165,130);
//    gui->Model()->Add(MyCircle);
//    gui->Model()->Add(MyCircle2);
   // gui->Model()->Add(circleButton);
    world->Model()->World().Step(0.0, 0, 0);
    MyContactListener contactListener;
//    revolutejoint = new RevoluteJoint(Box->Model()->Body(),Box2->Model()->Body(),world);
    distancejointFL = new DistanceJoint(BoxFL->Model()->Body(),Box->Model()->Body(),world);
    scene->Model()->Add(distancejointFL);
    distancejointFR = new DistanceJoint(BoxFR->Model()->Body(),Box->Model()->Body(),world);
    scene->Model()->Add(distancejointFR);
//    weldJointFR = new WeldJoint(Box->Model()->Body(),BoxFR->Model()->Body(),world);
//    weldJointFL= new WeldJoint(BoxFL->Model()->Body(),Box->Model()->Body(),world);
    distancejointML = new DistanceJoint(BoxML->Model()->Body(),Box->Model()->Body(),world);
    scene->Model()->Add(distancejointML);
    distancejointMR = new DistanceJoint(BoxMR->Model()->Body(),Box->Model()->Body(),world);
    scene->Model()->Add(distancejointMR);
    distancejointRL = new DistanceJoint(BoxRL->Model()->Body(),Box->Model()->Body(),world);
    scene->Model()->Add(distancejointRL);
    distancejointRR = new DistanceJoint(BoxRR->Model()->Body(),Box->Model()->Body(),world);
    scene->Model()->Add(distancejointRR);
    distancejointFLwithML = new DistanceJoint(BoxFL->Model()->Body(),BoxML->Model()->Body(),world);
    scene->Model()->Add(distancejointFLwithML);
    distancejointFRwithMR = new DistanceJoint(BoxFR->Model()->Body(),BoxMR->Model()->Body(),world);
    scene->Model()->Add(distancejointFRwithMR);
    distancejointMLwithRL = new DistanceJoint(BoxML->Model()->Body(),BoxRL->Model()->Body(),world);
    scene->Model()->Add(distancejointMLwithRL);
    distancejointMRwithRR = new DistanceJoint(BoxMR->Model()->Body(),BoxRR->Model()->Body(),world);
    scene->Model()->Add(distancejointMRwithRR);
    distancejointFRwithFL = new DistanceJoint(BoxFR->Model()->Body(),BoxFL->Model()->Body(),world);
    scene->Model()->Add(distancejointFRwithFL);
    distancejointRRwithRL = new DistanceJoint(BoxRR->Model()->Body(),BoxRL->Model()->Body(),world);
   scene->Model()->Add(distancejointRRwithRL);

    world->Model()->GetWorld()->SetContactListener(&contactListener);



    timer = new Timer();
    timer->Model()->SetInterval(sf::milliseconds(1));
    timer->Model()->SetOnTimer(timer_on_timer);
    timer->Model()->SetEnabled(true);
    gui->Model()->Add(timer);

    camera = new Camera();
    camera->Model()->SetLocalCoord(10,10);
    camera->Model()->SetSize(150,100);
    //scene->Model()->Add(camera);
    Box->Model()->Add(camera);

    //"Оживить" окно, заставить его реагировать на взаимодействие
    //функция завершит свою работу, когда окно будет закрыто
    gui->loop();
    return 0;
}

