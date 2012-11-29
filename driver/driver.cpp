#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "driver.hpp"
using namespace xclang;



XClangDriver::XClangDriver(const int argc,const char *argv[])
:m_program(argv[0])
,m_opt(argc,argv)
{
//    m_config = new ConfigReader(m_program.gethome(),m_program,m_opt);
}
XClangDriver::~XClangDriver()
{
}

int XClangDriver::exce(void)
{    
    vector<string> actions = m_opt.getClangActions();
    for(auto it = actions.begin(); it != actions.end()  ;it++ )
    {
        string cmdline("-target ");
        cmdline += m_opt.gettarget();
        cmdline += " " + *it + " " ;
        cout << "cmdline=<" << cmdline << ">" << endl;
        ConfigReader act(m_program.gethome(),m_program,m_opt);
        cmdline = act.getAction("clang",cmdline);
        //system(cmdline.c_str());
    }
    vector<string> linkActions = m_opt.getLinkActions();
    for(auto it = linkActions.begin(); it != linkActions.end()  ;it++ )
    {
        string cmdline;
        cmdline += " " + *it + " " ;
        cout << "cmdline=<" << cmdline << ">" << endl;
        ConfigReader act(m_program.gethome(),m_program,m_opt);
        cmdline = act.getAction("link",cmdline);
        //system(cmdline.c_str());
    }    
    return 0;
}

