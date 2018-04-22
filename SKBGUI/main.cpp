#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <locale>

#include <Component/Component.h>
#include <Button/Button.h>
#include <Transformer/Transformer.h>
#include <Label/Label.h>
#include <Edit/Edit.h>
//---------------------
#include <CircleCollider/CircleCollider.h>
#include <BoxCollider/BoxCollider.h>
#include <Picture/Picture.h>
#include <GUI/GUI.h>
#include <MyPicture/MyPicture.h>
//---------------------------

using namespace std;
//using namespace sf;

pGUI gui;


int main()
{
    setlocale(LC_ALL,"russian");

    gui = new GUI(800, 600, "Title");


    pMyPicture mypic = new MyPicture();
    gui->Model()->Add(mypic);



    gui->loop();


    return 0;
}
