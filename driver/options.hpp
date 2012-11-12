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
    };
}
#endif // __OPTIONS_HPP_
