#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class AnimationModel: public ComponentModel
{
    public:
        AnimationModel();
        virtual ~AnimationModel();
        sf::Texture& Texture();
        void SetTexture(sf::Texture texture);
        int currentFrame();
        void SetCurrentFrame(int currentFrame);
        sf::Vector2f tilesCount();
        void setTilesCount(sf::Vector2f tilesCount);
        void loadFromFile(std::string fileName);
        void nextFrame();
        sf::Time interval();
        void setInterval(sf::Time interval);
        sf::Time currentTime();
        void setCurrentTime(sf::Time currentTime);

        int __row;
        int __col;
        int __x1;
        int __x2;
        int __y1;
        int __y2;
        int __tw;
        int __th;
        sf::Sprite sprite;

    protected:

    private:
        sf::Texture __texture;
        sf::Vector2f __tilesCount;
        int __currentFrame;
        sf::Time __interval;
        sf::Time __currentTime;

};
