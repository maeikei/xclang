#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "driver.hpp"
using namespace xclang;

#include "boost/filesystem.hpp"


XClangDriver::XClangDriver(const int argc,const char *argv[])
:m_opt(argc,argv)
,m_program(argv[0])
,m_config(nullptr)
{
    m_config = new ConfigReader(m_program.gethome(),m_program);
}
XClangDriver::~XClangDriver()
{
}

int XClangDriver::exce(void)
{    
    vector<string> actions = m_opt.getClangActions();
    for(auto it = actions.begin(); it != actions.end()  ;it++ )
    {
        string cmdline(m_program.findProgramName("clang"));
        cmdline += " -target " + m_program.gettarget();
        cmdline += " " + *it + " " ;
        cout << "cmdline=<" << cmdline << ">" << endl;
        //system(cmdline.c_str());
    }
    return 0;
}

