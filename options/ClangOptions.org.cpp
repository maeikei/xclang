

#define PREFIX(NAME, VALUE) const char *const NAME[] = VALUE;
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)
#include "ClangOptions.org.inc"
#undef OPTION
#undef PREFIX


static const OptTable::Info InfoTable[] = {
#define PREFIX(NAME, VALUE)
#define OPTION(PREFIX, NAME, ID, KIND, GROUP, ALIAS, FLAGS, PARAM, \
HELPTEXT, METAVAR)   \
{ PREFIX, NAME,FLAGS },
#include "ClangOptions.org.inc"
};


