#include "LuaInterpreter.h"
#include <iostream>

LuaInterpreter::LuaInterpreter()
{
    //ctor
    __state = luaL_newstate();
}

LuaInterpreter::LuaInterpreter(lua_State* state)
{
    __state = state;
}

LuaInterpreter::~LuaInterpreter()
{
    //dtor

}

void LuaInterpreter::free()
{
    lua_close(__state);
}

//other methods

void LuaInterpreter::initStandartLibrary()
{
    luaL_openlibs(State());
}

void LuaInterpreter::loadFromFile(std::string filename)
{
    bool error = luaL_loadfile(State(), filename.c_str());
    if (!error)
        std::cout << "";//"load is ok" << std::endl;
    else
        std::cout << Error() << std::endl;
}

void LuaInterpreter::run()
{
    bool error = lua_pcall(State(), 0, LUA_MULTRET, 0);
    if (!error)
        std::cout << "";//"run is ok" << std::endl;
    else
        std::cout << Error() << std::endl;
}

std::string LuaInterpreter::Error()
{
    const char* buffer = lua_tostring(State(), -1);
    lua_pop(State(), 1);
    return std::string(buffer);
}

void LuaInterpreter::RegisterFunction(lua_CFunction func, std::string name)
{
    lua_register(State(), name.c_str(), func);
}

int LuaInterpreter::CountArguments()
{
    return lua_gettop(State());
}

std::string LuaInterpreter::ArgumentAsString(int index)
{
    return std::string(lua_tostring(State(), index));
}

int LuaInterpreter::ArgumentAsInt(int index)
{
    return int(lua_tonumber(State(), index));
}

double LuaInterpreter::ArgumentAsDouble(int index)
{
    return double(lua_tonumber(State(), index));
}

void LuaInterpreter::ReturnString(std::string value)
{
    lua_pushstring(State(), value.c_str());
}

void LuaInterpreter::ReturnNumber(double value)
{
    lua_pushnumber(State(), value);
}

//setters
lua_State* LuaInterpreter::State()
{
    return __state;
}


//getters
void LuaInterpreter::SetState(lua_State* state)
{
    lua_close(__state);
    __state = state;
}
