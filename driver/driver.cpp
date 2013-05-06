#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "driver.hpp"
using namespace xclang;

//#define DEBUG_CMDLINE
//#define DEBUG_ACTIONS

XClangDriver::XClangDriver(const int argc,const char *argv[])
:m_program(argv[0])
,m_opt(argc,argv,m_program)
,m_config(nullptr)
{
#ifdef DEBUG_CMDLINE
    for(auto it = 0; it < argc  ;it++ )
    {
        cout << "argv=<" << argv[it] << ">" << endl;
    }
#endif
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
#ifdef DEBUG_ACTIONS
        cout << "cmdline=<" << *it << ">" << endl;
#endif
        ret = system(it->c_str());
    }
    list<string> linkActions = m_opt.getLinkActions();
    for(auto it = linkActions.begin(); it != linkActions.end()  ;it++ )
    {
#ifdef DEBUG_ACTIONS
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

