#pragma once
#include <base.h>
#include <string>
#include <Component/ComponentModel.h>


class EditModel: public ComponentModel
{
    public:
        EditModel();
        virtual ~EditModel();
        std::string Text();
        void SetText(std::string text);
        int CaretPos();
        void SetCaretPos(int pos);
        sf::Color FillColor();
        void SetFillColor(sf::Color color);
        sf::Color TextColor();
        void SetTextColor(sf::Color color);
        sf::Clock __clock;
        std::string SerializeToString();

    protected:

    private:
        std::string __text;
        int __caretPos;
        sf::Color __fillColor;
        sf::Color __textColor;
};
