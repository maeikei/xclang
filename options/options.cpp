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
            m_input_files.push_back(m_argv[i]);
            m_input_files_str += m_argv[i];
            m_input_files_str += " ";
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
        value = m_argv[++i];
    }
    m_real_options.insert(pair<string,string>(opt,value));
    return ++i;
}

string XClangOptions::concatOpt(const string &key,const string &value,const map<string,int> &opts) const
{
    string ret(key);
    auto it = opts.find(key);
    if(it != opts.end())
    {
        if( it->second & iConstOptionTypeNextValue )
        {
            ret += " ";
        }
        ret += value;
    }
    return ret;
}

vector<string> XClangOptions::getClangCC1Actions(void) const
{
    string opts;
    auto it = m_real_options.begin();
    for(;it !=  m_real_options.end();it++)
    {
        opts += concatOpt(it->first,it->second,m_clang_cc1_options);
        opts += " ";
    }
    vector<string> ret;
    ret.push_back(opts);
    return ret;
}

vector<string> XClangOptions::getLinkActions(void) const
{
    string opts;
    auto it = m_real_options.begin();
    for(;it !=  m_real_options.end();it++)
    {
        opts += concatOpt(it->first,it->second,m_clang_options);
        opts += " ";
    }
    vector<string> ret;
    ret.push_back(opts);
    return ret;
}
bool XClangOptions::is_do_link(void) const
{
    if (this->has_c())
    {
        return false;
    }
    return true;
}
