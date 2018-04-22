#include <Scene/Scene.h>


Scene::Scene(sf::RenderWindow* window)
{
    SetModel(new SceneModel(window));
    SetViewer(new SceneViewer(Model()));
    SetController(new SceneController(Model()));
}

Scene::~Scene()
{

}

pSceneModel Scene::Model()
{
    return pSceneModel(__model);
}

void Scene::SetModel(pSceneModel model)
{
    __model = model;
}

pSceneViewer Scene::Viewer()
{
    return pSceneViewer(__viewer);
}

void Scene::SetViewer(pSceneViewer viewer)
{
    __viewer = viewer;
}

pSceneController Scene::Controller()
{
    return pSceneController(__controller);
}

void Scene::SetController(pSceneController controller)
{
    __controller = controller;
}

