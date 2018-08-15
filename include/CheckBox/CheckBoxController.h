#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <CheckBox/CheckBoxModel.h>
#include <SFML/Graphics.hpp>

class CheckBoxController: public ComponentController
{
    public:
        CheckBoxController(pCheckBoxModel model);
        virtual ~CheckBoxController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pCheckBoxModel Owner();
        virtual void SetOwner(pCheckBoxModel owner);

    protected:

    private:
};
