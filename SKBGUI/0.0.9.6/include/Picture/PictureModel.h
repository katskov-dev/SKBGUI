#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <SFML/Graphics.hpp>

class PictureModel: public ComponentModel
{
    public:
        PictureModel();
        virtual ~PictureModel();
        sf::Texture* Texture();
        void SetTexture(sf::Texture* texture);
        void LoadFromFile(std::string filename);

    protected:

    private:
        sf::Texture* __texture;

};
