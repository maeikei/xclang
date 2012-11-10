#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "programs.hpp"
using namespace xclang;

#include "boost/filesystem.hpp"
namespace fs = boost::filesystem;

#include <boost/regex.hpp>

XClangPrograms::XClangPrograms(const string &argv0)
:m_argv0(argv0)
,m_fullpath("")
,m_home("")
,m_target("")
,m_suffix("")
{
    try
    {
        fs::path xclangpath(m_argv0);
        xclangpath = fs::absolute(xclangpath);
        xclangpath = fs::canonical(xclangpath);
        m_fullpath = xclangpath.string();
        m_home = xclangpath.parent_path().parent_path().string();
        boost::regex re(string("-xclang*"));
        m_target = boost::regex_replace(xclangpath.filename().string(),re,"");
        boost::regex re2(string("-xclang"));
        boost::sregex_token_iterator i(argv0.begin(),argv0.end(), re2, -1);
        boost::sregex_token_iterator j;
        if (++i != j)
        {
            m_suffix = *i;
        }
    }
    catch (...)
    {
    }
    cout << "m_fullpath=<" << m_fullpath << ">" << endl;
    cout << "m_home=<" << m_home << ">" << endl;
    cout << "m_target=<" << m_target << ">" << endl;
    cout << "m_suffix=<" << m_suffix << ">" << endl;
}
XClangPrograms::~XClangPrograms()
{
}
