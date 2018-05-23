#include "Scene/SceneController.h"
#include <math.h>
SceneController::SceneController(pSceneModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

SceneController::~SceneController()
{
    //dtor
}

bool SceneController::Handle(sf::Event event)
{
    sf::Event child_event = event;
    sf::Vector2f m = -Owner()->__position;
//    m.x *= (1.0 / Owner()->__scale);
//    m.y *= (1.0 / Owner()->__scale);
    if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased){
//        child_event.mouseButton.x *= Owner()->__scale;
//        child_event.mouseButton.y *= Owner()->__scale;
        child_event.mouseButton.x += std::floor(m.x);
        child_event.mouseButton.y += std::floor(m.y);

    }
    else
    if (event.type == sf::Event::MouseMoved){
        child_event.mouseMove.x += std::floor(m.x);
        child_event.mouseMove.y += std::floor(m.y);
    }


	if (ComponentController::Handle(child_event))
        return true;
    std::cout << "LOL" << std::endl;
    switch (event.type){
        case sf::Event::MouseButtonPressed: {
            Owner()->__state = SCENE_STATE_MOUSE_DOWN;
            Owner()->__old_mouse_pos = (sf::Vector2f)sf::Mouse::getPosition(*Owner()->__render_target);
            break;
        };
        case sf::Event::MouseButtonReleased: {
            Owner()->__state = SCENE_STATE_NONE;
            break;
        };
        case sf::Event::MouseMoved: {
            if (Owner()->Focus()){
                if (Owner()->__state == SCENE_STATE_MOUSE_DOWN){
                    double dx = event.mouseMove.x - Owner()->__old_mouse_pos.x;
                    double dy = event.mouseMove.y - Owner()->__old_mouse_pos.y;

                    Owner()->__old_mouse_pos.x += dx;
                    Owner()->__old_mouse_pos.y += dy;
                    dx = dx * Owner()->__scale;
                    dy = dy * Owner()->__scale;
                    Owner()->__position.x += dx;
                    Owner()->__position.y += dy;

                }
            }
            break;
        };
        case sf::Event::MouseWheelMoved:{
            if (Owner()->Focus()){
                int d= event.mouseWheel.delta;
                    //std::cout << d << std::endl;
                Owner()->__scale += 0.1 * (-d) * Owner()->__scale;
            }
            break;
        };
    };
    return false;
}

pSceneModel SceneController::Owner()
{
    return pSceneModel(ComponentController::Owner());
}

void SceneController::SetOwner(pSceneModel owner)
{
    ComponentController::SetOwner(owner);
}

void SceneController::Update(sf::Time time)
{
    ComponentController::Update(time);
}
