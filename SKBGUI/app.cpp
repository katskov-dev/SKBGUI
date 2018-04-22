#include <GUI/GUI.h>
#include <Button/Button.h>
#include <Picture/Picture.h>
#include <Transformer/Transformer.h>
#include <SFML/System.hpp>
#include <Edit/Edit.h>
#include <Label/Label.h>
#include <string>
#include <iostream>

#include <Panel/Panel.h>
#include <Table/Table.h>
#include <Timer/Timer.h>
#include <locale>
#include <fstream>

pGUI gui;
pComponent current;
pTransformer t;
pPanel panelEditor;
int obj_number;
bool selected = false;
 pTable pvt;

void key_down(pComponentModel model,int key)
{
    if (key == sf::Keyboard::Return)
        std::cout << "Key: "  << std::endl;
}

void transformer_mouse_move(pComponentModel model)
{
    if (current != nullptr)
    {
        pEdit cell = pvt->Model()->Cell(1, 1);
        if (!cell->Model()->Focus())
            cell->Model()->SetText(std::to_string(current->Model()->LocalCoord().x));
        cell = pvt->Model()->Cell(2, 1);
        if (!cell->Model()->Focus())
            cell->Model()->SetText(std::to_string(current->Model()->LocalCoord().y));
        cell = pvt->Model()->Cell(3, 1);
        if (!cell->Model()->Focus())
            cell->Model()->SetText(std::to_string(current->Model()->Size().x));
        cell = pvt->Model()->Cell(4, 1);
        if (!cell->Model()->Focus())
            cell->Model()->SetText(std::to_string(current->Model()->Size().y));
        cell = pvt->Model()->Cell(5, 1);
        if (!cell->Model()->Focus())
            cell->Model()->SetText(current->Model()->Name());
        cell = pvt->Model()->Cell(6, 1);
        if (!cell->Model()->Focus())
            cell->Model()->SetText(std::to_string(current->Model()->Enabled()));
    }
}


void set_transform(pComponentModel model, int x, int y, int button)
{

//    if (current != nullptr)
//    {
//        std::cout << "X: " << x <<", Y: " << y <<", Button: " << button << std::endl;
//        double v_c_x = std::stod(editCoordX->Model()->Text());
//        double v_c_y = std::stod(editCoordY->Model()->Text());
//        double v_s_x = std::stod(editSizeX->Model()->Text());
//        double v_s_y = std::stod(editSizeY->Model()->Text());
//        std::cout << "Test" << std::endl;
//        std::cout << "Test cx" << v_c_x<< std::endl;
//        std::cout << "Test cy" <<  v_c_y<< std::endl;
//        std::cout << "Test sx" << v_s_x<< std::endl;
//        std::cout << "Test sy" << v_s_y<< std::endl;
//        current->Model()->SetLocalCoord(v_c_x, v_c_y);
//        current->Model()->SetSize(v_s_x, v_s_y);
//    }
}

void unselect(pComponentModel model, int x, int y, int button)
{
    if ((t != nullptr) && (current != nullptr)){

        current->Model()->Delete("TRANSFORM");
        current->Controller()->SetIdle(nullptr);
        current = nullptr;
        selected = false;
    }
}
void key_down_delete(pComponentModel model, int key)
{
    if (key == sf::Keyboard::Delete){
        pComponent p= current;
        unselect(model, 0, 0, 0);
        gui->Model()->Find("gui")->Model()->Delete(p);
    }
    if (key == sf::Keyboard::Escape){
        unselect(model, 0, 0, 0);
    }
}


void select(pComponentModel model, int x, int y, int button)
{

    if (current != nullptr){
        unselect(model, x, y, button);

    }
    std::cout << model->Name() << std::endl;

    current = panelEditor->Model()->Find(model->Name());
    t = new Transformer();
    current->Controller()->SetIdle(transformer_mouse_move);
    current->Controller()->SetKeyDown(key_down_delete);
    t->Model()->SetName("TRANSFORM");
    //std::cout << current << std::endl;

    t->Model()->SetTarget(current);
    current->Model()->Add(t);
    selected = true;


}


void addLabel(pComponentModel model, int x, int y, int button)
{
    pLabel label = new Label();
    std::string name;
    name = "Label";
    name += std::to_string(obj_number);
    label->Model()->SetName(name);
    label->Controller()->SetMouseDown(select);
    panelEditor->Model()->Add(label);

    obj_number++;
}

void addEdit(pComponentModel model, int x, int y, int button)
{
    pEdit edit = new Edit();
    std::string name;
    name = "Edit";
    name += std::to_string(obj_number);
    edit->Model()->SetName(name);
    edit->Controller()->SetMouseDown(select);
    edit->Controller()->SetKeyDown(key_down);
    edit->Model()->SetFillColor(sf::Color(0xddddddff));
    panelEditor->Model()->Add(edit);

    obj_number++;
}

void addButton(pComponentModel model, int x, int y, int btn)
{
    pButton button = new Button();
    std::string name;
    name = "Button";
    name += std::to_string(obj_number);
    button->Model()->SetName(name);
    button->Controller()->SetMouseDown(select);
    panelEditor->Model()->Add(button);

    obj_number++;
}

void addPicture(pComponentModel model, int x, int y, int button)
{
    pPicture picture = new Picture();
    std::string name;
    name = "Picture";
    name += std::to_string(obj_number);
    picture->Model()->SetName(name);
    picture->Model()->LoadFromFile("assets/images/image_sprite.png");
    picture->Model()->SetSize(100, 100);
    picture->Controller()->SetMouseDown(select);
    panelEditor->Model()->Add(picture);

    obj_number++;
}

void addPanel(pComponentModel model, int x, int y, int button)
{
    pPanel panel = new Panel();
    std::string name;
    name = "Panel";
    name += std::to_string(obj_number);
    panel->Model()->SetName(name);
    panel->Model()->SetSize(100, 100);
    panel->Controller()->SetMouseDown(select);
    panelEditor->Model()->Add(panel);

    obj_number++;
}

void addTable(pComponentModel model, int x, int y, int button)
{
    pTable table = new Table();
    std::string name;
    name = "Table";
    name += std::to_string(obj_number);
    table->Model()->SetName(name);
    table->Model()->SetRowCount(3);
    table->Model()->SetColCount(3);
    table->Controller()->SetMouseDown(select);
    panelEditor->Model()->Add(table);

    obj_number++;
}


int counter = 0;
void my_idle(pComponentModel model)
{
//    counter++;
//    std::cout << "My counter: " << counter << std::endl;
}

void inspector_set_coord_x(pComponentModel model, int key)
{
    if (key == sf::Keyboard::Return){
        if (current != nullptr){

            sf::Vector2f coord = current->Model()->LocalCoord();
            coord.x = std::stod(pvt->Model()->Cell(1,1)->Model()->Text());
            current->Model()->SetLocalCoord(coord);
        }
    }
}

void inspector_set_coord_y(pComponentModel model, int key)
{
    if (key == sf::Keyboard::Return){
        if (current != nullptr){

            sf::Vector2f coord = current->Model()->LocalCoord();
            coord.y = std::stod(pvt->Model()->Cell(2,1)->Model()->Text());
            current->Model()->SetLocalCoord(coord);
        }
    }
}

void inspector_set_size_x(pComponentModel model, int key)
{
    if (key == sf::Keyboard::Return){
        if (current != nullptr){

            sf::Vector2f sz = current->Model()->Size();
            sz.x = std::stod(pvt->Model()->Cell(3,1)->Model()->Text());
            current->Model()->SetSize(sz);
            std::cout << sz.x << " " << sz.y << std::endl;
        }
    }
}

void inspector_set_size_y(pComponentModel model, int key)
{
    if (key == sf::Keyboard::Return){
        if (current != nullptr){

            sf::Vector2f sz = current->Model()->Size();
            sz.y = std::stod(pvt->Model()->Cell(4,1)->Model()->Text());
            current->Model()->SetSize(sz);
        }
    }
}



void save(pComponentModel model)
{
    ofstream fout;
    fout.open("form.ui");
    for (int i = 0; i < panelEditor->Model()->Count(); i++){
        //std::cout << panelEditor->Model()->Children(i)->Model()->Name() << std::endl;
        std::string s  = panelEditor->Model()->Children(i)->Model()->SerializeToString();
        std::cout << pButtonModel(panelEditor->Model()->Children(i)->Model())->SerializeToString();

        fout << s;
    }
    fout.close();
}

void TimeFunc()
{
    static int my_counter = 0;
    std::cout << "Counter: " << my_counter++  << std::endl;
}

void Editor()
{
    //setlocale(LC_ALL, "russian");
    obj_number = 0;
    gui = new GUI(1000, 600, "SKBGUI");
    //------------------------------------
    //--------------------INFO
    pPanel panelInfo = new Panel();
    panelInfo->Model()->SetSize(150, 600);



    //----------------BUTTONS ADD
    pButton setValues = new Button();
    setValues->Model()->SetLocalCoord(5, 500);
    setValues->Model()->SetSize(140, 25);
    setValues->Model()->SetCaption("Set");
    setValues->Controller()->SetMouseDown(set_transform);
    panelInfo->Model()->Add(setValues);

    pButton btnSave = new Button();
    btnSave->Model()->SetLocalCoord(5, 530);
    btnSave->Model()->SetSize(140, 25);
    btnSave->Model()->SetCaption("Save to file");

    btnSave->Controller()->SetClick(save);
    panelInfo->Model()->Add(btnSave);

    pButton btnLoad = new Button();
    btnLoad->Model()->SetLocalCoord(5, 560);
    btnLoad->Model()->SetSize(140, 25);
    btnLoad->Model()->SetCaption("Load from file(not work)");

    panelInfo->Model()->Add(btnLoad);




    pPicture buttonAddLabel = new Picture();
    buttonAddLabel->Model()->LoadFromFile("assets/images/components/label.png");
    buttonAddLabel->Model()->SetLocalCoord(5, 10);
    buttonAddLabel->Model()->SetSize(32, 32);
    //buttonAddLabel->Model()->SetCaption("Add Label");
    buttonAddLabel->Controller()->SetMouseUp(addLabel);

    panelInfo->Model()->Add(buttonAddLabel);

    pPicture buttonAddEdit = new Picture();
    buttonAddEdit->Model()->SetLocalCoord(5, 50);
    buttonAddEdit->Model()->SetSize(32, 32);
    buttonAddEdit->Model()->LoadFromFile("assets/images/components/edit.png");
    //buttonAddEdit->Model()->SetCaption("Add Edit");
    buttonAddEdit->Controller()->SetMouseUp(addEdit);

    panelInfo->Model()->Add(buttonAddEdit);

    pPicture buttonAddButton = new Picture();
    buttonAddButton->Model()->SetLocalCoord(5, 90);
    buttonAddButton->Model()->SetSize(32, 32);
    buttonAddButton->Model()->LoadFromFile("assets/images/components/button.png");
    //buttonAddButton->Model()->SetCaption("Add Button");
    buttonAddButton->Controller()->SetMouseUp(addButton);

    panelInfo->Model()->Add(buttonAddButton);

    pPicture PictureAddPicture = new Picture();
    PictureAddPicture->Model()->SetLocalCoord(5, 130);
    PictureAddPicture->Model()->SetSize(32, 32);
    PictureAddPicture->Model()->LoadFromFile("assets/images/components/picture.png");
    //PictureAddPicture->Model()->SetCaption("Add Picture");
    PictureAddPicture->Controller()->SetMouseUp(addPicture);

    panelInfo->Model()->Add(PictureAddPicture);

    pPicture buttonAddPanel = new Picture();
    buttonAddPanel->Model()->SetLocalCoord(5, 170);
    buttonAddPanel->Model()->SetSize(32, 32);
    buttonAddPanel->Model()->LoadFromFile("assets/images/components/panel.png");
    buttonAddPanel->Controller()->SetMouseUp(addPanel);
    panelInfo->Model()->Add(buttonAddPanel);

    pPicture buttonAddTable = new Picture();
    buttonAddTable->Model()->SetLocalCoord(5, 210);
    buttonAddTable->Model()->SetSize(32, 32);
    buttonAddTable->Model()->LoadFromFile("assets/images/components/table.png");
    buttonAddTable->Controller()->SetMouseUp(addTable);
    panelInfo->Model()->Add(buttonAddTable);

    //--------------------Editor

    panelEditor = new Panel();
//    panelEditor->Model()->SetLocalCoord(150, 0);
//    panelEditor->Model()->SetSize(650, 600);
    panelEditor->Model()->SetLocalCoord(150, 0);
    panelEditor->Model()->SetSize(650, 600);

    panelEditor->Model()->SetColor(sf::Color(0xffffffff));
    panelEditor->Model()->SetName("gui");


//    current = new Edit();
//    current->Model()->SetName("Edit1");
//    current->Controller()->SetMouseDown(select);
//    current->Model()->SetLocalCoord(50, 50);
//    std::cout << current << std::endl;





    //panelEditor->Model()->Add(current);

//     pLabel l = new Label();
//    l->Model()->SetName("Label1");
//    l->Controller()->SetMouseDown(select);
//    l->Model()->SetLocalCoord(0, 0);
//    panelEditor->Model()->Add(l);
//    std::cout << l << std::endl;


    panelInfo->Controller()->SetMouseDown(unselect);
    gui->Model()->Add(panelInfo);

    current = nullptr;
    t = nullptr;
    //-----------OBJECT INSPECTOR

    pPanel panelInspector = new Panel();
    panelInspector->Model()->SetLocalCoord(800, 0);
    panelInspector->Model()->SetSize(200, 600);
    gui->Model()->Add(panelInspector);

    pvt = new Table();
    pvt->Model()->SetColCount(2);
    pvt->Model()->SetRowCount(10);


    pvt->Model()->Cell(0, 0)->Model()->SetText("Property");
    pvt->Model()->Cell(0, 0)->Model()->SetFillColor(sf::Color(0xCEE5EDff));
    pvt->Model()->Cell(0, 0)->Model()->SetTextColor(sf::Color(0x444444ff));
    pvt->Model()->Cell(0, 0)->Model()->SetEnabled(false);
    pvt->Model()->Cell(0, 0)->Model()->SetFillColor(sf::Color(0xCEE5EDff));
    pvt->Model()->Cell(0, 1)->Model()->SetText("Value");
    pvt->Model()->Cell(0, 1)->Model()->SetFillColor(sf::Color(0xCEE5EDff));
    pvt->Model()->Cell(0, 1)->Model()->SetTextColor(sf::Color(0x444444ff));
    pvt->Model()->Cell(0, 1)->Model()->SetEnabled(false);
    for (int i = 0; i < pvt->Model()->RowCount(); i++)
        pvt->Model()->Cell(i, 0)->Model()->SetFillColor(sf::Color(0xCEE5EDff));
    pvt->Model()->Cell(1, 0)->Model()->SetText("Coord.x");
    pvt->Model()->Cell(1, 1)->Controller()->SetKeyDown(inspector_set_coord_x);
    pvt->Model()->Cell(2, 0)->Model()->SetText("Coord.y");
    pvt->Model()->Cell(2, 1)->Controller()->SetKeyDown(inspector_set_coord_y);
    pvt->Model()->Cell(3, 0)->Model()->SetText("Size.x");
    pvt->Model()->Cell(3, 1)->Controller()->SetKeyDown(inspector_set_size_x);
    pvt->Model()->Cell(4, 0)->Model()->SetText("Size.y");
    pvt->Model()->Cell(4, 1)->Controller()->SetKeyDown(inspector_set_size_y);
    pvt->Model()->Cell(5, 0)->Model()->SetText("Name");
    pvt->Model()->Cell(6, 0)->Model()->SetText("Enabled");

//    for (int i = 1; i < 6; i++)
//        pvt->Model()->Cell(i, 1)->Controller()->SetKeyDown(key_down);


    //addButton(nullptr, 1, 1, 0);


    panelInspector->Model()->Add(pvt);
    gui->Model()->Add(panelEditor);


    gui->loop();
}


int main()
{



    Editor();
    return 0;
}
