#include <GUI/GUI.h>
#include <string>
#include <Label/Label.h>


GUI::GUI(int width, int height, std::string title)
{
    __window = new sf::RenderWindow(sf::VideoMode(width, height), title);
    __window_size = sf::Vector2f(width, height);
    //__window->setFramerateLimit(60);
    //__window->setVerticalSyncEnabled(true);
    SetModel(new GUIModel(width, height));
    SetViewer(new GUIViewer(Model()));
    SetController(new GUIController(Model()));
    SetBackgroundColor(sf::Color(0x336699ff));
}

GUI::~GUI()
{

}

void GUI::loop()
{
    FPS = 0;
    curFPS = 0;
    pLabel lFPS = new Label();
    __fps_clock.restart();
    __oldtime = sf::Time(sf::seconds(0));

    __guiclock.restart();
    while (__window->isOpen())
    {
        sf::Event event;
        while (__window->pollEvent(event))
        {
            SetEventState(EVENT_STATE_OPEN);
            Controller()->Handle(event);
            if (event.type == sf::Event::Closed)
                __window->close();
            if (event.type == sf::Event::Resized){


            }


        }
        Controller()->RunIdle();

        __window->clear(__backgroundColor);

        Viewer()->Render(*__window);


        lFPS->Model()->SetCaption("FPS: "+std::to_string(FPS));
        lFPS->Model()->SetLocalCoord(__window_size.x - 100, 5);
        lFPS->Model()->SetSize(100, 15);
        lFPS->Model()->SetColor(sf::Color(0x0000ffff));

        lFPS->Viewer()->Render(*__window);
        sf::Time elapsed = __guiclock.getElapsedTime();
        Controller()->Update(elapsed - __oldtime);
        __oldtime = elapsed;

        __window->display();

        //sf::sleep(sf::milliseconds(10));
        //system("cls");
        curFPS++;
        if (__fps_clock.getElapsedTime().asSeconds() > 1.0){
            __fps_clock.restart();
            FPS = curFPS;
            curFPS = 0;
        }
        sf::Vector2i cursor_pos = sf::Mouse::getPosition(*Window());
        std::string s = "x : ";
        s += std::to_string(cursor_pos.x);
        s += "; y : ";
        s += std::to_string(cursor_pos.y);
        //Window()->setTitle(s);
    }
}

pGUIModel GUI::Model()
{
    return pGUIModel(__model);
}

void GUI::SetModel(pGUIModel model)
{
    __model = model;
}

pGUIViewer GUI::Viewer()
{
    return pGUIViewer(__viewer);
}

void GUI::SetViewer(pGUIViewer viewer)
{
    __viewer = viewer;
}

pGUIController GUI::Controller()
{
    return pGUIController(__controller);
}

void GUI::SetController(pGUIController controller)
{
    __controller = controller;
}

sf::RenderWindow* GUI::Window()
{
    return __window;
}

void GUI::Window(sf::RenderWindow* window)
{
    __window = window;
}

int GUI::EventState()
{
    return __eventState;
}

void GUI::SetEventState(int eventState)
{
    __eventState = eventState;
}

sf::Color GUI::BackgroundColor()
{
    return __backgroundColor;
}

void GUI::SetBackgroundColor(sf::Color color)
{
    __backgroundColor = color;
}
