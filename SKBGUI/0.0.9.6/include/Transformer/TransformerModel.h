#pragma once
#include <base.h>
#include <Component/ComponentModel.h>
#include <Component/Component.h>
#include <SFML/Graphics.hpp>


const int TRANSFORMER_STATE_NORMAL = 0;
const int TRANSFORMER_STATE_DOWN = 1;
const int TRANSFORMER_STATE_RELEASE = 2;
const int TRANSFORMER_STATE_MOVE = 3;

class TransformerModel: public ComponentModel
{
    public:
        TransformerModel();
        virtual ~TransformerModel();
        pComponent Target();
        void SetTarget(pComponent target);
        void UpdatePoints();
        sf::Vector2f Point(int index);
        void SetRadius(double radius);
        double Radius();
    protected:

    public:
        sf::Vector2f __points[9];
        double __radius;
        sf::Color __defaultColor;
        sf::Color __activeColor;
        pComponent __target;
        int activePoint;

};
