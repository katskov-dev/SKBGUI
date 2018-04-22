#pragma once
#include <base.h>
#include <Component/ComponentModel.h>
#include <string>

class LabelModel: public ComponentModel
{
    public:
        LabelModel();
        virtual ~LabelModel();
        std::string Caption();
        void SetCaption(std::string caption);
        sf::Color Color();
        void SetColor(sf::Color color);
    protected:

    private:
        std::string __caption;
        sf::Color __color;
};
