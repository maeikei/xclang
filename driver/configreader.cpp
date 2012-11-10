#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "configreader.hpp"
using namespace xclang;

ConfigReader::ConfigReader(const string &home)
:m_home(home)
,m_LuaState(nullptr)
{
    m_LuaState = luaL_newstate();
}
ConfigReader::~ConfigReader()
{
    lua_close(m_LuaState);
}
