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
    class linkConfigExe;
    class linkConfigExeStatic;
    class linkConfigShared;
    class linkConfigSharedStatic;
    
    class ConfigReader
    {
        friend class XClangOptions;
        friend class linkConfigExe;
        friend class linkConfigExeStatic;
        friend class linkConfigShared;
        friend class linkConfigSharedStatic;
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
        string getToolChainProgram(const string &name) const
        {
            auto it = m_progs.find(name);
            if(it != m_progs.end())
            {
                return it->second;
            }
            return name;
        }
        string getProperty(const string &name) const
        {
            auto it = m_props.find(name);
            if(it != m_props.end())
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
        
        map<string,string> m_props;
        vector<string> m_archcflags;
        vector<string> m_archcxxflags;
        vector<string> m_stdinc;
        vector<string> m_stdincxx;

        map<string,string> m_progs;


        
        vector<string> m_link_exe_arch;
        vector<string> m_link_exe_beginobject;
        vector<string> m_link_exe_stdxxdirs;
        vector<string> m_link_exe_stdxxlibs;
        vector<string> m_link_exe_stddirs;
        vector<string> m_link_exe_stdlibs;
        vector<string> m_link_exe_endobject;

        
        vector<string> m_link_exe_s_arch;
        vector<string> m_link_exe_s_beginobject;
        vector<string> m_link_exe_s_stdxxdirs;
        vector<string> m_link_exe_s_stdxxlibs;
        vector<string> m_link_exe_s_stddirs;
        vector<string> m_link_exe_s_stdlibs;
        vector<string> m_link_exe_s_endobject;

        vector<string> m_link_shared_arch;
        vector<string> m_link_shared_beginobject;
        vector<string> m_link_shared_stdxxdirs;
        vector<string> m_link_shared_stdxxlibs;
        vector<string> m_link_shared_stddirs;
        vector<string> m_link_shared_stdlibs;
        vector<string> m_link_shared_endobject;
        
        vector<string> m_link_shared_s_arch;
        vector<string> m_link_shared_s_beginobject;
        vector<string> m_link_shared_s_stdxxdirs;
        vector<string> m_link_shared_s_stdxxlibs;
        vector<string> m_link_shared_s_stddirs;
        vector<string> m_link_shared_s_stdlibs;
        vector<string> m_link_shared_s_endobject;
        
    };
    
    class linkConfig
    {
    public:
        virtual string arch(void) const = 0;
        virtual string beginobject(void) const = 0;
        virtual string stdxxdirs(void) const = 0;
        virtual string stdxxlibs(void) const = 0;
        virtual string stddirs(void) const = 0;
        virtual string stdlibs(void) const = 0;
        virtual string endobject(void) const = 0;
    protected:
        ConfigReader *m_conf;
        linkConfig();
        linkConfig(ConfigReader *_conf);
    };

    
    
    

    class linkConfigExe : public linkConfig
    {
    public:
        linkConfigExe(ConfigReader *_conf);
        virtual string arch(void) const;
        virtual string beginobject(void) const;
        virtual string stdxxdirs(void) const;
        virtual string stdxxlibs(void) const;
        virtual string stddirs(void) const;
        virtual string stdlibs(void) const;
        virtual string endobject(void) const;
    };
    
    class linkConfigExeStatic : public linkConfig
    {
    public:
        linkConfigExeStatic(ConfigReader *_conf);
        virtual string arch(void) const;
        virtual string beginobject(void) const;
        virtual string stdxxdirs(void) const;
        virtual string stdxxlibs(void) const;
        virtual string stddirs(void) const;
        virtual string stdlibs(void) const;
        virtual string endobject(void) const;
    };
    

    class linkConfigShared : public linkConfig
    {
    public:
        linkConfigShared(ConfigReader *_conf);
        virtual string arch(void) const;
        virtual string beginobject(void) const;
        virtual string stdxxdirs(void) const;
        virtual string stdxxlibs(void) const;
        virtual string stddirs(void) const;
        virtual string stdlibs(void) const;
        virtual string endobject(void) const;
    };
    
    
    class linkConfigSharedStatic : public linkConfig
    {
    public:
        linkConfigSharedStatic(ConfigReader *_conf);
        virtual string arch(void) const;
        virtual string beginobject(void) const;
        virtual string stdxxdirs(void) const;
        virtual string stdxxlibs(void) const;
        virtual string stddirs(void) const;
        virtual string stdlibs(void) const;
        virtual string endobject(void) const;
    };
    
    
}
#endif // __CONFIG_READER_HPP_
