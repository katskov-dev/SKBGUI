#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Arrow/ArrowModel.h>
#include <SFML/Graphics.hpp>

class ArrowViewer: public ComponentViewer
{
    public:
        ArrowViewer(pArrowModel model);
        virtual ~ArrowViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pArrowModel Owner();
        virtual void SetOwner(pArrowModel owner);
    protected:

    private:


};
