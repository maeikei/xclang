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
            (",###","                      Print the commands to run for this compilation")
            ("analyze,analyze","                 Run the static analyzer")
            ("help,help","                    Display available options")
            ("migrate,migrate","                 Run the migrator")
            ("relocatable-pch,relocatable-pch","         Build a relocatable precompiled header")
            ("serialize-diagnostics,serialize-diagnostics",value(&m_serialize_diagnostics),"   <value>                          Serialize compiler diagnostics to a file")
            (",E","                        Only run the preprocessor")
            (",ObjC++","                   Treat source input files as Objective-C++ inputs")
            (",ObjC","                     Treat source input files as Objective-C inputs")
            (",Qunused-arguments","        Don't emit warning for unused driver arguments")
            (",S","                        Only run preprocess and compilation steps")
            (",Wa",value(&m_Wa),"                 Pass the comma separated arguments in <arg> to the assembler")
            (",Wl",value(&m_Wl),"                 Pass the comma separated arguments in <arg> to the linker")
            (",Wp",value(&m_Wp),"                 Pass the comma separated arguments in <arg> to the preprocessor")
            (",Xanalyzer",value(&m_Xanalyzer),"   <arg>        Pass <arg> to the static analyzer")
            (",Xassembler",value(&m_Xassembler),"   <arg>       Pass <arg> to the assembler")
            (",Xclang",value(&m_Xclang),"   <arg>           Pass <arg> to the clang compiler")
            (",Xlinker",value(&m_Xlinker),"   <arg>          Pass <arg> to the linker")
            (",Xpreprocessor",value(&m_Xpreprocessor),"   <arg>    Pass <arg> to the preprocessor")
            (",arcmt-migrate-emit-errors","                            Emit ARC errors even if the migrator can fix them")
            (",arcmt-migrate-report-output",value(&m_arcmt_migrate_report_output),"   <value>                          Output path for the plist report")
            (",c","                        Only run preprocess, compile, and assemble steps")
            (",emit-ast","                 Emit Clang AST files for source inputs")
            (",emit-llvm","                Use the LLVM representation for assembler and object files")
            (",fcatch-undefined-behavior","                            Generate runtime checks for undefined behavior.")
            (",flimit-debug-info","        Limit debug information produced to reduce size of debug binary")
            (",fno-limit-debug-info","     Do not limit debug information produced to reduce size of debug binary")
            (",ftrap-function",value(&m_ftrap_function),"   Issue call to specified function rather than a trap instruction")
            (",gcc-toolchain",value(&m_gcc_toolchain),"   <value>  Use the gcc toolchain at the given directory")
            (",objcmt-migrate-literals","                            Enable migration to modern ObjC literals")
            (",objcmt-migrate-subscripting","                            Enable migration to modern ObjC subscripting")
            (",o",value(&m_o),"   <file>               Write output to <file>")
            (",pipe","                     Use pipes between commands, when possible")
            (",print-file-name",value(&m_print_file_name),"   Print the full library path of <file>")
            (",print-libgcc-file-name","   Print the library path for "libgcc.a"")
            (",print-prog-name",value(&m_print_prog_name),"   Print the full program path of <name>")
            (",print-search-dirs","        Print the paths used for finding libraries and programs")
            (",rewrite-objc","             Rewrite Objective-C source to C++")
            (",save-temps","               Save intermediate compilation results")
            (",target",value(&m_target),"   <value>         Generate code for the given target")
            (",time","                     Time individual commands")
            (",verify","                   Verify output using a verifier.")
            (",v","                        Show commands to run and use verbose output")
            (",working-directory",value(&m_working_directory),"   <value>                          Resolve file paths relative to the specified directory")
        ;
        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        if (vm.count("help")) {
            cout << desc << "\n";
            return;
        }
        if(vm.count("###")){
            m_spspsp = true;
        }
        if(vm.count("analyze")){
            m_analyze = true;
        }
        if(vm.count("help")){
            m_help = true;
        }
        if(vm.count("migrate")){
            m_migrate = true;
        }
        if(vm.count("relocatable-pch")){
            m_relocatable_pch = true;
        }
        if(vm.count("serialize-diagnostics")){
            m_serialize_diagnostics = vm["serialize-diagnostics"].as<string>();
        }
        if(vm.count("E")){
            m_E = true;
        }
        if(vm.count("ObjC++")){
            m_ObjCplusplus = true;
        }
        if(vm.count("ObjC")){
            m_ObjC = true;
        }
        if(vm.count("Qunused-arguments")){
            m_Qunused_arguments = true;
        }
        if(vm.count("S")){
            m_S = true;
        }
        if(vm.count("Wa")){
            m_Wa = vm["Wa"].as<string>();
        }
        if(vm.count("Wl")){
            m_Wl = vm["Wl"].as<string>();
        }
        if(vm.count("Wp")){
            m_Wp = vm["Wp"].as<string>();
        }
        if(vm.count("Xanalyzer")){
            m_Xanalyzer = vm["Xanalyzer"].as<string>();
        }
        if(vm.count("Xassembler")){
            m_Xassembler = vm["Xassembler"].as<string>();
        }
        if(vm.count("Xclang")){
            m_Xclang = vm["Xclang"].as<string>();
        }
        if(vm.count("Xlinker")){
            m_Xlinker = vm["Xlinker"].as<string>();
        }
        if(vm.count("Xpreprocessor")){
            m_Xpreprocessor = vm["Xpreprocessor"].as<string>();
        }
        if(vm.count("arcmt-migrate-emit-errors")){
            m_arcmt_migrate_emit_errors = true;
        }
        if(vm.count("arcmt-migrate-report-output")){
            m_arcmt_migrate_report_output = vm["arcmt-migrate-report-output"].as<string>();
        }
        if(vm.count("c")){
            m_c = true;
        }
        if(vm.count("emit-ast")){
            m_emit_ast = true;
        }
        if(vm.count("emit-llvm")){
            m_emit_llvm = true;
        }
        if(vm.count("fcatch-undefined-behavior")){
            m_fcatch_undefined_behavior = true;
        }
        if(vm.count("flimit-debug-info")){
            m_flimit_debug_info = true;
        }
        if(vm.count("fno-limit-debug-info")){
            m_fno_limit_debug_info = true;
        }
        if(vm.count("ftrap-function")){
            m_ftrap_function = vm["ftrap-function"].as<string>();
        }
        if(vm.count("gcc-toolchain")){
            m_gcc_toolchain = vm["gcc-toolchain"].as<string>();
        }
        if(vm.count("objcmt-migrate-literals")){
            m_objcmt_migrate_literals = true;
        }
        if(vm.count("objcmt-migrate-subscripting")){
            m_objcmt_migrate_subscripting = true;
        }
        if(vm.count("o")){
            m_o = vm["o"].as<string>();
        }
        if(vm.count("pipe")){
            m_pipe = true;
        }
        if(vm.count("print-file-name")){
            m_print_file_name = vm["print-file-name"].as<string>();
        }
        if(vm.count("print-libgcc-file-name")){
            m_print_libgcc_file_name = true;
        }
        if(vm.count("print-prog-name")){
            m_print_prog_name = vm["print-prog-name"].as<string>();
        }
        if(vm.count("print-search-dirs")){
            m_print_search_dirs = true;
        }
        if(vm.count("rewrite-objc")){
            m_rewrite_objc = true;
        }
        if(vm.count("save-temps")){
            m_save_temps = true;
        }
        if(vm.count("target")){
            m_target = vm["target"].as<string>();
        }
        if(vm.count("time")){
            m_time = true;
        }
        if(vm.count("verify")){
            m_verify = true;
        }
        if(vm.count("v")){
            m_v = true;
        }
        if(vm.count("working-directory")){
            m_working_directory = vm["working-directory"].as<string>();
        }
    }//try
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }
}
