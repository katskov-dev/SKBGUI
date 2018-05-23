#pragma once
#include <base.h>
#include <GUI/GUI.h>
#include <LuaInterpreter.h>
#include <Button/Button.h>


extern pGUI gui;

int lua_Component_Create(lua_State* state);
int lua_Component_Delete(lua_State* state);
int lua_Component_Model_SetLocalCoord(lua_State* state);
int lua_Component_Model_SetSize(lua_State* state);
int lua_Component_Model_SetName(lua_State* state);
int lua_Component_Model_SetParent(lua_State* state);


int lua_Button_Create(lua_State* state);
int lua_Button_Model_SetCaption(lua_State* state);
int lua_Button_Model_Caption(lua_State* state);

void registerSKBGUI(LuaInterpreter* lua);
