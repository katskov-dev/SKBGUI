#include <GUI/GUI.h>
#include <MyCircle/MyCircle.h>
pGUI gui;
int main()
{
    gui = new GUI(800, 600, "MyCircler test");
    pMyCircle mycircle = new MyCircle();

    gui->Model()->SetLocalCoord(100, 100);

    gui->Model()->Add(mycircle);



    gui->loop();
	return 0;
}
