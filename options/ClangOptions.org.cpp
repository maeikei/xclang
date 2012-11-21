

enum OPT_ID {
#define PREFIX(NAME, VALUE)
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)   \
OPT_##ID,
#include "ClangOptions.org.inc"
#undef OPTION
#undef PREFIX

};





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
    const OPT_ID id;
};

static const OptTable_Info InfoTable[] = {
#define PREFIX(NAME, VALUE)
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)   \
{ PREFIX, NAME,KIND,FLAGS,OPT_##ID},
#include "ClangOptions.org.inc"
};

#if 0
#include <stdio.h>
int main()
{
    for (auto i = 0; i < sizeof(InfoTable)/sizeof(OptTable_Info); i++)
    {
        char** p = (char **)InfoTable[i].prefix;
        if(nullptr == p || nullptr == *p )
        {
            continue;
        }
        while ( nullptr != p && nullptr != *p)
        {
            printf("%s,",*p);
            p++;
        }
        printf("%s,0x%x,0x%x ,0x%x\n",InfoTable[i].name,InfoTable[i].kind,InfoTable[i].flags,InfoTable[i].id);
    }
    return 0;
}
#endif

