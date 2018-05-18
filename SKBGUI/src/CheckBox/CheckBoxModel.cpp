#include "CheckBox/CheckBoxModel.h"

CheckBoxModel::CheckBoxModel(): ComponentModel()
{
    __caption = new Label();
    __caption->Model()->SetCaption("CheckBox");
    SetLocalCoord(0, 0);
    SetSize(150, 25);
    //SetVisibleBorders(true);
    SetChecked(false);


    //


}

CheckBoxModel::~CheckBoxModel()
{
    //dtor
    delete __caption;
}

bool CheckBoxModel::Checked()
{
    return __checked;
}

void CheckBoxModel::SetChecked(bool checked)
{
    __checked = checked;
}

void CheckBoxModel::SetSize(double x,double y)
{
    ComponentModel::SetSize(x,y);
    int sz = std::min(Size().x,Size().y);
    __sz = sz;
    sf::RectangleShape& r = __rect;

    r.setPosition(2,2);
    r.setSize(sf::Vector2f(sz-4,sz-4));

    sf::Vertex* line;
    line = __line2;
    line[0].position = sf::Vector2f(4,4);
    line[1].position = sf::Vector2f(sz-4,sz-4);
    line[2].position = sf::Vector2f(sz-4,4);
    line[3].position = sf::Vector2f(4,sz-4);
    for (int i = 0; i < 4; i++)
        line[i].color = sf::Color(0x000000ff);

    __caption->Model()->SetSize(Size().x - sz, Size().y - 4);
}

void CheckBoxModel::SetSize(Vector2f ComSize)
{
    ComponentModel::SetSize(ComSize);
    int sz = std::min(Size().x,Size().y);
    __sz = sz;
    sf::RectangleShape& r = __rect;

    r.setPosition(2,2);
    r.setSize(sf::Vector2f(sz-4,sz-4));

    sf::Vertex* line;
    line = __line2;
    line[0].position = sf::Vector2f(4,4);
    line[1].position = sf::Vector2f(sz-4,sz-4);
    line[2].position = sf::Vector2f(sz-4,4);
    line[3].position = sf::Vector2f(4,sz-4);
    for (int i = 0; i < 4; i++)
        line[i].color = sf::Color(0x000000ff);

    __caption->Model()->SetSize(Size().x - sz, Size().y - 4);
}

std::string CheckBoxModel::Caption()
{
    return __caption->Model()->Caption();
}

void CheckBoxModel::SetCaption(std::string caption)
{
    __caption->Model()->SetCaption(caption);
}
