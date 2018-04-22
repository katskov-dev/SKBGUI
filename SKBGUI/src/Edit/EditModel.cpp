#include "Edit/EditModel.h"

EditModel::EditModel(): ComponentModel()
{
    SetText("");
    SetCaretPos(0);

    SetLocalCoord(0, 0);
    SetSize(150, 25);
    SetFillColor(sf::Color(0xffffffff));
    SetTextColor(sf::Color(0x000000ff));
    __class = "Edit";

    //загружаем шрифт и устанавливаем его для надписи на кнопке
    __font.loadFromFile("assets/fonts/OpenSans-Regular.ttf");
    __render_text.setFont(__font);
    __render_text.setColor(sf::Color(0x000000ff));
    SetVisibleOutline(true);


}

EditModel::~EditModel()
{
    //dtor
}

std::string EditModel::Text()
{
    return __text;
}

void EditModel::SetText(std::string text)
{
    __text = text;
    __render_text.setCharacterSize(Size().y * 0.8);
    __render_text.setString(Text());
}

int EditModel::CaretPos()
{
    return __caretPos;
}

void EditModel::SetCaretPos(int pos)
{
    __caretPos = pos;
}

sf::Color EditModel::FillColor()
{
    return __fillColor;
}

void EditModel::SetFillColor(sf::Color color)
{
    __fillColor = color;
}

sf::Color EditModel::TextColor()
{
    return __render_text.getColor();
}

void EditModel::SetTextColor(sf::Color color)
{
    __render_text.setColor(color);
}

void EditModel::SetVisibleOutline(bool visibleOutline)
{
    __visibleOutline = visibleOutline;
}

bool EditModel::VisibleOutline()
{
    return __visibleOutline;
}

std::string EditModel::SerializeToString()
{
    std::string result = "";
    std::string parent_name = Parent()->Name();
    result += "edit_create('"+Name()+"', '"+parent_name+"')\n";
    result += "component_model_setlocalcoord('"+Name()+"', "+std::to_string(LocalCoord().x)+", "+std::to_string(LocalCoord().y) + ")\n";
    result += "component_model_setsize('"+Name()+"', "+std::to_string(Size().x)+", "+std::to_string(Size().y) + ")\n";

    return result;

}
