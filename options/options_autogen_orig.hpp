#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_

#include <string>
#include <map>
using namespace std;
namespace xclang
{
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
    private:
        XClangOptions();
        void splitArgs(void);
        void parseArgs(void);
    private:
        const int m_argc;
        const char** m_argv;
        map<string,string> m_real_options;
        static const map<string,int> m_clang_options;
        static const map<string,int> m_clang_cc1_options;
        replace_header_members
    public:
        replace_header_methods
    };
}
#endif // __OPTIONS_HPP_
