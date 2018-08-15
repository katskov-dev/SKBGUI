#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <Scene/SceneModel.h>
#include <SFML/Graphics.hpp>

class SceneViewer: public ComponentViewer
{
    public:
        SceneViewer(pSceneModel model);
        virtual ~SceneViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pSceneModel Owner();
        virtual void SetOwner(pSceneModel owner);
    protected:

    private:


};
