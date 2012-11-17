#include "options.hpp"
using namespace xclang;
#include <boost/assign/list_of.hpp>
using namespace boost::assign;
#include <iostream>
#include <iterator>
using namespace std;


const map<string,int> XClangOptions::m_clang_options = map_list_of
replace_clang_options
;




const map<string,int> XClangOptions::m_clang_cc1_options  = map_list_of
replace_clang_cc1_options
;



XClangOptions::XClangOptions(int argc,const char** argv)
:m_argc(argc)
,m_argv(argv)
,m_real_options()
replace_intialize
{
    parseArgs();
}

void XClangOptions::parseArgs(void)
{
    auto it = m_real_options.begin();
    replace_parse_args
}