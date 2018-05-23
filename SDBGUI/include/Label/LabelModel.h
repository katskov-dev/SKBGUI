#pragma once
#include <base.h>
#include <Component/ComponentModel.h>
#include <string>

class LabelModel: public ComponentModel
{
    public:
        LabelModel();
        virtual ~LabelModel();
        sf::String Caption();
        void SetCaption(sf::String caption);
        sf::Color Color();
        void SetColor(sf::Color color);
    protected:

    private:
        sf::String __caption;
        sf::Color __color;
};
