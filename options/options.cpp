#include <string>
#include <iostream>
using namespace std;
#include "options.hpp"
using namespace xclang;

#include <boost/program_options.hpp>
namespace po = boost::program_options;


XClangOptions::XClangOptions(int argc,const char** argv)
:m_argc(argc)
,m_argv(argv)
{
}
XClangOptions::~XClangOptions()
{
}