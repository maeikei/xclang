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
,m_program(argv[0])
,m_config(nullptr)
{
    for (int i = 1; i < m_OrigArgc; i++) {
        m_Argv.push_back(string(m_OrigArgv[i]));
    }
    m_config = new ConfigReader(m_program.gethome());
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

void XClangDriver::calcNewOptionLength(void)
{
    m_NewArgc = m_OrigArgc;
    
}

void XClangDriver::adjustClangOptions(void)
{
#if 0
    this->calcNewOptionLength();
    m_NewArgv = new char *[m_NewArgc];
    cout << "m_OrigArgv[0]=" << m_OrigArgv[0] << endl;
//    m_NewArgv[0] = "clang";
    for (int i = 1; i < m_OrigArgc; i++) {
        m_NewArgv[i] = const_cast<char *>(m_OrigArgv[i]);
    }
#endif
#if 1 // will change to a const list
    m_Argv.push_back("-nostdinc");
    m_Argv.push_back("-nostdlib");
    if (m_CXX)
    {
        m_Argv.push_back("-nostdincxx");
    }
#endif

    m_Argv.push_front(findProgramName("clang"));
}
string XClangDriver::findProgramName(const string &name)
{
    string ret(name);
    return ret;
}
void XClangDriver::calcTarget(void)
{
//    cout << "m_OrigArgv[0]=" << m_OrigArgv[0] << endl;
}

