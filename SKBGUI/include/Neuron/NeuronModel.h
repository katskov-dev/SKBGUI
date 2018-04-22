#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class NeuronModel: public ComponentModel
{
    public:
        NeuronModel();
        virtual ~NeuronModel();

        double signal;
    protected:

    private:


};
