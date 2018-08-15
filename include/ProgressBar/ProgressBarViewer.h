#pragma once
#include <base.h>
#include <Component/ComponentViewer.h>
#include <ProgressBar/ProgressBarModel.h>
#include <SFML/Graphics.hpp>

class ProgressBarViewer: public ComponentViewer
{
    public:
        ProgressBarViewer(pProgressBarModel model);
        virtual ~ProgressBarViewer();
        virtual void Render(sf::RenderTarget& target);
		virtual pProgressBarModel Owner();
        virtual void SetOwner(pProgressBarModel owner);
    protected:

    private:


};
