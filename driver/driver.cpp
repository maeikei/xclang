#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "driver.hpp"
using namespace xclang;

//#define DEBUG_ACTIONS
//#define DEBUG_ACTIONS_CC
//#define DEBUG_ACTIONS_LINKER

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
#ifdef DEBUG_ACTIONS
    cout << typeid(this).name() <<"::" << __func__ << " entry" << endl;
#endif
    int ret = 0;
    list<string> actions = m_opt.getCC1Actions();
    for(auto it = actions.begin(); it != actions.end()  ;it++ )
    {
#ifdef DEBUG_ACTIONS_CC
        cout << "cmdline=<" << *it << ">" << endl;
#endif
        ret = system(it->c_str());
    }
    list<string> linkActions = m_opt.getLinkActions();
    for(auto it = linkActions.begin(); it != linkActions.end()  ;it++ )
    {
#ifdef DEBUG_ACTIONS_LINKER
        cout << "cmdline=<" << *it << ">" << endl;
#endif
        if(m_opt.showcommand())
        {
            cout << *it << endl;
        }
        ret = system(it->c_str());
    }
#ifdef DEBUG_ACTIONS
    cout << typeid(this).name() <<"::" << __func__ << " exit" << endl;
#endif
    return ret;
}

