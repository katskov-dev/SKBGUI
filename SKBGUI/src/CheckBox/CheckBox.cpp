#include <CheckBox/CheckBox.h>
#include <math.h>

CheckBox::CheckBox()
{
    SetModel(new CheckBoxModel());


    int sz = std::min(Model()->Size().x,Model()->Size().y);
    sf::RectangleShape& r = Model()->__rect;

    r.setPosition(1,1);
    r.setSize(sf::Vector2f(sz-2,sz-2));

//    sf::Vertex* line;
//    line = Model()->__line2;


    SetViewer(new CheckBoxViewer(Model()));
    SetController(new CheckBoxController(Model()));
}

CheckBox::~CheckBox()
{

}

pCheckBoxModel CheckBox::Model()
{
    return pCheckBoxModel(__model);
}

void CheckBox::SetModel(pCheckBoxModel model)
{
    __model = model;
}

pCheckBoxViewer CheckBox::Viewer()
{
    return pCheckBoxViewer(__viewer);
}

void CheckBox::SetViewer(pCheckBoxViewer viewer)
{
    __viewer = viewer;
}

pCheckBoxController CheckBox::Controller()
{
    return pCheckBoxController(__controller);
}

void CheckBox::SetController(pCheckBoxController controller)
{
    __controller = controller;
}

