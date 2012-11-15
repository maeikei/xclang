#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "driver.hpp"
using namespace xclang;

#include "boost/filesystem.hpp"


XClangDriver::XClangDriver(const int argc,const char *argv[])
:m_OrigArgc(argc)
,m_OrigArgv(argv)
,m_NewArgc(0)
,m_NewArgv(nullptr)
,m_Argv()
,m_CXX(false)
,m_opt(argc,argv)
,m_program(argv[0])
,m_config(nullptr)
{
    for (int i = 1; i < m_OrigArgc; i++) {
        m_Argv.push_back(string(m_OrigArgv[i]));
    }
    m_config = new ConfigReader(m_program.gethome(),m_program);
    m_CXX = m_program.iscxx();
}
XClangDriver::~XClangDriver()
{
}

int XClangDriver::exce(void)
{    
    this->calcTarget();
    this->adjustClangOptions();
    string cmdline ;
    for(auto it = m_Argv.begin(); it != m_Argv.end()  ;it++ )
    {
        cmdline += *it + " " ;
    }
    system(cmdline.c_str());
    return 0;
}

void XClangDriver::adjustClangOptions(void)
{
    m_Argv.push_front(findProgramName("clang"));
#if 1 // will change to a const list
    m_Argv.push_back("-nostdinc");
    m_Argv.push_back("-nostdlib");
    if (m_CXX)
    {
        m_Argv.push_back("-nostdincxx");
    }
#endif
}
string XClangDriver::findProgramName(const string &name)
{
    string ret(name);
    return ret;
}
void XClangDriver::calcTarget(void)
{
    m_Argv.push_back("-target " + m_program.gettarget() );
}

