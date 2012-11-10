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
        string gethome(void) const
        {
            return m_home;
        }
    private:
        XClangPrograms();
    private:
        const string m_argv0;
        string m_fullpath;
        string m_home;
    };
}
#endif // __PROGRAMS_HPP_
