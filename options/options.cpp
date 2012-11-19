#include <string>
#include <iostream>
using namespace std;
#include "options.hpp"
using namespace xclang;

#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
//namespace ud = boost::uuids;

XClangOptions::~XClangOptions()
{
}
void XClangOptions::splitArgs(void)
{
    int i = 1;
    while(i < m_argc)
    {
        string vStr(m_argv[i]);
        if("-o" == vStr)
        {
            m_out_file = string(m_argv[++i]);
            i++;
            continue;
        }
        auto it = m_clang_options.find(vStr);
        auto itcc = m_clang_cc1_options.find(vStr);
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
            m_input_files.push_back(vStr);
            m_input_files_str += vStr;
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

vector<string> XClangOptions::getClangActions(void)
{
    string opts;
    for(auto it = m_real_options.begin();it !=  m_real_options.end();it++)
    {
        opts += concatOpt(it->first,it->second,m_clang_cc1_options);
        opts += " ";
    }
    
    vector<string> actions;
    if(this->has_o() && ( this->has_c() || this->has_S()) )
    {
        actions.push_back(opts + " " + m_input_files_str);
        return actions;
    }
    string extension(".o");
    if(has_S())
    {
       extension = ".s";
    }

    for(auto it = m_input_files.begin();it !=  m_input_files.end();it++)
    {
        if(this->has_c() || this->has_S())
        {
            string opt_elment(opts);
            opt_elment += " ";
            opt_elment += *it;
            opt_elment += " -o ";
            fs::path fileName(*it);
            fileName.replace_extension(extension);
            opt_elment += fileName.string();
            actions.push_back(opt_elment);
        }
        if( not this->is_not_link() )
        {
            string opt_elment(opts);
            opt_elment += " ";
            opt_elment += *it;
            opt_elment += " -o ";
            fs::path fileName= fs::temp_directory_path();
            boost::uuids::uuid uName = boost::uuids::random_generator()();
            string name = boost::uuids::to_string(uName);
            fileName += name;
            fileName += extension;
            opt_elment += fileName.string();
            m_objects_files.push_back( fileName.string() );
            actions.push_back(opt_elment);
        }
    }
    return actions;
}

vector<string> XClangOptions::getLinkActions(void)
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

bool XClangOptions::is_not_link(void) const
{
    if (this->has_c())
    {
        return true;
    }
    if (this->has_S())
    {
        return true;
    }
    if (this->has_version())
    {
        return true;
    }
    if (this->has_help())
    {
        return true;
    }
    return false;
}
