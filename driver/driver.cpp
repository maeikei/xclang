#include "driver.hpp"
#include <cstdlib>
#include <string>

using namespace xclang;
using namespace std;
XClangDriver::XClangDriver(const int argc,const char *argv[])
:m_OrigArgc(argc)
,m_OrigArgv(argv)
,m_NewArgc(0)
,m_NewArgv(NULL)
{
}

int XClangDriver::exce(void)
{
    this->adjustClangOptions();
    string cmdline ;
    for(int i = 0; i < m_NewArgc  ;i++ )
    {
        cmdline += string(m_NewArgv[i]) + " " ;
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
    this->calcNewOptionLength();
    m_NewArgv = new char *[m_NewArgc];
//    m_NewArgv[0] = "clang";
    for (int i = 1; i < m_OrigArgc; i++) {
        m_NewArgv[i] = const_cast<char *>(m_OrigArgv[i]);
    }
}

