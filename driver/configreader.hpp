#ifndef __CONFIG_READER_HPP_
#define __CONFIG_READER_HPP_

extern "C"
{
#include "lauxlib.h"
}

#include <string>
#include <vector>
#include <map>
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
    private:
        ConfigReader();
        void readtable(const string &name,const string &item,map<string,string> &table);
        void readtable(const string &name,const string &item,vector<string> &table);
    private:
        string m_home;
        const XClangPrograms &m_program;
        const XClangOptions &m_opt;
        lua_State *m_L;
        string m_runscript;
        map<string,string> m_llvm;
        map<string,string> m_defaultasmcppcflags;
    };
}
#endif // __CONFIG_READER_HPP_
