#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "configreader.hpp"
using namespace xclang;
#include "lua.hpp"

ConfigReader::ConfigReader(const string &home,const XClangPrograms &p)
:m_home(home + "/share")
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
        // initialize search path
        string path_lua(m_home);
        path_lua += "/?.lua";
        ::setenv("LUA_PATH", path_lua.c_str(),1);
        ::setenv("LUA_CPATH", "",1);
//        cout << "LUA_PATH=<" << ::getenv("LUA_PATH") << ">" <<endl;
//        cout << "LUA_CPATH=<" << ::getenv("LUA_CPATH") << ">" <<endl;
        luaL_openlibs(m_L);

        
        // add target spec lua
        m_runscript += "require(\"";
        m_runscript += m_program.gettarget();
        m_runscript += "\")\n";
        
        
//        cout << "m_home=<" << m_home << ">" << endl;
//        cout << "m_runscript=<" << m_runscript << ">" << endl;
        int ret = luaL_dostring(m_L,m_runscript.c_str());
        if(LUA_OK != ret)
        {
            const char *msg = (lua_type(m_L, -1) == LUA_TSTRING) ? lua_tostring(m_L, -1): NULL;
            if (msg == NULL) msg = "(error object is not a string)";
            lua_pop(m_L, 1);
            throw string(msg) + m_runscript;
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
