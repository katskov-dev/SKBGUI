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
    if (!Owner()->Visible())
        return;
	ComponentViewer::RenderBegin(target);

	ComponentViewer::Render(target);
    sf::View view = target.getView();
    view.move(-Owner()->__position);
	view.zoom(Owner()->__scale);

	target.setView(view);

	sf::Vertex v[4];
	// Axe - X
	v[0].position = sf::Vector2f(0.0, 0.0);
	v[0].color = sf::Color(0xff0000ff);
	v[1].position = sf::Vector2f(10000.0, 0.0);
	v[1].color = sf::Color(0xff0000ff);
	// Axe - Y
	v[2].position = sf::Vector2f(0.0, 0.0);
	v[2].color = sf::Color(0x00ff00ff);
	v[3].position = sf::Vector2f(0.0, 10000.0);
	v[3].color = sf::Color(0x00ff00ff);

	target.draw(v, 4, sf::Lines);



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
