#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Panel/Panel.h>


class CheckBoxModel: public ComponentModel
{
    public:
        CheckBoxModel();
        virtual ~CheckBoxModel();
        bool Checked();
        void SetChecked(bool checked);

    protected:

    private:
        bool __checked;
        sf::RectangleShape __rect;
        sf::Vertex __line2[4];
        friend CheckBox;
        friend CheckBoxViewer;
        friend CheckBoxController;
};
