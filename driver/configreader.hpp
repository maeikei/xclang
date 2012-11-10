#ifndef __CONFIG_READER_HPP_
#define __CONFIG_READER_HPP_

extern "C"
{
#include "lauxlib.h"
}

#include <string>
using namespace std;
#include "programs.hpp"
namespace xclang
{
class ConfigReader
    {
    public:
        ConfigReader(const string &home,const XClangPrograms &p);
        ~ConfigReader();
    private:
        ConfigReader();
    private:
        string m_home;
        const XClangPrograms &m_program;
        lua_State *m_L;
        string m_runscript;
    };
}
#endif // __CONFIG_READER_HPP_
