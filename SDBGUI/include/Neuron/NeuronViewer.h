#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Neuron/NeuronModel.h>
#include <SFML/Graphics.hpp>

class NeuronViewer: public ComponentViewer
{
    public:
        NeuronViewer(pNeuronModel model);
        virtual ~NeuronViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pNeuronModel Owner();
        virtual void SetOwner(pNeuronModel owner);
    protected:

    private:


};
