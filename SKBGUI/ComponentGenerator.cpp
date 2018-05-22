#include <GUI/GUI.h>
#include <Picture/Picture.h>
#include <Table/Table.h>
#include <Edit/Edit.h>
#include <Label/Label.h>
#include <Button/Button.h>
pGUI gui;
pLabel label_componentName;
pEdit edit_ComponentName;
pTable table_Properties;
pPicture addPropertyPic;

void add_property(pComponentModel model, int x, int y, int button)
{
    int cnt = table_Properties->Model()->RowCount();
    table_Properties->Model()->SetRowCount(cnt+1);
    addPropertyPic->Model()->SetLocalCoord(table_Properties->Model()->LocalCoord() + table_Properties->Model()->Size() + sf::Vector2f(-32, 5));
}


void init()
{
    //create component name area
    label_componentName = new Label();
    label_componentName->Model()->SetLocalCoord(10,10);
    label_componentName->Model()->SetCaption(L"Название компонента");
    label_componentName->Model()->SetSize(200, 21);
    gui->Model()->Add(label_componentName);

    edit_ComponentName = new Edit();
    edit_ComponentName->Model()->SetLocalCoord(10, 40);
    edit_ComponentName->Model()->SetSize(200, 25);
    gui->Model()->Add(edit_ComponentName);

    table_Properties = new Table();
    table_Properties->Model()->SetLocalCoord(10, 70);
    table_Properties->Model()->SetColCount(2);
    table_Properties->Model()->SetRowCount(1);
    table_Properties->Model()->SetColWidth(0, 200);
    table_Properties->Model()->SetColWidth(1, 200);
    table_Properties->Model()->Cell(0,0)->Model()->SetEnabled(false);
    table_Properties->Model()->Cell(0,0)->Model()->SetText(L"Тип");
    table_Properties->Model()->Cell(0,0)->Model()->SetFillColor(sf::Color(0xe0fcf1ff));
    table_Properties->Model()->Cell(0,1)->Model()->SetEnabled(false);
    table_Properties->Model()->Cell(0,1)->Model()->SetText(L"Имя");
    table_Properties->Model()->Cell(0,1)->Model()->SetFillColor(sf::Color(0xe0fcf1ff));
    gui->Model()->Add(table_Properties);

    addPropertyPic = new Picture();
    addPropertyPic->Model()->LoadFromFile("assets/images/add.png");
    addPropertyPic->Model()->SetSize(32,32);
    addPropertyPic->Model()->SetLocalCoord(table_Properties->Model()->LocalCoord() + table_Properties->Model()->Size() + sf::Vector2f(-32, 5));
    addPropertyPic->Controller()->SetMouseDown(add_property);
    gui->Model()->Add(addPropertyPic);

}

int main()
{
    gui = new GUI(800, 600, "ComponentGenerator");
    gui->SetBackgroundColor(sf::Color(0xeeeeeeff));
    init();

    gui->loop();
    return 0;
}
