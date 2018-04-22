#include "drn.h"
#include <cstdlib>
void UpdateLink(Link& link)
{
    //forward
    double real_out = link.in->signal * link.w;
    double error = link.out->signal - real_out;
    double speed;
    speed = LEARN_SPEED;
//    if (error > 0)
//        speed = LEARN_SPEED;
//    else
//        speed = AMNESIA_SPEED;


    double corrector = error * link.in->signal * speed;
    if (corrector > 0)
        link.w += corrector;
    //back
}

Layer::Layer()
{
}

pNeuron Layer::AddNeuron(double signal, double x, double y)
{
    pNeuron n = new Neuron();
    n->signal = signal;
    neurons.push_back(n);
    tl.resize(neurons.size());
    n->index = neurons.size()-1;
    for (int i = 0; i < neurons.size(); i++){
        tl[i].resize(neurons.size());
    }
    return n;
}

pLink Layer::AddLink(pNeuron n1, pNeuron n2, double we)
{
    pLink l = new Link();
    l->in = n1;
    l->out = n2;
    l->w = we * n1->signal;
    links.push_back(l);
    return l;
}

void Layer::connect(pNeuron n1, pNeuron n2)
{
    if (next == nullptr)
        return;

    pNeuron n3 = next->AddNeuron(0,0,0);
    pLink L_1_3 = AddLink(n1, n3, 0.5);
    pLink L_2_3 = AddLink(n2, n3, 0.5);
};

void Layer::updateLinks()
{
    //calculate
    for (int i = 0; i < links.size(); i++){
        links[i]->out->tmp_signal += links[i]->in->signal * links[i]->w;
    }
}

void Layer::learn()
{
    for (int i = 0; i < links.size(); i++){
        UpdateLink(*links[i]);
    }
}

void Layer::updateSignals()
{

    //relocate and clear new_signal
    for (int i = 0; i < neurons.size(); i++){
        //n[i].signal = 1.0 / (1 + exp(-n[i].new_signal));
        neurons[i]->signal = tanh(neurons[i]->tmp_signal);
        //n[i].signal = n[i].new_signal;
        neurons[i]->tmp_signal = 0.0;
    }
}

void Layer::upgrade()
{
    //sorting...
    bool f;
    do{
        f = true;
        for (int i = 0; i < neurons.size()-1; i++){
            for (int j = i+1; j < neurons.size(); j++){
                if (neurons[i]->signal < neurons[j]->signal){
                    swap(neurons[i], neurons[j]);
                    f = false;
                }
            }
        }
    } while (!f);



    //assume neurons
    for (int i = 0; i < neurons.size()-1; i++){
        for (int j = i+1; j < neurons.size(); j++){
            pNeuron n1 = neurons[i];
            pNeuron n2 = neurons[j];
            if (tl[n1->index][n2->index])
                continue;
            if ((n1->signal < 0.1) || (n2->signal < 0.1))
                continue;
            if (next->neurons.size() >= next->count){
                //ничего не поделаешь
            }
            else{
                if (distance(n1->x, n1->y, n2->x, n2->y) < 2.0){
                    connect(n1,n2);
                    tl[n1->index][n2->index] = true;
                    tl[n2->index][n1->index] = true;
                }
            }
        }
    }

    //back sorting...

    do{
        f = true;
        for (int i = 0; i < neurons.size()-1; i++){
            for (int j = i+1; j < neurons.size(); j++){
                if (neurons[i]->index > neurons[j]->index){
                    swap(neurons[i], neurons[j]);
                    f = false;
                }
            }
        }
    } while (!f);
}

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}
