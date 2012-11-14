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
            ("xclang-target",value(&m_xclang_target) ,"xclang target ")
            repleace_option_desc
        ;
        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
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
