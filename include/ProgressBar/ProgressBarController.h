#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <ProgressBar/ProgressBarModel.h>
#include <SFML/Graphics.hpp>

class ProgressBarController: public ComponentController
{
    public:
        ProgressBarController(pProgressBarModel model);
        virtual ~ProgressBarController();
        virtual bool Handle(sf::Event event);
		virtual void Update(sf::Time time);
		virtual pProgressBarModel Owner();
        virtual void SetOwner(pProgressBarModel owner);

    protected:

    private:
};
