#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class PickerModel: public ComponentModel
{
    public:
        PickerModel();
        virtual ~PickerModel();
        sf::Texture& Mask();
        void SetMask(sf::Texture& mask);
        void LoadMaskFromFile(std::string filename);
        pComponent Target();
        void SetTarget(pComponent target);
    protected:

    private:
        sf::Texture __mask;
        pComponent __target;
	friend Picker;
	friend PickerViewer;
	friend PickerController;

};
