#include "Neuron/NeuronModel.h"

NeuronModel::NeuronModel(): ComponentModel()
{
    SetLocalCoord(0, 0);
    SetSize(20, 20);
    SetVisibleBorders(false);
    signal = 0.0;

}

NeuronModel::~NeuronModel()
{
    //dtor
}
