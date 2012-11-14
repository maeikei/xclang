#include "options.hpp"
using namespace xclang;
#include <boost/program_options.hpp>
namespace po = boost::program_options;
#include <iostream>
#include <iterator>
using namespace std;
void XClangOptions::parseArgs(void)
{
    try {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("xclang-target",po::value(&m_xclang_target) ,"xclang target ")
            repleace_option_desc
        ;
        po::variables_map vm;
        po::store(po::parse_command_line(m_argc, m_argv, desc), vm);
        if (vm.count("help")) {
            cout << desc << "\n";
            return;
        }
        repleace_vm_count
    }//try
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }
}
