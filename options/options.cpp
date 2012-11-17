#include <string>
#include <iostream>
using namespace std;
#include "options.hpp"
using namespace xclang;

#include <boost/program_options.hpp>
namespace po = boost::program_options;


XClangOptions::~XClangOptions()
{
}
void XClangOptions::splitArgs(void)
{
    int i = 1;
    while(i < m_argc)
    {
        auto it = m_clang_options.find(string(m_argv[i]));
        auto itcc = m_clang_cc1_options.find(string(m_argv[i]));
        if (it != m_clang_options.end())
        {
            i = getNextArgs(it->first,it->second,i);
        }
        else if (itcc != m_clang_cc1_options.end())
        {
            i = getNextArgs(itcc->first,itcc->second,i);
        }
        else
        {
            auto itreal = m_real_options.find("--source");
            if(itreal != m_real_options.end())
            {
                m_real_options["--source"] += ",";
                m_real_options["--source"] += m_argv[i];
            }
            else
            {
                m_real_options.insert(pair<string,string>("--source",m_argv[i]));
            }
            i++;
        }
    }
}
int XClangOptions::getNextArgs(const string &opt,int type,int i)
{
    string value;
    if ( type & iConstOptionTypeAlone )
    {
        m_real_options.insert(pair<string,string>(opt,""));
    }
    if ( type & iConstOptionTypeNextValue )
    {
        value = m_argv[i++];
    }
    m_real_options.insert(pair<string,string>(opt,value));
    return ++i;
}