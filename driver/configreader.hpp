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
        string getLLVMProgram(const string &name) const
        {
            auto it = m_llvm.find(name);
            if(it != m_llvm.end())
            {
                return it->second;
            }
            return name;
        }
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
        vector<string> m_defaultasmcppcflags;
        vector<string> m_defaultcflags;
        vector<string> m_defaultcxxflags;
    };
}
#endif // __CONFIG_READER_HPP_
