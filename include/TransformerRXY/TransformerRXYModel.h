#pragma once
#include <base.h>
#include <Component/ComponentModel.h>
#include <Component/Component.h>
#include <SFML/Graphics.hpp>
#include <Picture/Picture.h>


const int TransformerRXY_STATE_NORMAL = 0;
const int TransformerRXY_STATE_DOWN = 1;
const int TransformerRXY_STATE_RELEASE = 2;
const int TransformerRXY_STATE_MOVE = 3;

class TransformerRXYModel: public ComponentModel
{
    public:
        TransformerRXYModel();
        virtual ~TransformerRXYModel();
        pComponent Target();
        void SetTarget(pComponent target);
        void UpdatePoints();
        sf::Vector2f Point(int index);
        void SetRadius(double radius);
        double Radius();
        sf::Vector2f MouseCoord;
        sf::Vector2f OffsetPoint;
        bool flagOffsetX;
        bool flagOffsetY;
//        bool flagRotate;


        sf::CircleShape c;
        pPicture arrow_x;
        pPicture arrow_y;
//        pPicture ring;
    protected:

    public:
        sf::Vector2f __points[9];
        double __radius;
        sf::Color __defaultColor;
        sf::Color __activeColor;
        pComponent __target;
        int activePoint;
        pPicture __arrow_x;
        pPicture __arrow_y;
//        pPicture __ring;

};
