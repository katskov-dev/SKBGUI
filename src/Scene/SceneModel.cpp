#include "Scene/SceneModel.h"
#include <iostream>
SceneModel::SceneModel(sf::RenderWindow* window): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetVisibleBorders(true);
    SetViewLimit(true);
    __scale = 1.0;
    __render_target = window;
    __state = SCENE_STATE_NONE;
    __position = sf::Vector2f(0, 0);

}

SceneModel::~SceneModel()
{
    //dtor
}

Vector2f SceneModel::AbsoluteCoord()
{

    return ComponentModel::AbsoluteCoord();



}
