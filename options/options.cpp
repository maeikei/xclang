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
,m_clang_options()
,m_link_options()
,m_real_ids()
,m_input_files()
,m_input_files_str("")
,m_objects_files()
,m_out_file("a.out")
,m_target("")
{
    splitArgs();
}


XClangOptions::~XClangOptions()
{
}


vector<string> XClangOptions::getClangActions(void)
{
    adjustClangOptions();
    string opts;
    for(auto it = m_clang_options.begin();it !=  m_clang_options.end();it++)
    {
        opts += *it;
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
    adjustLinkOptions();
    vector<string> actions;
    if(  is_not_link() )
    {
        return actions;
    }
    string opts;
    for(auto it = m_link_options.begin();it !=  m_link_options.end();it++)
    {
        opts += *it;
        opts += " ";
    }
    opts += " -o ";
    opts += m_out_file;
    for(auto it = m_objects_files.begin();it != m_objects_files.end();it++)
    {
        opts += " ";
        opts += *it;
    }
    actions.push_back(opts);
    return actions;
}

bool XClangOptions::is_not_link(void) const
{
    if (has(c))
    {
        return true;
    }
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

void XClangOptions::adjustClangOptions(void)
{
    m_clang_options.push_back("-no-standard-includes");
    m_clang_options.push_back("-nobuiltininc");
    m_clang_options.push_back("-nostdinc");
    m_clang_options.push_back("-nostdlibinc");
    m_clang_options.push_back("-nostdsysteminc");
//    if (iscxx())
    {
        m_clang_options.push_back("-nostdinc++");
    }
}
void XClangOptions::adjustLinkOptions(void)
{
    m_link_options.push_back("-no-standard-libraries");
    m_link_options.push_back("-nodefaultlibs");
    m_link_options.push_back("-nolibc");
    m_link_options.push_back("-nostartfiles");
    m_link_options.push_back("-nostdlib");    
    //    if (iscxx())
    {
        m_link_options.push_back("");
    }
}

