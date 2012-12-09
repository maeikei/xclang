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




static int const iConstLanguageCXX = 1;
static int const iConstLanguageC = 2;


XClangOptions::XClangOptions(int argc,const char** argv,const XClangPrograms &_prog)
:m_argc(argc)
,m_argv(argv)
,m_prog(_prog)
,m_cc1_options()
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



list<string> XClangOptions::getCC1Actions(void)
{
    adjustCC1Options();
    // multi options
    if(has(o) && ( has(c) || has(S)) && m_input_files.size() > 1 )
    {
        list<string> actions;
        return actions;
    }
    string opts;
    for(auto it = m_cc1_options.begin();it !=  m_cc1_options.end();it++)
    {
        opts += *it;
        opts += " ";
    }
    
    string extension(".o");
    list<string> actions;
    if( has(S) )
    {
        extension = ".s";
    }
    
    for(auto it = m_input_files.begin();it !=  m_input_files.end();it++)
    {
        string opt_elment(opts);
        if( has(c) || has(S))
        {
            opt_elment += " ";
            opt_elment += *it;
            if( not has(o) )
            {
                opt_elment += " -o ";
                fs::path fileName(*it);
                fileName.replace_extension(extension);
                opt_elment += fileName.string();
            }
        }
        else if( has(E) )
        {
            opt_elment += " ";
            opt_elment += *it;
            opt_elment += " -o -";
        }
        if( not is_not_link() )
        {
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
        }
        if( not ( has(E) || has(S)))
        {
            opt_elment = " -emit-obj " + opt_elment;
        }
        opt_elment = "-triple " + this->gettarget() + " " + opt_elment;
        string act("cxx");
        switch (checkLanguage(*it))
        {
            case iConstLanguageC:
                act = "cc";
                break;
            case iConstLanguageCXX:
            default:
                break;
        }
        opt_elment =  m_config->getLLVMProgram(act) + " " + opt_elment;
        actions.push_back(opt_elment);
    }
    return actions;
}

list<string> XClangOptions::getLinkActions(void)
{
    adjustLinkOptions();
    list<string> actions;
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

void XClangOptions::adjustCC1Options(void)
{
    for (auto it = m_config->m_defaultcflags.begin();it != m_config->m_defaultcflags.end();it++ )
    {
        m_cc1_options.push_back(*it);
    }
    for (auto it = m_config->m_archcflags.begin();it != m_config->m_archcflags.end();it++ )
    {
        m_cc1_options.push_back(*it);
    }
    if(not has(nostdinc))
    {
        for (auto it = m_config->m_stdinc.begin();it != m_config->m_stdinc.end();it++ )
        {
            m_cc1_options.push_back(*it);
        }
    }
    if ( m_prog.iscxx())
    {
        for (auto it = m_config->m_defaultcxxflags.begin();it != m_config->m_defaultcxxflags.end();it++ )
        {
            m_cc1_options.push_back(*it);
        }
        for (auto it = m_config->m_archcxxflags.begin();it != m_config->m_archcxxflags.end();it++ )
        {
            m_cc1_options.push_back(*it);
        }
        if(not has(nostdincxx))
        {
            for (auto it = m_config->m_stdincxx.begin();it != m_config->m_stdincxx.end();it++ )
            {
                m_cc1_options.push_back(*it);
            }
        }
    }
}

int XClangOptions::checkLanguage(const string &input)
{
    int ret = iConstLanguageCXX;
    fs::path fileName(input);
    string ext = fileName.extension().string();
    if( ".c" == ext )
    {
        ret = iConstLanguageC;
    }
    return ret;
}




void XClangOptions::adjustClangOptions(void)
{
    if (not has(c) && not has(E) && not has(S))
    {
        m_clang_options.push_back("-c");
    }
    for (auto it = m_config->m_defaultcflags.begin();it != m_config->m_defaultcflags.end();it++ )
    {
        m_clang_options.push_back(*it);
    }
    for (auto it = m_config->m_archcflags.begin();it != m_config->m_archcflags.end();it++ )
    {
        m_clang_options.push_back(*it);
    }
    if(not has(nostdinc))
    {
        for (auto it = m_config->m_stdinc.begin();it != m_config->m_stdinc.end();it++ )
        {
            m_clang_options.push_back(*it);
        }
    }
    if ( m_prog.iscxx())
    {
        for (auto it = m_config->m_defaultcxxflags.begin();it != m_config->m_defaultcxxflags.end();it++ )
        {
            m_clang_options.push_back(*it);           
        }
        for (auto it = m_config->m_archcxxflags.begin();it != m_config->m_archcxxflags.end();it++ )
        {
            m_clang_options.push_back(*it);
        }
        if(not has(nostdincxx))
        {
            for (auto it = m_config->m_stdincxx.begin();it != m_config->m_stdincxx.end();it++ )
            {
                m_clang_options.push_back(*it);           
            }
        }
    }
}
void XClangOptions::adjustLinkOptions(void)
{
    m_link_options.push_back("-no-standard-libraries");
    m_link_options.push_back("-nodefaultlibs");
    m_link_options.push_back("-nolibc");
    m_link_options.push_back("-nostartfiles");
    m_link_options.push_back("-nostdlib");    
    if (m_prog.iscxx())
    {
        m_link_options.push_back("");
    }
}

