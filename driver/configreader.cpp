#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "configreader.hpp"
#include "programs.hpp"
#include "options.hpp"
using namespace xclang;
#include "lua.hpp"

//#define DEBUG

#define dout std::cout << __func__ << ":" << __LINE__ << ":"



#define readClangMemberValue(x) readtable("clang",#x,m_##x);
#define readXClangMemberValue(x) readtable("xclang",#x,m_##x);
#define readToolChainMemberValue(x) readtable("toolchain",#x,m_##x);

#define readLinkExeValue(x) readtable("link_exe",#x,m_link_exe_##x);
#define readLinkExeSValue(x) readtable("link_exe_s",#x,m_link_exe_s_##x);
#define readLinkSharedValue(x) readtable("link_shared",#x,m_link_shared_##x);
#define readLinkSharedSValue(x) readtable("link_shared_s",#x,m_link_shared_s_##x);


ConfigReader::ConfigReader(const string &home,const XClangPrograms &p,const XClangOptions &opt)
:m_home(home )
,m_program(p)
,m_opt(opt)
,m_L(nullptr)
,m_runscript("\n")
,m_llvm()
,m_defaultasmcppcflags()
,m_defaultcflags()
,m_defaultcxxflags()
,m_archcflags()
,m_archcxxflags()
,m_stdinc()
,m_stdincxx()
,m_progs()
{
    try
    {
        m_L = luaL_newstate();
        if(nullptr == m_L )
        {
            throw string("can not create lua vm \n");
        }
        // initialize search path
        string path_lua(m_home + "/share");
        path_lua += "/?.lua";
        ::setenv("LUA_PATH", path_lua.c_str(),1);
        ::setenv("LUA_CPATH", "",1);
        luaL_openlibs(m_L);

        // home var
        m_runscript += "globalXClangHome = ";
        m_runscript += "\"";
        m_runscript += m_home;
        m_runscript += "\"\n";

        
        // add target spec lua
        m_runscript += "require(\"";
        m_runscript += m_opt.gettarget();
        m_runscript += "\")\n";

        // add spec lua
        m_runscript += "require(\"xclang-llvm\")\n";
        int ret = luaL_dostring(m_L,m_runscript.c_str());
        if(LUA_OK != ret)
        {
            const char *msg = (lua_type(m_L, -1) == LUA_TSTRING) ? lua_tostring(m_L, -1): NULL;
            if (msg == NULL) msg = "(error object is not a string)";
            lua_pop(m_L, 1);
            throw string(msg) + m_runscript;
        }
// read confiure from lua.
        readClangMemberValue(llvm);
        readClangMemberValue(defaultasmcppcflags);
        readClangMemberValue(defaultcflags);
        readClangMemberValue(defaultcxxflags);
        
// read confiure from lua.
        readXClangMemberValue(master);
        readXClangMemberValue(archcflags);
        readXClangMemberValue(archcxxflags);
        readXClangMemberValue(stdinc);
        readXClangMemberValue(stdincxx);
        
// read confiure from lua.
        readToolChainMemberValue(progs);

// read confiure from lua.
        readLinkExeValue(arch);
        readLinkExeValue(beginobject);
        readLinkExeValue(stdxxdirs);
        readLinkExeValue(stdxxlibs);
        readLinkExeValue(stddirs);
        readLinkExeValue(stdlibs);
        readLinkExeValue(endobject);

// read confiure from lua.
        readLinkExeSValue(arch);
        readLinkExeSValue(beginobject);
        readLinkExeSValue(stdxxdirs);
        readLinkExeSValue(stdxxlibs);
        readLinkExeSValue(stddirs);
        readLinkExeSValue(stdlibs);
        readLinkExeSValue(endobject);
        
        
// read confiure from lua.
        readLinkSharedValue(arch);
        readLinkSharedValue(beginobject);
        readLinkSharedValue(stdxxdirs);
        readLinkSharedValue(stdxxlibs);
        readLinkSharedValue(stddirs);
        readLinkSharedValue(stdlibs);
        readLinkSharedValue(endobject);
        
        
// read confiure from lua.
        readLinkSharedSValue(arch);
        readLinkSharedSValue(beginobject);
        readLinkSharedSValue(stdxxdirs);
        readLinkSharedSValue(stdxxlibs);
        readLinkSharedSValue(stddirs);
        readLinkSharedSValue(stdlibs);
        readLinkSharedSValue(endobject);
// r --xclang-target x86_64-w64-mingw32 sub.c main.c -L./ -L ../ -I./ -I ../ -lc -o main.out

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

void ConfigReader::readtable(const string &name,const string &item,map<string,string> &table)
{
    lua_getglobal(m_L, name.c_str());
    lua_pushstring(m_L,item.c_str());
    lua_gettable(m_L, -2);
    lua_pushnil(m_L);
    while (lua_next(m_L, -2) != 0)
    {
        lua_pushvalue(m_L, -2);
        table.insert(pair<string, string>(lua_tostring(m_L, -1), lua_tostring(m_L, -2)));
        lua_pop(m_L, 2);
    }
    lua_settop(m_L, 0);
#ifdef DEBUG
    for (auto it = table.begin(); it != table.end(); it++ )
    {
        dout << "it->first=<" << it->first << ">" << "it->first=<" << it->second << ">" << endl;
    }
#endif
}

void ConfigReader::readtable(const string &name,const string &item,vector<string> &table)
{
    lua_getglobal(m_L, name.c_str());
    lua_pushstring(m_L,item.c_str());
    lua_gettable(m_L, -2);
    lua_pushnil(m_L);
    while (lua_next(m_L, -2) != 0)
    {
        lua_pushvalue(m_L, -2);
        table.push_back(lua_tostring(m_L, -2));
        lua_pop(m_L, 2);
    }
    lua_settop(m_L, 0);
#ifdef DEBUG
    for (auto it = table.begin(); it != table.end(); it++ )
    {
        dout << "*it =<" << *it << ">" << endl;
    }
#endif
}



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




#if 0 /// copy net work samples.

#include <lua.hpp>

static void ReadNestTable(lua_State *L, const char* lpszTableName, const char* lpszTableItem, int index)
{
    lua_getglobal(L, lpszTableName);
    lua_pushstring(L, lpszTableItem);
    lua_gettable(L, -2);
    
    lua_rawgeti(L, -1, index);
    printf("%s.%s[%d]=%d\n", lpszTableName, lpszTableItem, index, (int)lua_tonumber(L, -1));
    lua_pop(L, 3);
}

static void WriteNestTable(lua_State *L, const char* lpszTableName, const char* lpszTableItem, int index, int val)
{
    lua_getglobal(L, lpszTableName);
    lua_pushstring(L, lpszTableItem);
    lua_gettable(L, -2);
    
    lua_pushnumber(L, val);
    lua_rawseti(L, -2, index);
    lua_pop(L, 1);
}
int main (int argc, char* argv[])
{
    lua_State *L = luaL_newstate();
    luaopen_base(L);
    
    luaL_dofile(L, "NestTable.lua");
    ReadNestTable(L, "luat_Nest", "c", 1);  // print(luat_Nest.c[1])
    ReadNestTable(L, "luat_Nest", "c", 2);  // print(luat_Nest.c[2])
    ReadNestTable(L, "luat_Nest", "c", 3);  // print(luat_Nest.c[3])
    
    WriteNestTable(L, "luat_Nest", "c", 1, 9); // luat_Nest.c[1] = 9
    WriteNestTable(L, "luat_Nest", "c", 2, 8); // luat_Nest.c[2] = 8
    WriteNestTable(L, "luat_Nest", "c", 3, 7); // luat_Nest.c[3] = 7
    puts("-------------------------");
    ReadNestTable(L, "luat_Nest", "c", 1);
    ReadNestTable(L, "luat_Nest", "c", 2);
    ReadNestTable(L, "luat_Nest", "c", 3);
    lua_close(L);
    return 0;
}

#endif