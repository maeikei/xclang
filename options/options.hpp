#ifndef __OPTIONS_HPP_
#define __OPTIONS_HPP_

#include <string>
#include <map>
using namespace std;
namespace xclang
{
    const int iConstOptionTypeAlone         =      0x1;
    const int iConstOptionTypeNextValue     =     0x10;
    const int iConstOptionTypeEQValue       =    0x100;
    const int iConstOptionTypeCommaValue    =   0x1000;
    const int iConstOptionTypeBarValue      =  0x10000;
    const int iConstOptionTypeValue         = 0x100000;

    
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
        static const map<string,int> m_clang_options;
        static const map<string,int> m_clang_cc1_options;
        string m_xclang_target;
        bool m__fshow_column;
        string m__Xassembler;
        bool m__v;
        string m__working_directory;
        bool m__nostdincplusplus;
        string m__chain_include;
        string m__main_file_name;
        bool m__fblocks_runtime_optional;
        bool m__rewrite_macros;
        bool m__fobjc_runtime_has_terminate;
        bool m__fdelayed_template_parsing;
        string m__include_pth;
        bool m__no_code_completion_globals;
        bool m__print_preamble;
        bool m__MG;
        bool m__fno_show_source_location;
        string m__Wp;
        bool m__ast_print;
        string m__U;
        string m__mstack_alignment;
        bool m__cl_single_precision_constant;
        string m__iwithprefix;
        bool m__CC;
        bool m__fix_only_warnings;
        bool m__objcmt_migrate_subscripting;
        bool m__fno_constant_cfstrings;
        string m__analyzer_max_loop;
        bool m__fno_diagnostics_show_note_include_stack;
        bool m___help;
        string m__fdiagnostics_format;
        bool m__Wno_rewrite_macros;
        bool m__fshort_enums;
        string m___serialize_diagnostics;
        bool m__Os;
        bool m__w;
        string m__c_isystem;
        string m__token_cache;
        bool m__fdebugger_objc_literal;
        string m__fmodule_name;
        bool m__sys_header_deps;
        bool m__mstackrealign;
        string m__preamble_bytes;
        string m__analyzer_store;
        string m__mt_migrate_directory;
        string m__ftabstop;
        bool m__msave_temp_labels;
        bool m__fcxx_exceptions;
        bool m__cfg_add_initializers;
        string m__serialize_diagnostic_file;
        string m__objc_isystem;
        bool m__ffreestanding;
        bool m__index_header_map;
        bool m__fno_common;
        bool m__fno_inline;
        bool m__fno_const_strings;
        bool m__fno_dollars_in_identifiers;
        bool m__fno_diagnostics_fixit_info;
        string m__cxx_isystem;
        bool m__fdebugger_cast_result_to_id;
        string m__MT;
        bool m__dM;
        bool m__fixit_to_temporary;
        string m__Xanalyzer;
        bool m__ast_view;
        bool m__mms_bitfields;
        string m__analyzer_ipa;
        string m__internal_isystem;
        bool m__fforbid_guard_variables;
        string m__analyzer_constraints;
        string m__coverage_file;
        bool m__fwrapv;
        bool m__spspsp;
        string m__iwithprefixbefore;
        bool m__disable_free;
        bool m__no_ns_alloc_error;
        string m__ftrap_function;
        bool m__pg;
        bool m__fdollars_in_identifiers;
        string m__header_include_file;
        bool m__munwind_tables;
        bool m__arcmt_migrate_emit_errors;
        bool m__pthread;
        string m__print_file_name;
        bool m__fcuda_is_device;
        bool m__version;
        bool m__fno_inline_functions;
        bool m__fapple_pragma_pack;
        bool m__fobjc_gc_only;
        bool m__fgnu89_inline;
        bool m__mrelax_all;
        string m__fmessage_length;
        bool m__fdump_record_layouts;
        bool m__ast_dump_xml;
        bool m__fdiagnostics_parseable_fixits;
        string m__plugin_arg;
        bool m__mno_global_merge;
        bool m__fgnu_keywords;
        bool m__mdisable_tail_calls;
        bool m__ffunction_sections;
        bool m__unoptimized_cfg;
        bool m__cfg_add_implicit_dtors;
        bool m__c;
        string m__mlimit_float_precision;
        bool m__fuse_register_sized_bitfield_access;
        bool m__mqdsp6_compat;
        bool m__fmodules;
        bool m__pubnames_dump;
        string m__mregparm;
        bool m__Eonly;
        string m__ftrapv_handler;
        bool m__analyzer_opt_analyze_nested_blocks;
        string m__analyzer_output;
        bool m__ObjC;
        bool m__print_decl_contexts;
        string m__fdebug_compilation_dir;
        string m__stdlib;
        bool m___migrate;
        bool m__cl_fast_relaxed_math;
        bool m__fdump_record_layouts_simple;
        bool m__print_libgcc_file_name;
        string m__target;
        bool m__no_implicit_float;
        string m__backend_option;
        bool m__static_define;
        string m__mrelocation_model;
        bool m__fno_merge_all_constants;
        string m__Xclang;
        bool m__print_stats;
        bool m__fdiagnostics_show_note_include_stack;
        bool m__dD;
        string m__analyzer_max_nodes;
        string m__o;
        bool m__print_ivar_layout;
        bool m__fno_signed_char;
        string m__add_plugin;
        bool m__trigraphs;
        string m__iframework;
        bool m__emit_html;
        string m__pic_level;
        bool m__ffast_math;
        string m__mdebug_pass;
        string m__mfloat_abi;
        bool m__nostdsysteminc;
        bool m__arcmt_migrate;
        bool m__dump_raw_tokens;
        bool m__arcmt_check;
        bool m___analyze;
        bool m__relaxed_aliasing;
        bool m__C;
        bool m__dump_tokens;
        string m__analyzer_inlining_mode;
        bool m__femit_coverage_notes;
        bool m__fno_limit_debug_info;
        bool m__fobjc_arc;
        bool m__fdisable_module_hash;
        bool m__detailed_preprocessing_record;
        bool m__menable_unsafe_fp_math;
        bool m__fno_builtin;
        bool m__menable_no_infs;
        bool m__fvisibility_inlines_hidden;
        bool m__fno_rtti;
        string m__fconstant_string_class;
        string m__include_pch;
        bool m__fno_operator_names;
        bool m__init_only;
        string m__O;
        string m__imacros;
        bool m__cl_opt_disable;
        bool m__emit_codegen_only;
        bool m__fobjc_default_synthesize_properties;
        bool m__fno_spell_checking;
        string m__D;
        bool m__fpascal_strings;
        bool m__time;
        bool m__fapple_kext;
        bool m__code_completion_macros;
        bool m__analyzer_eagerly_assume;
        bool m__analyzer_no_eagerly_trim_egraph;
        bool m___relocatable_pch;
        bool m__faltivec;
        bool m__emit_pth;
        bool m__fobjc_exceptions;
        bool m__fno_validate_pch;
        string m__isystem;
        bool m__disable_llvm_verifier;
        string m__stack_protector;
        string m__Xpreprocessor;
        bool m__funknown_anytype;
        string m__fvisibility;
        string m__fmacro_backtrace_limit;
        bool m__fno_use_cxa_atexit;
        string m__fobjc_dispatch_method;
        bool m__objcmt_migrate_literals;
        string m__ftemplate_depth;
        bool m__emit_module;
        bool m__mdisable_fp_elim;
        bool m__cl_mad_enable;
        bool m__fhidden_weak_vtables;
        bool m__analyzer_viz_egraph_ubigraph;
        bool m__mno_zero_initialized_in_bss;
        bool m__code_completion_patterns;
        bool m__P;
        bool m__flimit_debug_info;
        string m__fdiagnostics_show_category;
        string m__fobjc_arc_cxxlib;
        bool m__fms_extensions;
        string m__ferror_limit;
        string m__load;
        bool m__E;
        string m__target_abi;
        string m__analyzer_inline_max_function_size;
        string m__analyze_function;
        bool m__trim_egraph;
        bool m__fix_what_you_can;
        bool m__fobjc_runtime_has_weak;
        string m__Xlinker;
        bool m__fno_gnu_keywords;
        bool m__fdebugger_support;
        bool m__fno_elide_constructors;
        bool m__femit_coverage_data;
        bool m__fsjlj_exceptions;
        string m__dump_build_information;
        bool m__g;
        string m__mcode_model;
        bool m__mnoexecstack;
        string m__ftemplate_backtrace_limit;
        string m__ast_merge;
        bool m__fexceptions;
        bool m__fno_objc_infer_related_result_type;
        string m__internal_externc_isystem;
        string m__target_feature;
        string m__Wl;
        bool m__print_search_dirs;
        bool m__ffake_address_space_map;
        string m__analyzer_purge;
        string m__dependency_file;
        bool m__fconst_strings;
        string m__iquote;
        string m__Wa;
        bool m__fno_access_control;
        bool m__Oz;
        string m__diagnostic_log_file;
        bool m__analyzer_opt_analyze_headers;
        bool m__fgnu_runtime;
        string m__F;
        bool m__fborland_extensions;
        bool m__fobjc_arc_exceptions;
        bool m__migrate;
        bool m__analyze;
        bool m__fobjc_gc;
        bool m__fno_threadsafe_statics;
        bool m__fno_assume_sane_operator_new;
        bool m__ast_dump;
        bool m__masm_verbose;
        string m__objcxx_isystem;
        string m__std;
        bool m__fcatch_undefined_behavior;
        string m__analyzer_disable_checker;
        string m__fconstexpr_depth;
        bool m__msoft_float;
        string m__remap_file;
        bool m__ObjCplusplus;
        bool m__fdiagnostics_print_source_range_info;
        string m__fpack_struct;
        bool m__fobjc_runtime_has_arc;
        string m__foverride_record_layout;
        string m__idirafter;
        bool m__menable_no_nans;
        bool m__finstrument_functions;
        bool m__fno_lax_vector_conversions;
        bool m__fno_bitfield_type_align;
        bool m__fno_show_column;
        string m__fmodule_cache_path;
        bool m__help;
        bool m__mrtd;
        bool m__rewrite_test;
        bool m__ftime_report;
        bool m__cl_unsafe_math_optimizations;
        bool m__analyzer_checker_help;
        bool m__faddress_sanitizer;
        string m__code_completion_at;
        bool m__analyzer_viz_egraph_graphviz;
        bool m__fsyntax_only;
        bool m__fwritable_strings;
        bool m__mconstructor_aliases;
        bool m__momit_leaf_frame_pointer;
        string m__arcmt_migrate_report_output;
        string m__print_prog_name;
        bool m__fdata_sections;
        bool m__emit_pch;
        bool m__cl_finite_math_only;
        bool m__emit_llvm_bc;
        bool m__undef;
        bool m__MP;
        bool m__fmath_errno;
        bool m__save_temps;
        bool m__fno_deprecated_macro;
        string m__cxx_abi;
        bool m__analyzer_stats;
        bool m__fixit;
        string m__triple;
        bool m__rewrite_objc;
        bool m__emit_llvm;
        string m__fmsc_version;
        bool m__fms_compatibility;
        bool m__fno_dwarf_directory_asm;
        bool m__disable_llvm_optzns;
        string m__fshow_overloads;
        bool m__femit_all_decls;
        string m__mlink_bitcode_file;
        bool m__pipe;
        string m__cl_std;
        bool m__fno_dwarf2_cfi_asm;
        bool m__nobuiltininc;
        string m__resource_dir;
        bool m__S;
        string m__dependency_dot;
        bool m__analyzer_display_progress;
        bool m__H;
        bool m__relocatable_pch;
        bool m__fshort_wchar;
        string m__error_on_deserialized_decl;
        string m__analyzer_inline_max_stack_depth;
        bool m__emit_llvm_only;
        bool m__fixit_recompile;
        string m__iprefix;
        string m__iwithsysroot;
        bool m__disable_red_zone;
        string m__MQ;
        string m__analyzer_checker;
        string m__mllvm;
        bool m__no_finalize_removal;
        bool m__traditional_cpp;
        bool m__arcmt_modify;
        string m__dwarf_debug_flags;
        string m__fconstexpr_backtrace_limit;
        bool m__fdump_vtable_layouts;
        string m__include;
        bool m__emit_obj;
        bool m__fcolor_diagnostics;
        bool m__dump_deserialized_decls;
        string m__isysroot;
        string m__target_linker_version;
        bool m__Qunused_arguments;
        bool m__fobjc_fragile_abi;
        bool m__fdeprecated_macro;
        bool m__funroll_loops;
        string m__I;
        string m__plugin;
        bool m__emit_ast;
        bool m__verify;
        bool m__fdiagnostics_show_option;
        bool m__fblocks;
        bool m__fno_caret_diagnostics;
        bool m__ftrapv;
        string m__Wlarge_by_value_copy;
        string m__target_cpu;
        string m__gcc_toolchain;
    public:
        bool has__fshow_column(void) const {
            return m__fshow_column;
        }
        bool has__Xassembler(void) const {
            return m__Xassembler.empty();
        }
        string get__Xassembler(void) const {
            return m__Xassembler;
        }
        bool has__v(void) const {
            return m__v;
        }
        bool has__working_directory(void) const {
            return m__working_directory.empty();
        }
        string get__working_directory(void) const {
            return m__working_directory;
        }
        bool has__nostdincplusplus(void) const {
            return m__nostdincplusplus;
        }
        bool has__chain_include(void) const {
            return m__chain_include.empty();
        }
        string get__chain_include(void) const {
            return m__chain_include;
        }
        bool has__main_file_name(void) const {
            return m__main_file_name.empty();
        }
        string get__main_file_name(void) const {
            return m__main_file_name;
        }
        bool has__fblocks_runtime_optional(void) const {
            return m__fblocks_runtime_optional;
        }
        bool has__rewrite_macros(void) const {
            return m__rewrite_macros;
        }
        bool has__fobjc_runtime_has_terminate(void) const {
            return m__fobjc_runtime_has_terminate;
        }
        bool has__fdelayed_template_parsing(void) const {
            return m__fdelayed_template_parsing;
        }
        bool has__include_pth(void) const {
            return m__include_pth.empty();
        }
        string get__include_pth(void) const {
            return m__include_pth;
        }
        bool has__no_code_completion_globals(void) const {
            return m__no_code_completion_globals;
        }
        bool has__print_preamble(void) const {
            return m__print_preamble;
        }
        bool has__MG(void) const {
            return m__MG;
        }
        bool has__fno_show_source_location(void) const {
            return m__fno_show_source_location;
        }
        bool has__Wp(void) const {
            return m__Wp.empty();
        }
        string get__Wp(void) const {
            return m__Wp;
        }
        bool has__ast_print(void) const {
            return m__ast_print;
        }
        bool has__U(void) const {
            return m__U.empty();
        }
        string get__U(void) const {
            return m__U;
        }
        bool has__mstack_alignment(void) const {
            return m__mstack_alignment.empty();
        }
        string get__mstack_alignment(void) const {
            return m__mstack_alignment;
        }
        bool has__cl_single_precision_constant(void) const {
            return m__cl_single_precision_constant;
        }
        bool has__iwithprefix(void) const {
            return m__iwithprefix.empty();
        }
        string get__iwithprefix(void) const {
            return m__iwithprefix;
        }
        bool has__CC(void) const {
            return m__CC;
        }
        bool has__fix_only_warnings(void) const {
            return m__fix_only_warnings;
        }
        bool has__objcmt_migrate_subscripting(void) const {
            return m__objcmt_migrate_subscripting;
        }
        bool has__fno_constant_cfstrings(void) const {
            return m__fno_constant_cfstrings;
        }
        bool has__analyzer_max_loop(void) const {
            return m__analyzer_max_loop.empty();
        }
        string get__analyzer_max_loop(void) const {
            return m__analyzer_max_loop;
        }
        bool has__fno_diagnostics_show_note_include_stack(void) const {
            return m__fno_diagnostics_show_note_include_stack;
        }
        bool has___help(void) const {
            return m___help;
        }
        bool has__fdiagnostics_format(void) const {
            return m__fdiagnostics_format.empty();
        }
        string get__fdiagnostics_format(void) const {
            return m__fdiagnostics_format;
        }
        bool has__Wno_rewrite_macros(void) const {
            return m__Wno_rewrite_macros;
        }
        bool has__fshort_enums(void) const {
            return m__fshort_enums;
        }
        bool has___serialize_diagnostics(void) const {
            return m___serialize_diagnostics.empty();
        }
        string get___serialize_diagnostics(void) const {
            return m___serialize_diagnostics;
        }
        bool has__Os(void) const {
            return m__Os;
        }
        bool has__w(void) const {
            return m__w;
        }
        bool has__c_isystem(void) const {
            return m__c_isystem.empty();
        }
        string get__c_isystem(void) const {
            return m__c_isystem;
        }
        bool has__token_cache(void) const {
            return m__token_cache.empty();
        }
        string get__token_cache(void) const {
            return m__token_cache;
        }
        bool has__fdebugger_objc_literal(void) const {
            return m__fdebugger_objc_literal;
        }
        bool has__fmodule_name(void) const {
            return m__fmodule_name.empty();
        }
        string get__fmodule_name(void) const {
            return m__fmodule_name;
        }
        bool has__sys_header_deps(void) const {
            return m__sys_header_deps;
        }
        bool has__mstackrealign(void) const {
            return m__mstackrealign;
        }
        bool has__preamble_bytes(void) const {
            return m__preamble_bytes.empty();
        }
        string get__preamble_bytes(void) const {
            return m__preamble_bytes;
        }
        bool has__analyzer_store(void) const {
            return m__analyzer_store.empty();
        }
        string get__analyzer_store(void) const {
            return m__analyzer_store;
        }
        bool has__mt_migrate_directory(void) const {
            return m__mt_migrate_directory.empty();
        }
        string get__mt_migrate_directory(void) const {
            return m__mt_migrate_directory;
        }
        bool has__ftabstop(void) const {
            return m__ftabstop.empty();
        }
        string get__ftabstop(void) const {
            return m__ftabstop;
        }
        bool has__msave_temp_labels(void) const {
            return m__msave_temp_labels;
        }
        bool has__fcxx_exceptions(void) const {
            return m__fcxx_exceptions;
        }
        bool has__cfg_add_initializers(void) const {
            return m__cfg_add_initializers;
        }
        bool has__serialize_diagnostic_file(void) const {
            return m__serialize_diagnostic_file.empty();
        }
        string get__serialize_diagnostic_file(void) const {
            return m__serialize_diagnostic_file;
        }
        bool has__objc_isystem(void) const {
            return m__objc_isystem.empty();
        }
        string get__objc_isystem(void) const {
            return m__objc_isystem;
        }
        bool has__ffreestanding(void) const {
            return m__ffreestanding;
        }
        bool has__index_header_map(void) const {
            return m__index_header_map;
        }
        bool has__fno_common(void) const {
            return m__fno_common;
        }
        bool has__fno_inline(void) const {
            return m__fno_inline;
        }
        bool has__fno_const_strings(void) const {
            return m__fno_const_strings;
        }
        bool has__fno_dollars_in_identifiers(void) const {
            return m__fno_dollars_in_identifiers;
        }
        bool has__fno_diagnostics_fixit_info(void) const {
            return m__fno_diagnostics_fixit_info;
        }
        bool has__cxx_isystem(void) const {
            return m__cxx_isystem.empty();
        }
        string get__cxx_isystem(void) const {
            return m__cxx_isystem;
        }
        bool has__fdebugger_cast_result_to_id(void) const {
            return m__fdebugger_cast_result_to_id;
        }
        bool has__MT(void) const {
            return m__MT.empty();
        }
        string get__MT(void) const {
            return m__MT;
        }
        bool has__dM(void) const {
            return m__dM;
        }
        bool has__fixit_to_temporary(void) const {
            return m__fixit_to_temporary;
        }
        bool has__Xanalyzer(void) const {
            return m__Xanalyzer.empty();
        }
        string get__Xanalyzer(void) const {
            return m__Xanalyzer;
        }
        bool has__ast_view(void) const {
            return m__ast_view;
        }
        bool has__mms_bitfields(void) const {
            return m__mms_bitfields;
        }
        bool has__analyzer_ipa(void) const {
            return m__analyzer_ipa.empty();
        }
        string get__analyzer_ipa(void) const {
            return m__analyzer_ipa;
        }
        bool has__internal_isystem(void) const {
            return m__internal_isystem.empty();
        }
        string get__internal_isystem(void) const {
            return m__internal_isystem;
        }
        bool has__fforbid_guard_variables(void) const {
            return m__fforbid_guard_variables;
        }
        bool has__analyzer_constraints(void) const {
            return m__analyzer_constraints.empty();
        }
        string get__analyzer_constraints(void) const {
            return m__analyzer_constraints;
        }
        bool has__coverage_file(void) const {
            return m__coverage_file.empty();
        }
        string get__coverage_file(void) const {
            return m__coverage_file;
        }
        bool has__fwrapv(void) const {
            return m__fwrapv;
        }
        bool has__spspsp(void) const {
            return m__spspsp;
        }
        bool has__iwithprefixbefore(void) const {
            return m__iwithprefixbefore.empty();
        }
        string get__iwithprefixbefore(void) const {
            return m__iwithprefixbefore;
        }
        bool has__disable_free(void) const {
            return m__disable_free;
        }
        bool has__no_ns_alloc_error(void) const {
            return m__no_ns_alloc_error;
        }
        bool has__ftrap_function(void) const {
            return m__ftrap_function.empty();
        }
        string get__ftrap_function(void) const {
            return m__ftrap_function;
        }
        bool has__pg(void) const {
            return m__pg;
        }
        bool has__fdollars_in_identifiers(void) const {
            return m__fdollars_in_identifiers;
        }
        bool has__header_include_file(void) const {
            return m__header_include_file.empty();
        }
        string get__header_include_file(void) const {
            return m__header_include_file;
        }
        bool has__munwind_tables(void) const {
            return m__munwind_tables;
        }
        bool has__arcmt_migrate_emit_errors(void) const {
            return m__arcmt_migrate_emit_errors;
        }
        bool has__pthread(void) const {
            return m__pthread;
        }
        bool has__print_file_name(void) const {
            return m__print_file_name.empty();
        }
        string get__print_file_name(void) const {
            return m__print_file_name;
        }
        bool has__fcuda_is_device(void) const {
            return m__fcuda_is_device;
        }
        bool has__version(void) const {
            return m__version;
        }
        bool has__fno_inline_functions(void) const {
            return m__fno_inline_functions;
        }
        bool has__fapple_pragma_pack(void) const {
            return m__fapple_pragma_pack;
        }
        bool has__fobjc_gc_only(void) const {
            return m__fobjc_gc_only;
        }
        bool has__fgnu89_inline(void) const {
            return m__fgnu89_inline;
        }
        bool has__mrelax_all(void) const {
            return m__mrelax_all;
        }
        bool has__fmessage_length(void) const {
            return m__fmessage_length.empty();
        }
        string get__fmessage_length(void) const {
            return m__fmessage_length;
        }
        bool has__fdump_record_layouts(void) const {
            return m__fdump_record_layouts;
        }
        bool has__ast_dump_xml(void) const {
            return m__ast_dump_xml;
        }
        bool has__fdiagnostics_parseable_fixits(void) const {
            return m__fdiagnostics_parseable_fixits;
        }
        bool has__plugin_arg(void) const {
            return m__plugin_arg.empty();
        }
        string get__plugin_arg(void) const {
            return m__plugin_arg;
        }
        bool has__mno_global_merge(void) const {
            return m__mno_global_merge;
        }
        bool has__fgnu_keywords(void) const {
            return m__fgnu_keywords;
        }
        bool has__mdisable_tail_calls(void) const {
            return m__mdisable_tail_calls;
        }
        bool has__ffunction_sections(void) const {
            return m__ffunction_sections;
        }
        bool has__unoptimized_cfg(void) const {
            return m__unoptimized_cfg;
        }
        bool has__cfg_add_implicit_dtors(void) const {
            return m__cfg_add_implicit_dtors;
        }
        bool has__c(void) const {
            return m__c;
        }
        bool has__mlimit_float_precision(void) const {
            return m__mlimit_float_precision.empty();
        }
        string get__mlimit_float_precision(void) const {
            return m__mlimit_float_precision;
        }
        bool has__fuse_register_sized_bitfield_access(void) const {
            return m__fuse_register_sized_bitfield_access;
        }
        bool has__mqdsp6_compat(void) const {
            return m__mqdsp6_compat;
        }
        bool has__fmodules(void) const {
            return m__fmodules;
        }
        bool has__pubnames_dump(void) const {
            return m__pubnames_dump;
        }
        bool has__mregparm(void) const {
            return m__mregparm.empty();
        }
        string get__mregparm(void) const {
            return m__mregparm;
        }
        bool has__Eonly(void) const {
            return m__Eonly;
        }
        bool has__ftrapv_handler(void) const {
            return m__ftrapv_handler.empty();
        }
        string get__ftrapv_handler(void) const {
            return m__ftrapv_handler;
        }
        bool has__analyzer_opt_analyze_nested_blocks(void) const {
            return m__analyzer_opt_analyze_nested_blocks;
        }
        bool has__analyzer_output(void) const {
            return m__analyzer_output.empty();
        }
        string get__analyzer_output(void) const {
            return m__analyzer_output;
        }
        bool has__ObjC(void) const {
            return m__ObjC;
        }
        bool has__print_decl_contexts(void) const {
            return m__print_decl_contexts;
        }
        bool has__fdebug_compilation_dir(void) const {
            return m__fdebug_compilation_dir.empty();
        }
        string get__fdebug_compilation_dir(void) const {
            return m__fdebug_compilation_dir;
        }
        bool has__stdlib(void) const {
            return m__stdlib.empty();
        }
        string get__stdlib(void) const {
            return m__stdlib;
        }
        bool has___migrate(void) const {
            return m___migrate;
        }
        bool has__cl_fast_relaxed_math(void) const {
            return m__cl_fast_relaxed_math;
        }
        bool has__fdump_record_layouts_simple(void) const {
            return m__fdump_record_layouts_simple;
        }
        bool has__print_libgcc_file_name(void) const {
            return m__print_libgcc_file_name;
        }
        bool has__target(void) const {
            return m__target.empty();
        }
        string get__target(void) const {
            return m__target;
        }
        bool has__no_implicit_float(void) const {
            return m__no_implicit_float;
        }
        bool has__backend_option(void) const {
            return m__backend_option.empty();
        }
        string get__backend_option(void) const {
            return m__backend_option;
        }
        bool has__static_define(void) const {
            return m__static_define;
        }
        bool has__mrelocation_model(void) const {
            return m__mrelocation_model.empty();
        }
        string get__mrelocation_model(void) const {
            return m__mrelocation_model;
        }
        bool has__fno_merge_all_constants(void) const {
            return m__fno_merge_all_constants;
        }
        bool has__Xclang(void) const {
            return m__Xclang.empty();
        }
        string get__Xclang(void) const {
            return m__Xclang;
        }
        bool has__print_stats(void) const {
            return m__print_stats;
        }
        bool has__fdiagnostics_show_note_include_stack(void) const {
            return m__fdiagnostics_show_note_include_stack;
        }
        bool has__dD(void) const {
            return m__dD;
        }
        bool has__analyzer_max_nodes(void) const {
            return m__analyzer_max_nodes.empty();
        }
        string get__analyzer_max_nodes(void) const {
            return m__analyzer_max_nodes;
        }
        bool has__o(void) const {
            return m__o.empty();
        }
        string get__o(void) const {
            return m__o;
        }
        bool has__print_ivar_layout(void) const {
            return m__print_ivar_layout;
        }
        bool has__fno_signed_char(void) const {
            return m__fno_signed_char;
        }
        bool has__add_plugin(void) const {
            return m__add_plugin.empty();
        }
        string get__add_plugin(void) const {
            return m__add_plugin;
        }
        bool has__trigraphs(void) const {
            return m__trigraphs;
        }
        bool has__iframework(void) const {
            return m__iframework.empty();
        }
        string get__iframework(void) const {
            return m__iframework;
        }
        bool has__emit_html(void) const {
            return m__emit_html;
        }
        bool has__pic_level(void) const {
            return m__pic_level.empty();
        }
        string get__pic_level(void) const {
            return m__pic_level;
        }
        bool has__ffast_math(void) const {
            return m__ffast_math;
        }
        bool has__mdebug_pass(void) const {
            return m__mdebug_pass.empty();
        }
        string get__mdebug_pass(void) const {
            return m__mdebug_pass;
        }
        bool has__mfloat_abi(void) const {
            return m__mfloat_abi.empty();
        }
        string get__mfloat_abi(void) const {
            return m__mfloat_abi;
        }
        bool has__nostdsysteminc(void) const {
            return m__nostdsysteminc;
        }
        bool has__arcmt_migrate(void) const {
            return m__arcmt_migrate;
        }
        bool has__dump_raw_tokens(void) const {
            return m__dump_raw_tokens;
        }
        bool has__arcmt_check(void) const {
            return m__arcmt_check;
        }
        bool has___analyze(void) const {
            return m___analyze;
        }
        bool has__relaxed_aliasing(void) const {
            return m__relaxed_aliasing;
        }
        bool has__C(void) const {
            return m__C;
        }
        bool has__dump_tokens(void) const {
            return m__dump_tokens;
        }
        bool has__analyzer_inlining_mode(void) const {
            return m__analyzer_inlining_mode.empty();
        }
        string get__analyzer_inlining_mode(void) const {
            return m__analyzer_inlining_mode;
        }
        bool has__femit_coverage_notes(void) const {
            return m__femit_coverage_notes;
        }
        bool has__fno_limit_debug_info(void) const {
            return m__fno_limit_debug_info;
        }
        bool has__fobjc_arc(void) const {
            return m__fobjc_arc;
        }
        bool has__fdisable_module_hash(void) const {
            return m__fdisable_module_hash;
        }
        bool has__detailed_preprocessing_record(void) const {
            return m__detailed_preprocessing_record;
        }
        bool has__menable_unsafe_fp_math(void) const {
            return m__menable_unsafe_fp_math;
        }
        bool has__fno_builtin(void) const {
            return m__fno_builtin;
        }
        bool has__menable_no_infs(void) const {
            return m__menable_no_infs;
        }
        bool has__fvisibility_inlines_hidden(void) const {
            return m__fvisibility_inlines_hidden;
        }
        bool has__fno_rtti(void) const {
            return m__fno_rtti;
        }
        bool has__fconstant_string_class(void) const {
            return m__fconstant_string_class.empty();
        }
        string get__fconstant_string_class(void) const {
            return m__fconstant_string_class;
        }
        bool has__include_pch(void) const {
            return m__include_pch.empty();
        }
        string get__include_pch(void) const {
            return m__include_pch;
        }
        bool has__fno_operator_names(void) const {
            return m__fno_operator_names;
        }
        bool has__init_only(void) const {
            return m__init_only;
        }
        bool has__O(void) const {
            return m__O.empty();
        }
        string get__O(void) const {
            return m__O;
        }
        bool has__imacros(void) const {
            return m__imacros.empty();
        }
        string get__imacros(void) const {
            return m__imacros;
        }
        bool has__cl_opt_disable(void) const {
            return m__cl_opt_disable;
        }
        bool has__emit_codegen_only(void) const {
            return m__emit_codegen_only;
        }
        bool has__fobjc_default_synthesize_properties(void) const {
            return m__fobjc_default_synthesize_properties;
        }
        bool has__fno_spell_checking(void) const {
            return m__fno_spell_checking;
        }
        bool has__D(void) const {
            return m__D.empty();
        }
        string get__D(void) const {
            return m__D;
        }
        bool has__fpascal_strings(void) const {
            return m__fpascal_strings;
        }
        bool has__time(void) const {
            return m__time;
        }
        bool has__fapple_kext(void) const {
            return m__fapple_kext;
        }
        bool has__code_completion_macros(void) const {
            return m__code_completion_macros;
        }
        bool has__analyzer_eagerly_assume(void) const {
            return m__analyzer_eagerly_assume;
        }
        bool has__analyzer_no_eagerly_trim_egraph(void) const {
            return m__analyzer_no_eagerly_trim_egraph;
        }
        bool has___relocatable_pch(void) const {
            return m___relocatable_pch;
        }
        bool has__faltivec(void) const {
            return m__faltivec;
        }
        bool has__emit_pth(void) const {
            return m__emit_pth;
        }
        bool has__fobjc_exceptions(void) const {
            return m__fobjc_exceptions;
        }
        bool has__fno_validate_pch(void) const {
            return m__fno_validate_pch;
        }
        bool has__isystem(void) const {
            return m__isystem.empty();
        }
        string get__isystem(void) const {
            return m__isystem;
        }
        bool has__disable_llvm_verifier(void) const {
            return m__disable_llvm_verifier;
        }
        bool has__stack_protector(void) const {
            return m__stack_protector.empty();
        }
        string get__stack_protector(void) const {
            return m__stack_protector;
        }
        bool has__Xpreprocessor(void) const {
            return m__Xpreprocessor.empty();
        }
        string get__Xpreprocessor(void) const {
            return m__Xpreprocessor;
        }
        bool has__funknown_anytype(void) const {
            return m__funknown_anytype;
        }
        bool has__fvisibility(void) const {
            return m__fvisibility.empty();
        }
        string get__fvisibility(void) const {
            return m__fvisibility;
        }
        bool has__fmacro_backtrace_limit(void) const {
            return m__fmacro_backtrace_limit.empty();
        }
        string get__fmacro_backtrace_limit(void) const {
            return m__fmacro_backtrace_limit;
        }
        bool has__fno_use_cxa_atexit(void) const {
            return m__fno_use_cxa_atexit;
        }
        bool has__fobjc_dispatch_method(void) const {
            return m__fobjc_dispatch_method.empty();
        }
        string get__fobjc_dispatch_method(void) const {
            return m__fobjc_dispatch_method;
        }
        bool has__objcmt_migrate_literals(void) const {
            return m__objcmt_migrate_literals;
        }
        bool has__ftemplate_depth(void) const {
            return m__ftemplate_depth.empty();
        }
        string get__ftemplate_depth(void) const {
            return m__ftemplate_depth;
        }
        bool has__emit_module(void) const {
            return m__emit_module;
        }
        bool has__mdisable_fp_elim(void) const {
            return m__mdisable_fp_elim;
        }
        bool has__cl_mad_enable(void) const {
            return m__cl_mad_enable;
        }
        bool has__fhidden_weak_vtables(void) const {
            return m__fhidden_weak_vtables;
        }
        bool has__analyzer_viz_egraph_ubigraph(void) const {
            return m__analyzer_viz_egraph_ubigraph;
        }
        bool has__mno_zero_initialized_in_bss(void) const {
            return m__mno_zero_initialized_in_bss;
        }
        bool has__code_completion_patterns(void) const {
            return m__code_completion_patterns;
        }
        bool has__P(void) const {
            return m__P;
        }
        bool has__flimit_debug_info(void) const {
            return m__flimit_debug_info;
        }
        bool has__fdiagnostics_show_category(void) const {
            return m__fdiagnostics_show_category.empty();
        }
        string get__fdiagnostics_show_category(void) const {
            return m__fdiagnostics_show_category;
        }
        bool has__fobjc_arc_cxxlib(void) const {
            return m__fobjc_arc_cxxlib.empty();
        }
        string get__fobjc_arc_cxxlib(void) const {
            return m__fobjc_arc_cxxlib;
        }
        bool has__fms_extensions(void) const {
            return m__fms_extensions;
        }
        bool has__ferror_limit(void) const {
            return m__ferror_limit.empty();
        }
        string get__ferror_limit(void) const {
            return m__ferror_limit;
        }
        bool has__load(void) const {
            return m__load.empty();
        }
        string get__load(void) const {
            return m__load;
        }
        bool has__E(void) const {
            return m__E;
        }
        bool has__target_abi(void) const {
            return m__target_abi.empty();
        }
        string get__target_abi(void) const {
            return m__target_abi;
        }
        bool has__analyzer_inline_max_function_size(void) const {
            return m__analyzer_inline_max_function_size.empty();
        }
        string get__analyzer_inline_max_function_size(void) const {
            return m__analyzer_inline_max_function_size;
        }
        bool has__analyze_function(void) const {
            return m__analyze_function.empty();
        }
        string get__analyze_function(void) const {
            return m__analyze_function;
        }
        bool has__trim_egraph(void) const {
            return m__trim_egraph;
        }
        bool has__fix_what_you_can(void) const {
            return m__fix_what_you_can;
        }
        bool has__fobjc_runtime_has_weak(void) const {
            return m__fobjc_runtime_has_weak;
        }
        bool has__Xlinker(void) const {
            return m__Xlinker.empty();
        }
        string get__Xlinker(void) const {
            return m__Xlinker;
        }
        bool has__fno_gnu_keywords(void) const {
            return m__fno_gnu_keywords;
        }
        bool has__fdebugger_support(void) const {
            return m__fdebugger_support;
        }
        bool has__fno_elide_constructors(void) const {
            return m__fno_elide_constructors;
        }
        bool has__femit_coverage_data(void) const {
            return m__femit_coverage_data;
        }
        bool has__fsjlj_exceptions(void) const {
            return m__fsjlj_exceptions;
        }
        bool has__dump_build_information(void) const {
            return m__dump_build_information.empty();
        }
        string get__dump_build_information(void) const {
            return m__dump_build_information;
        }
        bool has__g(void) const {
            return m__g;
        }
        bool has__mcode_model(void) const {
            return m__mcode_model.empty();
        }
        string get__mcode_model(void) const {
            return m__mcode_model;
        }
        bool has__mnoexecstack(void) const {
            return m__mnoexecstack;
        }
        bool has__ftemplate_backtrace_limit(void) const {
            return m__ftemplate_backtrace_limit.empty();
        }
        string get__ftemplate_backtrace_limit(void) const {
            return m__ftemplate_backtrace_limit;
        }
        bool has__ast_merge(void) const {
            return m__ast_merge.empty();
        }
        string get__ast_merge(void) const {
            return m__ast_merge;
        }
        bool has__fexceptions(void) const {
            return m__fexceptions;
        }
        bool has__fno_objc_infer_related_result_type(void) const {
            return m__fno_objc_infer_related_result_type;
        }
        bool has__internal_externc_isystem(void) const {
            return m__internal_externc_isystem.empty();
        }
        string get__internal_externc_isystem(void) const {
            return m__internal_externc_isystem;
        }
        bool has__target_feature(void) const {
            return m__target_feature.empty();
        }
        string get__target_feature(void) const {
            return m__target_feature;
        }
        bool has__Wl(void) const {
            return m__Wl.empty();
        }
        string get__Wl(void) const {
            return m__Wl;
        }
        bool has__print_search_dirs(void) const {
            return m__print_search_dirs;
        }
        bool has__ffake_address_space_map(void) const {
            return m__ffake_address_space_map;
        }
        bool has__analyzer_purge(void) const {
            return m__analyzer_purge.empty();
        }
        string get__analyzer_purge(void) const {
            return m__analyzer_purge;
        }
        bool has__dependency_file(void) const {
            return m__dependency_file.empty();
        }
        string get__dependency_file(void) const {
            return m__dependency_file;
        }
        bool has__fconst_strings(void) const {
            return m__fconst_strings;
        }
        bool has__iquote(void) const {
            return m__iquote.empty();
        }
        string get__iquote(void) const {
            return m__iquote;
        }
        bool has__Wa(void) const {
            return m__Wa.empty();
        }
        string get__Wa(void) const {
            return m__Wa;
        }
        bool has__fno_access_control(void) const {
            return m__fno_access_control;
        }
        bool has__Oz(void) const {
            return m__Oz;
        }
        bool has__diagnostic_log_file(void) const {
            return m__diagnostic_log_file.empty();
        }
        string get__diagnostic_log_file(void) const {
            return m__diagnostic_log_file;
        }
        bool has__analyzer_opt_analyze_headers(void) const {
            return m__analyzer_opt_analyze_headers;
        }
        bool has__fgnu_runtime(void) const {
            return m__fgnu_runtime;
        }
        bool has__F(void) const {
            return m__F.empty();
        }
        string get__F(void) const {
            return m__F;
        }
        bool has__fborland_extensions(void) const {
            return m__fborland_extensions;
        }
        bool has__fobjc_arc_exceptions(void) const {
            return m__fobjc_arc_exceptions;
        }
        bool has__migrate(void) const {
            return m__migrate;
        }
        bool has__analyze(void) const {
            return m__analyze;
        }
        bool has__fobjc_gc(void) const {
            return m__fobjc_gc;
        }
        bool has__fno_threadsafe_statics(void) const {
            return m__fno_threadsafe_statics;
        }
        bool has__fno_assume_sane_operator_new(void) const {
            return m__fno_assume_sane_operator_new;
        }
        bool has__ast_dump(void) const {
            return m__ast_dump;
        }
        bool has__masm_verbose(void) const {
            return m__masm_verbose;
        }
        bool has__objcxx_isystem(void) const {
            return m__objcxx_isystem.empty();
        }
        string get__objcxx_isystem(void) const {
            return m__objcxx_isystem;
        }
        bool has__std(void) const {
            return m__std.empty();
        }
        string get__std(void) const {
            return m__std;
        }
        bool has__fcatch_undefined_behavior(void) const {
            return m__fcatch_undefined_behavior;
        }
        bool has__analyzer_disable_checker(void) const {
            return m__analyzer_disable_checker.empty();
        }
        string get__analyzer_disable_checker(void) const {
            return m__analyzer_disable_checker;
        }
        bool has__fconstexpr_depth(void) const {
            return m__fconstexpr_depth.empty();
        }
        string get__fconstexpr_depth(void) const {
            return m__fconstexpr_depth;
        }
        bool has__msoft_float(void) const {
            return m__msoft_float;
        }
        bool has__remap_file(void) const {
            return m__remap_file.empty();
        }
        string get__remap_file(void) const {
            return m__remap_file;
        }
        bool has__ObjCplusplus(void) const {
            return m__ObjCplusplus;
        }
        bool has__fdiagnostics_print_source_range_info(void) const {
            return m__fdiagnostics_print_source_range_info;
        }
        bool has__fpack_struct(void) const {
            return m__fpack_struct.empty();
        }
        string get__fpack_struct(void) const {
            return m__fpack_struct;
        }
        bool has__fobjc_runtime_has_arc(void) const {
            return m__fobjc_runtime_has_arc;
        }
        bool has__foverride_record_layout(void) const {
            return m__foverride_record_layout.empty();
        }
        string get__foverride_record_layout(void) const {
            return m__foverride_record_layout;
        }
        bool has__idirafter(void) const {
            return m__idirafter.empty();
        }
        string get__idirafter(void) const {
            return m__idirafter;
        }
        bool has__menable_no_nans(void) const {
            return m__menable_no_nans;
        }
        bool has__finstrument_functions(void) const {
            return m__finstrument_functions;
        }
        bool has__fno_lax_vector_conversions(void) const {
            return m__fno_lax_vector_conversions;
        }
        bool has__fno_bitfield_type_align(void) const {
            return m__fno_bitfield_type_align;
        }
        bool has__fno_show_column(void) const {
            return m__fno_show_column;
        }
        bool has__fmodule_cache_path(void) const {
            return m__fmodule_cache_path.empty();
        }
        string get__fmodule_cache_path(void) const {
            return m__fmodule_cache_path;
        }
        bool has__help(void) const {
            return m__help;
        }
        bool has__mrtd(void) const {
            return m__mrtd;
        }
        bool has__rewrite_test(void) const {
            return m__rewrite_test;
        }
        bool has__ftime_report(void) const {
            return m__ftime_report;
        }
        bool has__cl_unsafe_math_optimizations(void) const {
            return m__cl_unsafe_math_optimizations;
        }
        bool has__analyzer_checker_help(void) const {
            return m__analyzer_checker_help;
        }
        bool has__faddress_sanitizer(void) const {
            return m__faddress_sanitizer;
        }
        bool has__code_completion_at(void) const {
            return m__code_completion_at.empty();
        }
        string get__code_completion_at(void) const {
            return m__code_completion_at;
        }
        bool has__analyzer_viz_egraph_graphviz(void) const {
            return m__analyzer_viz_egraph_graphviz;
        }
        bool has__fsyntax_only(void) const {
            return m__fsyntax_only;
        }
        bool has__fwritable_strings(void) const {
            return m__fwritable_strings;
        }
        bool has__mconstructor_aliases(void) const {
            return m__mconstructor_aliases;
        }
        bool has__momit_leaf_frame_pointer(void) const {
            return m__momit_leaf_frame_pointer;
        }
        bool has__arcmt_migrate_report_output(void) const {
            return m__arcmt_migrate_report_output.empty();
        }
        string get__arcmt_migrate_report_output(void) const {
            return m__arcmt_migrate_report_output;
        }
        bool has__print_prog_name(void) const {
            return m__print_prog_name.empty();
        }
        string get__print_prog_name(void) const {
            return m__print_prog_name;
        }
        bool has__fdata_sections(void) const {
            return m__fdata_sections;
        }
        bool has__emit_pch(void) const {
            return m__emit_pch;
        }
        bool has__cl_finite_math_only(void) const {
            return m__cl_finite_math_only;
        }
        bool has__emit_llvm_bc(void) const {
            return m__emit_llvm_bc;
        }
        bool has__undef(void) const {
            return m__undef;
        }
        bool has__MP(void) const {
            return m__MP;
        }
        bool has__fmath_errno(void) const {
            return m__fmath_errno;
        }
        bool has__save_temps(void) const {
            return m__save_temps;
        }
        bool has__fno_deprecated_macro(void) const {
            return m__fno_deprecated_macro;
        }
        bool has__cxx_abi(void) const {
            return m__cxx_abi.empty();
        }
        string get__cxx_abi(void) const {
            return m__cxx_abi;
        }
        bool has__analyzer_stats(void) const {
            return m__analyzer_stats;
        }
        bool has__fixit(void) const {
            return m__fixit;
        }
        bool has__triple(void) const {
            return m__triple.empty();
        }
        string get__triple(void) const {
            return m__triple;
        }
        bool has__rewrite_objc(void) const {
            return m__rewrite_objc;
        }
        bool has__emit_llvm(void) const {
            return m__emit_llvm;
        }
        bool has__fmsc_version(void) const {
            return m__fmsc_version.empty();
        }
        string get__fmsc_version(void) const {
            return m__fmsc_version;
        }
        bool has__fms_compatibility(void) const {
            return m__fms_compatibility;
        }
        bool has__fno_dwarf_directory_asm(void) const {
            return m__fno_dwarf_directory_asm;
        }
        bool has__disable_llvm_optzns(void) const {
            return m__disable_llvm_optzns;
        }
        bool has__fshow_overloads(void) const {
            return m__fshow_overloads.empty();
        }
        string get__fshow_overloads(void) const {
            return m__fshow_overloads;
        }
        bool has__femit_all_decls(void) const {
            return m__femit_all_decls;
        }
        bool has__mlink_bitcode_file(void) const {
            return m__mlink_bitcode_file.empty();
        }
        string get__mlink_bitcode_file(void) const {
            return m__mlink_bitcode_file;
        }
        bool has__pipe(void) const {
            return m__pipe;
        }
        bool has__cl_std(void) const {
            return m__cl_std.empty();
        }
        string get__cl_std(void) const {
            return m__cl_std;
        }
        bool has__fno_dwarf2_cfi_asm(void) const {
            return m__fno_dwarf2_cfi_asm;
        }
        bool has__nobuiltininc(void) const {
            return m__nobuiltininc;
        }
        bool has__resource_dir(void) const {
            return m__resource_dir.empty();
        }
        string get__resource_dir(void) const {
            return m__resource_dir;
        }
        bool has__S(void) const {
            return m__S;
        }
        bool has__dependency_dot(void) const {
            return m__dependency_dot.empty();
        }
        string get__dependency_dot(void) const {
            return m__dependency_dot;
        }
        bool has__analyzer_display_progress(void) const {
            return m__analyzer_display_progress;
        }
        bool has__H(void) const {
            return m__H;
        }
        bool has__relocatable_pch(void) const {
            return m__relocatable_pch;
        }
        bool has__fshort_wchar(void) const {
            return m__fshort_wchar;
        }
        bool has__error_on_deserialized_decl(void) const {
            return m__error_on_deserialized_decl.empty();
        }
        string get__error_on_deserialized_decl(void) const {
            return m__error_on_deserialized_decl;
        }
        bool has__analyzer_inline_max_stack_depth(void) const {
            return m__analyzer_inline_max_stack_depth.empty();
        }
        string get__analyzer_inline_max_stack_depth(void) const {
            return m__analyzer_inline_max_stack_depth;
        }
        bool has__emit_llvm_only(void) const {
            return m__emit_llvm_only;
        }
        bool has__fixit_recompile(void) const {
            return m__fixit_recompile;
        }
        bool has__iprefix(void) const {
            return m__iprefix.empty();
        }
        string get__iprefix(void) const {
            return m__iprefix;
        }
        bool has__iwithsysroot(void) const {
            return m__iwithsysroot.empty();
        }
        string get__iwithsysroot(void) const {
            return m__iwithsysroot;
        }
        bool has__disable_red_zone(void) const {
            return m__disable_red_zone;
        }
        bool has__MQ(void) const {
            return m__MQ.empty();
        }
        string get__MQ(void) const {
            return m__MQ;
        }
        bool has__analyzer_checker(void) const {
            return m__analyzer_checker.empty();
        }
        string get__analyzer_checker(void) const {
            return m__analyzer_checker;
        }
        bool has__mllvm(void) const {
            return m__mllvm.empty();
        }
        string get__mllvm(void) const {
            return m__mllvm;
        }
        bool has__no_finalize_removal(void) const {
            return m__no_finalize_removal;
        }
        bool has__traditional_cpp(void) const {
            return m__traditional_cpp;
        }
        bool has__arcmt_modify(void) const {
            return m__arcmt_modify;
        }
        bool has__dwarf_debug_flags(void) const {
            return m__dwarf_debug_flags.empty();
        }
        string get__dwarf_debug_flags(void) const {
            return m__dwarf_debug_flags;
        }
        bool has__fconstexpr_backtrace_limit(void) const {
            return m__fconstexpr_backtrace_limit.empty();
        }
        string get__fconstexpr_backtrace_limit(void) const {
            return m__fconstexpr_backtrace_limit;
        }
        bool has__fdump_vtable_layouts(void) const {
            return m__fdump_vtable_layouts;
        }
        bool has__include(void) const {
            return m__include.empty();
        }
        string get__include(void) const {
            return m__include;
        }
        bool has__emit_obj(void) const {
            return m__emit_obj;
        }
        bool has__fcolor_diagnostics(void) const {
            return m__fcolor_diagnostics;
        }
        bool has__dump_deserialized_decls(void) const {
            return m__dump_deserialized_decls;
        }
        bool has__isysroot(void) const {
            return m__isysroot.empty();
        }
        string get__isysroot(void) const {
            return m__isysroot;
        }
        bool has__target_linker_version(void) const {
            return m__target_linker_version.empty();
        }
        string get__target_linker_version(void) const {
            return m__target_linker_version;
        }
        bool has__Qunused_arguments(void) const {
            return m__Qunused_arguments;
        }
        bool has__fobjc_fragile_abi(void) const {
            return m__fobjc_fragile_abi;
        }
        bool has__fdeprecated_macro(void) const {
            return m__fdeprecated_macro;
        }
        bool has__funroll_loops(void) const {
            return m__funroll_loops;
        }
        bool has__I(void) const {
            return m__I.empty();
        }
        string get__I(void) const {
            return m__I;
        }
        bool has__plugin(void) const {
            return m__plugin.empty();
        }
        string get__plugin(void) const {
            return m__plugin;
        }
        bool has__emit_ast(void) const {
            return m__emit_ast;
        }
        bool has__verify(void) const {
            return m__verify;
        }
        bool has__fdiagnostics_show_option(void) const {
            return m__fdiagnostics_show_option;
        }
        bool has__fblocks(void) const {
            return m__fblocks;
        }
        bool has__fno_caret_diagnostics(void) const {
            return m__fno_caret_diagnostics;
        }
        bool has__ftrapv(void) const {
            return m__ftrapv;
        }
        bool has__Wlarge_by_value_copy(void) const {
            return m__Wlarge_by_value_copy.empty();
        }
        string get__Wlarge_by_value_copy(void) const {
            return m__Wlarge_by_value_copy;
        }
        bool has__target_cpu(void) const {
            return m__target_cpu.empty();
        }
        string get__target_cpu(void) const {
            return m__target_cpu;
        }
        bool has__gcc_toolchain(void) const {
            return m__gcc_toolchain.empty();
        }
        string get__gcc_toolchain(void) const {
            return m__gcc_toolchain;
        }
    };
}
#endif // __OPTIONS_HPP_
