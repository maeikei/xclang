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
static int const iConstLanguageASM = 3;
static int const iConstLanguageObject = 4;




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
//    adjustCC1Options();
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
        opt_elment = "-triple " + m_config->getMaster("triple") + " " + opt_elment;
        string act("cxx");
        switch (checkLanguage(*it))
        {
            case iConstLanguageC:
                act = "cc";
                opt_elment += adjustCC1Options(iConstLanguageC);
                break;
            case iConstLanguageCXX:
            default:
                opt_elment += adjustCC1Options(iConstLanguageCXX);
                break;
        }
        opt_elment =  m_config->getLLVMProgram(act) + " " + opt_elment;
        actions.push_back(opt_elment);
    }
    return actions;
}

string XClangOptions::calcLinkCmd(void) const
{
    string ret("ld");
    for (auto it = m_lang_flags.begin(); it != m_lang_flags.end(); it++)
    {
        if( iConstLanguageCXX == *it)
        {
            ret = "ldxx";
            break;
        }
    }
    return ret;
}

list<string> XClangOptions::getLinkActions(void)
{
    adjustLinkOptions();
    list<string> actions;
    if(  is_not_link() )
    {
        actions.empty();
        return actions;
    }
    string opts;
    opts += m_config->getToolChainProgram("ld");
    if(has(shared))
    {
        if (has(static))
        {
            
        }
        else
        {
            
        }
    }
    else
    {
        if (has(static))
        {
            
        }
        else
        {
            
        }
    }
    for(auto it = m_link_options.begin();it !=  m_link_options.end();it++)
    {
        opts += " ";
        opts += *it;
    }
    for(auto it = m_objects_files.begin();it != m_objects_files.end();it++)
    {
        opts += " ";
        opts += *it;
    }
    opts += " -o ";
    opts += m_out_file;
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



string XClangOptions::adjustCC1Options(int lang) const
{
    string ret;
    for (auto it = m_config->m_defaultcflags.begin();it != m_config->m_defaultcflags.end();it++ )
    {
        ret += " " + *it;
    }
    for (auto it = m_config->m_archcflags.begin();it != m_config->m_archcflags.end();it++ )
    {
        ret += " " + *it;
    }
    if(not has(nostdinc))
    {
        for (auto it = m_config->m_stdinc.begin();it != m_config->m_stdinc.end();it++ )
        {
            ret += " " + *it;
        }
    }
    if ( iConstLanguageCXX == lang)
    {
        for (auto it = m_config->m_defaultcxxflags.begin();it != m_config->m_defaultcxxflags.end();it++ )
        {
            ret += " " + *it;
        }
        for (auto it = m_config->m_archcxxflags.begin();it != m_config->m_archcxxflags.end();it++ )
        {
            ret += " " + *it;
        }
        if(not has(nostdincxx))
        {
            for (auto it = m_config->m_stdincxx.begin();it != m_config->m_stdincxx.end();it++ )
            {
                ret += " " + *it;
            }
        }
    }
    ret += " ";
    return ret;
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
    if( ".o" == ext )
    {
        ret = iConstLanguageObject;
    }
    if( ".obj" == ext )
    {
        ret = iConstLanguageObject;
    }
    if( ".a" == ext )
    {
        ret = iConstLanguageObject;
    }
    if( ".s" == ext )
    {
        ret = iConstLanguageASM;
    }
    if( ".asm" == ext )
    {
        ret = iConstLanguageASM;
    }
    m_lang_flags.push_back(ret);
    return ret;
}




void XClangOptions::adjustClangOptions(void)
{
}

void XClangOptions::adjustLinkOptions(void)
{
    
}

