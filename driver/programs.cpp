#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
#include "programs.hpp"
#include "configreader.hpp"
using namespace xclang;

#include "boost/filesystem.hpp"
namespace fs = boost::filesystem;

#include <boost/regex.hpp>

XClangPrograms::XClangPrograms(const string &argv0)
:m_argv0(argv0)
,m_fullpath("")
,m_home("")
,m_suffix("")
{
    try
    {
        fs::path xclangpath(m_argv0);
        if(not xclangpath.has_parent_path())
        {
            string path_env(getenv("PATH"));
            boost::regex re3(string("[:|;]"));
            boost::sregex_token_iterator i(path_env.begin(),path_env.end(), re3, -1);
            boost::sregex_token_iterator j;
            do
            {
                fs::path temp_search(*i + "/" + m_argv0);
                if ( fs::exists(temp_search) )
                {
                    xclangpath = temp_search;
                    break;
                }
            }while (i++ != j);
        }
        xclangpath = fs::absolute(xclangpath);
        xclangpath = fs::canonical(xclangpath);
        m_fullpath = xclangpath.string();
        m_home = xclangpath.parent_path().parent_path().string();
        
        fs::path xclangpath_orig(m_argv0);
        string filename = xclangpath_orig.filename().string();
        boost::regex re2(string("-xclang"));
        boost::sregex_token_iterator i(filename.begin(),filename.end(), re2, -1);
        boost::sregex_token_iterator j;
        if (++i != j)
        {
            m_suffix = *i;
        }
    }
    catch (...)
    {
    }
#if 0
    cout << "m_fullpath=<" << m_fullpath << ">" << endl;
    cout << "m_home=<" << m_home << ">" << endl;
    cout << "m_target=<" << m_target << ">" << endl;
    cout << "m_suffix=<" << m_suffix << ">" << endl;
#endif
}
XClangPrograms::~XClangPrograms()
{
}

string XClangPrograms::findProgramName(const string &name) const
{
    string ret(name);
    return ret;
}
