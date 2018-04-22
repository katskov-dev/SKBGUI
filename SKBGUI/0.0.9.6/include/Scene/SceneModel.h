#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>

const int SCENE_STATE_NONE = 0;
const int SCENE_STATE_MOUSE_DOWN = 1;
const int SCENE_STATE_MOUSE_MOVE = 2;

class SceneModel: public ComponentModel
{
    public:
        SceneModel(sf::RenderWindow* window);
        virtual ~SceneModel();



        double __scale;
        unsigned int __state;
        sf::RenderWindow* __render_target;
        sf::Vector2f __old_mouse_pos;
        sf::Vector2f __position;


    protected:

    private:


};
