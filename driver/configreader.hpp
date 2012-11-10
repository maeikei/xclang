#ifndef __CONFIG_READER_HPP_
#define __CONFIG_READER_HPP_

extern "C"
{
#include "lauxlib.h"
}

#include <string>
using namespace std;
namespace xclang
{
class ConfigReader
    {
    public:
        ConfigReader(const string &home);
        ~ConfigReader();
    private:
        ConfigReader();
    private:
        string m_home;
        lua_State *m_LuaState;
    };
}
#endif // __CONFIG_READER_HPP_
