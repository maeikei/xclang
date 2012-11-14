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
    private:
        const int m_argc;
        const char** m_argv;
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
        bool m_CC;
        bool m_C;
        string m_D;
        bool m_Eonly;
        bool m_E;
        string m_F;
        bool m_H;
        string m_I;
        bool m_MG;
        bool m_MP;
        string m_MQ;
        string m_MT;
        bool m_Os;
        bool m_Oz;
        string m_O;
        bool m_P;
        bool m_S;
        string m_U;
        string m_Wlarge_by_value_copy;
        bool m_Wno_rewrite_macros;
        string m_add_plugin;
        string m_analyze_function;
        bool m_analyzer_checker_help;
        string m_analyzer_checker;
        string m_analyzer_constraints;
        string m_analyzer_disable_checker;
        bool m_analyzer_display_progress;
        bool m_analyzer_eagerly_assume;
        string m_analyzer_inline_max_function_size;
        string m_analyzer_inline_max_stack_depth;
        string m_analyzer_inlining_mode;
        string m_analyzer_ipa;
        string m_analyzer_max_loop;
        string m_analyzer_max_nodes;
        bool m_analyzer_no_eagerly_trim_egraph;
        bool m_analyzer_opt_analyze_headers;
        bool m_analyzer_opt_analyze_nested_blocks;
        string m_analyzer_output;
        string m_analyzer_purge;
        bool m_analyzer_stats;
        string m_analyzer_store;
        bool m_analyzer_viz_egraph_graphviz;
        bool m_analyzer_viz_egraph_ubigraph;
        bool m_analyze;
        bool m_arcmt_check;
        bool m_arcmt_migrate;
        bool m_arcmt_modify;
        bool m_ast_dump_xml;
        bool m_ast_dump;
        bool m_ast_merge;
        bool m_ast_print;
        bool m_ast_view;
        string m_backend_option;
        string m_c_isystem;
        bool m_cfg_add_implicit_dtors;
        bool m_cfg_add_initializers;
        string m_chain_include;
        bool m_cl_fast_relaxed_math;
        bool m_cl_finite_math_only;
        bool m_cl_mad_enable;
        bool m_cl_opt_disable;
        bool m_cl_single_precision_constant;
        string m_cl_std;
        bool m_cl_unsafe_math_optimizations;
        string m_code_completion_at;
        bool m_code_completion_macros;
        bool m_code_completion_patterns;
        string m_coverage_file;
        string m_cxx_abi;
        string m_cxx_isystem;
        bool m_dD;
        bool m_dM;
        string m_dependency_dot;
        string m_dependency_file;
        bool m_detailed_preprocessing_record;
        string m_diagnostic_log_file;
        bool m_disable_free;
        bool m_disable_llvm_optzns;
        bool m_disable_llvm_verifier;
        bool m_disable_red_zone;
        string m_dump_build_information;
        bool m_dump_deserialized_decls;
        bool m_dump_raw_tokens;
        bool m_dump_tokens;
        string m_dwarf_debug_flags;
        bool m_emit_codegen_only;
        bool m_emit_html;
        bool m_emit_llvm_bc;
        bool m_emit_llvm_only;
        bool m_emit_llvm;
        bool m_emit_module;
        bool m_emit_obj;
        bool m_emit_pch;
        bool m_emit_pth;
        string m_error_on_deserialized_decl;
        bool m_faddress_sanitizer;
        bool m_faltivec;
        bool m_fapple_kext;
        bool m_fapple_pragma_pack;
        bool m_fblocks_runtime_optional;
        bool m_fblocks;
        bool m_fborland_extensions;
        bool m_fcolor_diagnostics;
        bool m_fconst_strings;
        bool m_fconstant_string_class;
        string m_fconstexpr_backtrace_limit;
        string m_fconstexpr_depth;
        bool m_fcuda_is_device;
        bool m_fcxx_exceptions;
        bool m_fdata_sections;
        string m_fdebug_compilation_dir;
        bool m_fdebugger_cast_result_to_id;
        bool m_fdebugger_objc_literal;
        bool m_fdebugger_support;
        bool m_fdelayed_template_parsing;
        bool m_fdeprecated_macro;
        string m_fdiagnostics_format;
        bool m_fdiagnostics_parseable_fixits;
        bool m_fdiagnostics_print_source_range_info;
        string m_fdiagnostics_show_category;
        bool m_fdiagnostics_show_note_include_stack;
        bool m_fdiagnostics_show_option;
        bool m_fdisable_module_hash;
        bool m_fdollars_in_identifiers;
        bool m_fdump_record_layouts_simple;
        bool m_fdump_record_layouts;
        bool m_fdump_vtable_layouts;
        bool m_femit_all_decls;
        bool m_femit_coverage_data;
        bool m_femit_coverage_notes;
        string m_ferror_limit;
        bool m_fexceptions;
        bool m_ffake_address_space_map;
        bool m_ffast_math;
        bool m_fforbid_guard_variables;
        bool m_ffreestanding;
        bool m_ffunction_sections;
        bool m_fgnu_keywords;
        bool m_fgnu_runtime;
        bool m_fgnu89_inline;
        bool m_fhidden_weak_vtables;
        bool m_finstrument_functions;
        bool m_fix_only_warnings;
        bool m_fix_what_you_can;
        bool m_fixit_recompile;
        bool m_fixit_to_temporary;
        string m_fixit;
        bool m_fixit;
        string m_fmacro_backtrace_limit;
        bool m_fmath_errno;
        string m_fmessage_length;
        string m_fmodule_cache_path;
        string m_fmodule_name;
        bool m_fmodules;
        bool m_fms_compatibility;
        bool m_fms_extensions;
        string m_fmsc_version;
        bool m_fno_access_control;
        bool m_fno_assume_sane_operator_new;
        bool m_fno_bitfield_type_align;
        bool m_fno_builtin;
        bool m_fno_caret_diagnostics;
        bool m_fno_common;
        bool m_fno_const_strings;
        bool m_fno_constant_cfstrings;
        bool m_fno_deprecated_macro;
        bool m_fno_diagnostics_fixit_info;
        bool m_fno_diagnostics_show_note_include_stack;
        bool m_fno_dollars_in_identifiers;
        bool m_fno_dwarf_directory_asm;
        bool m_fno_dwarf2_cfi_asm;
        bool m_fno_elide_constructors;
        bool m_fno_gnu_keywords;
        bool m_fno_inline_functions;
        bool m_fno_inline;
        bool m_fno_lax_vector_conversions;
        bool m_fno_merge_all_constants;
        bool m_fno_objc_infer_related_result_type;
        bool m_fno_operator_names;
        bool m_fno_rtti;
        bool m_fno_show_column;
        bool m_fno_show_source_location;
        bool m_fno_signed_char;
        bool m_fno_spell_checking;
        bool m_fno_threadsafe_statics;
        bool m_fno_use_cxa_atexit;
        bool m_fno_validate_pch;
        string m_fobjc_arc_cxxlib;
        bool m_fobjc_arc_exceptions;
        bool m_fobjc_arc;
        bool m_fobjc_default_synthesize_properties;
        string m_fobjc_dispatch_method;
        bool m_fobjc_exceptions;
        bool m_fobjc_fragile_abi;
        bool m_fobjc_gc_only;
        bool m_fobjc_gc;
        bool m_fobjc_runtime_has_arc;
        bool m_fobjc_runtime_has_terminate;
        bool m_fobjc_runtime_has_weak;
        string m_foverride_record_layout;
        string m_fpack_struct;
        bool m_fpascal_strings;
        bool m_fshort_enums;
        bool m_fshort_wchar;
        bool m_fshow_column;
        string m_fshow_overloads;
        bool m_fsjlj_exceptions;
        bool m_fsyntax_only;
        string m_ftabstop;
        string m_ftemplate_backtrace_limit;
        string m_ftemplate_depth;
        bool m_ftime_report;
        bool m_ftrapv_handler;
        bool m_ftrapv;
        bool m_funknown_anytype;
        bool m_funroll_loops;
        bool m_fuse_register_sized_bitfield_access;
        bool m_fvisibility_inlines_hidden;
        string m_fvisibility;
        bool m_fwrapv;
        bool m_fwritable_strings;
        bool m_g;
        string m_header_include_file;
        bool m_help;
        string m_idirafter;
        string m_iframework;
        string m_imacros;
        string m_include_pch;
        string m_include_pth;
        string m_include;
        bool m_index_header_map;
        bool m_init_only;
        string m_internal_externc_isystem;
        string m_internal_isystem;
        string m_iprefix;
        string m_iquote;
        string m_isysroot;
        string m_isystem;
        string m_iwithprefixbefore;
        string m_iwithprefix;
        string m_iwithsysroot;
        string m_load;
        string m_main_file_name;
        bool m_masm_verbose;
        string m_mcode_model;
        bool m_mconstructor_aliases;
        string m_mdebug_pass;
        bool m_mdisable_fp_elim;
        bool m_mdisable_tail_calls;
        bool m_menable_no_infs;
        bool m_menable_no_nans;
        bool m_menable_unsafe_fp_math;
        string m_mfloat_abi;
        bool m_migrate;
        string m_mlimit_float_precision;
        string m_mlink_bitcode_file;
        string m_mllvm;
        bool m_mms_bitfields;
        bool m_mno_global_merge;
        bool m_mno_zero_initialized_in_bss;
        bool m_mnoexecstack;
        bool m_momit_leaf_frame_pointer;
        bool m_mqdsp6_compat;
        string m_mregparm;
        bool m_mrelax_all;
        string m_mrelocation_model;
        bool m_mrtd;
        bool m_msave_temp_labels;
        bool m_msoft_float;
        string m_mstack_alignment;
        bool m_mstackrealign;
        string m_mt_migrate_directory;
        bool m_munwind_tables;
        bool m_no_code_completion_globals;
        bool m_no_finalize_removal;
        bool m_no_implicit_float;
        bool m_no_ns_alloc_error;
        bool m_nobuiltininc;
        bool m_nostdincplusplus;
        bool m_nostdsysteminc;
        string m_objc_isystem;
        string m_objcxx_isystem;
        string m_o;
        bool m_pg;
        string m_pic_level;
        string m_plugin_arg;
        string m_plugin;
        string m_preamble_bytes;
        bool m_print_decl_contexts;
        bool m_print_ivar_layout;
        bool m_print_preamble;
        bool m_print_stats;
        bool m_pthread;
        bool m_pubnames_dump;
        bool m_relaxed_aliasing;
        bool m_relocatable_pch;
        string m_remap_file;
        string m_resource_dir;
        bool m_rewrite_macros;
        bool m_rewrite_objc;
        bool m_rewrite_test;
        string m_serialize_diagnostic_file;
        string m_stack_protector;
        bool m_static_define;
        string m_std;
        string m_stdlib;
        bool m_sys_header_deps;
        string m_target_abi;
        string m_target_cpu;
        string m_target_feature;
        string m_target_linker_version;
        string m_token_cache;
        bool m_traditional_cpp;
        bool m_trigraphs;
        bool m_trim_egraph;
        string m_triple;
        bool m_undef;
        bool m_unoptimized_cfg;
        bool m_verify;
        bool m_version;
        bool m_v;
        bool m_w;
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
            return m_serialize_diagnostics.empty();
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
            return m_Wa.empty();
        }
        bool has_Wl(void) const {
            return m_Wl.empty();
        }
        string get_Wl(void) const {
            return m_Wl.empty();
        }
        bool has_Wp(void) const {
            return m_Wp.empty();
        }
        string get_Wp(void) const {
            return m_Wp.empty();
        }
        bool has_Xanalyzer(void) const {
            return m_Xanalyzer.empty();
        }
        string get_Xanalyzer(void) const {
            return m_Xanalyzer.empty();
        }
        bool has_Xassembler(void) const {
            return m_Xassembler.empty();
        }
        string get_Xassembler(void) const {
            return m_Xassembler.empty();
        }
        bool has_Xclang(void) const {
            return m_Xclang.empty();
        }
        string get_Xclang(void) const {
            return m_Xclang.empty();
        }
        bool has_Xlinker(void) const {
            return m_Xlinker.empty();
        }
        string get_Xlinker(void) const {
            return m_Xlinker.empty();
        }
        bool has_Xpreprocessor(void) const {
            return m_Xpreprocessor.empty();
        }
        string get_Xpreprocessor(void) const {
            return m_Xpreprocessor.empty();
        }
        bool has_arcmt_migrate_emit_errors(void) const {
            return m_arcmt_migrate_emit_errors;
        }
        bool has_arcmt_migrate_report_output(void) const {
            return m_arcmt_migrate_report_output.empty();
        }
        string get_arcmt_migrate_report_output(void) const {
            return m_arcmt_migrate_report_output.empty();
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
            return m_ftrap_function.empty();
        }
        bool has_gcc_toolchain(void) const {
            return m_gcc_toolchain.empty();
        }
        string get_gcc_toolchain(void) const {
            return m_gcc_toolchain.empty();
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
            return m_o.empty();
        }
        bool has_pipe(void) const {
            return m_pipe;
        }
        bool has_print_file_name(void) const {
            return m_print_file_name.empty();
        }
        string get_print_file_name(void) const {
            return m_print_file_name.empty();
        }
        bool has_print_libgcc_file_name(void) const {
            return m_print_libgcc_file_name;
        }
        bool has_print_prog_name(void) const {
            return m_print_prog_name.empty();
        }
        string get_print_prog_name(void) const {
            return m_print_prog_name.empty();
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
            return m_target.empty();
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
            return m_working_directory.empty();
        }
        bool has_CC(void) const {
            return m_CC;
        }
        bool has_C(void) const {
            return m_C;
        }
        bool has_D(void) const {
            return m_D.empty();
        }
        string get_D(void) const {
            return m_D.empty();
        }
        bool has_Eonly(void) const {
            return m_Eonly;
        }
        bool has_E(void) const {
            return m_E;
        }
        bool has_F(void) const {
            return m_F.empty();
        }
        string get_F(void) const {
            return m_F.empty();
        }
        bool has_H(void) const {
            return m_H;
        }
        bool has_I(void) const {
            return m_I.empty();
        }
        string get_I(void) const {
            return m_I.empty();
        }
        bool has_MG(void) const {
            return m_MG;
        }
        bool has_MP(void) const {
            return m_MP;
        }
        bool has_MQ(void) const {
            return m_MQ.empty();
        }
        string get_MQ(void) const {
            return m_MQ.empty();
        }
        bool has_MT(void) const {
            return m_MT.empty();
        }
        string get_MT(void) const {
            return m_MT.empty();
        }
        bool has_Os(void) const {
            return m_Os;
        }
        bool has_Oz(void) const {
            return m_Oz;
        }
        bool has_O(void) const {
            return m_O.empty();
        }
        string get_O(void) const {
            return m_O.empty();
        }
        bool has_P(void) const {
            return m_P;
        }
        bool has_S(void) const {
            return m_S;
        }
        bool has_U(void) const {
            return m_U.empty();
        }
        string get_U(void) const {
            return m_U.empty();
        }
        bool has_Wlarge_by_value_copy(void) const {
            return m_Wlarge_by_value_copy.empty();
        }
        string get_Wlarge_by_value_copy(void) const {
            return m_Wlarge_by_value_copy.empty();
        }
        bool has_Wno_rewrite_macros(void) const {
            return m_Wno_rewrite_macros;
        }
        bool has_add_plugin(void) const {
            return m_add_plugin.empty();
        }
        string get_add_plugin(void) const {
            return m_add_plugin.empty();
        }
        bool has_analyze_function(void) const {
            return m_analyze_function.empty();
        }
        string get_analyze_function(void) const {
            return m_analyze_function.empty();
        }
        bool has_analyzer_checker_help(void) const {
            return m_analyzer_checker_help;
        }
        bool has_analyzer_checker(void) const {
            return m_analyzer_checker.empty();
        }
        string get_analyzer_checker(void) const {
            return m_analyzer_checker.empty();
        }
        bool has_analyzer_constraints(void) const {
            return m_analyzer_constraints.empty();
        }
        string get_analyzer_constraints(void) const {
            return m_analyzer_constraints.empty();
        }
        bool has_analyzer_disable_checker(void) const {
            return m_analyzer_disable_checker.empty();
        }
        string get_analyzer_disable_checker(void) const {
            return m_analyzer_disable_checker.empty();
        }
        bool has_analyzer_display_progress(void) const {
            return m_analyzer_display_progress;
        }
        bool has_analyzer_eagerly_assume(void) const {
            return m_analyzer_eagerly_assume;
        }
        bool has_analyzer_inline_max_function_size(void) const {
            return m_analyzer_inline_max_function_size.empty();
        }
        string get_analyzer_inline_max_function_size(void) const {
            return m_analyzer_inline_max_function_size.empty();
        }
        bool has_analyzer_inline_max_stack_depth(void) const {
            return m_analyzer_inline_max_stack_depth.empty();
        }
        string get_analyzer_inline_max_stack_depth(void) const {
            return m_analyzer_inline_max_stack_depth.empty();
        }
        bool has_analyzer_inlining_mode(void) const {
            return m_analyzer_inlining_mode.empty();
        }
        string get_analyzer_inlining_mode(void) const {
            return m_analyzer_inlining_mode.empty();
        }
        bool has_analyzer_ipa(void) const {
            return m_analyzer_ipa.empty();
        }
        string get_analyzer_ipa(void) const {
            return m_analyzer_ipa.empty();
        }
        bool has_analyzer_max_loop(void) const {
            return m_analyzer_max_loop.empty();
        }
        string get_analyzer_max_loop(void) const {
            return m_analyzer_max_loop.empty();
        }
        bool has_analyzer_max_nodes(void) const {
            return m_analyzer_max_nodes.empty();
        }
        string get_analyzer_max_nodes(void) const {
            return m_analyzer_max_nodes.empty();
        }
        bool has_analyzer_no_eagerly_trim_egraph(void) const {
            return m_analyzer_no_eagerly_trim_egraph;
        }
        bool has_analyzer_opt_analyze_headers(void) const {
            return m_analyzer_opt_analyze_headers;
        }
        bool has_analyzer_opt_analyze_nested_blocks(void) const {
            return m_analyzer_opt_analyze_nested_blocks;
        }
        bool has_analyzer_output(void) const {
            return m_analyzer_output.empty();
        }
        string get_analyzer_output(void) const {
            return m_analyzer_output.empty();
        }
        bool has_analyzer_purge(void) const {
            return m_analyzer_purge.empty();
        }
        string get_analyzer_purge(void) const {
            return m_analyzer_purge.empty();
        }
        bool has_analyzer_stats(void) const {
            return m_analyzer_stats;
        }
        bool has_analyzer_store(void) const {
            return m_analyzer_store.empty();
        }
        string get_analyzer_store(void) const {
            return m_analyzer_store.empty();
        }
        bool has_analyzer_viz_egraph_graphviz(void) const {
            return m_analyzer_viz_egraph_graphviz;
        }
        bool has_analyzer_viz_egraph_ubigraph(void) const {
            return m_analyzer_viz_egraph_ubigraph;
        }
        bool has_analyze(void) const {
            return m_analyze;
        }
        bool has_arcmt_check(void) const {
            return m_arcmt_check;
        }
        bool has_arcmt_migrate(void) const {
            return m_arcmt_migrate;
        }
        bool has_arcmt_modify(void) const {
            return m_arcmt_modify;
        }
        bool has_ast_dump_xml(void) const {
            return m_ast_dump_xml;
        }
        bool has_ast_dump(void) const {
            return m_ast_dump;
        }
        bool has_ast_merge(void) const {
            return m_ast_merge;
        }
        bool has_ast_print(void) const {
            return m_ast_print;
        }
        bool has_ast_view(void) const {
            return m_ast_view;
        }
        bool has_backend_option(void) const {
            return m_backend_option.empty();
        }
        string get_backend_option(void) const {
            return m_backend_option.empty();
        }
        bool has_c_isystem(void) const {
            return m_c_isystem.empty();
        }
        string get_c_isystem(void) const {
            return m_c_isystem.empty();
        }
        bool has_cfg_add_implicit_dtors(void) const {
            return m_cfg_add_implicit_dtors;
        }
        bool has_cfg_add_initializers(void) const {
            return m_cfg_add_initializers;
        }
        bool has_chain_include(void) const {
            return m_chain_include.empty();
        }
        string get_chain_include(void) const {
            return m_chain_include.empty();
        }
        bool has_cl_fast_relaxed_math(void) const {
            return m_cl_fast_relaxed_math;
        }
        bool has_cl_finite_math_only(void) const {
            return m_cl_finite_math_only;
        }
        bool has_cl_mad_enable(void) const {
            return m_cl_mad_enable;
        }
        bool has_cl_opt_disable(void) const {
            return m_cl_opt_disable;
        }
        bool has_cl_single_precision_constant(void) const {
            return m_cl_single_precision_constant;
        }
        bool has_cl_std(void) const {
            return m_cl_std.empty();
        }
        string get_cl_std(void) const {
            return m_cl_std.empty();
        }
        bool has_cl_unsafe_math_optimizations(void) const {
            return m_cl_unsafe_math_optimizations;
        }
        bool has_code_completion_at(void) const {
            return m_code_completion_at.empty();
        }
        string get_code_completion_at(void) const {
            return m_code_completion_at.empty();
        }
        bool has_code_completion_macros(void) const {
            return m_code_completion_macros;
        }
        bool has_code_completion_patterns(void) const {
            return m_code_completion_patterns;
        }
        bool has_coverage_file(void) const {
            return m_coverage_file.empty();
        }
        string get_coverage_file(void) const {
            return m_coverage_file.empty();
        }
        bool has_cxx_abi(void) const {
            return m_cxx_abi.empty();
        }
        string get_cxx_abi(void) const {
            return m_cxx_abi.empty();
        }
        bool has_cxx_isystem(void) const {
            return m_cxx_isystem.empty();
        }
        string get_cxx_isystem(void) const {
            return m_cxx_isystem.empty();
        }
        bool has_dD(void) const {
            return m_dD;
        }
        bool has_dM(void) const {
            return m_dM;
        }
        bool has_dependency_dot(void) const {
            return m_dependency_dot.empty();
        }
        string get_dependency_dot(void) const {
            return m_dependency_dot.empty();
        }
        bool has_dependency_file(void) const {
            return m_dependency_file.empty();
        }
        string get_dependency_file(void) const {
            return m_dependency_file.empty();
        }
        bool has_detailed_preprocessing_record(void) const {
            return m_detailed_preprocessing_record;
        }
        bool has_diagnostic_log_file(void) const {
            return m_diagnostic_log_file.empty();
        }
        string get_diagnostic_log_file(void) const {
            return m_diagnostic_log_file.empty();
        }
        bool has_disable_free(void) const {
            return m_disable_free;
        }
        bool has_disable_llvm_optzns(void) const {
            return m_disable_llvm_optzns;
        }
        bool has_disable_llvm_verifier(void) const {
            return m_disable_llvm_verifier;
        }
        bool has_disable_red_zone(void) const {
            return m_disable_red_zone;
        }
        bool has_dump_build_information(void) const {
            return m_dump_build_information.empty();
        }
        string get_dump_build_information(void) const {
            return m_dump_build_information.empty();
        }
        bool has_dump_deserialized_decls(void) const {
            return m_dump_deserialized_decls;
        }
        bool has_dump_raw_tokens(void) const {
            return m_dump_raw_tokens;
        }
        bool has_dump_tokens(void) const {
            return m_dump_tokens;
        }
        bool has_dwarf_debug_flags(void) const {
            return m_dwarf_debug_flags.empty();
        }
        string get_dwarf_debug_flags(void) const {
            return m_dwarf_debug_flags.empty();
        }
        bool has_emit_codegen_only(void) const {
            return m_emit_codegen_only;
        }
        bool has_emit_html(void) const {
            return m_emit_html;
        }
        bool has_emit_llvm_bc(void) const {
            return m_emit_llvm_bc;
        }
        bool has_emit_llvm_only(void) const {
            return m_emit_llvm_only;
        }
        bool has_emit_llvm(void) const {
            return m_emit_llvm;
        }
        bool has_emit_module(void) const {
            return m_emit_module;
        }
        bool has_emit_obj(void) const {
            return m_emit_obj;
        }
        bool has_emit_pch(void) const {
            return m_emit_pch;
        }
        bool has_emit_pth(void) const {
            return m_emit_pth;
        }
        bool has_error_on_deserialized_decl(void) const {
            return m_error_on_deserialized_decl.empty();
        }
        string get_error_on_deserialized_decl(void) const {
            return m_error_on_deserialized_decl.empty();
        }
        bool has_faddress_sanitizer(void) const {
            return m_faddress_sanitizer;
        }
        bool has_faltivec(void) const {
            return m_faltivec;
        }
        bool has_fapple_kext(void) const {
            return m_fapple_kext;
        }
        bool has_fapple_pragma_pack(void) const {
            return m_fapple_pragma_pack;
        }
        bool has_fblocks_runtime_optional(void) const {
            return m_fblocks_runtime_optional;
        }
        bool has_fblocks(void) const {
            return m_fblocks;
        }
        bool has_fborland_extensions(void) const {
            return m_fborland_extensions;
        }
        bool has_fcolor_diagnostics(void) const {
            return m_fcolor_diagnostics;
        }
        bool has_fconst_strings(void) const {
            return m_fconst_strings;
        }
        bool has_fconstant_string_class(void) const {
            return m_fconstant_string_class;
        }
        bool has_fconstexpr_backtrace_limit(void) const {
            return m_fconstexpr_backtrace_limit.empty();
        }
        string get_fconstexpr_backtrace_limit(void) const {
            return m_fconstexpr_backtrace_limit.empty();
        }
        bool has_fconstexpr_depth(void) const {
            return m_fconstexpr_depth.empty();
        }
        string get_fconstexpr_depth(void) const {
            return m_fconstexpr_depth.empty();
        }
        bool has_fcuda_is_device(void) const {
            return m_fcuda_is_device;
        }
        bool has_fcxx_exceptions(void) const {
            return m_fcxx_exceptions;
        }
        bool has_fdata_sections(void) const {
            return m_fdata_sections;
        }
        bool has_fdebug_compilation_dir(void) const {
            return m_fdebug_compilation_dir.empty();
        }
        string get_fdebug_compilation_dir(void) const {
            return m_fdebug_compilation_dir.empty();
        }
        bool has_fdebugger_cast_result_to_id(void) const {
            return m_fdebugger_cast_result_to_id;
        }
        bool has_fdebugger_objc_literal(void) const {
            return m_fdebugger_objc_literal;
        }
        bool has_fdebugger_support(void) const {
            return m_fdebugger_support;
        }
        bool has_fdelayed_template_parsing(void) const {
            return m_fdelayed_template_parsing;
        }
        bool has_fdeprecated_macro(void) const {
            return m_fdeprecated_macro;
        }
        bool has_fdiagnostics_format(void) const {
            return m_fdiagnostics_format.empty();
        }
        string get_fdiagnostics_format(void) const {
            return m_fdiagnostics_format.empty();
        }
        bool has_fdiagnostics_parseable_fixits(void) const {
            return m_fdiagnostics_parseable_fixits;
        }
        bool has_fdiagnostics_print_source_range_info(void) const {
            return m_fdiagnostics_print_source_range_info;
        }
        bool has_fdiagnostics_show_category(void) const {
            return m_fdiagnostics_show_category.empty();
        }
        string get_fdiagnostics_show_category(void) const {
            return m_fdiagnostics_show_category.empty();
        }
        bool has_fdiagnostics_show_note_include_stack(void) const {
            return m_fdiagnostics_show_note_include_stack;
        }
        bool has_fdiagnostics_show_option(void) const {
            return m_fdiagnostics_show_option;
        }
        bool has_fdisable_module_hash(void) const {
            return m_fdisable_module_hash;
        }
        bool has_fdollars_in_identifiers(void) const {
            return m_fdollars_in_identifiers;
        }
        bool has_fdump_record_layouts_simple(void) const {
            return m_fdump_record_layouts_simple;
        }
        bool has_fdump_record_layouts(void) const {
            return m_fdump_record_layouts;
        }
        bool has_fdump_vtable_layouts(void) const {
            return m_fdump_vtable_layouts;
        }
        bool has_femit_all_decls(void) const {
            return m_femit_all_decls;
        }
        bool has_femit_coverage_data(void) const {
            return m_femit_coverage_data;
        }
        bool has_femit_coverage_notes(void) const {
            return m_femit_coverage_notes;
        }
        bool has_ferror_limit(void) const {
            return m_ferror_limit.empty();
        }
        string get_ferror_limit(void) const {
            return m_ferror_limit.empty();
        }
        bool has_fexceptions(void) const {
            return m_fexceptions;
        }
        bool has_ffake_address_space_map(void) const {
            return m_ffake_address_space_map;
        }
        bool has_ffast_math(void) const {
            return m_ffast_math;
        }
        bool has_fforbid_guard_variables(void) const {
            return m_fforbid_guard_variables;
        }
        bool has_ffreestanding(void) const {
            return m_ffreestanding;
        }
        bool has_ffunction_sections(void) const {
            return m_ffunction_sections;
        }
        bool has_fgnu_keywords(void) const {
            return m_fgnu_keywords;
        }
        bool has_fgnu_runtime(void) const {
            return m_fgnu_runtime;
        }
        bool has_fgnu89_inline(void) const {
            return m_fgnu89_inline;
        }
        bool has_fhidden_weak_vtables(void) const {
            return m_fhidden_weak_vtables;
        }
        bool has_finstrument_functions(void) const {
            return m_finstrument_functions;
        }
        bool has_fix_only_warnings(void) const {
            return m_fix_only_warnings;
        }
        bool has_fix_what_you_can(void) const {
            return m_fix_what_you_can;
        }
        bool has_fixit_recompile(void) const {
            return m_fixit_recompile;
        }
        bool has_fixit_to_temporary(void) const {
            return m_fixit_to_temporary;
        }
        bool has_fixit(void) const {
            return m_fixit.empty();
        }
        string get_fixit(void) const {
            return m_fixit.empty();
        }
        bool has_fixit(void) const {
            return m_fixit;
        }
        bool has_fmacro_backtrace_limit(void) const {
            return m_fmacro_backtrace_limit.empty();
        }
        string get_fmacro_backtrace_limit(void) const {
            return m_fmacro_backtrace_limit.empty();
        }
        bool has_fmath_errno(void) const {
            return m_fmath_errno;
        }
        bool has_fmessage_length(void) const {
            return m_fmessage_length.empty();
        }
        string get_fmessage_length(void) const {
            return m_fmessage_length.empty();
        }
        bool has_fmodule_cache_path(void) const {
            return m_fmodule_cache_path.empty();
        }
        string get_fmodule_cache_path(void) const {
            return m_fmodule_cache_path.empty();
        }
        bool has_fmodule_name(void) const {
            return m_fmodule_name.empty();
        }
        string get_fmodule_name(void) const {
            return m_fmodule_name.empty();
        }
        bool has_fmodules(void) const {
            return m_fmodules;
        }
        bool has_fms_compatibility(void) const {
            return m_fms_compatibility;
        }
        bool has_fms_extensions(void) const {
            return m_fms_extensions;
        }
        bool has_fmsc_version(void) const {
            return m_fmsc_version.empty();
        }
        string get_fmsc_version(void) const {
            return m_fmsc_version.empty();
        }
        bool has_fno_access_control(void) const {
            return m_fno_access_control;
        }
        bool has_fno_assume_sane_operator_new(void) const {
            return m_fno_assume_sane_operator_new;
        }
        bool has_fno_bitfield_type_align(void) const {
            return m_fno_bitfield_type_align;
        }
        bool has_fno_builtin(void) const {
            return m_fno_builtin;
        }
        bool has_fno_caret_diagnostics(void) const {
            return m_fno_caret_diagnostics;
        }
        bool has_fno_common(void) const {
            return m_fno_common;
        }
        bool has_fno_const_strings(void) const {
            return m_fno_const_strings;
        }
        bool has_fno_constant_cfstrings(void) const {
            return m_fno_constant_cfstrings;
        }
        bool has_fno_deprecated_macro(void) const {
            return m_fno_deprecated_macro;
        }
        bool has_fno_diagnostics_fixit_info(void) const {
            return m_fno_diagnostics_fixit_info;
        }
        bool has_fno_diagnostics_show_note_include_stack(void) const {
            return m_fno_diagnostics_show_note_include_stack;
        }
        bool has_fno_dollars_in_identifiers(void) const {
            return m_fno_dollars_in_identifiers;
        }
        bool has_fno_dwarf_directory_asm(void) const {
            return m_fno_dwarf_directory_asm;
        }
        bool has_fno_dwarf2_cfi_asm(void) const {
            return m_fno_dwarf2_cfi_asm;
        }
        bool has_fno_elide_constructors(void) const {
            return m_fno_elide_constructors;
        }
        bool has_fno_gnu_keywords(void) const {
            return m_fno_gnu_keywords;
        }
        bool has_fno_inline_functions(void) const {
            return m_fno_inline_functions;
        }
        bool has_fno_inline(void) const {
            return m_fno_inline;
        }
        bool has_fno_lax_vector_conversions(void) const {
            return m_fno_lax_vector_conversions;
        }
        bool has_fno_merge_all_constants(void) const {
            return m_fno_merge_all_constants;
        }
        bool has_fno_objc_infer_related_result_type(void) const {
            return m_fno_objc_infer_related_result_type;
        }
        bool has_fno_operator_names(void) const {
            return m_fno_operator_names;
        }
        bool has_fno_rtti(void) const {
            return m_fno_rtti;
        }
        bool has_fno_show_column(void) const {
            return m_fno_show_column;
        }
        bool has_fno_show_source_location(void) const {
            return m_fno_show_source_location;
        }
        bool has_fno_signed_char(void) const {
            return m_fno_signed_char;
        }
        bool has_fno_spell_checking(void) const {
            return m_fno_spell_checking;
        }
        bool has_fno_threadsafe_statics(void) const {
            return m_fno_threadsafe_statics;
        }
        bool has_fno_use_cxa_atexit(void) const {
            return m_fno_use_cxa_atexit;
        }
        bool has_fno_validate_pch(void) const {
            return m_fno_validate_pch;
        }
        bool has_fobjc_arc_cxxlib(void) const {
            return m_fobjc_arc_cxxlib.empty();
        }
        string get_fobjc_arc_cxxlib(void) const {
            return m_fobjc_arc_cxxlib.empty();
        }
        bool has_fobjc_arc_exceptions(void) const {
            return m_fobjc_arc_exceptions;
        }
        bool has_fobjc_arc(void) const {
            return m_fobjc_arc;
        }
        bool has_fobjc_default_synthesize_properties(void) const {
            return m_fobjc_default_synthesize_properties;
        }
        bool has_fobjc_dispatch_method(void) const {
            return m_fobjc_dispatch_method.empty();
        }
        string get_fobjc_dispatch_method(void) const {
            return m_fobjc_dispatch_method.empty();
        }
        bool has_fobjc_exceptions(void) const {
            return m_fobjc_exceptions;
        }
        bool has_fobjc_fragile_abi(void) const {
            return m_fobjc_fragile_abi;
        }
        bool has_fobjc_gc_only(void) const {
            return m_fobjc_gc_only;
        }
        bool has_fobjc_gc(void) const {
            return m_fobjc_gc;
        }
        bool has_fobjc_runtime_has_arc(void) const {
            return m_fobjc_runtime_has_arc;
        }
        bool has_fobjc_runtime_has_terminate(void) const {
            return m_fobjc_runtime_has_terminate;
        }
        bool has_fobjc_runtime_has_weak(void) const {
            return m_fobjc_runtime_has_weak;
        }
        bool has_foverride_record_layout(void) const {
            return m_foverride_record_layout.empty();
        }
        string get_foverride_record_layout(void) const {
            return m_foverride_record_layout.empty();
        }
        bool has_fpack_struct(void) const {
            return m_fpack_struct.empty();
        }
        string get_fpack_struct(void) const {
            return m_fpack_struct.empty();
        }
        bool has_fpascal_strings(void) const {
            return m_fpascal_strings;
        }
        bool has_fshort_enums(void) const {
            return m_fshort_enums;
        }
        bool has_fshort_wchar(void) const {
            return m_fshort_wchar;
        }
        bool has_fshow_column(void) const {
            return m_fshow_column;
        }
        bool has_fshow_overloads(void) const {
            return m_fshow_overloads.empty();
        }
        string get_fshow_overloads(void) const {
            return m_fshow_overloads.empty();
        }
        bool has_fsjlj_exceptions(void) const {
            return m_fsjlj_exceptions;
        }
        bool has_fsyntax_only(void) const {
            return m_fsyntax_only;
        }
        bool has_ftabstop(void) const {
            return m_ftabstop.empty();
        }
        string get_ftabstop(void) const {
            return m_ftabstop.empty();
        }
        bool has_ftemplate_backtrace_limit(void) const {
            return m_ftemplate_backtrace_limit.empty();
        }
        string get_ftemplate_backtrace_limit(void) const {
            return m_ftemplate_backtrace_limit.empty();
        }
        bool has_ftemplate_depth(void) const {
            return m_ftemplate_depth.empty();
        }
        string get_ftemplate_depth(void) const {
            return m_ftemplate_depth.empty();
        }
        bool has_ftime_report(void) const {
            return m_ftime_report;
        }
        bool has_ftrapv_handler(void) const {
            return m_ftrapv_handler;
        }
        bool has_ftrapv(void) const {
            return m_ftrapv;
        }
        bool has_funknown_anytype(void) const {
            return m_funknown_anytype;
        }
        bool has_funroll_loops(void) const {
            return m_funroll_loops;
        }
        bool has_fuse_register_sized_bitfield_access(void) const {
            return m_fuse_register_sized_bitfield_access;
        }
        bool has_fvisibility_inlines_hidden(void) const {
            return m_fvisibility_inlines_hidden;
        }
        bool has_fvisibility(void) const {
            return m_fvisibility.empty();
        }
        string get_fvisibility(void) const {
            return m_fvisibility.empty();
        }
        bool has_fwrapv(void) const {
            return m_fwrapv;
        }
        bool has_fwritable_strings(void) const {
            return m_fwritable_strings;
        }
        bool has_g(void) const {
            return m_g;
        }
        bool has_header_include_file(void) const {
            return m_header_include_file.empty();
        }
        string get_header_include_file(void) const {
            return m_header_include_file.empty();
        }
        bool has_help(void) const {
            return m_help;
        }
        bool has_idirafter(void) const {
            return m_idirafter.empty();
        }
        string get_idirafter(void) const {
            return m_idirafter.empty();
        }
        bool has_iframework(void) const {
            return m_iframework.empty();
        }
        string get_iframework(void) const {
            return m_iframework.empty();
        }
        bool has_imacros(void) const {
            return m_imacros.empty();
        }
        string get_imacros(void) const {
            return m_imacros.empty();
        }
        bool has_include_pch(void) const {
            return m_include_pch.empty();
        }
        string get_include_pch(void) const {
            return m_include_pch.empty();
        }
        bool has_include_pth(void) const {
            return m_include_pth.empty();
        }
        string get_include_pth(void) const {
            return m_include_pth.empty();
        }
        bool has_include(void) const {
            return m_include.empty();
        }
        string get_include(void) const {
            return m_include.empty();
        }
        bool has_index_header_map(void) const {
            return m_index_header_map;
        }
        bool has_init_only(void) const {
            return m_init_only;
        }
        bool has_internal_externc_isystem(void) const {
            return m_internal_externc_isystem.empty();
        }
        string get_internal_externc_isystem(void) const {
            return m_internal_externc_isystem.empty();
        }
        bool has_internal_isystem(void) const {
            return m_internal_isystem.empty();
        }
        string get_internal_isystem(void) const {
            return m_internal_isystem.empty();
        }
        bool has_iprefix(void) const {
            return m_iprefix.empty();
        }
        string get_iprefix(void) const {
            return m_iprefix.empty();
        }
        bool has_iquote(void) const {
            return m_iquote.empty();
        }
        string get_iquote(void) const {
            return m_iquote.empty();
        }
        bool has_isysroot(void) const {
            return m_isysroot.empty();
        }
        string get_isysroot(void) const {
            return m_isysroot.empty();
        }
        bool has_isystem(void) const {
            return m_isystem.empty();
        }
        string get_isystem(void) const {
            return m_isystem.empty();
        }
        bool has_iwithprefixbefore(void) const {
            return m_iwithprefixbefore.empty();
        }
        string get_iwithprefixbefore(void) const {
            return m_iwithprefixbefore.empty();
        }
        bool has_iwithprefix(void) const {
            return m_iwithprefix.empty();
        }
        string get_iwithprefix(void) const {
            return m_iwithprefix.empty();
        }
        bool has_iwithsysroot(void) const {
            return m_iwithsysroot.empty();
        }
        string get_iwithsysroot(void) const {
            return m_iwithsysroot.empty();
        }
        bool has_load(void) const {
            return m_load.empty();
        }
        string get_load(void) const {
            return m_load.empty();
        }
        bool has_main_file_name(void) const {
            return m_main_file_name.empty();
        }
        string get_main_file_name(void) const {
            return m_main_file_name.empty();
        }
        bool has_masm_verbose(void) const {
            return m_masm_verbose;
        }
        bool has_mcode_model(void) const {
            return m_mcode_model.empty();
        }
        string get_mcode_model(void) const {
            return m_mcode_model.empty();
        }
        bool has_mconstructor_aliases(void) const {
            return m_mconstructor_aliases;
        }
        bool has_mdebug_pass(void) const {
            return m_mdebug_pass.empty();
        }
        string get_mdebug_pass(void) const {
            return m_mdebug_pass.empty();
        }
        bool has_mdisable_fp_elim(void) const {
            return m_mdisable_fp_elim;
        }
        bool has_mdisable_tail_calls(void) const {
            return m_mdisable_tail_calls;
        }
        bool has_menable_no_infs(void) const {
            return m_menable_no_infs;
        }
        bool has_menable_no_nans(void) const {
            return m_menable_no_nans;
        }
        bool has_menable_unsafe_fp_math(void) const {
            return m_menable_unsafe_fp_math;
        }
        bool has_mfloat_abi(void) const {
            return m_mfloat_abi.empty();
        }
        string get_mfloat_abi(void) const {
            return m_mfloat_abi.empty();
        }
        bool has_migrate(void) const {
            return m_migrate;
        }
        bool has_mlimit_float_precision(void) const {
            return m_mlimit_float_precision.empty();
        }
        string get_mlimit_float_precision(void) const {
            return m_mlimit_float_precision.empty();
        }
        bool has_mlink_bitcode_file(void) const {
            return m_mlink_bitcode_file.empty();
        }
        string get_mlink_bitcode_file(void) const {
            return m_mlink_bitcode_file.empty();
        }
        bool has_mllvm(void) const {
            return m_mllvm.empty();
        }
        string get_mllvm(void) const {
            return m_mllvm.empty();
        }
        bool has_mms_bitfields(void) const {
            return m_mms_bitfields;
        }
        bool has_mno_global_merge(void) const {
            return m_mno_global_merge;
        }
        bool has_mno_zero_initialized_in_bss(void) const {
            return m_mno_zero_initialized_in_bss;
        }
        bool has_mnoexecstack(void) const {
            return m_mnoexecstack;
        }
        bool has_momit_leaf_frame_pointer(void) const {
            return m_momit_leaf_frame_pointer;
        }
        bool has_mqdsp6_compat(void) const {
            return m_mqdsp6_compat;
        }
        bool has_mregparm(void) const {
            return m_mregparm.empty();
        }
        string get_mregparm(void) const {
            return m_mregparm.empty();
        }
        bool has_mrelax_all(void) const {
            return m_mrelax_all;
        }
        bool has_mrelocation_model(void) const {
            return m_mrelocation_model.empty();
        }
        string get_mrelocation_model(void) const {
            return m_mrelocation_model.empty();
        }
        bool has_mrtd(void) const {
            return m_mrtd;
        }
        bool has_msave_temp_labels(void) const {
            return m_msave_temp_labels;
        }
        bool has_msoft_float(void) const {
            return m_msoft_float;
        }
        bool has_mstack_alignment(void) const {
            return m_mstack_alignment.empty();
        }
        string get_mstack_alignment(void) const {
            return m_mstack_alignment.empty();
        }
        bool has_mstackrealign(void) const {
            return m_mstackrealign;
        }
        bool has_mt_migrate_directory(void) const {
            return m_mt_migrate_directory.empty();
        }
        string get_mt_migrate_directory(void) const {
            return m_mt_migrate_directory.empty();
        }
        bool has_munwind_tables(void) const {
            return m_munwind_tables;
        }
        bool has_no_code_completion_globals(void) const {
            return m_no_code_completion_globals;
        }
        bool has_no_finalize_removal(void) const {
            return m_no_finalize_removal;
        }
        bool has_no_implicit_float(void) const {
            return m_no_implicit_float;
        }
        bool has_no_ns_alloc_error(void) const {
            return m_no_ns_alloc_error;
        }
        bool has_nobuiltininc(void) const {
            return m_nobuiltininc;
        }
        bool has_nostdincplusplus(void) const {
            return m_nostdincplusplus;
        }
        bool has_nostdsysteminc(void) const {
            return m_nostdsysteminc;
        }
        bool has_objc_isystem(void) const {
            return m_objc_isystem.empty();
        }
        string get_objc_isystem(void) const {
            return m_objc_isystem.empty();
        }
        bool has_objcxx_isystem(void) const {
            return m_objcxx_isystem.empty();
        }
        string get_objcxx_isystem(void) const {
            return m_objcxx_isystem.empty();
        }
        bool has_o(void) const {
            return m_o.empty();
        }
        string get_o(void) const {
            return m_o.empty();
        }
        bool has_pg(void) const {
            return m_pg;
        }
        bool has_pic_level(void) const {
            return m_pic_level.empty();
        }
        string get_pic_level(void) const {
            return m_pic_level.empty();
        }
        bool has_plugin_arg(void) const {
            return m_plugin_arg.empty();
        }
        string get_plugin_arg(void) const {
            return m_plugin_arg.empty();
        }
        bool has_plugin(void) const {
            return m_plugin.empty();
        }
        string get_plugin(void) const {
            return m_plugin.empty();
        }
        bool has_preamble_bytes(void) const {
            return m_preamble_bytes.empty();
        }
        string get_preamble_bytes(void) const {
            return m_preamble_bytes.empty();
        }
        bool has_print_decl_contexts(void) const {
            return m_print_decl_contexts;
        }
        bool has_print_ivar_layout(void) const {
            return m_print_ivar_layout;
        }
        bool has_print_preamble(void) const {
            return m_print_preamble;
        }
        bool has_print_stats(void) const {
            return m_print_stats;
        }
        bool has_pthread(void) const {
            return m_pthread;
        }
        bool has_pubnames_dump(void) const {
            return m_pubnames_dump;
        }
        bool has_relaxed_aliasing(void) const {
            return m_relaxed_aliasing;
        }
        bool has_relocatable_pch(void) const {
            return m_relocatable_pch;
        }
        bool has_remap_file(void) const {
            return m_remap_file.empty();
        }
        string get_remap_file(void) const {
            return m_remap_file.empty();
        }
        bool has_resource_dir(void) const {
            return m_resource_dir.empty();
        }
        string get_resource_dir(void) const {
            return m_resource_dir.empty();
        }
        bool has_rewrite_macros(void) const {
            return m_rewrite_macros;
        }
        bool has_rewrite_objc(void) const {
            return m_rewrite_objc;
        }
        bool has_rewrite_test(void) const {
            return m_rewrite_test;
        }
        bool has_serialize_diagnostic_file(void) const {
            return m_serialize_diagnostic_file.empty();
        }
        string get_serialize_diagnostic_file(void) const {
            return m_serialize_diagnostic_file.empty();
        }
        bool has_stack_protector(void) const {
            return m_stack_protector.empty();
        }
        string get_stack_protector(void) const {
            return m_stack_protector.empty();
        }
        bool has_static_define(void) const {
            return m_static_define;
        }
        bool has_std(void) const {
            return m_std.empty();
        }
        string get_std(void) const {
            return m_std.empty();
        }
        bool has_stdlib(void) const {
            return m_stdlib.empty();
        }
        string get_stdlib(void) const {
            return m_stdlib.empty();
        }
        bool has_sys_header_deps(void) const {
            return m_sys_header_deps;
        }
        bool has_target_abi(void) const {
            return m_target_abi.empty();
        }
        string get_target_abi(void) const {
            return m_target_abi.empty();
        }
        bool has_target_cpu(void) const {
            return m_target_cpu.empty();
        }
        string get_target_cpu(void) const {
            return m_target_cpu.empty();
        }
        bool has_target_feature(void) const {
            return m_target_feature.empty();
        }
        string get_target_feature(void) const {
            return m_target_feature.empty();
        }
        bool has_target_linker_version(void) const {
            return m_target_linker_version.empty();
        }
        string get_target_linker_version(void) const {
            return m_target_linker_version.empty();
        }
        bool has_token_cache(void) const {
            return m_token_cache.empty();
        }
        string get_token_cache(void) const {
            return m_token_cache.empty();
        }
        bool has_traditional_cpp(void) const {
            return m_traditional_cpp;
        }
        bool has_trigraphs(void) const {
            return m_trigraphs;
        }
        bool has_trim_egraph(void) const {
            return m_trim_egraph;
        }
        bool has_triple(void) const {
            return m_triple.empty();
        }
        string get_triple(void) const {
            return m_triple.empty();
        }
        bool has_undef(void) const {
            return m_undef;
        }
        bool has_unoptimized_cfg(void) const {
            return m_unoptimized_cfg;
        }
        bool has_verify(void) const {
            return m_verify;
        }
        bool has_version(void) const {
            return m_version;
        }
        bool has_v(void) const {
            return m_v;
        }
        bool has_w(void) const {
            return m_w;
        }
    };
}
#endif // __OPTIONS_HPP_
