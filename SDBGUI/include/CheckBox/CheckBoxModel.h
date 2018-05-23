#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>
#include <Panel/Panel.h>
#include <Label/Label.h>

class CheckBoxModel: public ComponentModel
{
    public:
        CheckBoxModel();
        virtual ~CheckBoxModel();
        bool Checked();
        void SetChecked(bool checked);
        virtual void SetSize(double x,double y);
        virtual void SetSize(Vector2f ComSize);
        std::string Caption();
        void SetCaption(std::string caption);

    protected:

    private:
        bool __checked; //состояние checkbox'а
        sf::RectangleShape __rect; //квадрат с флажком
        sf::Vertex __line2[4]; // тот самый флажок (крестик)
        pLabel __caption; // надпись чекбокса
        int __sz; // размер зоны для флажка

        friend CheckBox;
        friend CheckBoxViewer;
        friend CheckBoxController;
};
