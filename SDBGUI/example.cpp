#include <GUI/GUI.h>
#include <Button/Button.h>
#include <Picture/Picture.h>
#include <Transformer/Transformer.h>
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
#include <CheckBox/CheckBox.h>

#include <ProgressBar/ProgressBar.h>

pEdit edit;
pLabel label;
pPicture picture;
pPicture picture1;
pProgressBar pb;
pAnimation animation;
psensor Sensor;
pWorld world;
pCircleCollider MyCircle;
pCircleCollider MyCircle2;
pButton saveButton;
pButton loadButton;
pButton circleButton;
pEdit QuantEdit;

pTransformer t;


class MyContactListener : public b2ContactListener
  {

    void BeginContact(b2Contact* contact) {

    if ((contact->GetFixtureA()->IsSensor()||contact->GetFixtureB()->IsSensor()))
        {
            if (contact->GetFixtureA()->IsSensor()){
                pCircleColliderModel col = pCircleColliderModel(contact->GetFixtureB()->GetUserData());
                cout << "B_ADDR: " << (void*)col << endl;



            }
        }
    }

    void EndContact(b2Contact* contact) {
        if ((contact->GetFixtureA()->IsSensor()||contact->GetFixtureB()->IsSensor()))
        {

        }
    }
  };

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
    QuantEdit= new Edit();
    QuantEdit->Model()->SetLocalCoord(300,0);
    QuantEdit->Model()->SetText("0.5");
    psensor Sensor= new sensor(85,300,"123",25);
    pButton saveButton = new Button();
    pButton circleButton = new Button();
    circleButton->Model()->SetCaption("CircleCollider");
    circleButton->Model()->SetLocalCoord(450,0);
    saveButton->Model()->SetCaption("Save");
    saveButton->Model()->SetLocalCoord(0,0);
    pButton loadButton = new Button();
    loadButton->Model()->SetCaption("Load");
    loadButton->Model()->SetLocalCoord(150,0);

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
    gui->Model()->Add(Sensor);
    //запускаем таймер
    timer->Model()->SetEnabled(true);
    pWorld world = new World();
    gui->Model()->Add(world);
    world->Model()->setUpEdit(QuantEdit);
    world->Model()->createGroundBody();
    Sensor->Model()->setWorld(world->Model()->GetWorld());
    Sensor->Model()->createBody();
    //MyCircle = new CircleCollider(world,25,"dynamic");
    //MyCircle->Model()->SetLocalCoord(200,150);
    MyCircle2 = new CircleCollider(world,25,"dynamic");
    MyCircle2->Model()->SetLocalCoord(100,75);
    //gui->Model()->Add(MyCircle);
    gui->Model()->Add(MyCircle2);
    gui->Model()->Add(circleButton);
    MyContactListener contactListener;
    world->Model()->GetWorld()->SetContactListener(&contactListener);
    gui->Model()->Add(QuantEdit);

    t = new Transformer();
    t->Model()->SetTarget(MyCircle2);
    gui->Model()->Add(t);

//    pCheckBox checkbox = new CheckBox();
//    checkbox->Model()->SetLocalCoord(10, 180);
//    std::string s = "Test";
//    s[0] = 0x04;
//    s[1] = 0x1b;
//    checkbox->Model()->SetCaption(s);
//    panel->Model()->Add(checkbox);










    //"Оживить" окно, заставить его реагировать на взаимодействие
    //функция завершит свою работу, когда окно будет закрыто
    gui->loop();
    return 0;
}

