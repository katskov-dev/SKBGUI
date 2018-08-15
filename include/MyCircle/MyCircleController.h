#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <MyCircle/MyCircleModel.h>
#include <SFML/Graphics.hpp>

class MyCircleController: public ComponentController
{
    public:
        MyCircleController(pMyCircleModel model);
        virtual ~MyCircleController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pMyCircleModel Owner();
        virtual void SetOwner(pMyCircleModel owner);

    protected:

    private:
};
