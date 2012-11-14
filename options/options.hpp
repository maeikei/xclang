#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_

#include <string>
using namespace std;
namespace xclang
{
    class XClangOptions
    {
    public:
        XClangOptions(int argc,const char** argv);
        ~XClangOptions();
    private:
        XClangOptions();
        void parseArgs(void);
    private:
        const int m_argc;
        const char** m_argv;
        string m_xclang_target;
    public:
        bool m_spspsp;
        bool m_analyze;
        bool m_help;
        bool m_migrate;
        bool m_relocatable_pch;
        string m_serialize_diagnostics;
        bool m_E;
        bool m_ObjCplusplus;
        bool m_ObjC;
        bool m_Qunused_arguments;
        bool m_S;
        string m_Wa;
        string m_Wl;
        string m_Wp;
        string m_Xanalyzer;
        string m_Xassembler;
        string m_Xclang;
        string m_Xlinker;
        string m_Xpreprocessor;
        bool m_arcmt_migrate_emit_errors;
        string m_arcmt_migrate_report_output;
        bool m_c;
        bool m_emit_ast;
        bool m_emit_llvm;
        bool m_fcatch_undefined_behavior;
        bool m_flimit_debug_info;
        bool m_fno_limit_debug_info;
        string m_ftrap_function;
        string m_gcc_toolchain;
        bool m_objcmt_migrate_literals;
        bool m_objcmt_migrate_subscripting;
        string m_o;
        bool m_pipe;
        string m_print_file_name;
        bool m_print_libgcc_file_name;
        string m_print_prog_name;
        bool m_print_search_dirs;
        bool m_rewrite_objc;
        bool m_save_temps;
        string m_target;
        bool m_time;
        bool m_verify;
        bool m_v;
        string m_working_directory;
    private:
        bool has_spspsp(void) const {
            return m_spspsp;
        }
        bool has_analyze(void) const {
            return m_analyze;
        }
        bool has_help(void) const {
            return m_help;
        }
        bool has_migrate(void) const {
            return m_migrate;
        }
        bool has_relocatable_pch(void) const {
            return m_relocatable_pch;
        }
        bool has_serialize_diagnostics(void) const {
            return m_serialize_diagnostics.empty();
        }
        string get_serialize_diagnostics(void) const {
            return m_serialize_diagnostics;
        }
        bool has_E(void) const {
            return m_E;
        }
        bool has_ObjCplusplus(void) const {
            return m_ObjCplusplus;
        }
        bool has_ObjC(void) const {
            return m_ObjC;
        }
        bool has_Qunused_arguments(void) const {
            return m_Qunused_arguments;
        }
        bool has_S(void) const {
            return m_S;
        }
        bool has_Wa(void) const {
            return m_Wa.empty();
        }
        string get_Wa(void) const {
            return m_Wa;
        }
        bool has_Wl(void) const {
            return m_Wl.empty();
        }
        string get_Wl(void) const {
            return m_Wl;
        }
        bool has_Wp(void) const {
            return m_Wp.empty();
        }
        string get_Wp(void) const {
            return m_Wp;
        }
        bool has_Xanalyzer(void) const {
            return m_Xanalyzer.empty();
        }
        string get_Xanalyzer(void) const {
            return m_Xanalyzer;
        }
        bool has_Xassembler(void) const {
            return m_Xassembler.empty();
        }
        string get_Xassembler(void) const {
            return m_Xassembler;
        }
        bool has_Xclang(void) const {
            return m_Xclang.empty();
        }
        string get_Xclang(void) const {
            return m_Xclang;
        }
        bool has_Xlinker(void) const {
            return m_Xlinker.empty();
        }
        string get_Xlinker(void) const {
            return m_Xlinker;
        }
        bool has_Xpreprocessor(void) const {
            return m_Xpreprocessor.empty();
        }
        string get_Xpreprocessor(void) const {
            return m_Xpreprocessor;
        }
        bool has_arcmt_migrate_emit_errors(void) const {
            return m_arcmt_migrate_emit_errors;
        }
        bool has_arcmt_migrate_report_output(void) const {
            return m_arcmt_migrate_report_output.empty();
        }
        string get_arcmt_migrate_report_output(void) const {
            return m_arcmt_migrate_report_output;
        }
        bool has_c(void) const {
            return m_c;
        }
        bool has_emit_ast(void) const {
            return m_emit_ast;
        }
        bool has_emit_llvm(void) const {
            return m_emit_llvm;
        }
        bool has_fcatch_undefined_behavior(void) const {
            return m_fcatch_undefined_behavior;
        }
        bool has_flimit_debug_info(void) const {
            return m_flimit_debug_info;
        }
        bool has_fno_limit_debug_info(void) const {
            return m_fno_limit_debug_info;
        }
        bool has_ftrap_function(void) const {
            return m_ftrap_function.empty();
        }
        string get_ftrap_function(void) const {
            return m_ftrap_function;
        }
        bool has_gcc_toolchain(void) const {
            return m_gcc_toolchain.empty();
        }
        string get_gcc_toolchain(void) const {
            return m_gcc_toolchain;
        }
        bool has_objcmt_migrate_literals(void) const {
            return m_objcmt_migrate_literals;
        }
        bool has_objcmt_migrate_subscripting(void) const {
            return m_objcmt_migrate_subscripting;
        }
        bool has_o(void) const {
            return m_o.empty();
        }
        string get_o(void) const {
            return m_o;
        }
        bool has_pipe(void) const {
            return m_pipe;
        }
        bool has_print_file_name(void) const {
            return m_print_file_name.empty();
        }
        string get_print_file_name(void) const {
            return m_print_file_name;
        }
        bool has_print_libgcc_file_name(void) const {
            return m_print_libgcc_file_name;
        }
        bool has_print_prog_name(void) const {
            return m_print_prog_name.empty();
        }
        string get_print_prog_name(void) const {
            return m_print_prog_name;
        }
        bool has_print_search_dirs(void) const {
            return m_print_search_dirs;
        }
        bool has_rewrite_objc(void) const {
            return m_rewrite_objc;
        }
        bool has_save_temps(void) const {
            return m_save_temps;
        }
        bool has_target(void) const {
            return m_target.empty();
        }
        string get_target(void) const {
            return m_target;
        }
        bool has_time(void) const {
            return m_time;
        }
        bool has_verify(void) const {
            return m_verify;
        }
        bool has_v(void) const {
            return m_v;
        }
        bool has_working_directory(void) const {
            return m_working_directory.empty();
        }
        string get_working_directory(void) const {
            return m_working_directory;
        }
    };
}
#endif // __OPTIONS_HPP_
