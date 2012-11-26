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

#include "options.hpp"
using namespace xclang;
#include <boost/assign/list_of.hpp>
using namespace boost::assign;
#include <iostream>
#include <iterator>
using namespace std;



#define has(x) has_option(OPT_##x)





XClangOptions::XClangOptions(int argc,const char** argv)
:m_argc(argc)
,m_argv(argv)
,m_real_options()
,m_real_ids()
,m_input_files()
,m_input_files_str("")
,m_objects_files()
,m_out_file("a.out")
{
    splitArgs();
    parseArgs();
}

void XClangOptions::parseArgs(void)
{
}

XClangOptions::~XClangOptions()
{
}

string XClangOptions::concatOpt(const string &key,const string &value,const map<string,int> &opts) const
{
    string ret(key);
#if 0
    auto it = opts.find(key);
    if(it != opts.end())
    {
        if( it->second & iConstOptionTypeNextValue )
        {
            ret += " ";
        }
        ret += value;
    }
#endif
    return ret;
}

vector<string> XClangOptions::getClangActions(void)
{
    string opts;
    for(auto it = m_real_options.begin();it !=  m_real_options.end();it++)
    {
//        opts += concatOpt(it->first,it->second,m_clang_cc1_options);
        opts += " ";
    }
    
    vector<string> actions;
    // has no link action,whill use orignal o parameter.
    if(has(o)&& ( has(c) || has(S)) )
    {
        opts += " -o ";
        opts += m_out_file;
        opts += " ";
        opts += m_input_files_str;
        actions.push_back(opts);
        return actions;
    }
    if(has(E) )
    {
        if(has(o))
        {
            opts += " -o ";
            opts += m_out_file;
        }
        opts += " ";
        opts += m_input_files_str;
        actions.push_back(opts);
        return actions;
    }
    string extension(".o");
    if(has(S))
    {
       extension = ".s";
    }

    for(auto it = m_input_files.begin();it !=  m_input_files.end();it++)
    {
        if(has(c) || has(S))
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
        if( not is_not_link() )
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
//        opts += concatOpt(it->first,it->second,m_clang_options);
        opts += " ";
    }
    vector<string> actions;
    if( not is_not_link() )
    {
        opts += " -o ";
        opts += m_out_file;
        for(auto it = m_objects_files.begin();it != m_objects_files.end();it++)
        {
            opts += " ";
            opts += *it;
        }
        actions.push_back(opts);
    }
    return actions;
}

bool XClangOptions::is_not_link(void) const
{
    if (has(C))
    {
        return true;
    }
    if (has(S))
    {
        return true;
    }
    if (has(E))
    {
        return true;
    }
    if (has(help))
    {
        return true;
    }
    if (has(version))
    {
        return true;
    }
    return false;
}
bool XClangOptions::has_option(int opt_id) const
{
    auto it = m_real_ids.find(opt_id);
    if(it != m_real_ids.end())
    {
        return true;
    }
    return false;
}

#if 0
void XClangOptions::adjustClangOptions(void)
{
#if 1 // will change to a const list
    m_Argv.push_back("-nostdinc");
    m_Argv.push_back("-nostdlib");
    if (m_program.iscxx())
    {
        m_Argv.push_back("-nostdincxx");
    }
#endif
}
#endif

