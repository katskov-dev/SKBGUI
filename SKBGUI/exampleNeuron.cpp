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

#include <Neuron/Neuron.h>
#include <Scene/Scene.h>
#include <Arrow/Arrow.h>
#include <vector>
#include <fstream>

pScene scene;
pGUI gui;
pNeuron sn1 = nullptr;
pNeuron sn2 = nullptr;
std::vector < pArrow > links;
int obj_ID = 0;

void select_neuron(pComponentModel model, int x, int y, int button)
{
    if (sn1 == nullptr){
        //select first
        sn1 = pNeuron(gui->Model()->FindAll(model->Name()));
        sn1->Model()->signal = 1.0;
    }
    else{
        //select second
        sn2 = pNeuron(gui->Model()->FindAll(model->Name()));
        // connecting...
        pArrow link = new Arrow(sn1,sn2);
        gui->Model()->Add(link);
        links.push_back(link);
        sn1->Model()->signal = 0.0;
        sn2->Model()->signal = 0.0;
        sn1 = nullptr;
        sn2 = nullptr;
    }
}


void gui_key_down(pComponentModel model, int key)
{
    switch (key){
        case sf::Keyboard::Num1:{
            sf::Vector2i mc = sf::Mouse::getPosition(*gui->Window());

            pNeuron n = new Neuron();
            n->Controller()->SetMouseDown(select_neuron);
            n->Model()->SetName(std::string("") + std::to_string(obj_ID++));
            gui->Model()->Add(n);
            n->Model()->SetAbsoluteCoord(sf::Vector2f(mc.x - 10, mc.y - 10));



        };

        case sf::Keyboard::S:{
            ofstream fout;
            fout.open("neurons.txt");
            for (int i = 0; i < links.size(); i++){
                std::string n1 = links[i]->Model()->__start->Model()->Name();
                std::string n2 = links[i]->Model()->__end->Model()->Name();

                fout << "AddLink(" << n1 << ", " << n2 << ", " << std::to_string(1.0 - (links[i]->Model()->distance / 500.0)) << "); " << std::endl;
            }
            fout.close();
        }
    };
}



int main()
{

    gui = new GUI(800, 600, "SKBGUI");



//    scene = new Scene(gui->Window());
//    scene->Model()->SetSize(10000.0, 10000.0);
//    scene->Model()->SetLocalCoord(-5000.0, -5000.0);
//    gui->Model()->Add(scene);



    gui->Controller()->SetKeyDown(gui_key_down);



    gui->loop();
    return 0;
}


