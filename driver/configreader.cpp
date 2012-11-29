#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "configreader.hpp"
#include "programs.hpp"
#include "options.hpp"
using namespace xclang;
#include "lua.hpp"

ConfigReader::ConfigReader(const string &home,const XClangPrograms &p,const XClangOptions &opt)
:m_home(home + "/share")
,m_program(p)
,m_opt(opt)
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
        m_runscript += m_opt.gettarget();
        m_runscript += "\")\n";

        // add spec lua
        m_runscript += "require(\"xclang-llvm\")\n";
        m_runscript += "require(\"xclang-actions\")\n";
        
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


//#define DEBUG

#define dout std::cout << __func__ << ":" << __LINE__ << ":"


string ConfigReader::getValue(const string &key)
{
    string ret;
    dout << "key=<" << key << ">" << endl;
    return ret;
}
vector<string> ConfigReader::getValues(const string &key)
{
    vector<string> ret;
    return ret;
}
string ConfigReader::getAction(const string &act,const string &cmds)
{
    dout << "act=<" << act << ">" << endl;
    dout << "cmds=<" << cmds << ">" << endl;
    string ret;
    try
    {
        m_runscript += "do_action_";
        m_runscript += act;
        m_runscript += "(\"";
        m_runscript += cmds;
        m_runscript += "\")\n";
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
    
    return ret;
}
