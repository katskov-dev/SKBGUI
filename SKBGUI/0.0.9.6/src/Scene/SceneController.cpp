#include "Scene/SceneController.h"

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
	ComponentController::Handle(event);
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
