#include "Neuron/NeuronController.h"

NeuronController::NeuronController(pNeuronModel model): ComponentController(pComponentModel(model))
{
    //ctor
}

NeuronController::~NeuronController()
{
    //dtor
}

bool NeuronController::Handle(sf::Event event)
{
	ComponentController::Handle(event);
    switch (event.type){
        case sf::Event::MouseButtonPressed : {

            break;
        };
    };
    return false;
}

void NeuronController::Update(sf::Time time)
{
    ComponentController::Update(time);

}

pNeuronModel NeuronController::Owner()
{
    return pNeuronModel(ComponentController::Owner());
}

void NeuronController::SetOwner(pNeuronModel owner)
{
    ComponentController::SetOwner(owner);
}
