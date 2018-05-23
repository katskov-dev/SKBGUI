#include "World/WorldController.h"

WorldController::WorldController(pWorldModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

WorldController::~WorldController()
{
    //dtor
}

bool WorldController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };


    return false;
}

pWorldModel WorldController::Owner()
{
    return pWorldModel(ComponentController::Owner());
}

void WorldController::SetOwner(pWorldModel owner)
{
    ComponentController::SetOwner(owner);
}

void WorldController::Update(sf::Time time)
{
    ComponentController::Update(time);

    static float32 timeStep = time.asSeconds();
    static float32 velocityIterations = 6;
    static float32 positionIterations = 2;
    Owner()->SetIterations(positionIterations);
    Owner()->SetTime(timeStep);
    Owner()->SetVelocity(velocityIterations);
    Owner()->Step();
}
