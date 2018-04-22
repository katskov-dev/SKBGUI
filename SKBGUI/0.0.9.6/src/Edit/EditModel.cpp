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
    return __textColor;
}

void EditModel::SetTextColor(sf::Color color)
{
    __textColor = color;
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
