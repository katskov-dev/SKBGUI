#pragma once
#include <base.h>
#include <Component/ComponentController.h>
#include <Scene/SceneModel.h>
#include <SFML/Graphics.hpp>

class SceneController: public ComponentController
{
    public:
        SceneController(pSceneModel model);
        virtual ~SceneController();
        virtual bool Handle(sf::Event event);
		virtual pSceneModel Owner();
        virtual void SetOwner(pSceneModel owner);
        virtual void Update(sf::Time time);

    protected:

    private:
};
