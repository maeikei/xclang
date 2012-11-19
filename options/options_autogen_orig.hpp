#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_

#include <string>
#include <map>
#include <vector>
using namespace std;
namespace xclang
{
    const int iConstOptionTypeNone          =      0x0;
    const int iConstOptionTypeAlone         =      0x1;
    const int iConstOptionTypeNextValue     =     0x10;
    const int iConstOptionTypeEQValue       =    0x100;
    const int iConstOptionTypeCommaValue    =   0x1000;
    const int iConstOptionTypeBarValue      =  0x10000;
    const int iConstOptionTypeValue         = 0x100000;

    
    class XClangOptions
    {
    public:
        XClangOptions(int argc,const char** argv);
        ~XClangOptions();
        vector<string> getClangActions(void);
        vector<string> getLinkActions(void);
    private:
        XClangOptions();
        int getNextArgs(const string &opt,int type,int i);
        void splitArgs(void);
        void parseArgs(void);
        string concatOpt(const string &key,const string &value,const map<string,int> &opts) const;
        bool is_not_link(void) const;
    private:
        const int m_argc;
        const char** m_argv;
        map<string,string> m_real_options;
        vector<string> m_input_files;
        string m_input_files_str;
        vector<string> m_objects_files;
        string m_out_file;
        static const map<string,int> m_clang_options;
        static const map<string,int> m_clang_cc1_options;
        replace_header_members
    public:
        replace_header_methods
    };
}
#endif // __OPTIONS_HPP_
