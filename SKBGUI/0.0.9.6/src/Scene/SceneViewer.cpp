#include "Scene/SceneViewer.h"

SceneViewer::SceneViewer(pSceneModel model): ComponentViewer(pComponentModel(model))
{

}

SceneViewer::~SceneViewer()
{
    //dtor
}

void SceneViewer::Render(sf::RenderTarget& target)
{
	ComponentViewer::RenderBegin(target);

	ComponentViewer::Render(target);
    sf::View view = target.getView();
    view.move(-Owner()->__position);
	view.zoom(Owner()->__scale);

	target.setView(view);


	ComponentViewer::RenderEnd(target);
}

pSceneModel SceneViewer::Owner()
{
    return pSceneModel(ComponentViewer::Owner());
}

void SceneViewer::SetOwner(pSceneModel owner)
{
    ComponentViewer::SetOwner(owner);
}
