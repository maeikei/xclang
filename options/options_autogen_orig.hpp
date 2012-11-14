#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_

#include <string>
using namespace std;
namespace xclang
{
    class XClangOptions
    {
    public:
        XClangOptions(int argc,const char** argv);
        ~XClangOptions();
    private:
        XClangOptions();
    private:
        const int m_argc;
        const char** m_argv;
    public:
        replace_header_members
    private:
        replace_header_methods
    };
}
#endif // __OPTIONS_HPP_
