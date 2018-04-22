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





 class MnistSet{
    public:
        sf::Int32 magic_number;
        sf::Int32 count_images;
        sf::Int32 rows;
        sf::Int32 cols;
        sf::Int32 number_of_labels;
        char* labels;
        char* pixels;
        void LoadImagesFromFile(std::string filename);
        void LoadLabelsFromFile(std::string filename);
        sf::Texture GetImage(int index);
        int GetLabel(int index);
        ~MnistSet();
    private:
        sf::Int32 readInt32(ifstream* fin);
 };

MnistSet::~MnistSet()
{
    delete labels;
    delete pixels;

}
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

 void MnistSet::LoadImagesFromFile(std::string filename)
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

 void MnistSet::LoadLabelsFromFile(std::string filename)
 {
    ifstream fin(filename, ios_base::binary);
    magic_number = readInt32(&fin);
    number_of_labels = readInt32(&fin);
    labels = new char[number_of_labels];
    fin.read(labels, number_of_labels);
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

 int MnistSet::GetLabel(int index)
 {
    return labels[index];
 }

pLabel label;
pPicture mpic;
MnistSet mset;
sf::Texture texture ;
 int ID = 0;

void on_timer()
{
    ID++;
    texture = mset.GetImage(ID);
    mpic->Model()->SetTexture(&texture);
    label->Model()->SetCaption(std::to_string(mset.GetLabel(ID)));
}


int main()
{
    gui = new GUI(800, 600, "SKBGUI");

    pWorld world = new World();
    gui->Model()->Add(world);



    mset.LoadImagesFromFile("assets/mnist/test_images");
    mset.LoadLabelsFromFile("assets/mnist/test_labels");

    mpic = new Picture();
    mpic->Model()->SetLocalCoord(5, 5);
    mpic->Model()->SetSize(50, 50);
    mpic->Model()->SetVisibleBorders(true);
    gui->Model()->Add(mpic);
    texture = mset.GetImage(ID);
    texture = mset.GetImage(ID);
    mpic->Model()->SetTexture(&texture);
    //gui->Model()->Add(mpic);

    label = new Label();
    label->Model()->SetLocalCoord(60, 5);
    gui->Model()->Add(label);
    label->Model()->SetCaption(std::to_string(mset.GetLabel(ID)));

    pTimer timer = new Timer();
    timer->Model()->SetInterval(sf::seconds(1.0));
    timer->Model()->SetOnTimer(on_timer);
    timer->Model()->SetVisibleBorders(false);
    gui->Model()->Add(timer);








    //"ќживить" окно, заставить его реагировать на взаимодействие
    //функци€ завершит свою работу, когда окно будет закрыто
    gui->loop();

    delete gui;
    return 0;
}


