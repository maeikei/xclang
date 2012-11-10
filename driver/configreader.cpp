#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "configreader.hpp"
using namespace xclang;
extern "C"
{
#include "lualib.h"
}

ConfigReader::ConfigReader(const string &home,const XClangPrograms &p)
:m_home(home + "/luaScript")
,m_program(p)
,m_L(nullptr)
,m_runscript("\n")
{
    try
    {
        m_L = luaL_newstate();
        if(nullptr == m_L )
        {
            throw string("can not create lua vm \n");
        }
        luaL_openlibs(m_L);

        
        // add search path
        m_runscript += "package.path = package.path..\"";
        m_runscript += m_home;
        m_runscript += "/\"\n";
        
        // add target spec lua
        m_runscript += "require(\"";
        m_runscript += m_program.gettarget();
        m_runscript += "\")\n";
        
        
        cout << "m_home=<" << m_home << ">" << endl;
        cout << "m_runscript=<" << m_runscript << ">" << endl;
        int ret = luaL_dostring(m_L,m_runscript.c_str());
        if(LUA_OK != ret)
        {
            const char *msg = (lua_type(m_L, -1) == LUA_TSTRING) ? lua_tostring(m_L, -1): NULL;
            if (msg == NULL) msg = "(error object is not a string)";
            lua_pop(m_L, 1);
            throw string(msg);
        }
    }
    catch (string e)
    {
        cout << "exceptin=<" << e << ">" << endl;
    }
    catch (...)
    {
    }
}
ConfigReader::~ConfigReader()
{
    if( nullptr != m_L )
    {
        lua_close(m_L);
    }
}
