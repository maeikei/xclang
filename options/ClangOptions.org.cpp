



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



static const int iConstKindBase        = 0x1;

static const int JoinedOrSeparate      = iConstKindBase << 1;
static const int Joined                = iConstKindBase << 2;
static const int Separate              = iConstKindBase << 3;
static const int CommaJoined           = iConstKindBase << 4;
static const int MultiArg              = iConstKindBase << 5;
static const int JoinedAndSeparate     = iConstKindBase << 6;
static const int Input                 = iConstKindBase << 7;
static const int Unknown               = iConstKindBase << 8;
static const int Flag                  = iConstKindBase << 9;
static const int Action_Group          = iConstKindBase << 10;





struct OptTable_Info
{
    const char * const *prefix;
    const char *name;
    const int kind;
    const int flags;
    const int id;
};

static const OptTable_Info InfoTable[] = {
#define PREFIX(NAME, VALUE)
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)   \
{ PREFIX, NAME,KIND,FLAGS,XClangOptions::OPT_##ID},
#include "ClangOptions.org.inc"
};
static map<string,OptProperty> genMap(void);

//const map<string,int> XClangOptions::m_clang_options = genMap(CC1Option);
//const map<string,int> XClangOptions::m_clang_cc1_options = genMap(DriverOption);

const map<string,OptProperty> XClangOptions::m_xclang_options = genMap();

static map<string,OptProperty> genMap()
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
            string key(*p);
            key += InfoTable[i].name;
            OptProperty pro = {InfoTable[i].kind,InfoTable[i].flags,InfoTable[i].id};
            ret.insert(pair<string, OptProperty>(key, pro  ));
            p++;
        }
    }
    return ret;
}



void XClangOptions::splitArgs(void)
{
#ifdef DEBUG
    for(auto it = m_xclang_options.begin();it != m_xclang_options.end();it++)
    {
        cout << "key=<" << it->first << ">" << endl;
    }
    cout << "m_xclang_options end" << endl;
#endif

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
        auto it = m_xclang_options.find(vStr);
        if (it != m_xclang_options.end())
        {
            i = getNextArgs(it->first,it->second,i);
            continue;
        }
        m_input_files.push_back(vStr);
        m_input_files_str += vStr;
        m_input_files_str += " ";
        i++;
    }
}

int XClangOptions::getNextArgs(const string &opt,const OptProperty &prop,int i)
{
    string value("");
    if ( prop.kind & Separate )
    {
    }
    if ( prop.kind & Joined )
    {
        value = m_argv[++i];
    }
    m_real_options.insert(pair<string,string>(opt,value));
    return ++i;
}
