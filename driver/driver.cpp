#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "driver.hpp"
using namespace xclang;



XClangDriver::XClangDriver(const int argc,const char *argv[])
:m_program(argv[0])
,m_opt(argc,argv,m_program)
,m_config(nullptr)
{
    m_config = new ConfigReader(m_program.gethome(),m_program,m_opt);
    m_program.setConfig(m_config);
    m_opt.setConfig(m_config);
}
XClangDriver::~XClangDriver()
{
}

int XClangDriver::exce(void)
{    
    list<string> actions = m_opt.getCC1Actions();
    for(auto it = actions.begin(); it != actions.end()  ;it++ )
    {
//        cout << "cmdline=<" << *it << ">" << endl;
        system(it->c_str());
    }
    list<string> linkActions = m_opt.getLinkActions();
    for(auto it = linkActions.begin(); it != linkActions.end()  ;it++ )
    {
//        cout << "cmdline=<" << *it << ">" << endl;
        system(it->c_str());
    }
    return 0;
}

