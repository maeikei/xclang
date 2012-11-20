#ifndef __DRIVER_HPP_
#define __DRIVER_HPP_

#include <string>
#include <list>
#include <vector>
using namespace std;
#include "programs.hpp"
#include "configreader.hpp"
#include "options.hpp"
namespace xclang
{
class XClangDriver
    {
    public:
        XClangDriver(const int argc,const char **argv);
        int exce(void);
        ~XClangDriver();
    private:
        XClangDriver();
        int execProgram(const string &name );
    private:
        XClangOptions m_opt;
        XClangPrograms m_program;
        ConfigReader *m_config;
    };
}
#endif // __DRIVER_HPP_
