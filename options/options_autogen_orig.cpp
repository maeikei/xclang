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
