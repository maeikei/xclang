#ifndef __PROGRAMS_HPP_
#define __PROGRAMS_HPP_

#include <string>
using namespace std;
namespace xclang
{
class XClangPrograms
    {
    public:
        XClangPrograms(const string &argv0);

        ~XClangPrograms();
    private:
        XClangPrograms();
    private:
        const string m_argv0;
    };
}
#endif // __PROGRAMS_HPP_
