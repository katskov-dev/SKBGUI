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
#include <World/World.h>
#include <Timer/Timer.h>

#include <CircleCollider/CircleCollider.h>
#include <BoxCollider/BoxCollider.h>
#include <Scene/Scene.h>
#include <fstream>
#include <vector>
#include <utility>


 pGUI gui;
pEdit edit;
pLabel label;
pTable table;
pCircleCollider mycol;
pCircleCollider col;
pBoxCollider box;
pWorld world;
pTimer world_timer;
pBoxCollider groundbody;
pBoxCollider groundbody1;
pBoxCollider boxs[5];
const int boxs_count = 5;
 pScene scene;

 pPicture mnist;

 class MnistSet{
    public:
        sf::Int32 magic_number;
        sf::Int32 count_images;
        sf::Int32 rows;
        sf::Int32 cols;
        char* pixels;
        void LoadFromFile(std::string filename);
        sf::Texture GetImage(int index);
    private:
        sf::Int32 readInt32(ifstream* fin);
 };

sf::Int32 MnistSet::readInt32(ifstream* fin)
 {
    char c[4];
    fin->read(c, 4);
    std::swap(c[0], c[3]);
    std::swap(c[1], c[2]);
    sf::Int32 r;
    ((char*)&r)[0] = c[0];
    ((char*)&r)[1] = c[1];
    ((char*)&r)[2] = c[2];
    ((char*)&r)[3] = c[3];
    return r;
 }

 void MnistSet::LoadFromFile(std::string filename)
 {
    ifstream fin(filename, ios_base::binary);
    magic_number = readInt32(&fin);
    count_images = readInt32(&fin);
    rows = readInt32(&fin);
    cols = readInt32(&fin);

    char c;

    std::cout << "Magic number: " << magic_number << std::endl;
    std::cout << "Count images: " << count_images << std::endl;
    std::cout << "Rows: " << rows << std::endl;
    std::cout << "Cols: " << cols << std::endl;
    pixels = new char[rows * cols * count_images];
    //pixels.resize(rows * cols * count_images);
    fin.read(pixels, rows * cols * count_images);
//    for (int i = 0; i < rows * cols * count_images; i++){
//        fin >> pixels[i];
//    }
    fin.close();

 }

 sf::Texture MnistSet::GetImage(int index)
 {
    sf::Image image;
    sf::Texture texture;
    int image_size = rows * cols;
    unsigned long int offset = image_size * index;
    std::cout << "Offset: " << offset <<std::endl;
    image.create(cols, rows);
    int id = 0;
    for (int row = 0; row < rows; row++){
        for (int col = 0; col < cols; col++){

            uint8 c = pixels[offset + id++];
            image.setPixel(col, row, sf::Color(c,c,c));
        }

    }
//    for (int row = 0; row < rows; row++){
//        for (int col = 0; col < cols; col++){
//            int id = offset + row * cols + col;
//            uint8 c = pixels[id];
//            image.setPixel(col, row, sf::Color(c,c,c));
//        }
//
//    }
    texture.loadFromImage(image);
    return texture;
 }

void init_scene(pComponentModel model, int x, int y, int button)
{
    for (int i = 0; i < scene->Model()->Count(); i++){
        pComponent child = scene->Model()->Children(i);
        scene->Model()->Delete(child);
    }
    //---Статические "стены"
    groundbody = new BoxCollider(world, 450, 5, "static");
    groundbody->Model()->SetLocalCoord(20, 250);
    groundbody->Model()->Body()->SetTransform(groundbody->Model()->Body()->GetPosition(), 3.1415 / 180 * 35);
    scene->Model()->Add(groundbody);

    groundbody1 = new BoxCollider(world, 5, 115, "static");
    groundbody1->Model()->SetLocalCoord(470, 150);
    groundbody1->Model()->Body()->SetTransform(groundbody1->Model()->Body()->GetPosition(), 3.1415 / 180 * 5);
    scene->Model()->Add(groundbody1);




    //---Колайдеры
    mycol = new CircleCollider(world, 25, "dynamic");
    mycol->Model()->SetLocalCoord(100, 0);
    scene->Model()->Add(mycol);

    //---Картинка колеса
////
////    pPicture wheel = new Picture();
////    wheel->Model()->LoadFromFile("assets/images/wheel.png");
////    wheel->Model()->SetSize(50,50);
////    mycol->Model()->Add(wheel);
}



int main()
{
    gui = new GUI(800, 600, "SKBGUI");
    gui->Model()->SetName("gui");

    world = new World();
    gui->Model()->Add(world);
    //--------Сцена
    scene = new Scene(gui->Window());
    scene->Model()->SetLocalCoord(5, 5);
    scene->Model()->SetSize(500, 300);
    gui->Model()->Add(scene);
    // --- Кнопки управления симуляцией
    pButton btnPlay = new Button();
    btnPlay->Model()->SetSize(250, 50);
    btnPlay->Model()->SetLocalCoord(525, 10);
    btnPlay->Model()->SetCaption("Play");
    btnPlay->Controller()->SetMouseDown(init_scene);
    gui->Model()->Add(btnPlay);

//    MnistSet mset;
//    mset.LoadFromFile("assets/mnist/test_images");
//
//    pPicture mpic = new Picture();
//    mpic->Model()->SetLocalCoord(5, 310);
//    mpic->Model()->SetSize(200, 200);
//    mpic->Model()->SetVisibleBorders(true);
//    sf::Texture texture = mset.GetImage(3);
//    mpic->Model()->SetTexture(&texture);
//    gui->Model()->Add(mpic);










    //"Оживить" окно, заставить его реагировать на взаимодействие
    //функция завершит свою работу, когда окно будет закрыто
    gui->loop();
    return 0;
}


