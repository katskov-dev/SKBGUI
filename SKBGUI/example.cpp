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



pEdit edit;
pLabel label;
pPicture picture;
pPicture picture1;
pProgressBar pb;

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
    //-----------Создание компонентов---------
    ///////////////////Кнопка
    //Создаем
    pButton button = new Button();
    //установить надпись на кнопке
    button->Model()->SetCaption(L"Установить");
    //Добавляем в gui
    gui->Model()->Add(button);
    //Добавить обработчик на нажатие кнопки
    button->Controller()->SetMouseDown(my_button_handler);
    //Методы общие для всех компонентов:
    //задать положение компонента относительно предка
    button->Model()->SetLocalCoord(300, 10);
    //задать размеры
    button->Model()->SetSize(200, 50);


    //////////////////////Панель
    pPanel panel = new Panel();
    panel->Model()->SetLocalCoord(10, 10);
    panel->Model()->SetSize(280, 580);
    //задание цвета для панели
    panel->Model()->SetColor(sf::Color(0xffffccff));

    gui->Model()->Add(panel);

    ////////////////Поле ввода
    edit = new Edit();
    //установить текст
    edit->Model()->SetText("Hello");

    edit->Model()->SetLocalCoord(300, 70);
    edit->Model()->SetSize(200, 25);
    edit->Model()->SetTextColor(sf::Color(0x000000ff));
    gui->Model()->Add(edit);

    //зададим цвет edit'у
    edit->Model()->SetFillColor(sf::Color(0xB0EFFFff));

    ////////////Надпись (текстовая строка)
    label = new Label();
    //установить текст
    label->Model()->SetCaption(L"Тест");

    label->Model()->SetLocalCoord(300, 100);
    label->Model()->SetSize(250, 40);
    gui->Model()->Add(label);


    //////////////////////Изображение
    picture = new Picture();
    //загружаем картинку
    picture->Model()->LoadFromFile("assets/images/chair.png");

    picture->Model()->SetLocalCoord(300, 150);
    picture->Model()->SetSize(250, 400);

    gui->Model()->Add(picture);

    picture1 = new Picture();
    //загружаем картинку
    picture1->Model()->LoadFromFile("assets/images/chair1.png");

    picture1->Model()->SetLocalCoord(1600, 1150);
    picture1->Model()->SetSize(250, 400);

    gui->Model()->Add(picture1);

    //Создаем таблицу
    pTable table = new Table();
    //сдвинем таблицу
    table->Model()->SetLocalCoord(5,5);
    //задать количество стобцов
    table->Model()->SetColCount(3);
    //задать количство строк
    table->Model()->SetRowCount(7);
    //задать ширину столбца
    table->Model()->SetColWidth(0, 30);
    //задать высоту сроки
    table->Model()->SetRowHeight(0, 15);
    //Обращение к ячейкам таблицы...
    table->Model()->Cell(0, 0)->Model()->SetText("No");
     table->Model()->Cell(0, 0)->Model()->SetFillColor(sf::Color(0xB0EFFFff));
    table->Model()->Cell(0, 1)->Model()->SetText("Time");
     table->Model()->Cell(0, 1)->Model()->SetFillColor(sf::Color(0xB0EFFFff));
    table->Model()->Cell(0, 2)->Model()->SetText("Name");
     table->Model()->Cell(0, 2)->Model()->SetFillColor(sf::Color(0xB0EFFFff));

    for (int i = 1; i <=6; i++){
        pEdit edit = table->Model()->Cell(i, 0);
        std::string s = std::to_string(i);
        edit->Model()->SetText(s);
        edit->Model()->SetFillColor(sf::Color(0xB0EFFFff));
    }


    //добавляем на панель
    gui->Model()->Add(table);


    //Создадим таймер
    pTimer timer = new Timer();
    //Установить интервал
    timer->Model()->SetInterval(sf::milliseconds(500));
    //Установить обработчик на таймер
    timer->Model()->SetOnTimer(swap_chairs);
    //Добавить таймер
    gui->Model()->Add(timer);
    //запускаем таймер
    timer->Model()->SetEnabled(true);

//    pCheckBox checkbox = new CheckBox();
//    checkbox->Model()->SetLocalCoord(10, 180);
//    std::string s = "Test";
//    s[0] = 0x04;
//    s[1] = 0x1b;
//    checkbox->Model()->SetCaption(s);
//    panel->Model()->Add(checkbox);

    pCheckBox checkboxs[5];
    for (int i = 0; i < 5; i++){
        checkboxs[i] = new CheckBox();
        checkboxs[i]->Model()->SetLocalCoord(10, 220+25*i);
        checkboxs[i]->Model()->SetCaption(" My CheckBox "+std::to_string(i));
        panel->Model()->Add(checkboxs[i]);
    }

    pTransformer t = new Transformer();
    t->Model()->SetTarget(checkboxs[0]);
    checkboxs[0]->Model()->SetEnabled(false);
    gui->Model()->Add(t);

    pb = new ProgressBar();
    pb->Model()->SetLocalCoord(10, 350);
    pb->Model()->SetCurrent(0.0);
    pb->Model()->SetVertical(false);
    panel->Model()->Add(pb);

    pAnimation animation = new Animation();
    panel->Model()->Add(animation);
    animation->Model()->setTilesCount(sf::Vector2f(8,2));
    animation->Model()->SetSize(108, 140 );
    animation->Model()->SetLocalCoord(10, 400);
    animation->Model()->loadFromFile("assets/images/cat.png");
    animation->Model()->setInterval(sf::seconds(0.05));









    //"Оживить" окно, заставить его реагировать на взаимодействие
    //функция завершит свою работу, когда окно будет закрыто
    gui->loop();
    return 0;
}



    animation->Model()->loadFromFile("assets/images/man_sprite.png");
    animation->Model()->setInterval(sf::seconds(0.25));