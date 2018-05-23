#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <CheckBox/CheckBoxModel.h>
#include <SFML/Graphics.hpp>

class CheckBoxViewer: public ComponentViewer
{
    public:
        CheckBoxViewer(pCheckBoxModel model);
        virtual ~CheckBoxViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pCheckBoxModel Owner();
        virtual void SetOwner(pCheckBoxModel owner);
    protected:

    private:


};
