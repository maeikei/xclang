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
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
using namespace boost::assign;
#include <iostream>
#include <iterator>
using namespace std;


//#define DEBUG_CC1
//#define DEBUG_CC1_LUA

//#define DEBUG_LINK

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
,m_out_file()
,m_target("")
{
    splitArgs();
}


XClangOptions::~XClangOptions()
{
}



list<string> XClangOptions::getCC1Actions(void)
{
    string opts;
    for(auto it = m_cc1_options.begin();it !=  m_cc1_options.end();it++)
    {
        opts += *it;
        opts += " ";
    }
#ifdef DEBUG_CC1
    cout <<__func__<< " opts=<"<< opts <<">"<< endl;
#endif
    //
    if(has(_version))
    {
        list<string> actions;
        actions.push_back(m_config->getLLVMProgram("clang") + " " + opts) ;
        return actions;        
    }
    // multi options
    if(has(o) && ( has(c) || has(S)) && m_input_files.size() > 1 )
    {
        list<string> actions;
        return actions;
    }
    
    string extension(m_config->getProperty("objext"));
    list<string> actions;
    if( has(S) )
    {
        extension = m_config->getProperty("asmext");
    }
#ifdef DEBUG_CC1
    cout <<__func__<< " extension=<"<< extension <<">"<< endl;
    cout <<__func__<< " m_input_files.size()=<"<< m_input_files.size() <<">"<< endl;
#endif
    
    for(auto it = m_input_files.begin();it !=  m_input_files.end();it++)
    {
#ifdef DEBUG_CC1
        cout <<__func__<< " it=<"<< *it <<">"<< endl;
#endif
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
            else
            {
                opt_elment += " -o ";                
                opt_elment += m_out_file;
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
        opt_elment = "-triple " + m_config->getProperty("triple") + " " + opt_elment;
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


bool XClangOptions::calcLinkCXX(void) const
{
    if( m_prog.iscxx())
    {
        return true;
    }
    for (auto it = m_lang_flags.begin(); it != m_lang_flags.end(); it++)
    {
        if( iConstLanguageCXX == *it)
        {
            return true;
        }
    }
    return false;
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
    linkConfig *pLinker = nullptr;
    if(has(shared))
    {
        if (has(static))
        {
            pLinker = new linkConfigSharedStatic(m_config);
        }
        else
        {
            pLinker = new linkConfigShared(m_config);
        }
    }
    else
    {
        if (has(static))
        {
            pLinker = new linkConfigExeStatic(m_config);
        }
        else
        {
            pLinker = new linkConfigExe(m_config);            
        }
    }
    opts += pLinker->arch();
    opts += " -o ";
    if(m_out_file.empty())
    {
        opts += m_config->getProperty("defaultexe") + " ";
    }
    else
    {
        opts += m_out_file;
    }
    
    
    opts += pLinker->beginobject();
    opts += pLinker->stdxxdirs();
    opts += pLinker->stddirs();
    for(auto it = m_link_options.begin();it !=  m_link_options.end();it++)
    {
        opts += " ";
        string ldOption(*it);
        boost::algorithm::replace_all(ldOption, "Wl,", "");
        boost::regex reg("--soname.*");
        if(boost::regex_match(ldOption,reg))
        {
            if (has(o))
            {
                continue;
            }
            else
            {
                boost::algorithm::replace_all(ldOption, "--soname,", " -o ");
            }
        }
        opts += ldOption;
    }
    for(auto it = m_objects_files.begin();it != m_objects_files.end();it++)
    {
        opts += " ";
        opts += *it;
    }
    if(not m_input_objects_str.empty())
    {
        opts += " " + m_input_objects_str;
    }
    if(calcLinkCXX())
    {
        if( not has(nostdlib))
        {
            opts += pLinker->stdxxlibs();
        }
    }
    if( not has(nostdlib) )
    {
        opts += pLinker->stdlibs();
    }
    opts += pLinker->endobject();
    actions.push_back(opts);
    if(m_objects_files.empty() && m_input_objects_str.empty())
    {
        actions.clear();
    }
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
    if (has(_version))
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
#ifdef DEBUG_CC1_LUA
    cout << "lang=<" << lang << ">" << endl;
#endif
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



linkConfig::linkConfig()
:m_conf(nullptr)
{
}


linkConfig::linkConfig(ConfigReader *_conf)
:m_conf(_conf)
{
}


#define concatValuesExe(table) \
{\
for(auto it = m_conf->m_link_exe_##table.begin();it != m_conf->m_link_exe_##table.end();it++)\
{ \
ret += " "; \
ret += *it; \
}\
}

linkConfigExe::linkConfigExe(ConfigReader *_conf)
:linkConfig(_conf)
{
}

string linkConfigExe::arch(void) const
{
        string ret;
        concatValuesExe(arch);
        return ret;
}
string linkConfigExe::beginobject(void) const
{
    string ret;
    concatValuesExe(beginobject);
    return ret;
}
string linkConfigExe::stdxxdirs(void) const
{
    string ret;
    concatValuesExe(stdxxdirs);
    return ret;
}
string linkConfigExe::stdxxlibs(void) const
{
    string ret;
    concatValuesExe(stdxxlibs);
    return ret;
}
string linkConfigExe::stddirs(void) const
{
    string ret;
    concatValuesExe(stddirs);
    return ret;
}
string linkConfigExe::stdlibs(void) const
{
    string ret;
    concatValuesExe(stdlibs);
#ifdef DEBUG_LINK
    cout << typeid(*this).name() <<"::"<< __func__ << " ret=<" << ret << ">"<< endl;
#endif
    return ret;
}
string linkConfigExe::endobject(void) const
{
    string ret;
    concatValuesExe(endobject);
    return ret;
}


#define concatValuesExeS(table) \
{\
for(auto it = m_conf->m_link_exe_s_##table.begin();it != m_conf->m_link_exe_s_##table.end();it++)\
{ \
ret += " "; \
ret += *it; \
}\
}
linkConfigExeStatic::linkConfigExeStatic(ConfigReader *_conf)
:linkConfig(_conf)
{
}

string linkConfigExeStatic::arch(void) const
    {
        string ret;
        concatValuesExeS(arch);
        return ret;
    }
string linkConfigExeStatic::beginobject(void) const
    {
        string ret;
        concatValuesExeS(beginobject);
        return ret;
    }
string linkConfigExeStatic::stdxxdirs(void) const
    {
        string ret;
        concatValuesExeS(stdxxdirs);
        return ret;
    }
string linkConfigExeStatic::stdxxlibs(void) const
    {
        string ret;
        concatValuesExeS(stdxxlibs);
        return ret;
    }
string linkConfigExeStatic::stddirs(void) const
    {
        string ret;
        concatValuesExeS(stddirs);
        return ret;
    }
string linkConfigExeStatic::stdlibs(void) const
    {
        string ret;
        concatValuesExeS(stdlibs);
#ifdef DEBUG_LINK
        cout << typeid(*this).name() <<"::"<< __func__ << " ret=<" << ret << ">"<< endl;
#endif
        return ret;
    }
string linkConfigExeStatic::endobject(void) const
    {
        string ret;
        concatValuesExeS(endobject);
        return ret;
    }


#define concatValuesShared(table) \
{\
for(auto it = m_conf->m_link_shared_##table.begin();it != m_conf->m_link_shared_##table.end();it++)\
{ \
ret += " "; \
ret += *it; \
}\
}
linkConfigShared::linkConfigShared(ConfigReader *_conf)
:linkConfig(_conf)
{
}

string linkConfigShared::arch(void) const
    {
        string ret;
        concatValuesShared(arch);
        return ret;
    }
string linkConfigShared::beginobject(void) const
    {
        string ret;
        concatValuesShared(beginobject);
        return ret;
    }
string linkConfigShared::stdxxdirs(void) const
    {
        string ret;
        concatValuesShared(stdxxdirs);
        return ret;
    }
string linkConfigShared::stdxxlibs(void) const
    {
        string ret;
        concatValuesShared(stdxxlibs);
        return ret;
    }
string linkConfigShared::stddirs(void) const
    {
        string ret;
        concatValuesShared(stddirs);
        return ret;
    }
string linkConfigShared::stdlibs(void) const
    {
        string ret;
        concatValuesShared(stdlibs);
#ifdef DEBUG_LINK
        cout << typeid(*this).name() <<"::"<< __func__ << " ret=<" << ret << ">"<< endl;
#endif
        return ret;
    }
string linkConfigShared::endobject(void) const
    {
        string ret;
        concatValuesShared(endobject);
        return ret;
    }


#define concatValuesSharedS(table) \
{\
for(auto it = m_conf->m_link_shared_s_##table.begin();it != m_conf->m_link_shared_s_##table.end();it++)\
{ \
ret += " "; \
ret += *it; \
}\
}

linkConfigSharedStatic::linkConfigSharedStatic(ConfigReader *_conf)
:linkConfig(_conf)
{
}

string linkConfigSharedStatic::arch(void) const
    {
        string ret;
        concatValuesSharedS(arch);
        return ret;
    }
string linkConfigSharedStatic::beginobject(void) const
    {
        string ret;
        concatValuesSharedS(beginobject);
        return ret;
    }
string linkConfigSharedStatic::stdxxdirs(void) const
    {
        string ret;
        concatValuesSharedS(stdxxdirs);
        return ret;
    }
string linkConfigSharedStatic::stdxxlibs(void) const
    {
        string ret;
        concatValuesSharedS(stdxxlibs);
        return ret;
    }
string linkConfigSharedStatic::stddirs(void) const
    {
        string ret;
        concatValuesSharedS(stddirs);
        return ret;
    }
string linkConfigSharedStatic::stdlibs(void) const
    {
        string ret;
        concatValuesSharedS(stdlibs);
#ifdef DEBUG_LINK
        cout << typeid(*this).name() <<"::"<< __func__ << " ret=<" << ret << ">"<< endl;
#endif
        return ret;
    }
string linkConfigSharedStatic::endobject(void) const
    {
        string ret;
        concatValuesSharedS(endobject);
        return ret;
    }

