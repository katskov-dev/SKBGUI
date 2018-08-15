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
        sf::Texture* Mask();
        void SetMask(sf::Texture* mask);
        void LoadMaskFromFile(std::string filename);
        void LoadFromFile(std::string filename, bool useSelectMask = false);

    protected:

    private:
        sf::Texture* __texture;
        sf::Texture* __mask;

};
