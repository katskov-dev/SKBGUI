#pragma once
#include <base.h>
#include <Edit/EditModel.h>
#include <Component/ComponentController.h>
#include <SFML/Graphics.hpp>

class EditController: public ComponentController
{
    public:
        EditController(pEditModel model);
        virtual ~EditController();
        virtual bool Handle(sf::Event event);
//        virtual pEditModel Owner();
//        virtual void SetOwner(pEditModel owner);
    protected:

    private:
};
