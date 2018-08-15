#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class PanelModel: public ComponentModel
{
    public:
        PanelModel();
        virtual ~PanelModel();
        sf::Color Color();
        void SetColor(sf::Color color);
    protected:

    private:
        sf::Color __color;

};
