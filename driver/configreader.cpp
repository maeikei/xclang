#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "configreader.hpp"
using namespace xclang;

ConfigReader::ConfigReader(const string &home,const XClangPrograms &p)
:m_home(home + "/luaScript")
,m_program(p)
,m_LuaState(nullptr)
,m_runscript("")
{
    try
    {
        m_LuaState = luaL_newstate();
        
        cout << "m_home=<" << m_home << ">" << endl;
        cout << "m_runscript=<" << m_runscript << ">" << endl;
    }
    catch (...)
    {
    }
}
ConfigReader::~ConfigReader()
{
    if( nullptr != m_LuaState )
    {
        lua_close(m_LuaState);
    }
}
