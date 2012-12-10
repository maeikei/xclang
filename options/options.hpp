#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_

#include <string>
#include <map>
#include <list>
using namespace std;

#include "configreader.hpp"
#include "programs.hpp"

namespace xclang
{

    struct OptProperty
    {
        const int kind;
        const int flags;
        const int id;
    };

    class XClangOptions
    {
    public:
        enum {
#define PREFIX(NAME, VALUE)
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)   \
OPT_##ID,
#include "ClangOptions.org.inc"
#undef OPTION
#undef PREFIX
        };
    public:
        XClangOptions(int argc,const char** argv,const XClangPrograms &_prog);
        ~XClangOptions();
        list<string> getCC1Actions(void);
        list<string> getLinkActions(void);
        
        string gettarget(void) const
        {
            return m_target;
        }
        void setConfig(ConfigReader *_config)
        {
            m_config = _config;
        }
    private:
        XClangOptions();
        int getNextArgsFullMatch(const string &opt,const OptProperty &prop,int i);
        int getNextArgsPrefixMatch(const string &opt,const string &prefix,const OptProperty &prop,int i);
        int getNextArgsInputs(const string &opt,int i);
        void splitArgs(void);
        bool is_not_link(void) const;
        
        bool has_option(int opt_id) const;
        string adjustCC1Options(int lang) const;
        void adjustClangOptions(void);
        void adjustLinkOptions(void);
        
        int checkLanguage(const string &input);
        string calcLinkCmd(void) const;
    private:
        const int m_argc;
        const char** m_argv;
        ConfigReader *m_config;
        const XClangPrograms &m_prog;
        vector<string> m_cc1_options;
        vector<string> m_clang_options;
        vector<string> m_link_options;
        map<int,bool> m_real_ids;
        vector<string> m_input_files;
        string m_input_files_str;
        vector<string> m_input_objects;
        string m_input_objects_str;
        vector<string> m_objects_files;
        string m_out_file;
        string m_target;
        vector<int> m_lang_flags;
        static const map<string,OptProperty> m_xclang_options_full_match;
        static const map<string,OptProperty> m_xclang_options_prefix_match;
//        static const map<string,int> m_clang_options;
//        static const map<string,int> m_clang_cc1_options;
    };
}
#endif // __OPTIONS_HPP_
