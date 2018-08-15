#pragma once

#include <base.h>
#include <Component/Component.h>
#include <Animation/AnimationModel.h>
#include <Animation/AnimationViewer.h>
#include <Animation/AnimationController.h>

class Animation: public Component
{
    public:
        Animation();
        ~Animation();
        virtual pAnimationModel Model();
        virtual void SetModel(pAnimationModel model);
        virtual pAnimationViewer Viewer();
        virtual void SetViewer(pAnimationViewer viewer);
        virtual pAnimationController Controller();
        virtual void SetController(pAnimationController controller);

        static pAnimation FastCreate(pComponent parent, std::string filename, sf::Vector2f tc, sf::Time interval, sf::Vector2f size, sf::Vector2f localcoord);
    private:

};
