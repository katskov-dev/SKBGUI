#pragma once

#include <base.h>
#include <Component/Component.h>
#include <GUI/GUIModel.h>
#include <GUI/GUIViewer.h>
#include <GUI/GUIController.h>
#include <SFML/Graphics.hpp>
#include <string>

const std::string SKBGUI_VERSION = "0.0.9.8";

const int EVENT_STATE_OPEN = 0;
const int EVENT_STATE_CLOSED = 1;

class GUI: public Component
{
    public:
        GUI(int width, int height, std::string title);
        ~GUI();
        void loop();
        virtual pGUIModel Model();
        virtual void SetModel(pGUIModel model);
        virtual pGUIViewer Viewer();
        virtual void SetViewer(pGUIViewer viewer);
        virtual pGUIController Controller();
        virtual void SetController(pGUIController controller);
        sf::RenderWindow* Window();
        void Window(sf::RenderWindow* window);
        int EventState();
        void SetEventState(int eventState);
        sf::Color BackgroundColor();
        void SetBackgroundColor(sf::Color color);
    private:
        sf::RenderWindow* __window;
        sf::Vector2f __window_size;
        sf::Clock __fps_clock;
        int FPS;
        int curFPS;
        sf::Clock __guiclock;
        sf::Time __oldtime;
        int __eventState;
        sf::Color __backgroundColor;
};
