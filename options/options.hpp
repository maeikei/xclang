#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_

#include <string>
#include <map>
#include <vector>
using namespace std;
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
        XClangOptions(int argc,const char** argv);
        ~XClangOptions();
        vector<string> getClangActions(void);
        vector<string> getLinkActions(void);
    private:
        XClangOptions();
        int getNextArgs(const string &opt,const OptProperty &prop,int i);
        void splitArgs(void);
        void parseArgs(void);
        string concatOpt(const string &key,const string &value,const map<string,int> &opts) const;
        bool is_not_link(void) const;
        
        bool has_option(int opt_id) const;
    private:
        const int m_argc;
        const char** m_argv;
        map<string,string> m_real_options;
        map<int,string> m_real_ids;
        vector<string> m_input_files;
        string m_input_files_str;
        vector<string> m_objects_files;
        string m_out_file;
        static const map<string,OptProperty> m_xclang_options;
        static const map<string,OptProperty> m_xclang_options_joined;
//        static const map<string,int> m_clang_options;
//        static const map<string,int> m_clang_cc1_options;
    };
}
#endif // __OPTIONS_HPP_
