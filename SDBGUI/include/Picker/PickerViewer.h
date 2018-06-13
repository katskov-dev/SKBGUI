#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Picker/PickerModel.h>
#include <SFML/Graphics.hpp>

class PickerViewer: public ComponentViewer
{
    public:
        PickerViewer(pPickerModel model);
        virtual ~PickerViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pPickerModel Owner();
        virtual void SetOwner(pPickerModel owner);
    protected:

    private:
        sf::Sprite __sprite;


};
