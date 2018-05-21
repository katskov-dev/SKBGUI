#include <GUI/GUI.h>
#include <Picture/Picture.h>
#include <iostream>
#include <Timer/Timer.h>

pGUI gui;
//pPicture redcap;
const int speed = 32;
const int DIR_TOP = 0;
const int DIR_LEFT = 1;
const int DIR_RIGHT = 2;
const int DIR_DOWN = 3;
const int DIR_STOP = 4;
const int n=20;
const int m=25;
const int W      = 20;         // ширина рабочего пол€
const int H      =  25;         // высота рабочего пол€
const int WALL   = -1;         // непроходима€ €чейка
const int BLANK  = -2;         // свободна€ непомеченна€ €чейка

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
int cntMove = 0;
Character redcap;
Character wolf;

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

int px[W * H], py[W * H];      // координаты €чеек, вход€щих в путь
int len;                       // длина пути

bool wave(int ax, int ay, int bx, int by)   // поиск пути из €чейки (ax, ay) в €чейку (bx, by)
{
  int dx[4] = {1, 0, -1, 0};   // смещени€, соответствующие сосед€м €чейки
  int dy[4] = {0, 1, 0, -1};   // справа, снизу, слева и сверху
  int d, x, y, k;
  bool stop;

  if (Map[ay][ax].n1 == WALL || Map[by][bx].n1 == WALL) return false;  // €чейка (ax, ay) или (bx, by) - стена

  // распространение волны
  d = 0;
  Map[ay][ax].n1 = 0;            // стартова€ €чейка помечена 0
  do {
    stop = true;               // предполагаем, что все свободные клетки уже помечены
    for ( y = 0; y < H; y++ )
      for ( x = 0; x < W; x++ )
        if ( Map[y][x].n1 == d )                         // €чейка (x, y) помечена числом d
        {
          for ( k = 0; k < 4; k++ )                    // проходим по всем непомеченным сосед€м
          {
             int iy=y + dy[k], ix = x + dx[k];
             if ( iy >= 0 && iy < H && ix >= 0 && ix < W &&
                  Map[iy][ix].n1 == BLANK )
             {
                stop = false;              // найдены непомеченные клетки
                Map[iy][ix].n1 = d + 1;      // распростран€ем волну
             }
          }
        }
    d++;
  } while ( !stop && Map[by][bx].n1 == BLANK );

  if (Map[by][bx].n1 == BLANK) return false;  // путь не найден

  // восстановление пути
  len = Map[by][bx].n1;// длина кратчайшего пути из (ax, ay) в (bx, by)
  x = bx;
  y = by;
  d = len;
  while ( d > 0 )
  {
    px[d] = x;
    py[d] = y;                   // записываем €чейку (x, y) в путь
    d--;
    for (k = 0; k < 4; k++)
    {
       int iy=y + dy[k], ix = x + dx[k];
       if ( iy >= 0 && iy < H && ix >= 0 && ix < W &&
            Map[iy][ix].n1 == d)
      {
          x = x + dx[k];
          y = y + dy[k];           // переходим в €чейку, котора€ на 1 ближе к старту
          break;
      }
    }
  }
  px[0] = ax;
  py[0] = ay;
  cntMove=0;                // теперь px[0..len] и py[0..len] - координаты €чеек пути
  return true;
}

void ontimer()
{
    if (fixDirection != DIR_STOP)
        return;
    sf::Vector2f coord = redcap.image->Model()->LocalCoord();
    fixDirection = direction;
    //wave(wolf.i,wolf.j,redcap.i,redcap.j);
//    if (fixDirection == DIR_RIGHT){ // right
//        coord.x += speed;
//        redcap->Model()->SetLocalCoord(coord);
//    }
//    if (fixDirection == DIR_TOP){ // top
//        coord.y -= speed;
//        redcap->Model()->SetLocalCoord(coord);
//    }
//    if (fixDirection == DIR_LEFT){ // left
//        coord.x -= speed;
//        redcap->Model()->SetLocalCoord(coord);
//    }
//    if (fixDirection == DIR_DOWN){ // down
//        coord.y += speed;
//        redcap->Model()->SetLocalCoord(coord);
//    }
    direction = DIR_STOP;
}

void timer2()
{
    if (fixDirection == DIR_STOP)
        return;
    sf::Vector2f coord = redcap.image->Model()->LocalCoord();
    int speed1 = speed / 10;
    if (fixDirection == DIR_RIGHT){ // right
        coord.x += speed1;
        redcap.image->Model()->SetLocalCoord(coord);
        redcap.j += 1;

    }
    if (fixDirection == DIR_TOP){ // top
        coord.y -= speed1;
        redcap.image->Model()->SetLocalCoord(coord);
        redcap.i -= 1;

    }
    if (fixDirection == DIR_LEFT){ // left
        coord.x -= speed1;
        redcap.image->Model()->SetLocalCoord(coord);
        redcap.j -= 1;

    }
    if (fixDirection == DIR_DOWN){ // down
        coord.y += speed1;
        redcap.image->Model()->SetLocalCoord(coord);
        redcap.i += 1;

    }
    if (fixDirection != DIR_STOP){
       // std::cout << cnt << std::endl;
        cnt ++;
    }

    if (cnt >= 10){
        cnt = 0;
        fixDirection = DIR_STOP;
        direction = DIR_STOP;


    }

}

void wolfMove()
{
    wolf.j=px[cntMove];
    wolf.i=py[cntMove];
    for(int i=0;i<20;i++)
    {
        cout << px[i] << "\n";
    }
    wolf.image->Model()->SetLocalCoord(wolf.j*32,wolf.i*32);
    cntMove++;
    if (cntMove == len)
    {
        wave(wolf.j,wolf.i,redcap.j,redcap.i);
        cntMove=0;
    }
}


int main()
{
    gui = new GUI(800, 640, "Test");
    cnt = 0;
    direction = DIR_STOP;
    fixDirection = DIR_STOP;

    gui->Controller()->SetKeyDown(myKeyDown);
    pTimer zoneStepTimer = new Timer();
    zoneStepTimer->Model()->SetInterval(sf::seconds(0.1));
    zoneStepTimer->Model()->SetOnTimer(ontimer);
    zoneStepTimer->Model()->SetEnabled(true);
    gui->Model()->Add(zoneStepTimer);

    pTimer animationTimer = new Timer();
    animationTimer->Model()->SetInterval(sf::seconds(0.01));
    animationTimer->Model()->SetOnTimer(timer2);
    animationTimer->Model()->SetEnabled(true);
    gui->Model()->Add(animationTimer);

    pTimer wolfMoveTimer = new Timer();
    wolfMoveTimer->Model()->SetInterval(sf::seconds(1));
    wolfMoveTimer->Model()->SetOnTimer(wolfMove);
    wolfMoveTimer->Model()->SetEnabled(true);
    gui->Model()->Add(wolfMoveTimer);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            Map[i][j].image = new Picture();
            Map[i][j].image->Model()->LoadFromFile("assets/images/grass2.png");
            Map[i][j].image->Model()->SetSize(32,32);
            Map[i][j].image->Model()->SetLocalCoord(j*32,i*32);
            gui->Model()->Add(Map[i][j].image);
            Map[i][j].n1=-2;
        }
    }

    redcap.image = new Picture();
    redcap.image->Model()->LoadFromFile("assets/images/redcap.png");
    redcap.i=0; redcap.j=0;
    redcap.image->Model()->SetSize(32,32);
    redcap.image->Model()->SetLocalCoord(32*wolf.j, 32*wolf.i);
    gui->Model()->Add(redcap.image);

    wolf.image = new Picture();
    wolf.image->Model()->LoadFromFile("assets/images/wolf.png");
    wolf.i=10; wolf.j=10;
    wolf.image->Model()->SetSize(32, 64);
    wolf.image->Model()->SetLocalCoord(32*wolf.j, 32*wolf.i);
    wave(wolf.j,wolf.i,redcap.j,redcap.i);

    gui->Model()->Add(wolf.image);
    gui->loop();
	return 0;
}
