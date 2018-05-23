#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class ArrowModel: public ComponentModel
{
    public:
        ArrowModel(pComponent start, pComponent end);
        virtual ~ArrowModel();

        pComponent __start;
        pComponent __end;
        double distance;

    protected:

    private:


        friend ArrowViewer;

};
