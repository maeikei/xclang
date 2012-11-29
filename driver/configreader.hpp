#ifndef __CONFIG_READER_HPP_
#define __CONFIG_READER_HPP_

extern "C"
{
#include "lauxlib.h"
}

#include <string>
#include <vector>
using namespace std;

namespace xclang
{
    class XClangPrograms;
    class XClangOptions;
    class ConfigReader
    {
    public:
        ConfigReader(const string &home,const XClangPrograms &p,const XClangOptions &opt);
        ~ConfigReader();
        string getValue(const string &key);
        vector<string> getValues(const string &key);
        string getAction(const string &act,const string &cmds);
    private:
        ConfigReader();
    private:
        string m_home;
        const XClangPrograms &m_program;
        const XClangOptions &m_opt;
        lua_State *m_L;
        string m_runscript;
    };
}
#endif // __CONFIG_READER_HPP_
