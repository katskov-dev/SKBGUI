#pragma once
#include <Lua/lua.hpp>
#include <string>

class LuaInterpreter
{
    public:
        LuaInterpreter();
        LuaInterpreter(lua_State* state);
        virtual ~LuaInterpreter();

        void free();

        //other methods

        //----BASE
        void initStandartLibrary();
        void loadFromFile(std::string filename);
        void run();
        std::string Error();
        //----CALL FROM LUA
        void RegisterFunction(lua_CFunction func, std::string name);

        int CountArguments();
        std::string ArgumentAsString(int index);
        int ArgumentAsInt(int index);
        double ArgumentAsDouble(int index);

        void ReturnString(std::string value);
        void ReturnNumber(double value);



        //setters
        lua_State* State();
        //getters
        void SetState(lua_State* state);
    protected:

    private:
        lua_State* __state;

};

