#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Arrow/ArrowModel.h>
#include <SFML/Graphics.hpp>

class ArrowController: public ComponentController
{
    public:
        ArrowController(pArrowModel model);
        virtual ~ArrowController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pArrowModel Owner();
        virtual void SetOwner(pArrowModel owner);

    protected:

    private:
};
