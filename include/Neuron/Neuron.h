#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Neuron/NeuronModel.h>
#include <Neuron/NeuronViewer.h>
#include <Neuron/NeuronController.h>

class Neuron: public Component
{
    public:
        Neuron();
        ~Neuron();
        virtual pNeuronModel Model();
        virtual void SetModel(pNeuronModel model);
        virtual pNeuronViewer Viewer();
        virtual void SetViewer(pNeuronViewer viewer);
        virtual pNeuronController Controller();
        virtual void SetController(pNeuronController controller);
    private:

};
