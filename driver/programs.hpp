#ifndef __PROGRAMS_HPP_
#define __PROGRAMS_HPP_

#include <string>
using namespace std;


namespace xclang
{
    class ConfigReader;
    class XClangPrograms
    {
    public:
        XClangPrograms(const string &argv0);
        ~XClangPrograms();
        string findProgramName(const string &name) const;
        string gethome(void) const
        {
            return m_home;
        }
        string gettarget(void) const
        {
            return m_target;
        }
        bool iscxx(void) const
        {
            return m_suffix == "++";
        }
        void setConfig(ConfigReader *conf)
        {
            m_config =conf;
        }
    private:
        XClangPrograms();
    private:
        const string m_argv0;
        string m_fullpath;
        string m_home;
        string m_target;
        string m_suffix;
        ConfigReader *m_config;
    };
}
#endif // __PROGRAMS_HPP_
