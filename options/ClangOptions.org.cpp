



#include "options.hpp"
using namespace xclang;



#define PREFIX(NAME, VALUE) const char *const NAME[] = VALUE;
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)
#include "ClangOptions.org.inc"
#undef OPTION
#undef PREFIX



static const int DriverOption          = 0x1 << 1;
static const int CC1Option             = 0x1 << 2;
static const int RenderJoined          = 0x1 << 3;
static const int LinkerInput           = 0x1 << 4;
static const int Unsupported           = 0x1 << 5;
static const int HelpHidden            = 0x1 << 6;
static const int NoForward             = 0x1 << 7;
static const int RenderAsInput         = 0x1 << 8;
static const int NoArgumentUnused      = 0x1 << 9;
static const int Group                 = 0x1 << 10;

static const int NoDriverOption = ~DriverOption;


static const int JoinedOrSeparate      = 0x1 << 1;
static const int Joined                = 0x1 << 2;
static const int Separate              = 0x1 << 3;
static const int CommaJoined           = 0x1 << 4;
static const int MultiArg              = 0x1 << 5;
static const int JoinedAndSeparate     = 0x1 << 6;
static const int Input                 = 0x1 << 7;
static const int Unknown               = 0x1 << 8;
static const int Flag                  = 0x1 << 9;
static const int Action_Group          = 0x1 << 10;





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
static map<string,int> genMap(int flags);

const map<string,int> XClangOptions::m_clang_options = genMap(CC1Option);
const map<string,int> XClangOptions::m_clang_cc1_options = genMap(DriverOption);



static map<string,int> genMap(int flags)
{
    map<string,int> ret;
    for (auto i = 0; i < sizeof(InfoTable)/sizeof(OptTable_Info); i++)
    {
        char** p = (char **)InfoTable[i].prefix;
        if(nullptr == p || nullptr == *p )
        {
            continue;
        }
        while ( nullptr != p && nullptr != *p)
        {
            if( flags &InfoTable[i].flags )
            {
                string key(*p);
                key += InfoTable[i].name;
                ret.insert(pair<string, int>(key,InfoTable[i].kind));
            }
            p++;
        }
    }
    return ret;
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
