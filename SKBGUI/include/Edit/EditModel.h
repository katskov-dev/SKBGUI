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
        void SetVisibleOutline(bool visibleOutline);
        bool VisibleOutline();
        sf::Clock __clock;

        std::string SerializeToString();

    protected:

    private:
        std::string __text;
        int __caretPos;
        sf::Font __font;
        sf::Text __render_text;
        sf::Color __fillColor;
        bool __visibleOutline;
        friend EditViewer;
        friend EditController;
};
