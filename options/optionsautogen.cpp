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
            (",###","                      Print the commands to run for this compilation")
            (",C","                        Enable comment output in -E mode")
            (",CC","                       Enable comment output in -E mode, even from macro expansions")
            (",D",po::value(&m_D),"   <macro>              Predefine the specified macro")
            (",E","                        Only run the preprocessor")
            (",Eonly","                    Just run preprocessor, no output (for timings)")
            (",F",po::value(&m_F),"   <directory>          Add directory to framework include search path")
            (",H","                        Show header includes and nesting depth")
            (",I",po::value(&m_I),"   <directory>          Add directory to include search path")
            (",MG","                       Add missing headers to dependency list")
            (",MP","                       Create phony target for each dependency (other than main file)")
            (",MQ",po::value(&m_MQ),"   <value>             Specify target to quote for dependency")
            (",MT",po::value(&m_MT),"   <value>             Specify target for dependency")
            (",O",po::value(&m_O),"                 Optimization level")
            (",ObjC","                     Treat source input files as Objective-C inputs")
            (",ObjC++","                   Treat source input files as Objective-C++ inputs")
            (",Os","                       Optimize for size")
            (",Oz","                       Optimize for size, regardless of performance")
            (",P","                        Disable linemarker output in -E mode")
            (",Qunused-arguments","        Don't emit warning for unused driver arguments")
            (",S","                        Only run preprocess and compilation steps")
            (",U",po::value(&m_U),"   <macro>              Undefine the specified macro")
            (",Wa",po::value(&m_Wa),"                 Pass the comma separated arguments in <arg> to the assembler")
            (",Wl",po::value(&m_Wl),"                 Pass the comma separated arguments in <arg> to the linker")
            (",Wlarge-by-value-copy",po::value(&m_Wlarge_by_value_copy),"   <value>                          Warn if a function definition returns or accepts an object larger in bytes that a given value")
            (",Wno-rewrite-macros","       Silence ObjC rewriting warnings")
            (",Wp",po::value(&m_Wp),"                 Pass the comma separated arguments in <arg> to the preprocessor")
            (",Xanalyzer",po::value(&m_Xanalyzer),"   <arg>        Pass <arg> to the static analyzer")
            (",Xassembler",po::value(&m_Xassembler),"   <arg>       Pass <arg> to the assembler")
            (",Xclang",po::value(&m_Xclang),"   <arg>           Pass <arg> to the clang compiler")
            (",Xlinker",po::value(&m_Xlinker),"   <arg>          Pass <arg> to the linker")
            (",Xpreprocessor",po::value(&m_Xpreprocessor),"   <arg>    Pass <arg> to the preprocessor")
            (",add-plugin",po::value(&m_add_plugin),"   <name>      Use the named plugin action in addition to the default action")
            ("analyze,analyze","                 Run the static analyzer")
            (",analyze-function",po::value(&m_analyze_function),"   <value>                          Run analysis on specific function")
            (",analyzer-checker",po::value(&m_analyzer_checker),"   <value>                          Choose analyzer checkers to enable")
            (",analyzer-checker-help","    Display the list of analyzer checkers that are available")
            (",analyzer-constraints",po::value(&m_analyzer_constraints),"   <value>                          Source Code Analysis - Symbolic Constraint Engines")
            (",analyzer-disable-checker",po::value(&m_analyzer_disable_checker),"   <value>                          Choose analyzer checkers to disable")
            (",analyzer-display-progress","                            Emit verbose output about the analyzer's progress")
            (",analyzer-eagerly-assume","                            Eagerly assume the truth/falseness of some symbolic constraints")
            (",analyzer-inline-max-function-size",po::value(&m_analyzer_inline_max_function_size),"   <value>                          Bound on the number of basic blocks in an inlined function (200 by default)")
            (",analyzer-inline-max-stack-depth",po::value(&m_analyzer_inline_max_stack_depth),"   <value>                          Bound on stack depth while inlining (4 by default)")
            (",analyzer-inlining-mode",po::value(&m_analyzer_inlining_mode),"   <value>                          Specify the function selection heuristic used during inlining")
            (",analyzer-ipa",po::value(&m_analyzer_ipa),"   <value>   Specify the inter-procedural analysis mode")
            (",analyzer-max-loop",po::value(&m_analyzer_max_loop),"   <value>                          The maximum number of times the analyzer will go through a loop")
            (",analyzer-max-nodes",po::value(&m_analyzer_max_nodes),"   <value>                          The maximum number of nodes the analyzer can generate (150000 default, 0 = no limit)")
            (",analyzer-no-eagerly-trim-egraph","                            Don't eagerly remove uninteresting ExplodedNodes from the ExplodedGraph")
            (",analyzer-opt-analyze-headers","                            Force the static analyzer to analyze functions defined in header files")
            (",analyzer-opt-analyze-nested-blocks","                            Analyze the definitions of blocks in addition to functions")
            (",analyzer-output",po::value(&m_analyzer_output),"   <value>                          Source Code Analysis - Output Options")
            (",analyzer-purge",po::value(&m_analyzer_purge),"   <value> Source Code Analysis - Dead Symbol Removal Frequency")
            (",analyzer-stats","           Print internal analyzer statistics.")
            (",analyzer-store",po::value(&m_analyzer_store),"   <value> Source Code Analysis - Abstract Memory Store Models")
            (",analyzer-viz-egraph-graphviz","                            Display exploded graph using GraphViz")
            (",analyzer-viz-egraph-ubigraph","                            Display exploded graph using Ubigraph")
            (",arcmt-check","              Check for ARC migration issues that need manual handling")
            (",arcmt-migrate","            Apply modifications and produces temporary files that conform to ARC")
            (",arcmt-migrate-emit-errors","                            Emit ARC errors even if the migrator can fix them")
            (",arcmt-migrate-report-output",po::value(&m_arcmt_migrate_report_output),"   <value>                          Output path for the plist report")
            (",arcmt-modify","             Apply modifications to files to conform to ARC")
            (",ast-dump","                 Build ASTs and then debug dump them")
            (",ast-dump-xml","             Build ASTs and then debug dump them in a verbose XML format")
            (",ast-merge","   <ast file>   Merge the given AST file into the translation unit being compiled.")
            (",ast-print","                Build ASTs and then pretty-print them")
            (",ast-view","                 Build ASTs and view them with GraphViz")
            (",backend-option",po::value(&m_backend_option),"   <value> Additional arguments to forward to LLVM backend (during code gen)")
            (",c","                        Only run preprocess, compile, and assemble steps")
            (",c-isystem",po::value(&m_c_isystem),"   <directory>  Add directory to the C SYSTEM include search path")
            (",cfg-add-implicit-dtors","   Add C++ implicit destructors to CFGs for all analyses")
            (",cfg-add-initializers","     Add C++ initializers to CFGs for all analyses")
            (",chain-include",po::value(&m_chain_include),"   <file>   Include and chain a header file after turning it into PCH")
            (",cl-fast-relaxed-math","     OpenCL only. Sets -cl-finite-math-only and -cl-unsafe-math-optimizations, and defines __FAST_RELAXED_MATH__")
            (",cl-finite-math-only","      OpenCL only. Allow floating-point optimizations that assume arguments and results are not NaNs or +-Inf.")
            (",cl-mad-enable","            OpenCL only. Enable less precise MAD instructions to be generated.")
            (",cl-opt-disable","           OpenCL only. This option disables all optimizations. The default is optimizations are enabled.")
            (",cl-single-precision-constant","                            OpenCL only. Treat double precision floating-point constant as single precision constant.")
            (",cl-std",po::value(&m_cl_std),"           OpenCL language standard to compile for")
            (",cl-unsafe-math-optimizations","                            OpenCL only. Allow unsafe floating-point optimizations.  Also implies -cl-no-signed-zeros and -cl-mad-enable")
            (",code-completion-at",po::value(&m_code_completion_at),"   <file>:<line>:<column>                          Dump code-completion information at a location")
            (",code-completion-macros","   Include macros in code-completion results")
            (",code-completion-patterns","                            Include code patterns in code-completion results")
            (",coverage-file",po::value(&m_coverage_file),"   <value>  Emit coverage data to this filename. The extension will be replaced.")
            (",cxx-abi",po::value(&m_cxx_abi),"   <value>        Target a particular C++ ABI type")
            (",cxx-isystem",po::value(&m_cxx_isystem),"   <directory>                          Add directory to the C++ SYSTEM include search path")
            (",dD","                       Print macro definitions in -E mode in addition to normal output")
            (",dM","                       Print macro definitions in -E mode instead of normal output")
            (",dependency-dot",po::value(&m_dependency_dot),"   <value> Filename to write DOT-formatted header dependencies to")
            (",dependency-file",po::value(&m_dependency_file),"   <value>                          Filename (or -) to write dependency output to")
            (",detailed-preprocessing-record","                            include a detailed record of preprocessing actions")
            (",diagnostic-log-file",po::value(&m_diagnostic_log_file),"   <value>                          Filename (or -) to log diagnostics to")
            (",disable-free","             Disable freeing of memory on exit")
            (",disable-llvm-optzns","      Don't run LLVM optimization passes")
            (",disable-llvm-verifier","    Don't run the LLVM IR verifier pass")
            (",disable-red-zone","         Do not emit code that uses the red zone.")
            (",dump-build-information",po::value(&m_dump_build_information),"   <filename>                          output a dump of some build information to a file")
            (",dump-deserialized-decls","                            Dump declarations that are deserialized from PCH, for testing")
            (",dump-raw-tokens","          Lex file in raw mode and dump raw tokens")
            (",dump-tokens","              Run preprocessor, dump internal rep of tokens")
            (",dwarf-debug-flags",po::value(&m_dwarf_debug_flags),"   <value>                          The string to embed in the Dwarf debug flags record.")
            (",emit-ast","                 Emit Clang AST files for source inputs")
            (",emit-codegen-only","        Generate machine code, but discard output")
            (",emit-html","                Output input source as HTML")
            (",emit-llvm","                Use the LLVM representation for assembler and object files")
            (",emit-llvm-bc","             Build ASTs then convert to LLVM, emit .bc file")
            (",emit-llvm-only","           Build ASTs and convert to LLVM, discarding output")
            (",emit-module","              Generate pre-compiled module file from a module map")
            (",emit-obj","                 Emit native object files")
            (",emit-pch","                 Generate pre-compiled header file")
            (",emit-pth","                 Generate pre-tokenized header file")
            (",error-on-deserialized-decl",po::value(&m_error_on_deserialized_decl),"   <value>                          Emit error if a specific declaration is deserialized from PCH, for testing")
            (",faddress-sanitizer","       Enable AddressSanitizer instrumentation (memory error detection)")
            (",faltivec","                 Enable AltiVec vector initializer syntax")
            (",fapple-kext","              Use Apple's kernel extensions ABI")
            (",fapple-pragma-pack","       Enable Apple gcc-compatible #pragma pack handling")
            (",fblocks","                  Enable the 'blocks' language feature")
            (",fblocks-runtime-optional","                            Weakly link in the blocks runtime")
            (",fborland-extensions","      Accept non-standard constructs supported by the Borland compiler")
            (",fcatch-undefined-behavior","                            Generate runtime checks for undefined behavior.")
            (",fcolor-diagnostics","       Use colors in diagnostics")
            (",fconst-strings","           Use a const qualified type for string literals in C and ObjC")
            (",fconstant-string-class","   <class name>                          Specify the class to use for constant Objective-C string objects.")
            (",fconstexpr-backtrace-limit",po::value(&m_fconstexpr_backtrace_limit),"   <N>                          Set the maximum number of entries to print in a constexpr evaluation backtrace (0 = no limit).")
            (",fconstexpr-depth",po::value(&m_fconstexpr_depth),"   <value>                          Maximum depth of recursive constexpr function calls")
            (",fcuda-is-device","          Generate code for CUDA device")
            (",fcxx-exceptions","          Enable C++ exceptions")
            (",fdata-sections","           Place each data in its own section (ELF Only)")
            (",fdebug-compilation-dir",po::value(&m_fdebug_compilation_dir),"   <value>                          The compilation directory to embed in the debug info.")
            (",fdebugger-cast-result-to-id","                            Enable casting unknown expression results to id")
            (",fdebugger-objc-literal","   Enable special debugger support for objective-C subscripting and literals")
            (",fdebugger-support","        Enable special debugger support behavior")
            (",fdelayed-template-parsing","                            Parse templated function definitions at the end of the translation unit ")
            (",fdeprecated-macro","        Defines the __DEPRECATED macro")
            (",fdiagnostics-format",po::value(&m_fdiagnostics_format),"   <value>                          Change diagnostic formatting to match IDE and command line tools")
            (",fdiagnostics-parseable-fixits","                            Print fix-its in machine parseable form")
            (",fdiagnostics-print-source-range-info","                            Print source range spans in numeric form")
            (",fdiagnostics-show-category",po::value(&m_fdiagnostics_show_category),"   <value>                          Print diagnostic category")
            (",fdiagnostics-show-note-include-stack","                            Display include stacks for diagnostic notes")
            (",fdiagnostics-show-option","                            Print option name with mappable diagnostics")
            (",fdisable-module-hash","     Disable the module hash")
            (",fdollars-in-identifiers","                            Allow '$' in identifiers")
            (",fdump-record-layouts","     Dump record layout information")
            (",fdump-record-layouts-simple","                            Dump record layout information in a simple form used for testing")
            (",fdump-vtable-layouts","     Dump the layouts of all vtables that will be emitted in a translation unit")
            (",femit-all-decls","          Emit all declarations, even if unused")
            (",femit-coverage-data","      Instrument the program to emit gcov coverage data when run.")
            (",femit-coverage-notes","     Emit a gcov coverage notes file when compiling.")
            (",ferror-limit",po::value(&m_ferror_limit),"   <N>       Set the maximum number of errors to emit before stopping (0 = no limit).")
            (",fexceptions","              Enable support for exception handling")
            (",ffake-address-space-map","                            Use a fake address space map; OpenCL testing purposes only")
            (",ffast-math","               Enable the *frontend*'s 'fast-math' mode. This has no effect on optimizations, but provides a preprocessor macro __FAST_MATH__ the same as GCC's  flag.")
            (",fforbid-guard-variables","                            Emit an error if a C++ static local initializer would need a guard variable")
            (",ffreestanding","            Assert that the compilation takes place in a freestanding environment")
            (",ffunction-sections","       Place each function in its own section (ELF Only)")
            (",fgnu-keywords","            Allow GNU-extension keywords regardless of language standard")
            (",fgnu-runtime","             Generate output compatible with the standard GNU Objective-C runtime")
            (",fgnu89-inline","            Use the gnu89 inline semantics")
            (",fhidden-weak-vtables","     Generate weak vtables and RTTI with hidden visibility")
            (",finstrument-functions","    Generate calls to instrument function entry and exit")
            (",fix-only-warnings","        Apply fix-it advice only for warnings, not errors")
            (",fix-what-you-can","         Apply fix-it advice even in the presence of unfixable errors")
            (",fixit",po::value(&m_fixit),"            Apply fix-it advice creating a file with the given suffix")
            (",fixit-recompile","          Apply fix-it changes and recompile")
            (",fixit-to-temporary","       Apply fix-it changes to temporary files")
            (",flimit-debug-info","        Limit debug information produced to reduce size of debug binary")
            (",fmacro-backtrace-limit",po::value(&m_fmacro_backtrace_limit),"   <N>                          Set the maximum number of entries to print in a macro expansion backtrace (0 = no limit).")
            (",fmath-errno","              Require math functions to indicate errors by setting errno")
            (",fmessage-length",po::value(&m_fmessage_length),"   <N>    Format message diagnostics so that they fit within N columns or fewer, when possible.")
            (",fmodule-cache-path",po::value(&m_fmodule_cache_path),"   <directory>                          Specify the module cache path")
            (",fmodule-name",po::value(&m_fmodule_name),"      Specify the name of the module to build")
            (",fmodules","                 Enable the 'modules' language feature")
            (",fms-compatibility","        Enable Microsoft compatibility mode")
            (",fms-extensions","           Accept some non-standard constructs supported by the Microsoft compiler")
            (",fmsc-version",po::value(&m_fmsc_version),"     Version of the Microsoft C/C++ compiler to report in _MSC_VER (0 = don't define it (default))")
            (",fno-access-control","       Disable C++ access control")
            (",fno-assume-sane-operator-new","                            Don't assume that C++'s global operator new can't alias any pointer")
            (",fno-bitfield-type-align","                            Ignore bit-field types when aligning structures")
            (",fno-builtin","              Disable implicit builtin knowledge of functions")
            (",fno-caret-diagnostics","    Do not include source line and caret with diagnostics")
            (",fno-common","               Compile common globals like normal definitions")
            (",fno-const-strings","        Don't use a const qualified type for string literals in C and ObjC")
            (",fno-constant-cfstrings","   Enable creation of CodeFoundation-type constant strings")
            (",fno-deprecated-macro","     Undefines the __DEPRECATED macro")
            (",fno-diagnostics-fixit-info","                            Do not include fixit information in diagnostics")
            (",fno-diagnostics-show-note-include-stack","                            Display include stacks for diagnostic notes")
            (",fno-dollars-in-identifiers","                            Disallow '$' in identifiers")
            (",fno-dwarf-directory-asm","                            Don't separate directory and filename in .file directives")
            (",fno-dwarf2-cfi-asm","       Don't use the cfi directives")
            (",fno-elide-constructors","   Disable C++ copy constructor elision")
            (",fno-gnu-keywords","         Disallow GNU-extension keywords regardless of language standard")
            (",fno-inline","               Disable use of the inline keyword")
            (",fno-inline-functions","     Disable automatic function inlining")
            (",fno-lax-vector-conversions","                            Disallow implicit conversions between vectors with a different number of elements or different element types")
            (",fno-limit-debug-info","     Do not limit debug information produced to reduce size of debug binary")
            (",fno-merge-all-constants","                            Disallow merging of constants.")
            (",fno-objc-infer-related-result-type","                            do not infer Objective-C related result type based on method family")
            (",fno-operator-names","       Do not treat C++ operator name keywords as synonyms for operators")
            (",fno-rtti","                 Disable generation of rtti information")
            (",fno-show-column","          Do not include column number on diagnostics")
            (",fno-show-source-location","                            Do not include source location information with diagnostics")
            (",fno-signed-char","          Char is unsigned")
            (",fno-spell-checking","       Disable spell-checking")
            (",fno-threadsafe-statics","   Do not emit code to make initialization of local statics thread safe")
            (",fno-use-cxa-atexit","       Don't use __cxa_atexit for calling destructors")
            (",fno-validate-pch","         Disable validation of precompiled headers")
            (",fobjc-arc","                Synthesize retain and release calls for Objective-C pointers")
            (",fobjc-arc-cxxlib",po::value(&m_fobjc_arc_cxxlib),"                            Objective-C++ Automatic Reference Counting standard library kind")
            (",fobjc-arc-exceptions","     Use EH-safe code when synthesizing retains and releases in -fobjc-arc")
            (",fobjc-default-synthesize-properties","                            enable the default synthesis of Objective-C properties")
            (",fobjc-dispatch-method",po::value(&m_fobjc_dispatch_method),"                            Objective-C dispatch method to use")
            (",fobjc-exceptions","         Enable Objective-C exceptions")
            (",fobjc-fragile-abi","        Use Objective-C's fragile ABI")
            (",fobjc-gc","                 Enable Objective-C garbage collection")
            (",fobjc-gc-only","            Use GC exclusively for Objective-C related memory management")
            (",fobjc-runtime-has-arc","    The target Objective-C runtime provides ARC entrypoints")
            (",fobjc-runtime-has-terminate","                            The target Objective-C runtime provides an objc_terminate entrypoint")
            (",fobjc-runtime-has-weak","   The target Objective-C runtime supports ARC weak operations")
            (",foverride-record-layout",po::value(&m_foverride_record_layout),"                            Override record layouts with those in the given file")
            (",fpack-struct",po::value(&m_fpack_struct),"   <value>   Specify the default maximum struct packing alignment")
            (",fpascal-strings","          Recognize and construct Pascal-style string literals")
            (",fshort-enums","             Allocate to an enum type only as many bytes as it needs for the declared range of possible values")
            (",fshort-wchar","             Force wchar_t to be a short unsigned int")
            (",fshow-column","             Include column number on diagnostics")
            (",fshow-overloads",po::value(&m_fshow_overloads),"                            Which overload candidates to show when overload resolution fails: best|all; defaults to all")
            (",fsjlj-exceptions","         Use SjLj style exceptions")
            (",fsyntax-only","             Run parser and perform semantic analysis")
            (",ftabstop",po::value(&m_ftabstop),"   <N>           Set the tab stop distance.")
            (",ftemplate-backtrace-limit",po::value(&m_ftemplate_backtrace_limit),"   <N>                          Set the maximum number of entries to print in a template instantiation backtrace (0 = no limit).")
            (",ftemplate-depth",po::value(&m_ftemplate_depth),"   <value>                          Maximum depth of recursive template instantiation")
            (",ftime-report","             Print the amount of time each phase of compilation takes")
            (",ftrap-function",po::value(&m_ftrap_function),"   Issue call to specified function rather than a trap instruction")
            (",ftrapv","                   Trap on integer overflow")
            (",ftrapv-handler","   <function name>                          Specify the function to be called on overflow.")
            (",funknown-anytype","         Enable parser support for the __unknown_anytype type; for testing purposes only")
            (",funroll-loops","            Turn on loop unroller")
            (",fuse-register-sized-bitfield-access","                            Use register sized accesses to bit-fields, when possible.")
            (",fvisibility",po::value(&m_fvisibility),"   <value>    Default symbol visibility")
            (",fvisibility-inlines-hidden","                            Give inline C++ member functions default visibility by default")
            (",fwrapv","                   Treat signed integer overflow as two's complement")
            (",fwritable-strings","        Store string literals as writable data")
            (",g","                        Generate source level debug information")
            (",gcc-toolchain",po::value(&m_gcc_toolchain),"   <value>  Use the gcc toolchain at the given directory")
            (",header-include-file",po::value(&m_header_include_file),"   <value>                          Filename (or -) to write header include output to")
            ("help,help","                    Display available options")
            (",idirafter",po::value(&m_idirafter),"   <directory>  Add directory to AFTER include search path")
            (",iframework",po::value(&m_iframework),"   <directory> Add directory to SYSTEM framework search path")
            (",imacros",po::value(&m_imacros),"   <file>         Include macros from file before parsing")
            (",include",po::value(&m_include),"   <file>         Include file before parsing")
            (",include-pch",po::value(&m_include_pch),"   <file>     Include precompiled header file")
            (",include-pth",po::value(&m_include_pth),"   <file>     Include file before parsing")
            (",index-header-map","         Make the next included directory (-I or -F) an indexer header map")
            (",init-only","                Only execute frontend initialization")
            (",internal-externc-isystem",po::value(&m_internal_externc_isystem),"   <directory>                          Add directory to the internal system include search path with implicit extern \"C\" semantics; these are assumed to not be user-provided and are used to model system and standard headers' paths.")
            (",internal-isystem",po::value(&m_internal_isystem),"   <directory>                          Add directory to the internal system include search path; these are assumed to not be user-provided and are used to model system and standard headers' paths.")
            (",iprefix",po::value(&m_iprefix),"   <prefix>       Set the -iwithprefix/-iwithprefixbefore prefix")
            (",iquote",po::value(&m_iquote),"   <directory>     Add directory to QUOTE include search path")
            (",isysroot",po::value(&m_isysroot),"   <dir>         Set the system root directory (usually /)")
            (",isystem",po::value(&m_isystem),"   <directory>    Add directory to SYSTEM include search path")
            (",iwithprefix",po::value(&m_iwithprefix),"   <dir>      Set directory to SYSTEM include search path with prefix")
            (",iwithprefixbefore",po::value(&m_iwithprefixbefore),"   <dir>                          Set directory to include search path with prefix")
            (",iwithsysroot",po::value(&m_iwithsysroot),"   <directory>                          Add directory to SYSTEM include search path, absolute paths are relative to -isysroot")
            (",load",po::value(&m_load),"   <dsopath>         Load the named plugin (dynamic shared object)")
            (",main-file-name",po::value(&m_main_file_name),"   <value> Main file name to use for debug info")
            (",masm-verbose","             Generate verbose assembly output")
            (",mcode-model",po::value(&m_mcode_model),"   <value>    The code model to use")
            (",mconstructor-aliases","     Emit complete constructors and destructors as aliases when possible")
            (",mdebug-pass",po::value(&m_mdebug_pass),"   <value>    Enable additional debug output")
            (",mdisable-fp-elim","         Disable frame pointer elimination optimization")
            (",mdisable-tail-calls","      Disable tail call optimization, keeping the call stack accurate")
            (",menable-no-infs","          Allow optimization to assume there are no infinities.")
            (",menable-no-nans","          Allow optimization to assume there are no NaNs.")
            (",menable-unsafe-fp-math","   Allow unsafe floating-point math optimizations which may decrease precision")
            (",mfloat-abi",po::value(&m_mfloat_abi),"   <value>     The float ABI to use")
            ("migrate,migrate","                 Run the migrator")
            (",mlimit-float-precision",po::value(&m_mlimit_float_precision),"   <value>                          Limit float precision to the given value")
            (",mlink-bitcode-file",po::value(&m_mlink_bitcode_file),"   <value>                          Link the given bitcode file before performing optimizations.")
            (",mllvm",po::value(&m_mllvm),"   <value>          Additional arguments to forward to LLVM's option processing")
            (",mms-bitfields","            Set the default structure layout to be compatible with the Microsoft compiler standard.")
            (",mno-global-merge","         Disable merging of globals")
            (",mno-zero-initialized-in-bss","                            Do not put zero initialized data in the BSS")
            (",mnoexecstack","             Mark the file as not needing an executable stack")
            (",momit-leaf-frame-pointer","                            Omit frame pointer setup for leaf functions.")
            (",mqdsp6-compat","            Enable hexagon-qdsp6 backward compatibility")
            (",mregparm",po::value(&m_mregparm),"   <value>       Limit the number of registers available for integer arguments")
            (",mrelax-all","               (integrated-as) Relax all machine instructions")
            (",mrelocation-model",po::value(&m_mrelocation_model),"   <value>                          The relocation model to use")
            (",mrtd","                     Make StdCall calling convention the default")
            (",msave-temp-labels","        (integrated-as) Save temporary labels")
            (",msoft-float","              Use software floating point")
            (",mstack-alignment",po::value(&m_mstack_alignment),"                            Set the stack alignment")
            (",mstackrealign","            Force realign the stack at entry to every function.")
            (",mt-migrate-directory",po::value(&m_mt_migrate_directory),"   <value>                          Directory for temporary files produced during ARC or ObjC migration")
            (",munwind-tables","           Generate unwinding tables for all functions")
            (",no-code-completion-globals","                            Do not include global declarations in code-completion results.")
            (",no-finalize-removal","      Do not remove finalize method in gc mode")
            (",no-implicit-float","        Don't generate implicit floating point instructions (x86-only)")
            (",no-ns-alloc-error","        Do not error on use of NSAllocateCollectable/NSReallocateCollectable")
            (",nobuiltininc","             Disable builtin #include directories")
            (",nostdinc++","               Disable standard #include directories for the C++ standard library")
            (",nostdsysteminc","           Disable standard system #include directories")
            (",o",po::value(&m_o),"   <file>               Write output to <file>")
            (",objc-isystem",po::value(&m_objc_isystem),"   <directory>                          Add directory to the ObjC SYSTEM include search path")
            (",objcmt-migrate-literals","                            Enable migration to modern ObjC literals")
            (",objcmt-migrate-subscripting","                            Enable migration to modern ObjC subscripting")
            (",objcxx-isystem",po::value(&m_objcxx_isystem),"   <directory>                          Add directory to the ObjC++ SYSTEM include search path")
            (",pg","                       Enable mcount instrumentation")
            (",pic-level",po::value(&m_pic_level),"   <value>      Value for __PIC__")
            (",pipe","                     Use pipes between commands, when possible")
            (",plugin",po::value(&m_plugin),"   <name>          Use the named plugin action instead of the default action (use \"help\" to list available options)")
            (",plugin-arg",po::value(&m_plugin_arg),"   <arg>                          Pass <arg> to plugin <name>")
            (",preamble-bytes",po::value(&m_preamble_bytes),"   Assume that the precompiled header is a precompiled preamble covering the first N bytes of the main file")
            (",print-decl-contexts","      Print DeclContexts and their Decls")
            (",print-file-name",po::value(&m_print_file_name),"   Print the full library path of <file>")
            (",print-ivar-layout","        Enable Objective-C Ivar layout bitmap print trace")
            (",print-libgcc-file-name","   Print the library path for \"libgcc.a\"")
            (",print-preamble","           Print the \"preamble\" of a file, which is a candidate for implicit precompiled headers.")
            (",print-prog-name",po::value(&m_print_prog_name),"   Print the full program path of <name>")
            (",print-search-dirs","        Print the paths used for finding libraries and programs")
            (",print-stats","              Print performance metrics and statistics")
            (",pthread","                  Support POSIX threads in generated code")
            (",pubnames-dump","            Print all of the public (global) names in the source, e.g., the names of all global declarations and macros")
            (",relaxed-aliasing","         Turn off Type Based Alias Analysis")
            ("relocatable-pch,relocatable-pch","         Build a relocatable precompiled header")
            (",remap-file",po::value(&m_remap_file),"   <from>;<to> Replace the contents of the <from> file with the contents of the <to> file")
            (",resource-dir",po::value(&m_resource_dir),"   <value>   The directory which holds the compiler resource files")
            (",rewrite-macros","           Expand macros without full preprocessing")
            (",rewrite-objc","             Rewrite Objective-C source to C++")
            (",rewrite-test","             Rewriter playground")
            (",save-temps","               Save intermediate compilation results")
            (",serialize-diagnostic-file",po::value(&m_serialize_diagnostic_file),"   <filename>                          File for serializing diagnostics in a binary format")
            ("serialize-diagnostics,serialize-diagnostics",po::value(&m_serialize_diagnostics),"   <value>                          Serialize compiler diagnostics to a file")
            (",stack-protector",po::value(&m_stack_protector),"   <value>                          Enable stack protectors")
            (",static-define","            Should __STATIC__ be defined")
            (",std",po::value(&m_std),"              Language standard to compile for")
            (",stdlib",po::value(&m_stdlib),"           C++ standard library to use")
            (",sys-header-deps","          Include system headers in dependency output")
            (",target",po::value(&m_target),"   <value>         Generate code for the given target")
            (",target-abi",po::value(&m_target_abi),"   <value>     Target a particular ABI type")
            (",target-cpu",po::value(&m_target_cpu),"   <value>     Target a specific cpu type")
            (",target-feature",po::value(&m_target_feature),"   <value> Target specific attributes")
            (",target-linker-version",po::value(&m_target_linker_version),"   <value>                          Target linker version")
            (",time","                     Time individual commands")
            (",token-cache",po::value(&m_token_cache),"   <path>     Use specified token cache file")
            (",traditional-cpp","          Enable some traditional CPP emulation")
            (",trigraphs","                Process trigraph sequences")
            (",trim-egraph","              Only show error-related paths in the analysis graph")
            (",triple",po::value(&m_triple),"   <value>         Specify target triple (e.g. i686-apple-darwin9)")
            (",undef","                    undef all system defines")
            (",unoptimized-cfg","          Generate unoptimized CFGs for all analyses")
            (",v","                        Show commands to run and use verbose output")
            (",verify","                   Verify output using a verifier.")
            (",version","                  Print the compiler version")
            (",w","                        Suppress all warnings")
            (",working-directory",po::value(&m_working_directory),"   <value>                          Resolve file paths relative to the specified directory")
        ;
        po::variables_map vm;
        po::store(po::parse_command_line(m_argc, m_argv, desc), vm);
        if (vm.count("help")) {
            cout << desc << "\n";
            return;
        }
        if(vm.count("###")){
            m_spspsp = true;
        }
        if(vm.count("C")){
            m_C = true;
        }
        if(vm.count("CC")){
            m_CC = true;
        }
        if(vm.count("D")){
            m_D = vm["D"].as<string>();
        }
        if(vm.count("E")){
            m_E = true;
        }
        if(vm.count("Eonly")){
            m_Eonly = true;
        }
        if(vm.count("F")){
            m_F = vm["F"].as<string>();
        }
        if(vm.count("H")){
            m_H = true;
        }
        if(vm.count("I")){
            m_I = vm["I"].as<string>();
        }
        if(vm.count("MG")){
            m_MG = true;
        }
        if(vm.count("MP")){
            m_MP = true;
        }
        if(vm.count("MQ")){
            m_MQ = vm["MQ"].as<string>();
        }
        if(vm.count("MT")){
            m_MT = vm["MT"].as<string>();
        }
        if(vm.count("O")){
            m_O = vm["O"].as<string>();
        }
        if(vm.count("ObjC")){
            m_ObjC = true;
        }
        if(vm.count("ObjC++")){
            m_ObjCplusplus = true;
        }
        if(vm.count("Os")){
            m_Os = true;
        }
        if(vm.count("Oz")){
            m_Oz = true;
        }
        if(vm.count("P")){
            m_P = true;
        }
        if(vm.count("Qunused-arguments")){
            m_Qunused_arguments = true;
        }
        if(vm.count("S")){
            m_S = true;
        }
        if(vm.count("U")){
            m_U = vm["U"].as<string>();
        }
        if(vm.count("Wa")){
            m_Wa = vm["Wa"].as<string>();
        }
        if(vm.count("Wl")){
            m_Wl = vm["Wl"].as<string>();
        }
        if(vm.count("Wlarge-by-value-copy")){
            m_Wlarge_by_value_copy = vm["Wlarge-by-value-copy"].as<string>();
        }
        if(vm.count("Wno-rewrite-macros")){
            m_Wno_rewrite_macros = true;
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
        if(vm.count("add-plugin")){
            m_add_plugin = vm["add-plugin"].as<string>();
        }
        if(vm.count("analyze")){
            m_analyze = true;
        }
        if(vm.count("analyze-function")){
            m_analyze_function = vm["analyze-function"].as<string>();
        }
        if(vm.count("analyzer-checker")){
            m_analyzer_checker = vm["analyzer-checker"].as<string>();
        }
        if(vm.count("analyzer-checker-help")){
            m_analyzer_checker_help = true;
        }
        if(vm.count("analyzer-constraints")){
            m_analyzer_constraints = vm["analyzer-constraints"].as<string>();
        }
        if(vm.count("analyzer-disable-checker")){
            m_analyzer_disable_checker = vm["analyzer-disable-checker"].as<string>();
        }
        if(vm.count("analyzer-display-progress")){
            m_analyzer_display_progress = true;
        }
        if(vm.count("analyzer-eagerly-assume")){
            m_analyzer_eagerly_assume = true;
        }
        if(vm.count("analyzer-inline-max-function-size")){
            m_analyzer_inline_max_function_size = vm["analyzer-inline-max-function-size"].as<string>();
        }
        if(vm.count("analyzer-inline-max-stack-depth")){
            m_analyzer_inline_max_stack_depth = vm["analyzer-inline-max-stack-depth"].as<string>();
        }
        if(vm.count("analyzer-inlining-mode")){
            m_analyzer_inlining_mode = vm["analyzer-inlining-mode"].as<string>();
        }
        if(vm.count("analyzer-ipa")){
            m_analyzer_ipa = vm["analyzer-ipa"].as<string>();
        }
        if(vm.count("analyzer-max-loop")){
            m_analyzer_max_loop = vm["analyzer-max-loop"].as<string>();
        }
        if(vm.count("analyzer-max-nodes")){
            m_analyzer_max_nodes = vm["analyzer-max-nodes"].as<string>();
        }
        if(vm.count("analyzer-no-eagerly-trim-egraph")){
            m_analyzer_no_eagerly_trim_egraph = true;
        }
        if(vm.count("analyzer-opt-analyze-headers")){
            m_analyzer_opt_analyze_headers = true;
        }
        if(vm.count("analyzer-opt-analyze-nested-blocks")){
            m_analyzer_opt_analyze_nested_blocks = true;
        }
        if(vm.count("analyzer-output")){
            m_analyzer_output = vm["analyzer-output"].as<string>();
        }
        if(vm.count("analyzer-purge")){
            m_analyzer_purge = vm["analyzer-purge"].as<string>();
        }
        if(vm.count("analyzer-stats")){
            m_analyzer_stats = true;
        }
        if(vm.count("analyzer-store")){
            m_analyzer_store = vm["analyzer-store"].as<string>();
        }
        if(vm.count("analyzer-viz-egraph-graphviz")){
            m_analyzer_viz_egraph_graphviz = true;
        }
        if(vm.count("analyzer-viz-egraph-ubigraph")){
            m_analyzer_viz_egraph_ubigraph = true;
        }
        if(vm.count("arcmt-check")){
            m_arcmt_check = true;
        }
        if(vm.count("arcmt-migrate")){
            m_arcmt_migrate = true;
        }
        if(vm.count("arcmt-migrate-emit-errors")){
            m_arcmt_migrate_emit_errors = true;
        }
        if(vm.count("arcmt-migrate-report-output")){
            m_arcmt_migrate_report_output = vm["arcmt-migrate-report-output"].as<string>();
        }
        if(vm.count("arcmt-modify")){
            m_arcmt_modify = true;
        }
        if(vm.count("ast-dump")){
            m_ast_dump = true;
        }
        if(vm.count("ast-dump-xml")){
            m_ast_dump_xml = true;
        }
        if(vm.count("ast-merge")){
            m_ast_merge = true;
        }
        if(vm.count("ast-print")){
            m_ast_print = true;
        }
        if(vm.count("ast-view")){
            m_ast_view = true;
        }
        if(vm.count("backend-option")){
            m_backend_option = vm["backend-option"].as<string>();
        }
        if(vm.count("c")){
            m_c = true;
        }
        if(vm.count("c-isystem")){
            m_c_isystem = vm["c-isystem"].as<string>();
        }
        if(vm.count("cfg-add-implicit-dtors")){
            m_cfg_add_implicit_dtors = true;
        }
        if(vm.count("cfg-add-initializers")){
            m_cfg_add_initializers = true;
        }
        if(vm.count("chain-include")){
            m_chain_include = vm["chain-include"].as<string>();
        }
        if(vm.count("cl-fast-relaxed-math")){
            m_cl_fast_relaxed_math = true;
        }
        if(vm.count("cl-finite-math-only")){
            m_cl_finite_math_only = true;
        }
        if(vm.count("cl-mad-enable")){
            m_cl_mad_enable = true;
        }
        if(vm.count("cl-opt-disable")){
            m_cl_opt_disable = true;
        }
        if(vm.count("cl-single-precision-constant")){
            m_cl_single_precision_constant = true;
        }
        if(vm.count("cl-std")){
            m_cl_std = vm["cl-std"].as<string>();
        }
        if(vm.count("cl-unsafe-math-optimizations")){
            m_cl_unsafe_math_optimizations = true;
        }
        if(vm.count("code-completion-at")){
            m_code_completion_at = vm["code-completion-at"].as<string>();
        }
        if(vm.count("code-completion-macros")){
            m_code_completion_macros = true;
        }
        if(vm.count("code-completion-patterns")){
            m_code_completion_patterns = true;
        }
        if(vm.count("coverage-file")){
            m_coverage_file = vm["coverage-file"].as<string>();
        }
        if(vm.count("cxx-abi")){
            m_cxx_abi = vm["cxx-abi"].as<string>();
        }
        if(vm.count("cxx-isystem")){
            m_cxx_isystem = vm["cxx-isystem"].as<string>();
        }
        if(vm.count("dD")){
            m_dD = true;
        }
        if(vm.count("dM")){
            m_dM = true;
        }
        if(vm.count("dependency-dot")){
            m_dependency_dot = vm["dependency-dot"].as<string>();
        }
        if(vm.count("dependency-file")){
            m_dependency_file = vm["dependency-file"].as<string>();
        }
        if(vm.count("detailed-preprocessing-record")){
            m_detailed_preprocessing_record = true;
        }
        if(vm.count("diagnostic-log-file")){
            m_diagnostic_log_file = vm["diagnostic-log-file"].as<string>();
        }
        if(vm.count("disable-free")){
            m_disable_free = true;
        }
        if(vm.count("disable-llvm-optzns")){
            m_disable_llvm_optzns = true;
        }
        if(vm.count("disable-llvm-verifier")){
            m_disable_llvm_verifier = true;
        }
        if(vm.count("disable-red-zone")){
            m_disable_red_zone = true;
        }
        if(vm.count("dump-build-information")){
            m_dump_build_information = vm["dump-build-information"].as<string>();
        }
        if(vm.count("dump-deserialized-decls")){
            m_dump_deserialized_decls = true;
        }
        if(vm.count("dump-raw-tokens")){
            m_dump_raw_tokens = true;
        }
        if(vm.count("dump-tokens")){
            m_dump_tokens = true;
        }
        if(vm.count("dwarf-debug-flags")){
            m_dwarf_debug_flags = vm["dwarf-debug-flags"].as<string>();
        }
        if(vm.count("emit-ast")){
            m_emit_ast = true;
        }
        if(vm.count("emit-codegen-only")){
            m_emit_codegen_only = true;
        }
        if(vm.count("emit-html")){
            m_emit_html = true;
        }
        if(vm.count("emit-llvm")){
            m_emit_llvm = true;
        }
        if(vm.count("emit-llvm-bc")){
            m_emit_llvm_bc = true;
        }
        if(vm.count("emit-llvm-only")){
            m_emit_llvm_only = true;
        }
        if(vm.count("emit-module")){
            m_emit_module = true;
        }
        if(vm.count("emit-obj")){
            m_emit_obj = true;
        }
        if(vm.count("emit-pch")){
            m_emit_pch = true;
        }
        if(vm.count("emit-pth")){
            m_emit_pth = true;
        }
        if(vm.count("error-on-deserialized-decl")){
            m_error_on_deserialized_decl = vm["error-on-deserialized-decl"].as<string>();
        }
        if(vm.count("faddress-sanitizer")){
            m_faddress_sanitizer = true;
        }
        if(vm.count("faltivec")){
            m_faltivec = true;
        }
        if(vm.count("fapple-kext")){
            m_fapple_kext = true;
        }
        if(vm.count("fapple-pragma-pack")){
            m_fapple_pragma_pack = true;
        }
        if(vm.count("fblocks")){
            m_fblocks = true;
        }
        if(vm.count("fblocks-runtime-optional")){
            m_fblocks_runtime_optional = true;
        }
        if(vm.count("fborland-extensions")){
            m_fborland_extensions = true;
        }
        if(vm.count("fcatch-undefined-behavior")){
            m_fcatch_undefined_behavior = true;
        }
        if(vm.count("fcolor-diagnostics")){
            m_fcolor_diagnostics = true;
        }
        if(vm.count("fconst-strings")){
            m_fconst_strings = true;
        }
        if(vm.count("fconstant-string-class")){
            m_fconstant_string_class = true;
        }
        if(vm.count("fconstexpr-backtrace-limit")){
            m_fconstexpr_backtrace_limit = vm["fconstexpr-backtrace-limit"].as<string>();
        }
        if(vm.count("fconstexpr-depth")){
            m_fconstexpr_depth = vm["fconstexpr-depth"].as<string>();
        }
        if(vm.count("fcuda-is-device")){
            m_fcuda_is_device = true;
        }
        if(vm.count("fcxx-exceptions")){
            m_fcxx_exceptions = true;
        }
        if(vm.count("fdata-sections")){
            m_fdata_sections = true;
        }
        if(vm.count("fdebug-compilation-dir")){
            m_fdebug_compilation_dir = vm["fdebug-compilation-dir"].as<string>();
        }
        if(vm.count("fdebugger-cast-result-to-id")){
            m_fdebugger_cast_result_to_id = true;
        }
        if(vm.count("fdebugger-objc-literal")){
            m_fdebugger_objc_literal = true;
        }
        if(vm.count("fdebugger-support")){
            m_fdebugger_support = true;
        }
        if(vm.count("fdelayed-template-parsing")){
            m_fdelayed_template_parsing = true;
        }
        if(vm.count("fdeprecated-macro")){
            m_fdeprecated_macro = true;
        }
        if(vm.count("fdiagnostics-format")){
            m_fdiagnostics_format = vm["fdiagnostics-format"].as<string>();
        }
        if(vm.count("fdiagnostics-parseable-fixits")){
            m_fdiagnostics_parseable_fixits = true;
        }
        if(vm.count("fdiagnostics-print-source-range-info")){
            m_fdiagnostics_print_source_range_info = true;
        }
        if(vm.count("fdiagnostics-show-category")){
            m_fdiagnostics_show_category = vm["fdiagnostics-show-category"].as<string>();
        }
        if(vm.count("fdiagnostics-show-note-include-stack")){
            m_fdiagnostics_show_note_include_stack = true;
        }
        if(vm.count("fdiagnostics-show-option")){
            m_fdiagnostics_show_option = true;
        }
        if(vm.count("fdisable-module-hash")){
            m_fdisable_module_hash = true;
        }
        if(vm.count("fdollars-in-identifiers")){
            m_fdollars_in_identifiers = true;
        }
        if(vm.count("fdump-record-layouts")){
            m_fdump_record_layouts = true;
        }
        if(vm.count("fdump-record-layouts-simple")){
            m_fdump_record_layouts_simple = true;
        }
        if(vm.count("fdump-vtable-layouts")){
            m_fdump_vtable_layouts = true;
        }
        if(vm.count("femit-all-decls")){
            m_femit_all_decls = true;
        }
        if(vm.count("femit-coverage-data")){
            m_femit_coverage_data = true;
        }
        if(vm.count("femit-coverage-notes")){
            m_femit_coverage_notes = true;
        }
        if(vm.count("ferror-limit")){
            m_ferror_limit = vm["ferror-limit"].as<string>();
        }
        if(vm.count("fexceptions")){
            m_fexceptions = true;
        }
        if(vm.count("ffake-address-space-map")){
            m_ffake_address_space_map = true;
        }
        if(vm.count("ffast-math")){
            m_ffast_math = true;
        }
        if(vm.count("fforbid-guard-variables")){
            m_fforbid_guard_variables = true;
        }
        if(vm.count("ffreestanding")){
            m_ffreestanding = true;
        }
        if(vm.count("ffunction-sections")){
            m_ffunction_sections = true;
        }
        if(vm.count("fgnu-keywords")){
            m_fgnu_keywords = true;
        }
        if(vm.count("fgnu-runtime")){
            m_fgnu_runtime = true;
        }
        if(vm.count("fgnu89-inline")){
            m_fgnu89_inline = true;
        }
        if(vm.count("fhidden-weak-vtables")){
            m_fhidden_weak_vtables = true;
        }
        if(vm.count("finstrument-functions")){
            m_finstrument_functions = true;
        }
        if(vm.count("fix-only-warnings")){
            m_fix_only_warnings = true;
        }
        if(vm.count("fix-what-you-can")){
            m_fix_what_you_can = true;
        }
        if(vm.count("fixit")){
            m_fixit = vm["fixit"].as<string>();
        }
        if(vm.count("fixit-recompile")){
            m_fixit_recompile = true;
        }
        if(vm.count("fixit-to-temporary")){
            m_fixit_to_temporary = true;
        }
        if(vm.count("flimit-debug-info")){
            m_flimit_debug_info = true;
        }
        if(vm.count("fmacro-backtrace-limit")){
            m_fmacro_backtrace_limit = vm["fmacro-backtrace-limit"].as<string>();
        }
        if(vm.count("fmath-errno")){
            m_fmath_errno = true;
        }
        if(vm.count("fmessage-length")){
            m_fmessage_length = vm["fmessage-length"].as<string>();
        }
        if(vm.count("fmodule-cache-path")){
            m_fmodule_cache_path = vm["fmodule-cache-path"].as<string>();
        }
        if(vm.count("fmodule-name")){
            m_fmodule_name = vm["fmodule-name"].as<string>();
        }
        if(vm.count("fmodules")){
            m_fmodules = true;
        }
        if(vm.count("fms-compatibility")){
            m_fms_compatibility = true;
        }
        if(vm.count("fms-extensions")){
            m_fms_extensions = true;
        }
        if(vm.count("fmsc-version")){
            m_fmsc_version = vm["fmsc-version"].as<string>();
        }
        if(vm.count("fno-access-control")){
            m_fno_access_control = true;
        }
        if(vm.count("fno-assume-sane-operator-new")){
            m_fno_assume_sane_operator_new = true;
        }
        if(vm.count("fno-bitfield-type-align")){
            m_fno_bitfield_type_align = true;
        }
        if(vm.count("fno-builtin")){
            m_fno_builtin = true;
        }
        if(vm.count("fno-caret-diagnostics")){
            m_fno_caret_diagnostics = true;
        }
        if(vm.count("fno-common")){
            m_fno_common = true;
        }
        if(vm.count("fno-const-strings")){
            m_fno_const_strings = true;
        }
        if(vm.count("fno-constant-cfstrings")){
            m_fno_constant_cfstrings = true;
        }
        if(vm.count("fno-deprecated-macro")){
            m_fno_deprecated_macro = true;
        }
        if(vm.count("fno-diagnostics-fixit-info")){
            m_fno_diagnostics_fixit_info = true;
        }
        if(vm.count("fno-diagnostics-show-note-include-stack")){
            m_fno_diagnostics_show_note_include_stack = true;
        }
        if(vm.count("fno-dollars-in-identifiers")){
            m_fno_dollars_in_identifiers = true;
        }
        if(vm.count("fno-dwarf-directory-asm")){
            m_fno_dwarf_directory_asm = true;
        }
        if(vm.count("fno-dwarf2-cfi-asm")){
            m_fno_dwarf2_cfi_asm = true;
        }
        if(vm.count("fno-elide-constructors")){
            m_fno_elide_constructors = true;
        }
        if(vm.count("fno-gnu-keywords")){
            m_fno_gnu_keywords = true;
        }
        if(vm.count("fno-inline")){
            m_fno_inline = true;
        }
        if(vm.count("fno-inline-functions")){
            m_fno_inline_functions = true;
        }
        if(vm.count("fno-lax-vector-conversions")){
            m_fno_lax_vector_conversions = true;
        }
        if(vm.count("fno-limit-debug-info")){
            m_fno_limit_debug_info = true;
        }
        if(vm.count("fno-merge-all-constants")){
            m_fno_merge_all_constants = true;
        }
        if(vm.count("fno-objc-infer-related-result-type")){
            m_fno_objc_infer_related_result_type = true;
        }
        if(vm.count("fno-operator-names")){
            m_fno_operator_names = true;
        }
        if(vm.count("fno-rtti")){
            m_fno_rtti = true;
        }
        if(vm.count("fno-show-column")){
            m_fno_show_column = true;
        }
        if(vm.count("fno-show-source-location")){
            m_fno_show_source_location = true;
        }
        if(vm.count("fno-signed-char")){
            m_fno_signed_char = true;
        }
        if(vm.count("fno-spell-checking")){
            m_fno_spell_checking = true;
        }
        if(vm.count("fno-threadsafe-statics")){
            m_fno_threadsafe_statics = true;
        }
        if(vm.count("fno-use-cxa-atexit")){
            m_fno_use_cxa_atexit = true;
        }
        if(vm.count("fno-validate-pch")){
            m_fno_validate_pch = true;
        }
        if(vm.count("fobjc-arc")){
            m_fobjc_arc = true;
        }
        if(vm.count("fobjc-arc-cxxlib")){
            m_fobjc_arc_cxxlib = vm["fobjc-arc-cxxlib"].as<string>();
        }
        if(vm.count("fobjc-arc-exceptions")){
            m_fobjc_arc_exceptions = true;
        }
        if(vm.count("fobjc-default-synthesize-properties")){
            m_fobjc_default_synthesize_properties = true;
        }
        if(vm.count("fobjc-dispatch-method")){
            m_fobjc_dispatch_method = vm["fobjc-dispatch-method"].as<string>();
        }
        if(vm.count("fobjc-exceptions")){
            m_fobjc_exceptions = true;
        }
        if(vm.count("fobjc-fragile-abi")){
            m_fobjc_fragile_abi = true;
        }
        if(vm.count("fobjc-gc")){
            m_fobjc_gc = true;
        }
        if(vm.count("fobjc-gc-only")){
            m_fobjc_gc_only = true;
        }
        if(vm.count("fobjc-runtime-has-arc")){
            m_fobjc_runtime_has_arc = true;
        }
        if(vm.count("fobjc-runtime-has-terminate")){
            m_fobjc_runtime_has_terminate = true;
        }
        if(vm.count("fobjc-runtime-has-weak")){
            m_fobjc_runtime_has_weak = true;
        }
        if(vm.count("foverride-record-layout")){
            m_foverride_record_layout = vm["foverride-record-layout"].as<string>();
        }
        if(vm.count("fpack-struct")){
            m_fpack_struct = vm["fpack-struct"].as<string>();
        }
        if(vm.count("fpascal-strings")){
            m_fpascal_strings = true;
        }
        if(vm.count("fshort-enums")){
            m_fshort_enums = true;
        }
        if(vm.count("fshort-wchar")){
            m_fshort_wchar = true;
        }
        if(vm.count("fshow-column")){
            m_fshow_column = true;
        }
        if(vm.count("fshow-overloads")){
            m_fshow_overloads = vm["fshow-overloads"].as<string>();
        }
        if(vm.count("fsjlj-exceptions")){
            m_fsjlj_exceptions = true;
        }
        if(vm.count("fsyntax-only")){
            m_fsyntax_only = true;
        }
        if(vm.count("ftabstop")){
            m_ftabstop = vm["ftabstop"].as<string>();
        }
        if(vm.count("ftemplate-backtrace-limit")){
            m_ftemplate_backtrace_limit = vm["ftemplate-backtrace-limit"].as<string>();
        }
        if(vm.count("ftemplate-depth")){
            m_ftemplate_depth = vm["ftemplate-depth"].as<string>();
        }
        if(vm.count("ftime-report")){
            m_ftime_report = true;
        }
        if(vm.count("ftrap-function")){
            m_ftrap_function = vm["ftrap-function"].as<string>();
        }
        if(vm.count("ftrapv")){
            m_ftrapv = true;
        }
        if(vm.count("ftrapv-handler")){
            m_ftrapv_handler = true;
        }
        if(vm.count("funknown-anytype")){
            m_funknown_anytype = true;
        }
        if(vm.count("funroll-loops")){
            m_funroll_loops = true;
        }
        if(vm.count("fuse-register-sized-bitfield-access")){
            m_fuse_register_sized_bitfield_access = true;
        }
        if(vm.count("fvisibility")){
            m_fvisibility = vm["fvisibility"].as<string>();
        }
        if(vm.count("fvisibility-inlines-hidden")){
            m_fvisibility_inlines_hidden = true;
        }
        if(vm.count("fwrapv")){
            m_fwrapv = true;
        }
        if(vm.count("fwritable-strings")){
            m_fwritable_strings = true;
        }
        if(vm.count("g")){
            m_g = true;
        }
        if(vm.count("gcc-toolchain")){
            m_gcc_toolchain = vm["gcc-toolchain"].as<string>();
        }
        if(vm.count("header-include-file")){
            m_header_include_file = vm["header-include-file"].as<string>();
        }
        if(vm.count("help")){
            m_help = true;
        }
        if(vm.count("idirafter")){
            m_idirafter = vm["idirafter"].as<string>();
        }
        if(vm.count("iframework")){
            m_iframework = vm["iframework"].as<string>();
        }
        if(vm.count("imacros")){
            m_imacros = vm["imacros"].as<string>();
        }
        if(vm.count("include")){
            m_include = vm["include"].as<string>();
        }
        if(vm.count("include-pch")){
            m_include_pch = vm["include-pch"].as<string>();
        }
        if(vm.count("include-pth")){
            m_include_pth = vm["include-pth"].as<string>();
        }
        if(vm.count("index-header-map")){
            m_index_header_map = true;
        }
        if(vm.count("init-only")){
            m_init_only = true;
        }
        if(vm.count("internal-externc-isystem")){
            m_internal_externc_isystem = vm["internal-externc-isystem"].as<string>();
        }
        if(vm.count("internal-isystem")){
            m_internal_isystem = vm["internal-isystem"].as<string>();
        }
        if(vm.count("iprefix")){
            m_iprefix = vm["iprefix"].as<string>();
        }
        if(vm.count("iquote")){
            m_iquote = vm["iquote"].as<string>();
        }
        if(vm.count("isysroot")){
            m_isysroot = vm["isysroot"].as<string>();
        }
        if(vm.count("isystem")){
            m_isystem = vm["isystem"].as<string>();
        }
        if(vm.count("iwithprefix")){
            m_iwithprefix = vm["iwithprefix"].as<string>();
        }
        if(vm.count("iwithprefixbefore")){
            m_iwithprefixbefore = vm["iwithprefixbefore"].as<string>();
        }
        if(vm.count("iwithsysroot")){
            m_iwithsysroot = vm["iwithsysroot"].as<string>();
        }
        if(vm.count("load")){
            m_load = vm["load"].as<string>();
        }
        if(vm.count("main-file-name")){
            m_main_file_name = vm["main-file-name"].as<string>();
        }
        if(vm.count("masm-verbose")){
            m_masm_verbose = true;
        }
        if(vm.count("mcode-model")){
            m_mcode_model = vm["mcode-model"].as<string>();
        }
        if(vm.count("mconstructor-aliases")){
            m_mconstructor_aliases = true;
        }
        if(vm.count("mdebug-pass")){
            m_mdebug_pass = vm["mdebug-pass"].as<string>();
        }
        if(vm.count("mdisable-fp-elim")){
            m_mdisable_fp_elim = true;
        }
        if(vm.count("mdisable-tail-calls")){
            m_mdisable_tail_calls = true;
        }
        if(vm.count("menable-no-infs")){
            m_menable_no_infs = true;
        }
        if(vm.count("menable-no-nans")){
            m_menable_no_nans = true;
        }
        if(vm.count("menable-unsafe-fp-math")){
            m_menable_unsafe_fp_math = true;
        }
        if(vm.count("mfloat-abi")){
            m_mfloat_abi = vm["mfloat-abi"].as<string>();
        }
        if(vm.count("migrate")){
            m_migrate = true;
        }
        if(vm.count("mlimit-float-precision")){
            m_mlimit_float_precision = vm["mlimit-float-precision"].as<string>();
        }
        if(vm.count("mlink-bitcode-file")){
            m_mlink_bitcode_file = vm["mlink-bitcode-file"].as<string>();
        }
        if(vm.count("mllvm")){
            m_mllvm = vm["mllvm"].as<string>();
        }
        if(vm.count("mms-bitfields")){
            m_mms_bitfields = true;
        }
        if(vm.count("mno-global-merge")){
            m_mno_global_merge = true;
        }
        if(vm.count("mno-zero-initialized-in-bss")){
            m_mno_zero_initialized_in_bss = true;
        }
        if(vm.count("mnoexecstack")){
            m_mnoexecstack = true;
        }
        if(vm.count("momit-leaf-frame-pointer")){
            m_momit_leaf_frame_pointer = true;
        }
        if(vm.count("mqdsp6-compat")){
            m_mqdsp6_compat = true;
        }
        if(vm.count("mregparm")){
            m_mregparm = vm["mregparm"].as<string>();
        }
        if(vm.count("mrelax-all")){
            m_mrelax_all = true;
        }
        if(vm.count("mrelocation-model")){
            m_mrelocation_model = vm["mrelocation-model"].as<string>();
        }
        if(vm.count("mrtd")){
            m_mrtd = true;
        }
        if(vm.count("msave-temp-labels")){
            m_msave_temp_labels = true;
        }
        if(vm.count("msoft-float")){
            m_msoft_float = true;
        }
        if(vm.count("mstack-alignment")){
            m_mstack_alignment = vm["mstack-alignment"].as<string>();
        }
        if(vm.count("mstackrealign")){
            m_mstackrealign = true;
        }
        if(vm.count("mt-migrate-directory")){
            m_mt_migrate_directory = vm["mt-migrate-directory"].as<string>();
        }
        if(vm.count("munwind-tables")){
            m_munwind_tables = true;
        }
        if(vm.count("no-code-completion-globals")){
            m_no_code_completion_globals = true;
        }
        if(vm.count("no-finalize-removal")){
            m_no_finalize_removal = true;
        }
        if(vm.count("no-implicit-float")){
            m_no_implicit_float = true;
        }
        if(vm.count("no-ns-alloc-error")){
            m_no_ns_alloc_error = true;
        }
        if(vm.count("nobuiltininc")){
            m_nobuiltininc = true;
        }
        if(vm.count("nostdinc++")){
            m_nostdincplusplus = true;
        }
        if(vm.count("nostdsysteminc")){
            m_nostdsysteminc = true;
        }
        if(vm.count("o")){
            m_o = vm["o"].as<string>();
        }
        if(vm.count("objc-isystem")){
            m_objc_isystem = vm["objc-isystem"].as<string>();
        }
        if(vm.count("objcmt-migrate-literals")){
            m_objcmt_migrate_literals = true;
        }
        if(vm.count("objcmt-migrate-subscripting")){
            m_objcmt_migrate_subscripting = true;
        }
        if(vm.count("objcxx-isystem")){
            m_objcxx_isystem = vm["objcxx-isystem"].as<string>();
        }
        if(vm.count("pg")){
            m_pg = true;
        }
        if(vm.count("pic-level")){
            m_pic_level = vm["pic-level"].as<string>();
        }
        if(vm.count("pipe")){
            m_pipe = true;
        }
        if(vm.count("plugin")){
            m_plugin = vm["plugin"].as<string>();
        }
        if(vm.count("plugin-arg")){
            m_plugin_arg = vm["plugin-arg"].as<string>();
        }
        if(vm.count("preamble-bytes")){
            m_preamble_bytes = vm["preamble-bytes"].as<string>();
        }
        if(vm.count("print-decl-contexts")){
            m_print_decl_contexts = true;
        }
        if(vm.count("print-file-name")){
            m_print_file_name = vm["print-file-name"].as<string>();
        }
        if(vm.count("print-ivar-layout")){
            m_print_ivar_layout = true;
        }
        if(vm.count("print-libgcc-file-name")){
            m_print_libgcc_file_name = true;
        }
        if(vm.count("print-preamble")){
            m_print_preamble = true;
        }
        if(vm.count("print-prog-name")){
            m_print_prog_name = vm["print-prog-name"].as<string>();
        }
        if(vm.count("print-search-dirs")){
            m_print_search_dirs = true;
        }
        if(vm.count("print-stats")){
            m_print_stats = true;
        }
        if(vm.count("pthread")){
            m_pthread = true;
        }
        if(vm.count("pubnames-dump")){
            m_pubnames_dump = true;
        }
        if(vm.count("relaxed-aliasing")){
            m_relaxed_aliasing = true;
        }
        if(vm.count("relocatable-pch")){
            m_relocatable_pch = true;
        }
        if(vm.count("remap-file")){
            m_remap_file = vm["remap-file"].as<string>();
        }
        if(vm.count("resource-dir")){
            m_resource_dir = vm["resource-dir"].as<string>();
        }
        if(vm.count("rewrite-macros")){
            m_rewrite_macros = true;
        }
        if(vm.count("rewrite-objc")){
            m_rewrite_objc = true;
        }
        if(vm.count("rewrite-test")){
            m_rewrite_test = true;
        }
        if(vm.count("save-temps")){
            m_save_temps = true;
        }
        if(vm.count("serialize-diagnostic-file")){
            m_serialize_diagnostic_file = vm["serialize-diagnostic-file"].as<string>();
        }
        if(vm.count("serialize-diagnostics")){
            m_serialize_diagnostics = vm["serialize-diagnostics"].as<string>();
        }
        if(vm.count("stack-protector")){
            m_stack_protector = vm["stack-protector"].as<string>();
        }
        if(vm.count("static-define")){
            m_static_define = true;
        }
        if(vm.count("std")){
            m_std = vm["std"].as<string>();
        }
        if(vm.count("stdlib")){
            m_stdlib = vm["stdlib"].as<string>();
        }
        if(vm.count("sys-header-deps")){
            m_sys_header_deps = true;
        }
        if(vm.count("target")){
            m_target = vm["target"].as<string>();
        }
        if(vm.count("target-abi")){
            m_target_abi = vm["target-abi"].as<string>();
        }
        if(vm.count("target-cpu")){
            m_target_cpu = vm["target-cpu"].as<string>();
        }
        if(vm.count("target-feature")){
            m_target_feature = vm["target-feature"].as<string>();
        }
        if(vm.count("target-linker-version")){
            m_target_linker_version = vm["target-linker-version"].as<string>();
        }
        if(vm.count("time")){
            m_time = true;
        }
        if(vm.count("token-cache")){
            m_token_cache = vm["token-cache"].as<string>();
        }
        if(vm.count("traditional-cpp")){
            m_traditional_cpp = true;
        }
        if(vm.count("trigraphs")){
            m_trigraphs = true;
        }
        if(vm.count("trim-egraph")){
            m_trim_egraph = true;
        }
        if(vm.count("triple")){
            m_triple = vm["triple"].as<string>();
        }
        if(vm.count("undef")){
            m_undef = true;
        }
        if(vm.count("unoptimized-cfg")){
            m_unoptimized_cfg = true;
        }
        if(vm.count("v")){
            m_v = true;
        }
        if(vm.count("verify")){
            m_verify = true;
        }
        if(vm.count("version")){
            m_version = true;
        }
        if(vm.count("w")){
            m_w = true;
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
