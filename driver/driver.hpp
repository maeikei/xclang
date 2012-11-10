#ifndef __DRIVER_HPP_
#define __DRIVER_HPP_

extern "C"
{
#include "lauxlib.h"
}
#include <string>
#include <list>
#include <vector>
using namespace std;
#include "programs.hpp"
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
        void calcNewOptionLength(void);
        void adjustClangOptions(void);
        string findProgramName(const string &name );
        int execProgram(const string &name );
        void calcTarget(void);
    private:
        const int m_OrigArgc;
        const char **m_OrigArgv;
        int m_NewArgc;
        char **m_NewArgv;
        list<string> m_Argv;
        lua_State *m_LuaState;
        bool m_CXX ;
        XClangPrograms m_Program;

#if 0 // not suported
        const list<string> m_XClangArgV =
        {
            "-stdinc",
            ""
        };
#endif 

    };
}
#endif // __DRIVER_HPP_
