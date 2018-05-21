
#include <GUI/GUI.h>
#include <Picture/Picture.h>
#include <iostream>
#include <Timer/Timer.h>

pGUI gui;
pPicture barber;
const int speed = 32;
const int DIR_TOP = 0;
const int DIR_LEFT = 1;
const int DIR_RIGHT = 2;
const int DIR_DOWN = 3;
const int DIR_STOP = 4;
const int n=20;
const int m=20;

struct Object
{
    pPicture image;
    bool solid;
    int item;
    pPicture item_image;
    int n1;
};

struct Character
{
    int i,j;
    pPicture image;
};

Object Map[n][m];
int direction = DIR_STOP;
int fixDirection = DIR_STOP;
int cnt = 0;

void myKeyDown(pComponentModel model, int key)
{
    //std::cout << key << std::endl;
    if (fixDirection != DIR_STOP)
        return;
    if (key == 3){ // right
        direction = DIR_RIGHT;
    }
    if (key == 22){ // top
        direction = DIR_TOP;
    }
    if (key == 0){ // left
        direction = DIR_LEFT;
    }
    if (key == 18){ // down
        direction = DIR_DOWN;
    }
    if (key == 18){ // down
        direction = DIR_DOWN;
    }

};

void ontimer()
{
    if (fixDirection != DIR_STOP)
        return;
    sf::Vector2f coord = barber->Model()->LocalCoord();
    fixDirection = direction;
//    if (fixDirection == DIR_RIGHT){ // right
//        coord.x += speed;
//        barber->Model()->SetLocalCoord(coord);
//    }
//    if (fixDirection == DIR_TOP){ // top
//        coord.y -= speed;
//        barber->Model()->SetLocalCoord(coord);
//    }
//    if (fixDirection == DIR_LEFT){ // left
//        coord.x -= speed;
//        barber->Model()->SetLocalCoord(coord);
//    }
//    if (fixDirection == DIR_DOWN){ // down
//        coord.y += speed;
//        barber->Model()->SetLocalCoord(coord);
//    }
    direction = DIR_STOP;
}


void timer2()
{
    if (fixDirection == DIR_STOP)
        return;
    sf::Vector2f coord = barber->Model()->LocalCoord();
    int speed1 = speed / 10;
    if (fixDirection == DIR_RIGHT){ // right
        coord.x += speed1;
        barber->Model()->SetLocalCoord(coord);
    }
    if (fixDirection == DIR_TOP){ // top
        coord.y -= speed1;
        barber->Model()->SetLocalCoord(coord);
    }
    if (fixDirection == DIR_LEFT){ // left
        coord.x -= speed1;
        barber->Model()->SetLocalCoord(coord);
    }
    if (fixDirection == DIR_DOWN){ // down
        coord.y += speed1;
        barber->Model()->SetLocalCoord(coord);
    }
    if (fixDirection != DIR_STOP){
       // std::cout << cnt << std::endl;
        cnt ++;
    }

    if (cnt >= 9){
        cnt = 0;
        fixDirection = DIR_STOP;
        direction = DIR_STOP;


    }

}


int main()
{
    gui = new GUI(800, 600, "MyCircler test");
    cnt = 0;
    direction = DIR_STOP;
    fixDirection = DIR_STOP;
    pPicture chair = new Picture();
    chair->Model()->LoadFromFile("assets/images/chair1.png");
    chair->Model()->SetSize(50, 100);
    chair->Model()->SetLocalCoord(600, 450);
    gui->Model()->Add(chair);



    gui->Controller()->SetKeyDown(myKeyDown);
    pTimer zoneStepTimer = new Timer();
    zoneStepTimer->Model()->SetInterval(sf::seconds(0.05));
    zoneStepTimer->Model()->SetOnTimer(ontimer);
    zoneStepTimer->Model()->SetEnabled(true);
    gui->Model()->Add(zoneStepTimer);

    pTimer animationTimer = new Timer();
    animationTimer->Model()->SetInterval(sf::seconds(0.005));
    animationTimer->Model()->SetOnTimer(timer2);
    animationTimer->Model()->SetEnabled(true);
    gui->Model()->Add(animationTimer);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            Map[i][j].image = new Picture();
            Map[i][j].image->Model()->LoadFromFile("assets/images/dirt.jpeg");
            gui->Model()->Add(Map[i][j].image);
            Map[i][j].image->Model()->SetLocalCoord(j*32,i*32);
        }
    }

    barber = new Picture();
    barber->Model()->LoadFromFile("assets/images/barber.png");
    barber->Model()->SetSize(32,32);
    barber->Model()->SetLocalCoord(0,0);
    gui->Model()->Add(barber);

    gui->loop();
	return 0;
}
