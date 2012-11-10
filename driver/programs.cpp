#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "programs.hpp"
using namespace xclang;

#include "boost/filesystem.hpp"


XClangPrograms::XClangPrograms(const string &argv0)
:m_argv0(argv0)
{
}
XClangPrograms::~XClangPrograms()
{
}
