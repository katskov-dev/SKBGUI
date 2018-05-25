#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Picker/PickerModel.h>
#include <SFML/Graphics.hpp>

class PickerController: public ComponentController
{
    public:
        PickerController(pPickerModel model);
        virtual ~PickerController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pPickerModel Owner();
        virtual void SetOwner(pPickerModel owner);

    protected:

    private:
};
