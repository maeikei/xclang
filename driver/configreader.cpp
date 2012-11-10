#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "programs.hpp"
using namespace xclang;

#include "boost/filesystem.hpp"
namespace fs = boost::filesystem;

XClangPrograms::XClangPrograms(const string &argv0)
:m_argv0(argv0)
,m_fullpath("")
,m_xclanghome("")
{
}
XClangPrograms::~XClangPrograms()
{
}
void XClangPrograms::parse(void)
{
    try
    {
        fs::path xclangpath(m_argv0);
        xclangpath = fs::absolute(xclangpath);
        xclangpath = fs::canonical(xclangpath);
        m_fullpath = xclangpath.string();
        m_xclanghome = xclangpath.parent_path().parent_path().string();
    }
    catch (...)
    {
    }
    
    
    
    
    cout << "m_fullpath=<" << m_fullpath << ">" << endl;
    cout << "m_xclanghome=<" << m_xclanghome << ">" << endl;
}
