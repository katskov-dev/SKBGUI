#include <exports.h>


int lua_Component_Create(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name
    std::string name = lua.ArgumentAsString(1);
    std::string parent_name = lua.ArgumentAsString(2);
    pComponent component = new Component();
    component->Model()->SetVisibleBorders(true);
    component->Model()->SetSize(100,100);
    component->Model()->SetName(name);
    if (parent_name == "gui")
        gui->Model()->Add(component);
    else{
        pComponent parent = gui->Model()->FindAll(name);
    }
    return 0;
}

int lua_Component_Delete(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name
    std::string name = lua.ArgumentAsString(1);
    pComponent component = gui->Model()->FindAll(name);
    if (component != nullptr){

        pComponentModel parent = component->Model()->Parent();
        parent->Delete(component);
    }
    return 0;
}


int lua_Component_Model_SetLocalCoord(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name

    std::string name = lua.ArgumentAsString(1);
    double x = lua.ArgumentAsDouble(2);
    double y = lua.ArgumentAsDouble(3);
    pComponent component = gui->Model()->FindAll(name);
    if (component != nullptr)
        component->Model()->SetLocalCoord(x, y);
    return 0;
}

int lua_Component_Model_SetSize(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name

    std::string name = lua.ArgumentAsString(1);
    double w = lua.ArgumentAsDouble(2);
    double h = lua.ArgumentAsDouble(3);
    pComponent component = gui->Model()->FindAll(name);
    if (component != nullptr)
        component->Model()->SetSize(w, h);
    return 0;
}

int lua_Component_Model_SetName(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name
    std::string name = lua.ArgumentAsString(1);
    std::string new_name = lua.ArgumentAsString(2);
    pComponent component = gui->Model()->FindAll(name);
    if (component != nullptr)
        component->Model()->SetName(new_name);
    return 0;
}

int lua_Component_Model_SetParent(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name

    std::string name = lua.ArgumentAsString(1);
    std::string parent_name = lua.ArgumentAsString(2);
    pComponent component = gui->Model()->FindAll(name);
    pComponent parent = gui->Model()->FindAll(parent_name);
    parent->Model()->Add(component);
    if ((component != nullptr) && (parent != nullptr))
        parent->Model()->Add(component);
    return 0;
}

int lua_Button_Create(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name
    std::string name = lua.ArgumentAsString(1);
    std::string parent_name = lua.ArgumentAsString(2);
    pButton button = new Button();
    button->Model()->SetName(name);
    if (parent_name == "gui")
        gui->Model()->Add(button);
    else{
        pComponent parent = gui->Model()->FindAll(parent_name);
        parent->Model()->Add(button);
        std::cout << "PARENT: " << parent->Model()->Name();

    }

    return 0;
}

int lua_Button_Model_SetCaption(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name
    //caption - то что хотим установить
    std::string name = lua.ArgumentAsString(1);
    std::string caption = lua.ArgumentAsString(2);
    pButton button = pButton(gui->Model()->FindAll(name));
    if (button != nullptr)
        button->Model()->SetCaption(caption);
    return 0;
}

int lua_Button_Model_Caption(lua_State* state)
{
    LuaInterpreter lua(state);
    //name - component's name
    //caption - то что хотим установить
    std::string name = lua.ArgumentAsString(1);
    pButton button = pButton(gui->Model()->FindAll(name));
    std::string caption="None";
    if (button != nullptr)
        caption = button->Model()->Caption();
    lua.ReturnString(caption);
    return 1;
}

void registerSKBGUI(LuaInterpreter* lua)
{
    lua->RegisterFunction(lua_Component_Create, "component_create");
    lua->RegisterFunction(lua_Component_Delete, "component_delete");
    lua->RegisterFunction(lua_Component_Model_SetLocalCoord, "component_model_setlocalcoord");
    lua->RegisterFunction(lua_Component_Model_SetSize, "component_model_setsize");
    lua->RegisterFunction(lua_Component_Model_SetName, "component_model_setname");
    lua->RegisterFunction(lua_Component_Model_SetParent, "component_model_setparent");

    lua->RegisterFunction(lua_Button_Create, "button_create");
    lua->RegisterFunction(lua_Button_Model_SetCaption, "button_model_setcaption");
    lua->RegisterFunction(lua_Button_Model_Caption, "button_model_caption");
}
