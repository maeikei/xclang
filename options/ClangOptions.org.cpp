#include "options.hpp"
using namespace xclang;
#include <iostream>
using namespace std;


#define PREFIX(NAME, VALUE) const char *const NAME[] = VALUE;
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)
#include "ClangOptions.org.inc"
#undef OPTION
#undef PREFIX


static const int iConstTypeBase        = 0x1;


static const int DriverOption          = iConstTypeBase << 1;
static const int CC1Option             = iConstTypeBase << 2;
static const int RenderJoined          = iConstTypeBase << 3;
static const int LinkerInput           = iConstTypeBase << 4;
static const int Unsupported           = iConstTypeBase << 5;
static const int HelpHidden            = iConstTypeBase << 6;
static const int NoForward             = iConstTypeBase << 7;
static const int RenderAsInput         = iConstTypeBase << 8;
static const int NoArgumentUnused      = iConstTypeBase << 9;
static const int Group                 = iConstTypeBase << 10;
static const int NoDriverOption        = iConstTypeBase << 11;;

static const int iConstTypeLinker   =  RenderJoined | LinkerInput;



static const int iConstKindBase        = 0x1;

static const int Flag                  = iConstKindBase << 0;
static const int Joined                = iConstKindBase << 1;
static const int Separate              = iConstKindBase << 2;
static const int JoinedOrSeparate      = iConstKindBase << 3;
static const int JoinedAndSeparate     = iConstKindBase << 4;
static const int CommaJoined           = iConstKindBase << 5;
static const int MultiArg              = iConstKindBase << 6;
static const int Input                 = iConstKindBase << 7;
static const int Unknown               = iConstKindBase << 8;
static const int Action_Group          = iConstKindBase << 9;

static const int iConstKindFullMatch   = Flag | Separate | JoinedOrSeparate | Action_Group;
static const int iConstKindPrefixMatch = Joined | JoinedOrSeparate | JoinedAndSeparate | CommaJoined;




static const int iConstGroupBase       = 0x1;


static const int INVALID               = iConstGroupBase &0;
static const int CompileOnly_Group     = iConstGroupBase << 0;
static const int ccc_debug_Group       = iConstGroupBase << 1;



struct OptTable_Info
{
    const char * const *prefix;
    const char *name;
    OptProperty prop;
};

static const OptTable_Info InfoTable[] = {
#define PREFIX(NAME, VALUE)
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)   \
{ PREFIX, NAME,{KIND,FLAGS,XClangOptions::OPT_##ID}},
#include "ClangOptions.org.inc"
};

static map<string,OptProperty> genSplitMap(int kind);

const map<string,OptProperty> XClangOptions::m_xclang_options_full_match = genSplitMap(iConstKindFullMatch);
const map<string,OptProperty> XClangOptions::m_xclang_options_prefix_match = genSplitMap(iConstKindPrefixMatch);


//#define DEBUG

#define dout std::cout << __func__ << ":" << __LINE__ << ":"


static map<string,OptProperty> genSplitMap(int kind)
{
    map<string,OptProperty> ret;
    for (auto i = 0; i < sizeof(InfoTable)/sizeof(OptTable_Info); i++)
    {
        char** p = (char **)InfoTable[i].prefix;
        if(nullptr == p || nullptr == *p )
        {
            continue;
        }
        while ( nullptr != p && nullptr != *p)
        {
            if(InfoTable[i].prop.kind & kind )
            {
                string key(*p);
                key += InfoTable[i].name;
                ret.insert(pair<string, OptProperty>(key, InfoTable[i].prop  ));
            }
            p++;
        }
    }
    return ret;
}



//#define DEBUG

void XClangOptions::splitArgs(void)
{
#ifdef DEBUG
    for(auto it = m_xclang_options_full_match.begin();it != m_xclang_options_full_match.end();it++)
    {
        cout << "key=<" << it->first << ">" << endl;
    }
    cout << "m_xclang_options_full_match end" << endl;
    for(auto it = m_xclang_options_prefix_match.rbegin();it != m_xclang_options_prefix_match.rend();it++)
    {
        cout << "key=<" << it->first << ">" << endl;
    }
    cout << "m_xclang_options_prefix_match end" << endl;
#endif

    int i = 1;
    while(i < m_argc)
    {
        string vStr(m_argv[i]);
        if("-o" == vStr)
        {
            m_out_file = string(m_argv[++i]);
            m_real_ids.insert(pair<int,bool>(OPT_o,true));
            i++;
            continue;
        }
        if("--xclang-target" == vStr)
        {
            m_target = string(m_argv[++i]);
            i++;
            continue;
        }
        auto it = m_xclang_options_full_match.find(vStr);
        if (it != m_xclang_options_full_match.end())
        {
            i = getNextArgsFullMatch(vStr,it->second,i);
            continue;
        }
        else
        {
            bool prefix_match = false;
            for( auto itpre= m_xclang_options_prefix_match.rbegin();
                itpre != m_xclang_options_prefix_match.rend();itpre++ )
            {
                auto pos = vStr.find(itpre->first);
                if ( string::npos != pos)
                {
                    i = getNextArgsPrefixMatch(vStr,itpre->first,itpre->second,i);
                    prefix_match = true;
                    break;
                }
            }
            if(prefix_match)
            {
                continue;
            }
        }
        m_input_files.push_back(vStr);
        m_input_files_str += vStr;
        m_input_files_str += " ";
        i++;
    }
#ifdef DEBUG
    for(auto it = m_clang_options.begin();it != m_clang_options.end();it++)
    {
        cout << "*it=<" << *it << ">" << endl;
    }
    cout << "m_clang_options end" << endl;
    for(auto it = m_link_options.begin();it != m_link_options.end();it++)
    {
        cout << "*it=<" << *it << ">" << endl;
    }
    cout << "m_link_options end" << endl;
#endif
}



#ifdef DEBUG
#define add_option(opt,prop) \
{ \
    if ( prop.flags & CC1Option ) \
    {\
        dout << "opt=<" << opt << ">" << endl;\
        dout << "prop.flags=<" << prop.flags << ">" << endl;\
        m_cc1_options.push_back(opt);\
    }\
    if ( prop.flags & iConstTypeLinker ) \
    { \
        if ( prop.flags &NoDriverOption ) \
        { \
            dout << "opt=<" << opt << ">" << endl;\
            dout << "prop.flags=<" << prop.flags << ">" << endl;\
            m_clang_options.push_back(opt);\
        } \
        else \
        { \
            dout << "opt=<" << opt << ">" << endl;\
            dout << "prop.flags=<" << prop.flags << ">" << endl;\
            m_link_options.push_back(opt);\
        } \
    }\
    else \
    {\
        dout << "opt=<" << opt << ">" << endl;\
        dout << "prop.flags=<" << prop.flags << ">" << endl;\
        m_clang_options.push_back(opt);\
    }\
}

#else

#define add_option(opt,prop) \
{ \
    if ( prop.flags & CC1Option ) \
    {\
        m_cc1_options.push_back(opt);\
    }\
    if ( prop.flags & iConstTypeLinker ) \
    { \
        if ( prop.flags &NoDriverOption ) \
        { \
            m_clang_options.push_back(opt);\
        } \
        else \
        { \
            m_link_options.push_back(opt);\
        } \
    }\
    else \
    {\
        m_clang_options.push_back(opt);\
    }\
}

#endif




int XClangOptions::getNextArgsFullMatch(const string &opt,const OptProperty &prop,int i)
{
    add_option(opt,prop);
    if ( prop.kind & Separate )
    {
        ++i;
        add_option(m_argv[i],prop);
    }
    if ( prop.kind & JoinedOrSeparate )
    {
        ++i;
        add_option(m_argv[i],prop);
    }
    m_real_ids.insert(pair<int,bool>(prop.id,true));
    return ++i;
}

int XClangOptions::getNextArgsPrefixMatch(const string &opt,const string &prefix,const OptProperty &prop,int i)
{
    add_option(opt,prop);
    if ( prop.kind & JoinedAndSeparate )
    {
        ++i;
        add_option(m_argv[i],prop);
    }
    m_real_ids.insert(pair<int,bool>(prop.id,true));
    return ++i;
}
