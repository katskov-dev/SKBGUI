#include "DistanceJoint/DistanceJointViewer.h"
#include <Box2D.h>
DistanceJointViewer::DistanceJointViewer(pDistanceJointModel model): JointViewer(pJointModel(model))
{

}

DistanceJointViewer::~DistanceJointViewer()
{
    //dtor
}

void DistanceJointViewer::Render(sf::RenderTarget& target)
{
//	ComponentViewer::RenderBegin(target);
//	ComponentViewer::Render(target);
//
//
//
//	ComponentViewer::RenderEnd(target);
    b2Vec2 c1 = Owner()->FBody()->Model()->myBody()->GetWorldCenter();
    b2Vec2 c2 = Owner()->SBody()->Model()->myBody()->GetWorldCenter();
    sf::Vertex line[] =
    {
        sf::Vertex(sf::Vector2f(c1.x, c1.y), sf::Color(0x00ff00ff)),
        sf::Vertex(sf::Vector2f(c2.x, c2.y), sf::Color(0x00ff00ff))
    };

    target.draw(line, 2, sf::Lines);

}

pDistanceJointModel DistanceJointViewer::Owner()
{
    return pDistanceJointModel(ComponentViewer::Owner());
}

void DistanceJointViewer::SetOwner(pDistanceJointModel owner)
{
    ComponentViewer::SetOwner(owner);
}
