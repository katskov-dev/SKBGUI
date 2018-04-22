#pragma once
#include <math.h>
#include <vector>

using namespace std;

class Neuron;
typedef Neuron* pNeuron;

class Link;
typedef Link* pLink;

class Layer;
typedef Layer* pLayer;

const double LEARN_SPEED = 0.00001;
const double AMNESIA_SPEED = LEARN_SPEED / 10.0;

class Neuron{
    public:
        double signal = 0.0;
        double tmp_signal = 0.0;
        int index = 0;
        double x;
        double y;
        vector<pNeuron> links;
};

class Link{
    public:
        pNeuron in = nullptr;
        pNeuron out = nullptr;
        double w = 0.5;
};

class Layer{
    public:
        Layer();
        vector<pNeuron> neurons;
        vector<pLink> links;
        pLayer next = nullptr;
        vector<vector<bool>> tl; // таблица связности нейронов
        int count = 10;
        pNeuron AddNeuron(double signal, double x, double y);
        pLink AddLink(pNeuron n1, pNeuron n2, double we);
        void connect(pNeuron n1, pNeuron n2);
        void updateLinks();
        void learn();
        void updateSignals();
        void upgrade();
};

void UpdateLink(Link& link);
double distance(double x1, double y1, double x2, double y2);
