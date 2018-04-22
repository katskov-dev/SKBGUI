#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Neuron/NeuronModel.h>
#include <SFML/Graphics.hpp>

class NeuronController: public ComponentController
{
    public:
        NeuronController(pNeuronModel model);
        virtual ~NeuronController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pNeuronModel Owner();
        virtual void SetOwner(pNeuronModel owner);

    protected:

    private:
};
