#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Scene/SceneModel.h>
#include <Scene/SceneViewer.h>
#include <Scene/SceneController.h>

class Scene: public Component
{
    public:
        Scene(sf::RenderWindow* window);
        ~Scene();
        virtual pSceneModel Model();
        virtual void SetModel(pSceneModel model);
        virtual pSceneViewer Viewer();
        virtual void SetViewer(pSceneViewer viewer);
        virtual pSceneController Controller();
        virtual void SetController(pSceneController controller);
    private:

};
