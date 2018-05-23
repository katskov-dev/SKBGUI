#include <Neuron/Neuron.h>


Neuron::Neuron()
{
    SetModel(new NeuronModel());
    SetViewer(new NeuronViewer(Model()));
    SetController(new NeuronController(Model()));
}

Neuron::~Neuron()
{

}

pNeuronModel Neuron::Model()
{
    return pNeuronModel(__model);
}

void Neuron::SetModel(pNeuronModel model)
{
    __model = model;
}

pNeuronViewer Neuron::Viewer()
{
    return pNeuronViewer(__viewer);
}

void Neuron::SetViewer(pNeuronViewer viewer)
{
    __viewer = viewer;
}

pNeuronController Neuron::Controller()
{
    return pNeuronController(__controller);
}

void Neuron::SetController(pNeuronController controller)
{
    __controller = controller;
}

