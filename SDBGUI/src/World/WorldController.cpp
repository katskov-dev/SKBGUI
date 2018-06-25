#include "World/WorldController.h"
#include <Edit/Edit.h>
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
    float32    timeStep;
//    if (std::stof(Owner()->getEdit()->Model()->Text().toAnsiString())==0)
//    {
//            timeStep=0;
//    }
//    else
//     {
//          timeStep = time.asSeconds()/std::stof(Owner()->getEdit()->Model()->Text().toAnsiString());//перевести в int
//     }
    timeStep = time.asSeconds() * 4.0;
  //  std::cout << std::stof(Owner()->getEdit()->Model()->Text().toAnsiString()) <<std::endl;
    float32 velocityIterations = 6;
    float32 positionIterations = 6;
    Owner()->SetIterations(positionIterations);
    Owner()->SetTime(timeStep);
    Owner()->SetVelocity(velocityIterations);
    Owner()->Step();

}
