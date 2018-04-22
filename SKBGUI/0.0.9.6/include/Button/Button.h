#pragma once
#include <base.h>
#include <Component/Component.h>
#include <Button/ButtonModel.h>
#include <Button/ButtonViewer.h>
#include <Button/ButtonController.h>

class Button: public Component
{
    public:
        Button();
        Button(string caption);
        Button(string caption, sf::Vector2f coord);
        Button(string caption, sf::Vector2f coord, sf::Vector2f size);
        virtual ~Button();
        virtual pButtonModel Model();
        virtual void SetModel(pButtonModel model);
        virtual pButtonViewer Viewer();
        virtual void SetViewer(pButtonViewer viewer);
        virtual pButtonController Controller();
        virtual void SetController(pButtonController controller);
       //11`1`` virtual std::string Class();
    protected:

    private:
};
