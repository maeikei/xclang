#include "options.hpp"
using namespace xclang;
#include <boost/assign/list_of.hpp>
using namespace boost::assign;
#include <iostream>
#include <iterator>
using namespace std;


const map<string,int> XClangOptions::m_clang_options = map_list_of
    ("-###",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("--analyze",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("--help",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("--migrate",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("--relocatable-pch",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("--serialize-diagnostics",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-E",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ObjC",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ObjC++",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-Qunused-arguments",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-S",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-Wa",iConstOptionTypeValue| iConstOptionTypeCommaValue | iConstOptionTypeNone)
    ("-Wl",iConstOptionTypeValue| iConstOptionTypeCommaValue | iConstOptionTypeNone)
    ("-Wp",iConstOptionTypeValue| iConstOptionTypeCommaValue | iConstOptionTypeNone)
    ("-Xanalyzer",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-Xassembler",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-Xclang",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-Xlinker",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-Xpreprocessor",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-arcmt-migrate-emit-errors",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-arcmt-migrate-report-output",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-c",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-ast",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-llvm",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fcatch-undefined-behavior",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-flimit-debug-info",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-limit-debug-info",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ftrap-function",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-gcc-toolchain",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-o",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-objcmt-migrate-literals",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-objcmt-migrate-subscripting",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-pipe",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-print-file-name",iConstOptionTypeNextValue| iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-print-libgcc-file-name",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-print-prog-name",iConstOptionTypeNextValue| iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-print-search-dirs",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-rewrite-objc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-save-temps",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-target",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-time",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-v",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-verify",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-working-directory",iConstOptionTypeNextValue| iConstOptionTypeNone)
;




const map<string,int> XClangOptions::m_clang_cc1_options  = map_list_of
    ("-C",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-CC",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-D",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-E",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-Eonly",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-F",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-H",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-I",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-MG",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-MP",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-MQ",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-MT",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-O",iConstOptionTypeValue| iConstOptionTypeNone)
    ("-Os",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-Oz",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-P",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-S",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-U",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-Wlarge-by-value-copy",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-Wno-rewrite-macros",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-add-plugin",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyze",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyze-function",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-checker",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-checker-help",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-constraints",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-disable-checker",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-display-progress",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-eagerly-assume",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-inline-max-function-size",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-inline-max-stack-depth",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-inlining-mode",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-ipa",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-max-loop",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-max-nodes",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-no-eagerly-trim-egraph",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-opt-analyze-headers",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-opt-analyze-nested-blocks",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-output",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-purge",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-stats",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-store",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-analyzer-viz-egraph-graphviz",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-analyzer-viz-egraph-ubigraph",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-arcmt-check",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-arcmt-migrate",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-arcmt-migrate-emit-errors",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-arcmt-migrate-report-output",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-arcmt-modify",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ast-dump",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ast-dump-xml",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ast-merge",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-ast-print",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ast-view",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-backend-option",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-c-isystem",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-cfg-add-implicit-dtors",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-cfg-add-initializers",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-chain-include",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-cl-fast-relaxed-math",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-cl-finite-math-only",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-cl-mad-enable",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-cl-opt-disable",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-cl-single-precision-constant",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-cl-std",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-cl-unsafe-math-optimizations",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-code-completion-at",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-code-completion-macros",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-code-completion-patterns",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-coverage-file",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-cxx-abi",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-cxx-isystem",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-dD",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-dM",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-dependency-dot",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-dependency-file",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-detailed-preprocessing-record",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-diagnostic-log-file",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-disable-free",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-disable-llvm-optzns",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-disable-llvm-verifier",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-disable-red-zone",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-dump-build-information",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-dump-deserialized-decls",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-dump-raw-tokens",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-dump-tokens",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-dwarf-debug-flags",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-emit-codegen-only",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-html",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-llvm",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-llvm-bc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-llvm-only",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-module",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-obj",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-pch",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-emit-pth",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-error-on-deserialized-decl",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-faddress-sanitizer",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-faltivec",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fapple-kext",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fapple-pragma-pack",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fblocks",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fblocks-runtime-optional",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fborland-extensions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fcatch-undefined-behavior",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fcolor-diagnostics",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fconst-strings",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fconstant-string-class",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fconstexpr-backtrace-limit",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fconstexpr-depth",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fcuda-is-device",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fcxx-exceptions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdata-sections",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdebug-compilation-dir",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fdebugger-cast-result-to-id",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdebugger-objc-literal",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdebugger-support",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdelayed-template-parsing",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdeprecated-macro",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdiagnostics-format",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fdiagnostics-parseable-fixits",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdiagnostics-print-source-range-info",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdiagnostics-show-category",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fdiagnostics-show-note-include-stack",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdiagnostics-show-option",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdisable-module-hash",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdollars-in-identifiers",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdump-record-layouts",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdump-record-layouts-simple",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fdump-vtable-layouts",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-femit-all-decls",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-femit-coverage-data",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-femit-coverage-notes",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ferror-limit",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fexceptions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ffake-address-space-map",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ffast-math",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fforbid-guard-variables",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ffreestanding",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ffunction-sections",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fgnu-keywords",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fgnu-runtime",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fgnu89-inline",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fhidden-weak-vtables",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-finstrument-functions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fix-only-warnings",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fix-what-you-can",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fixit",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fixit-recompile",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fixit-to-temporary",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-flimit-debug-info",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fmacro-backtrace-limit",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fmath-errno",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fmessage-length",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fmodule-cache-path",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fmodule-name",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-fmodules",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fms-compatibility",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fms-extensions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fmsc-version",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-fno-access-control",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-assume-sane-operator-new",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-bitfield-type-align",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-builtin",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-caret-diagnostics",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-common",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-const-strings",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-constant-cfstrings",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-deprecated-macro",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-diagnostics-fixit-info",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-diagnostics-show-note-include-stack",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-dollars-in-identifiers",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-dwarf-directory-asm",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-dwarf2-cfi-asm",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-elide-constructors",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-gnu-keywords",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-inline",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-inline-functions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-lax-vector-conversions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-limit-debug-info",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-merge-all-constants",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-objc-infer-related-result-type",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-operator-names",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-rtti",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-show-column",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-show-source-location",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-signed-char",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-spell-checking",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-threadsafe-statics",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-use-cxa-atexit",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fno-validate-pch",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-arc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-arc-cxxlib",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-fobjc-arc-exceptions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-default-synthesize-properties",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-dispatch-method",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-fobjc-exceptions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-fragile-abi",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-gc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-gc-only",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-runtime-has-arc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-runtime-has-terminate",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fobjc-runtime-has-weak",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-foverride-record-layout",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-fpack-struct",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fpascal-strings",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fshort-enums",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fshort-wchar",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fshow-column",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fshow-overloads",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-fsjlj-exceptions",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fsyntax-only",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ftabstop",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-ftemplate-backtrace-limit",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-ftemplate-depth",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-ftime-report",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ftrap-function",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-ftrapv",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-ftrapv-handler",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-funknown-anytype",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-funroll-loops",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fuse-register-sized-bitfield-access",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fvisibility",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-fvisibility-inlines-hidden",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fwrapv",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-fwritable-strings",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-g",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-header-include-file",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-help",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-idirafter",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-iframework",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-imacros",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-include",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-include-pch",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-include-pth",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-index-header-map",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-init-only",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-internal-externc-isystem",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-internal-isystem",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-iprefix",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-iquote",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-isysroot",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-isystem",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-iwithprefix",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-iwithprefixbefore",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-iwithsysroot",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-load",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-main-file-name",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-masm-verbose",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mcode-model",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-mconstructor-aliases",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mdebug-pass",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-mdisable-fp-elim",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mdisable-tail-calls",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-menable-no-infs",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-menable-no-nans",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-menable-unsafe-fp-math",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mfloat-abi",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-migrate",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mlimit-float-precision",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-mlink-bitcode-file",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-mllvm",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-mms-bitfields",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mno-global-merge",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mno-zero-initialized-in-bss",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mnoexecstack",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-momit-leaf-frame-pointer",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mqdsp6-compat",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mregparm",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-mrelax-all",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mrelocation-model",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-mrtd",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-msave-temp-labels",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-msoft-float",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mstack-alignment",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-mstackrealign",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-mt-migrate-directory",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-munwind-tables",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-no-code-completion-globals",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-no-finalize-removal",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-no-implicit-float",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-no-ns-alloc-error",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-nobuiltininc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-nostdinc++",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-nostdsysteminc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-o",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-objc-isystem",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-objcmt-migrate-literals",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-objcmt-migrate-subscripting",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-objcxx-isystem",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-pg",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-pic-level",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-plugin",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-plugin-arg",iConstOptionTypeNextValue| iConstOptionTypeValue| iConstOptionTypeBarValue | iConstOptionTypeNone)
    ("-preamble-bytes",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-print-decl-contexts",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-print-ivar-layout",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-print-preamble",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-print-stats",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-pthread",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-pubnames-dump",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-relaxed-aliasing",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-relocatable-pch",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-remap-file",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-resource-dir",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-rewrite-macros",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-rewrite-objc",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-rewrite-test",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-serialize-diagnostic-file",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-stack-protector",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-static-define",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-std",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-stdlib",iConstOptionTypeValue| iConstOptionTypeEQValue | iConstOptionTypeNone)
    ("-sys-header-deps",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-target-abi",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-target-cpu",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-target-feature",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-target-linker-version",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-token-cache",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-traditional-cpp",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-trigraphs",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-trim-egraph",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-triple",iConstOptionTypeNextValue| iConstOptionTypeNone)
    ("-undef",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-unoptimized-cfg",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-v",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-verify",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-version",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-w",iConstOptionTypeAlone| iConstOptionTypeNone)
    ("-working-directory",iConstOptionTypeNextValue| iConstOptionTypeNone)
;



XClangOptions::XClangOptions(int argc,const char** argv)
:m_argc(argc)
,m_argv(argv)
,m_real_options()
,m_input_files()
,m_input_files_str("")
,m_objects_files()
,m_out_file("a.out")
,m_spspsp(false)
,m__analyze(false)
,m__help(false)
,m__migrate(false)
,m__relocatable_pch(false)
,m__serialize_diagnostics("")
,m_C(false)
,m_CC(false)
,m_D("")
,m_E(false)
,m_Eonly(false)
,m_F("")
,m_H(false)
,m_I("")
,m_MG(false)
,m_MP(false)
,m_MQ("")
,m_MT("")
,m_O("")
,m_ObjC(false)
,m_ObjCplusplus(false)
,m_Os(false)
,m_Oz(false)
,m_P(false)
,m_Qunused_arguments(false)
,m_S(false)
,m_U("")
,m_Wa("")
,m_Wl("")
,m_Wlarge_by_value_copy("")
,m_Wno_rewrite_macros(false)
,m_Wp("")
,m_Xanalyzer("")
,m_Xassembler("")
,m_Xclang("")
,m_Xlinker("")
,m_Xpreprocessor("")
,m_add_plugin("")
,m_analyze(false)
,m_analyze_function("")
,m_analyzer_checker("")
,m_analyzer_checker_help(false)
,m_analyzer_constraints("")
,m_analyzer_disable_checker("")
,m_analyzer_display_progress(false)
,m_analyzer_eagerly_assume(false)
,m_analyzer_inline_max_function_size("")
,m_analyzer_inline_max_stack_depth("")
,m_analyzer_inlining_mode("")
,m_analyzer_ipa("")
,m_analyzer_max_loop("")
,m_analyzer_max_nodes("")
,m_analyzer_no_eagerly_trim_egraph(false)
,m_analyzer_opt_analyze_headers(false)
,m_analyzer_opt_analyze_nested_blocks(false)
,m_analyzer_output("")
,m_analyzer_purge("")
,m_analyzer_stats(false)
,m_analyzer_store("")
,m_analyzer_viz_egraph_graphviz(false)
,m_analyzer_viz_egraph_ubigraph(false)
,m_arcmt_check(false)
,m_arcmt_migrate(false)
,m_arcmt_migrate_emit_errors(false)
,m_arcmt_migrate_report_output("")
,m_arcmt_modify(false)
,m_ast_dump(false)
,m_ast_dump_xml(false)
,m_ast_merge("")
,m_ast_print(false)
,m_ast_view(false)
,m_backend_option("")
,m_c(false)
,m_c_isystem("")
,m_cfg_add_implicit_dtors(false)
,m_cfg_add_initializers(false)
,m_chain_include("")
,m_cl_fast_relaxed_math(false)
,m_cl_finite_math_only(false)
,m_cl_mad_enable(false)
,m_cl_opt_disable(false)
,m_cl_single_precision_constant(false)
,m_cl_std("")
,m_cl_unsafe_math_optimizations(false)
,m_code_completion_at("")
,m_code_completion_macros(false)
,m_code_completion_patterns(false)
,m_coverage_file("")
,m_cxx_abi("")
,m_cxx_isystem("")
,m_dD(false)
,m_dM(false)
,m_dependency_dot("")
,m_dependency_file("")
,m_detailed_preprocessing_record(false)
,m_diagnostic_log_file("")
,m_disable_free(false)
,m_disable_llvm_optzns(false)
,m_disable_llvm_verifier(false)
,m_disable_red_zone(false)
,m_dump_build_information("")
,m_dump_deserialized_decls(false)
,m_dump_raw_tokens(false)
,m_dump_tokens(false)
,m_dwarf_debug_flags("")
,m_emit_ast(false)
,m_emit_codegen_only(false)
,m_emit_html(false)
,m_emit_llvm(false)
,m_emit_llvm_bc(false)
,m_emit_llvm_only(false)
,m_emit_module(false)
,m_emit_obj(false)
,m_emit_pch(false)
,m_emit_pth(false)
,m_error_on_deserialized_decl("")
,m_faddress_sanitizer(false)
,m_faltivec(false)
,m_fapple_kext(false)
,m_fapple_pragma_pack(false)
,m_fblocks(false)
,m_fblocks_runtime_optional(false)
,m_fborland_extensions(false)
,m_fcatch_undefined_behavior(false)
,m_fcolor_diagnostics(false)
,m_fconst_strings(false)
,m_fconstant_string_class("")
,m_fconstexpr_backtrace_limit("")
,m_fconstexpr_depth("")
,m_fcuda_is_device(false)
,m_fcxx_exceptions(false)
,m_fdata_sections(false)
,m_fdebug_compilation_dir("")
,m_fdebugger_cast_result_to_id(false)
,m_fdebugger_objc_literal(false)
,m_fdebugger_support(false)
,m_fdelayed_template_parsing(false)
,m_fdeprecated_macro(false)
,m_fdiagnostics_format("")
,m_fdiagnostics_parseable_fixits(false)
,m_fdiagnostics_print_source_range_info(false)
,m_fdiagnostics_show_category("")
,m_fdiagnostics_show_note_include_stack(false)
,m_fdiagnostics_show_option(false)
,m_fdisable_module_hash(false)
,m_fdollars_in_identifiers(false)
,m_fdump_record_layouts(false)
,m_fdump_record_layouts_simple(false)
,m_fdump_vtable_layouts(false)
,m_femit_all_decls(false)
,m_femit_coverage_data(false)
,m_femit_coverage_notes(false)
,m_ferror_limit("")
,m_fexceptions(false)
,m_ffake_address_space_map(false)
,m_ffast_math(false)
,m_fforbid_guard_variables(false)
,m_ffreestanding(false)
,m_ffunction_sections(false)
,m_fgnu_keywords(false)
,m_fgnu_runtime(false)
,m_fgnu89_inline(false)
,m_fhidden_weak_vtables(false)
,m_finstrument_functions(false)
,m_fix_only_warnings(false)
,m_fix_what_you_can(false)
,m_fixit(false)
,m_fixit_recompile(false)
,m_fixit_to_temporary(false)
,m_flimit_debug_info(false)
,m_fmacro_backtrace_limit("")
,m_fmath_errno(false)
,m_fmessage_length("")
,m_fmodule_cache_path("")
,m_fmodule_name("")
,m_fmodules(false)
,m_fms_compatibility(false)
,m_fms_extensions(false)
,m_fmsc_version("")
,m_fno_access_control(false)
,m_fno_assume_sane_operator_new(false)
,m_fno_bitfield_type_align(false)
,m_fno_builtin(false)
,m_fno_caret_diagnostics(false)
,m_fno_common(false)
,m_fno_const_strings(false)
,m_fno_constant_cfstrings(false)
,m_fno_deprecated_macro(false)
,m_fno_diagnostics_fixit_info(false)
,m_fno_diagnostics_show_note_include_stack(false)
,m_fno_dollars_in_identifiers(false)
,m_fno_dwarf_directory_asm(false)
,m_fno_dwarf2_cfi_asm(false)
,m_fno_elide_constructors(false)
,m_fno_gnu_keywords(false)
,m_fno_inline(false)
,m_fno_inline_functions(false)
,m_fno_lax_vector_conversions(false)
,m_fno_limit_debug_info(false)
,m_fno_merge_all_constants(false)
,m_fno_objc_infer_related_result_type(false)
,m_fno_operator_names(false)
,m_fno_rtti(false)
,m_fno_show_column(false)
,m_fno_show_source_location(false)
,m_fno_signed_char(false)
,m_fno_spell_checking(false)
,m_fno_threadsafe_statics(false)
,m_fno_use_cxa_atexit(false)
,m_fno_validate_pch(false)
,m_fobjc_arc(false)
,m_fobjc_arc_cxxlib("")
,m_fobjc_arc_exceptions(false)
,m_fobjc_default_synthesize_properties(false)
,m_fobjc_dispatch_method("")
,m_fobjc_exceptions(false)
,m_fobjc_fragile_abi(false)
,m_fobjc_gc(false)
,m_fobjc_gc_only(false)
,m_fobjc_runtime_has_arc(false)
,m_fobjc_runtime_has_terminate(false)
,m_fobjc_runtime_has_weak(false)
,m_foverride_record_layout("")
,m_fpack_struct("")
,m_fpascal_strings(false)
,m_fshort_enums(false)
,m_fshort_wchar(false)
,m_fshow_column(false)
,m_fshow_overloads("")
,m_fsjlj_exceptions(false)
,m_fsyntax_only(false)
,m_ftabstop("")
,m_ftemplate_backtrace_limit("")
,m_ftemplate_depth("")
,m_ftime_report(false)
,m_ftrap_function("")
,m_ftrapv(false)
,m_ftrapv_handler("")
,m_funknown_anytype(false)
,m_funroll_loops(false)
,m_fuse_register_sized_bitfield_access(false)
,m_fvisibility("")
,m_fvisibility_inlines_hidden(false)
,m_fwrapv(false)
,m_fwritable_strings(false)
,m_g(false)
,m_gcc_toolchain("")
,m_header_include_file("")
,m_help(false)
,m_idirafter("")
,m_iframework("")
,m_imacros("")
,m_include("")
,m_include_pch("")
,m_include_pth("")
,m_index_header_map(false)
,m_init_only(false)
,m_internal_externc_isystem("")
,m_internal_isystem("")
,m_iprefix("")
,m_iquote("")
,m_isysroot("")
,m_isystem("")
,m_iwithprefix("")
,m_iwithprefixbefore("")
,m_iwithsysroot("")
,m_load("")
,m_main_file_name("")
,m_masm_verbose(false)
,m_mcode_model("")
,m_mconstructor_aliases(false)
,m_mdebug_pass("")
,m_mdisable_fp_elim(false)
,m_mdisable_tail_calls(false)
,m_menable_no_infs(false)
,m_menable_no_nans(false)
,m_menable_unsafe_fp_math(false)
,m_mfloat_abi("")
,m_migrate(false)
,m_mlimit_float_precision("")
,m_mlink_bitcode_file("")
,m_mllvm("")
,m_mms_bitfields(false)
,m_mno_global_merge(false)
,m_mno_zero_initialized_in_bss(false)
,m_mnoexecstack(false)
,m_momit_leaf_frame_pointer(false)
,m_mqdsp6_compat(false)
,m_mregparm("")
,m_mrelax_all(false)
,m_mrelocation_model("")
,m_mrtd(false)
,m_msave_temp_labels(false)
,m_msoft_float(false)
,m_mstack_alignment("")
,m_mstackrealign(false)
,m_mt_migrate_directory("")
,m_munwind_tables(false)
,m_no_code_completion_globals(false)
,m_no_finalize_removal(false)
,m_no_implicit_float(false)
,m_no_ns_alloc_error(false)
,m_nobuiltininc(false)
,m_nostdincplusplus(false)
,m_nostdsysteminc(false)
,m_o("")
,m_objc_isystem("")
,m_objcmt_migrate_literals(false)
,m_objcmt_migrate_subscripting(false)
,m_objcxx_isystem("")
,m_pg(false)
,m_pic_level("")
,m_pipe(false)
,m_plugin("")
,m_plugin_arg("")
,m_preamble_bytes("")
,m_print_decl_contexts(false)
,m_print_file_name("")
,m_print_ivar_layout(false)
,m_print_libgcc_file_name(false)
,m_print_preamble(false)
,m_print_prog_name("")
,m_print_search_dirs(false)
,m_print_stats(false)
,m_pthread(false)
,m_pubnames_dump(false)
,m_relaxed_aliasing(false)
,m_relocatable_pch(false)
,m_remap_file("")
,m_resource_dir("")
,m_rewrite_macros(false)
,m_rewrite_objc(false)
,m_rewrite_test(false)
,m_save_temps(false)
,m_serialize_diagnostic_file("")
,m_stack_protector("")
,m_static_define(false)
,m_std("")
,m_stdlib("")
,m_sys_header_deps(false)
,m_target("")
,m_target_abi("")
,m_target_cpu("")
,m_target_feature("")
,m_target_linker_version("")
,m_time(false)
,m_token_cache("")
,m_traditional_cpp(false)
,m_trigraphs(false)
,m_trim_egraph(false)
,m_triple("")
,m_undef(false)
,m_unoptimized_cfg(false)
,m_v(false)
,m_verify(false)
,m_version(false)
,m_w(false)
,m_working_directory("")
{
    splitArgs();
    parseArgs();
}

void XClangOptions::parseArgs(void)
{
    auto it = m_real_options.begin();
    it = m_real_options.find("-###");
    if( m_real_options.end() != it) {
        m_spspsp = true;
    }
    it = m_real_options.find("--analyze");
    if( m_real_options.end() != it) {
        m__analyze = true;
    }
    it = m_real_options.find("--help");
    if( m_real_options.end() != it) {
        m__help = true;
    }
    it = m_real_options.find("--migrate");
    if( m_real_options.end() != it) {
        m__migrate = true;
    }
    it = m_real_options.find("--relocatable-pch");
    if( m_real_options.end() != it) {
        m__relocatable_pch = true;
    }
    it = m_real_options.find("--serialize-diagnostics");
    if( m_real_options.end() != it) {
        m__serialize_diagnostics = it->second;
    }
    it = m_real_options.find("-C");
    if( m_real_options.end() != it) {
        m_C = true;
    }
    it = m_real_options.find("-CC");
    if( m_real_options.end() != it) {
        m_CC = true;
    }
    it = m_real_options.find("-D");
    if( m_real_options.end() != it) {
        m_D = it->second;
    }
    it = m_real_options.find("-E");
    if( m_real_options.end() != it) {
        m_E = true;
    }
    it = m_real_options.find("-Eonly");
    if( m_real_options.end() != it) {
        m_Eonly = true;
    }
    it = m_real_options.find("-F");
    if( m_real_options.end() != it) {
        m_F = it->second;
    }
    it = m_real_options.find("-H");
    if( m_real_options.end() != it) {
        m_H = true;
    }
    it = m_real_options.find("-I");
    if( m_real_options.end() != it) {
        m_I = it->second;
    }
    it = m_real_options.find("-MG");
    if( m_real_options.end() != it) {
        m_MG = true;
    }
    it = m_real_options.find("-MP");
    if( m_real_options.end() != it) {
        m_MP = true;
    }
    it = m_real_options.find("-MQ");
    if( m_real_options.end() != it) {
        m_MQ = it->second;
    }
    it = m_real_options.find("-MT");
    if( m_real_options.end() != it) {
        m_MT = it->second;
    }
    it = m_real_options.find("-O");
    if( m_real_options.end() != it) {
        m_O = it->second;
    }
    it = m_real_options.find("-ObjC");
    if( m_real_options.end() != it) {
        m_ObjC = true;
    }
    it = m_real_options.find("-ObjC++");
    if( m_real_options.end() != it) {
        m_ObjCplusplus = true;
    }
    it = m_real_options.find("-Os");
    if( m_real_options.end() != it) {
        m_Os = true;
    }
    it = m_real_options.find("-Oz");
    if( m_real_options.end() != it) {
        m_Oz = true;
    }
    it = m_real_options.find("-P");
    if( m_real_options.end() != it) {
        m_P = true;
    }
    it = m_real_options.find("-Qunused-arguments");
    if( m_real_options.end() != it) {
        m_Qunused_arguments = true;
    }
    it = m_real_options.find("-S");
    if( m_real_options.end() != it) {
        m_S = true;
    }
    it = m_real_options.find("-U");
    if( m_real_options.end() != it) {
        m_U = it->second;
    }
    it = m_real_options.find("-Wa");
    if( m_real_options.end() != it) {
        m_Wa = it->second;
    }
    it = m_real_options.find("-Wl");
    if( m_real_options.end() != it) {
        m_Wl = it->second;
    }
    it = m_real_options.find("-Wlarge-by-value-copy");
    if( m_real_options.end() != it) {
        m_Wlarge_by_value_copy = it->second;
    }
    it = m_real_options.find("-Wno-rewrite-macros");
    if( m_real_options.end() != it) {
        m_Wno_rewrite_macros = true;
    }
    it = m_real_options.find("-Wp");
    if( m_real_options.end() != it) {
        m_Wp = it->second;
    }
    it = m_real_options.find("-Xanalyzer");
    if( m_real_options.end() != it) {
        m_Xanalyzer = it->second;
    }
    it = m_real_options.find("-Xassembler");
    if( m_real_options.end() != it) {
        m_Xassembler = it->second;
    }
    it = m_real_options.find("-Xclang");
    if( m_real_options.end() != it) {
        m_Xclang = it->second;
    }
    it = m_real_options.find("-Xlinker");
    if( m_real_options.end() != it) {
        m_Xlinker = it->second;
    }
    it = m_real_options.find("-Xpreprocessor");
    if( m_real_options.end() != it) {
        m_Xpreprocessor = it->second;
    }
    it = m_real_options.find("-add-plugin");
    if( m_real_options.end() != it) {
        m_add_plugin = it->second;
    }
    it = m_real_options.find("-analyze");
    if( m_real_options.end() != it) {
        m_analyze = true;
    }
    it = m_real_options.find("-analyze-function");
    if( m_real_options.end() != it) {
        m_analyze_function = it->second;
    }
    it = m_real_options.find("-analyzer-checker");
    if( m_real_options.end() != it) {
        m_analyzer_checker = it->second;
    }
    it = m_real_options.find("-analyzer-checker-help");
    if( m_real_options.end() != it) {
        m_analyzer_checker_help = true;
    }
    it = m_real_options.find("-analyzer-constraints");
    if( m_real_options.end() != it) {
        m_analyzer_constraints = it->second;
    }
    it = m_real_options.find("-analyzer-disable-checker");
    if( m_real_options.end() != it) {
        m_analyzer_disable_checker = it->second;
    }
    it = m_real_options.find("-analyzer-display-progress");
    if( m_real_options.end() != it) {
        m_analyzer_display_progress = true;
    }
    it = m_real_options.find("-analyzer-eagerly-assume");
    if( m_real_options.end() != it) {
        m_analyzer_eagerly_assume = true;
    }
    it = m_real_options.find("-analyzer-inline-max-function-size");
    if( m_real_options.end() != it) {
        m_analyzer_inline_max_function_size = it->second;
    }
    it = m_real_options.find("-analyzer-inline-max-stack-depth");
    if( m_real_options.end() != it) {
        m_analyzer_inline_max_stack_depth = it->second;
    }
    it = m_real_options.find("-analyzer-inlining-mode");
    if( m_real_options.end() != it) {
        m_analyzer_inlining_mode = it->second;
    }
    it = m_real_options.find("-analyzer-ipa");
    if( m_real_options.end() != it) {
        m_analyzer_ipa = it->second;
    }
    it = m_real_options.find("-analyzer-max-loop");
    if( m_real_options.end() != it) {
        m_analyzer_max_loop = it->second;
    }
    it = m_real_options.find("-analyzer-max-nodes");
    if( m_real_options.end() != it) {
        m_analyzer_max_nodes = it->second;
    }
    it = m_real_options.find("-analyzer-no-eagerly-trim-egraph");
    if( m_real_options.end() != it) {
        m_analyzer_no_eagerly_trim_egraph = true;
    }
    it = m_real_options.find("-analyzer-opt-analyze-headers");
    if( m_real_options.end() != it) {
        m_analyzer_opt_analyze_headers = true;
    }
    it = m_real_options.find("-analyzer-opt-analyze-nested-blocks");
    if( m_real_options.end() != it) {
        m_analyzer_opt_analyze_nested_blocks = true;
    }
    it = m_real_options.find("-analyzer-output");
    if( m_real_options.end() != it) {
        m_analyzer_output = it->second;
    }
    it = m_real_options.find("-analyzer-purge");
    if( m_real_options.end() != it) {
        m_analyzer_purge = it->second;
    }
    it = m_real_options.find("-analyzer-stats");
    if( m_real_options.end() != it) {
        m_analyzer_stats = true;
    }
    it = m_real_options.find("-analyzer-store");
    if( m_real_options.end() != it) {
        m_analyzer_store = it->second;
    }
    it = m_real_options.find("-analyzer-viz-egraph-graphviz");
    if( m_real_options.end() != it) {
        m_analyzer_viz_egraph_graphviz = true;
    }
    it = m_real_options.find("-analyzer-viz-egraph-ubigraph");
    if( m_real_options.end() != it) {
        m_analyzer_viz_egraph_ubigraph = true;
    }
    it = m_real_options.find("-arcmt-check");
    if( m_real_options.end() != it) {
        m_arcmt_check = true;
    }
    it = m_real_options.find("-arcmt-migrate");
    if( m_real_options.end() != it) {
        m_arcmt_migrate = true;
    }
    it = m_real_options.find("-arcmt-migrate-emit-errors");
    if( m_real_options.end() != it) {
        m_arcmt_migrate_emit_errors = true;
    }
    it = m_real_options.find("-arcmt-migrate-report-output");
    if( m_real_options.end() != it) {
        m_arcmt_migrate_report_output = it->second;
    }
    it = m_real_options.find("-arcmt-modify");
    if( m_real_options.end() != it) {
        m_arcmt_modify = true;
    }
    it = m_real_options.find("-ast-dump");
    if( m_real_options.end() != it) {
        m_ast_dump = true;
    }
    it = m_real_options.find("-ast-dump-xml");
    if( m_real_options.end() != it) {
        m_ast_dump_xml = true;
    }
    it = m_real_options.find("-ast-merge");
    if( m_real_options.end() != it) {
        m_ast_merge = it->second;
    }
    it = m_real_options.find("-ast-print");
    if( m_real_options.end() != it) {
        m_ast_print = true;
    }
    it = m_real_options.find("-ast-view");
    if( m_real_options.end() != it) {
        m_ast_view = true;
    }
    it = m_real_options.find("-backend-option");
    if( m_real_options.end() != it) {
        m_backend_option = it->second;
    }
    it = m_real_options.find("-c");
    if( m_real_options.end() != it) {
        m_c = true;
    }
    it = m_real_options.find("-c-isystem");
    if( m_real_options.end() != it) {
        m_c_isystem = it->second;
    }
    it = m_real_options.find("-cfg-add-implicit-dtors");
    if( m_real_options.end() != it) {
        m_cfg_add_implicit_dtors = true;
    }
    it = m_real_options.find("-cfg-add-initializers");
    if( m_real_options.end() != it) {
        m_cfg_add_initializers = true;
    }
    it = m_real_options.find("-chain-include");
    if( m_real_options.end() != it) {
        m_chain_include = it->second;
    }
    it = m_real_options.find("-cl-fast-relaxed-math");
    if( m_real_options.end() != it) {
        m_cl_fast_relaxed_math = true;
    }
    it = m_real_options.find("-cl-finite-math-only");
    if( m_real_options.end() != it) {
        m_cl_finite_math_only = true;
    }
    it = m_real_options.find("-cl-mad-enable");
    if( m_real_options.end() != it) {
        m_cl_mad_enable = true;
    }
    it = m_real_options.find("-cl-opt-disable");
    if( m_real_options.end() != it) {
        m_cl_opt_disable = true;
    }
    it = m_real_options.find("-cl-single-precision-constant");
    if( m_real_options.end() != it) {
        m_cl_single_precision_constant = true;
    }
    it = m_real_options.find("-cl-std");
    if( m_real_options.end() != it) {
        m_cl_std = it->second;
    }
    it = m_real_options.find("-cl-unsafe-math-optimizations");
    if( m_real_options.end() != it) {
        m_cl_unsafe_math_optimizations = true;
    }
    it = m_real_options.find("-code-completion-at");
    if( m_real_options.end() != it) {
        m_code_completion_at = it->second;
    }
    it = m_real_options.find("-code-completion-macros");
    if( m_real_options.end() != it) {
        m_code_completion_macros = true;
    }
    it = m_real_options.find("-code-completion-patterns");
    if( m_real_options.end() != it) {
        m_code_completion_patterns = true;
    }
    it = m_real_options.find("-coverage-file");
    if( m_real_options.end() != it) {
        m_coverage_file = it->second;
    }
    it = m_real_options.find("-cxx-abi");
    if( m_real_options.end() != it) {
        m_cxx_abi = it->second;
    }
    it = m_real_options.find("-cxx-isystem");
    if( m_real_options.end() != it) {
        m_cxx_isystem = it->second;
    }
    it = m_real_options.find("-dD");
    if( m_real_options.end() != it) {
        m_dD = true;
    }
    it = m_real_options.find("-dM");
    if( m_real_options.end() != it) {
        m_dM = true;
    }
    it = m_real_options.find("-dependency-dot");
    if( m_real_options.end() != it) {
        m_dependency_dot = it->second;
    }
    it = m_real_options.find("-dependency-file");
    if( m_real_options.end() != it) {
        m_dependency_file = it->second;
    }
    it = m_real_options.find("-detailed-preprocessing-record");
    if( m_real_options.end() != it) {
        m_detailed_preprocessing_record = true;
    }
    it = m_real_options.find("-diagnostic-log-file");
    if( m_real_options.end() != it) {
        m_diagnostic_log_file = it->second;
    }
    it = m_real_options.find("-disable-free");
    if( m_real_options.end() != it) {
        m_disable_free = true;
    }
    it = m_real_options.find("-disable-llvm-optzns");
    if( m_real_options.end() != it) {
        m_disable_llvm_optzns = true;
    }
    it = m_real_options.find("-disable-llvm-verifier");
    if( m_real_options.end() != it) {
        m_disable_llvm_verifier = true;
    }
    it = m_real_options.find("-disable-red-zone");
    if( m_real_options.end() != it) {
        m_disable_red_zone = true;
    }
    it = m_real_options.find("-dump-build-information");
    if( m_real_options.end() != it) {
        m_dump_build_information = it->second;
    }
    it = m_real_options.find("-dump-deserialized-decls");
    if( m_real_options.end() != it) {
        m_dump_deserialized_decls = true;
    }
    it = m_real_options.find("-dump-raw-tokens");
    if( m_real_options.end() != it) {
        m_dump_raw_tokens = true;
    }
    it = m_real_options.find("-dump-tokens");
    if( m_real_options.end() != it) {
        m_dump_tokens = true;
    }
    it = m_real_options.find("-dwarf-debug-flags");
    if( m_real_options.end() != it) {
        m_dwarf_debug_flags = it->second;
    }
    it = m_real_options.find("-emit-ast");
    if( m_real_options.end() != it) {
        m_emit_ast = true;
    }
    it = m_real_options.find("-emit-codegen-only");
    if( m_real_options.end() != it) {
        m_emit_codegen_only = true;
    }
    it = m_real_options.find("-emit-html");
    if( m_real_options.end() != it) {
        m_emit_html = true;
    }
    it = m_real_options.find("-emit-llvm");
    if( m_real_options.end() != it) {
        m_emit_llvm = true;
    }
    it = m_real_options.find("-emit-llvm-bc");
    if( m_real_options.end() != it) {
        m_emit_llvm_bc = true;
    }
    it = m_real_options.find("-emit-llvm-only");
    if( m_real_options.end() != it) {
        m_emit_llvm_only = true;
    }
    it = m_real_options.find("-emit-module");
    if( m_real_options.end() != it) {
        m_emit_module = true;
    }
    it = m_real_options.find("-emit-obj");
    if( m_real_options.end() != it) {
        m_emit_obj = true;
    }
    it = m_real_options.find("-emit-pch");
    if( m_real_options.end() != it) {
        m_emit_pch = true;
    }
    it = m_real_options.find("-emit-pth");
    if( m_real_options.end() != it) {
        m_emit_pth = true;
    }
    it = m_real_options.find("-error-on-deserialized-decl");
    if( m_real_options.end() != it) {
        m_error_on_deserialized_decl = it->second;
    }
    it = m_real_options.find("-faddress-sanitizer");
    if( m_real_options.end() != it) {
        m_faddress_sanitizer = true;
    }
    it = m_real_options.find("-faltivec");
    if( m_real_options.end() != it) {
        m_faltivec = true;
    }
    it = m_real_options.find("-fapple-kext");
    if( m_real_options.end() != it) {
        m_fapple_kext = true;
    }
    it = m_real_options.find("-fapple-pragma-pack");
    if( m_real_options.end() != it) {
        m_fapple_pragma_pack = true;
    }
    it = m_real_options.find("-fblocks");
    if( m_real_options.end() != it) {
        m_fblocks = true;
    }
    it = m_real_options.find("-fblocks-runtime-optional");
    if( m_real_options.end() != it) {
        m_fblocks_runtime_optional = true;
    }
    it = m_real_options.find("-fborland-extensions");
    if( m_real_options.end() != it) {
        m_fborland_extensions = true;
    }
    it = m_real_options.find("-fcatch-undefined-behavior");
    if( m_real_options.end() != it) {
        m_fcatch_undefined_behavior = true;
    }
    it = m_real_options.find("-fcolor-diagnostics");
    if( m_real_options.end() != it) {
        m_fcolor_diagnostics = true;
    }
    it = m_real_options.find("-fconst-strings");
    if( m_real_options.end() != it) {
        m_fconst_strings = true;
    }
    it = m_real_options.find("-fconstant-string-class");
    if( m_real_options.end() != it) {
        m_fconstant_string_class = it->second;
    }
    it = m_real_options.find("-fconstexpr-backtrace-limit");
    if( m_real_options.end() != it) {
        m_fconstexpr_backtrace_limit = it->second;
    }
    it = m_real_options.find("-fconstexpr-depth");
    if( m_real_options.end() != it) {
        m_fconstexpr_depth = it->second;
    }
    it = m_real_options.find("-fcuda-is-device");
    if( m_real_options.end() != it) {
        m_fcuda_is_device = true;
    }
    it = m_real_options.find("-fcxx-exceptions");
    if( m_real_options.end() != it) {
        m_fcxx_exceptions = true;
    }
    it = m_real_options.find("-fdata-sections");
    if( m_real_options.end() != it) {
        m_fdata_sections = true;
    }
    it = m_real_options.find("-fdebug-compilation-dir");
    if( m_real_options.end() != it) {
        m_fdebug_compilation_dir = it->second;
    }
    it = m_real_options.find("-fdebugger-cast-result-to-id");
    if( m_real_options.end() != it) {
        m_fdebugger_cast_result_to_id = true;
    }
    it = m_real_options.find("-fdebugger-objc-literal");
    if( m_real_options.end() != it) {
        m_fdebugger_objc_literal = true;
    }
    it = m_real_options.find("-fdebugger-support");
    if( m_real_options.end() != it) {
        m_fdebugger_support = true;
    }
    it = m_real_options.find("-fdelayed-template-parsing");
    if( m_real_options.end() != it) {
        m_fdelayed_template_parsing = true;
    }
    it = m_real_options.find("-fdeprecated-macro");
    if( m_real_options.end() != it) {
        m_fdeprecated_macro = true;
    }
    it = m_real_options.find("-fdiagnostics-format");
    if( m_real_options.end() != it) {
        m_fdiagnostics_format = it->second;
    }
    it = m_real_options.find("-fdiagnostics-parseable-fixits");
    if( m_real_options.end() != it) {
        m_fdiagnostics_parseable_fixits = true;
    }
    it = m_real_options.find("-fdiagnostics-print-source-range-info");
    if( m_real_options.end() != it) {
        m_fdiagnostics_print_source_range_info = true;
    }
    it = m_real_options.find("-fdiagnostics-show-category");
    if( m_real_options.end() != it) {
        m_fdiagnostics_show_category = it->second;
    }
    it = m_real_options.find("-fdiagnostics-show-note-include-stack");
    if( m_real_options.end() != it) {
        m_fdiagnostics_show_note_include_stack = true;
    }
    it = m_real_options.find("-fdiagnostics-show-option");
    if( m_real_options.end() != it) {
        m_fdiagnostics_show_option = true;
    }
    it = m_real_options.find("-fdisable-module-hash");
    if( m_real_options.end() != it) {
        m_fdisable_module_hash = true;
    }
    it = m_real_options.find("-fdollars-in-identifiers");
    if( m_real_options.end() != it) {
        m_fdollars_in_identifiers = true;
    }
    it = m_real_options.find("-fdump-record-layouts");
    if( m_real_options.end() != it) {
        m_fdump_record_layouts = true;
    }
    it = m_real_options.find("-fdump-record-layouts-simple");
    if( m_real_options.end() != it) {
        m_fdump_record_layouts_simple = true;
    }
    it = m_real_options.find("-fdump-vtable-layouts");
    if( m_real_options.end() != it) {
        m_fdump_vtable_layouts = true;
    }
    it = m_real_options.find("-femit-all-decls");
    if( m_real_options.end() != it) {
        m_femit_all_decls = true;
    }
    it = m_real_options.find("-femit-coverage-data");
    if( m_real_options.end() != it) {
        m_femit_coverage_data = true;
    }
    it = m_real_options.find("-femit-coverage-notes");
    if( m_real_options.end() != it) {
        m_femit_coverage_notes = true;
    }
    it = m_real_options.find("-ferror-limit");
    if( m_real_options.end() != it) {
        m_ferror_limit = it->second;
    }
    it = m_real_options.find("-fexceptions");
    if( m_real_options.end() != it) {
        m_fexceptions = true;
    }
    it = m_real_options.find("-ffake-address-space-map");
    if( m_real_options.end() != it) {
        m_ffake_address_space_map = true;
    }
    it = m_real_options.find("-ffast-math");
    if( m_real_options.end() != it) {
        m_ffast_math = true;
    }
    it = m_real_options.find("-fforbid-guard-variables");
    if( m_real_options.end() != it) {
        m_fforbid_guard_variables = true;
    }
    it = m_real_options.find("-ffreestanding");
    if( m_real_options.end() != it) {
        m_ffreestanding = true;
    }
    it = m_real_options.find("-ffunction-sections");
    if( m_real_options.end() != it) {
        m_ffunction_sections = true;
    }
    it = m_real_options.find("-fgnu-keywords");
    if( m_real_options.end() != it) {
        m_fgnu_keywords = true;
    }
    it = m_real_options.find("-fgnu-runtime");
    if( m_real_options.end() != it) {
        m_fgnu_runtime = true;
    }
    it = m_real_options.find("-fgnu89-inline");
    if( m_real_options.end() != it) {
        m_fgnu89_inline = true;
    }
    it = m_real_options.find("-fhidden-weak-vtables");
    if( m_real_options.end() != it) {
        m_fhidden_weak_vtables = true;
    }
    it = m_real_options.find("-finstrument-functions");
    if( m_real_options.end() != it) {
        m_finstrument_functions = true;
    }
    it = m_real_options.find("-fix-only-warnings");
    if( m_real_options.end() != it) {
        m_fix_only_warnings = true;
    }
    it = m_real_options.find("-fix-what-you-can");
    if( m_real_options.end() != it) {
        m_fix_what_you_can = true;
    }
    it = m_real_options.find("-fixit");
    if( m_real_options.end() != it) {
        m_fixit = true;
    }
    it = m_real_options.find("-fixit-recompile");
    if( m_real_options.end() != it) {
        m_fixit_recompile = true;
    }
    it = m_real_options.find("-fixit-to-temporary");
    if( m_real_options.end() != it) {
        m_fixit_to_temporary = true;
    }
    it = m_real_options.find("-flimit-debug-info");
    if( m_real_options.end() != it) {
        m_flimit_debug_info = true;
    }
    it = m_real_options.find("-fmacro-backtrace-limit");
    if( m_real_options.end() != it) {
        m_fmacro_backtrace_limit = it->second;
    }
    it = m_real_options.find("-fmath-errno");
    if( m_real_options.end() != it) {
        m_fmath_errno = true;
    }
    it = m_real_options.find("-fmessage-length");
    if( m_real_options.end() != it) {
        m_fmessage_length = it->second;
    }
    it = m_real_options.find("-fmodule-cache-path");
    if( m_real_options.end() != it) {
        m_fmodule_cache_path = it->second;
    }
    it = m_real_options.find("-fmodule-name");
    if( m_real_options.end() != it) {
        m_fmodule_name = it->second;
    }
    it = m_real_options.find("-fmodules");
    if( m_real_options.end() != it) {
        m_fmodules = true;
    }
    it = m_real_options.find("-fms-compatibility");
    if( m_real_options.end() != it) {
        m_fms_compatibility = true;
    }
    it = m_real_options.find("-fms-extensions");
    if( m_real_options.end() != it) {
        m_fms_extensions = true;
    }
    it = m_real_options.find("-fmsc-version");
    if( m_real_options.end() != it) {
        m_fmsc_version = it->second;
    }
    it = m_real_options.find("-fno-access-control");
    if( m_real_options.end() != it) {
        m_fno_access_control = true;
    }
    it = m_real_options.find("-fno-assume-sane-operator-new");
    if( m_real_options.end() != it) {
        m_fno_assume_sane_operator_new = true;
    }
    it = m_real_options.find("-fno-bitfield-type-align");
    if( m_real_options.end() != it) {
        m_fno_bitfield_type_align = true;
    }
    it = m_real_options.find("-fno-builtin");
    if( m_real_options.end() != it) {
        m_fno_builtin = true;
    }
    it = m_real_options.find("-fno-caret-diagnostics");
    if( m_real_options.end() != it) {
        m_fno_caret_diagnostics = true;
    }
    it = m_real_options.find("-fno-common");
    if( m_real_options.end() != it) {
        m_fno_common = true;
    }
    it = m_real_options.find("-fno-const-strings");
    if( m_real_options.end() != it) {
        m_fno_const_strings = true;
    }
    it = m_real_options.find("-fno-constant-cfstrings");
    if( m_real_options.end() != it) {
        m_fno_constant_cfstrings = true;
    }
    it = m_real_options.find("-fno-deprecated-macro");
    if( m_real_options.end() != it) {
        m_fno_deprecated_macro = true;
    }
    it = m_real_options.find("-fno-diagnostics-fixit-info");
    if( m_real_options.end() != it) {
        m_fno_diagnostics_fixit_info = true;
    }
    it = m_real_options.find("-fno-diagnostics-show-note-include-stack");
    if( m_real_options.end() != it) {
        m_fno_diagnostics_show_note_include_stack = true;
    }
    it = m_real_options.find("-fno-dollars-in-identifiers");
    if( m_real_options.end() != it) {
        m_fno_dollars_in_identifiers = true;
    }
    it = m_real_options.find("-fno-dwarf-directory-asm");
    if( m_real_options.end() != it) {
        m_fno_dwarf_directory_asm = true;
    }
    it = m_real_options.find("-fno-dwarf2-cfi-asm");
    if( m_real_options.end() != it) {
        m_fno_dwarf2_cfi_asm = true;
    }
    it = m_real_options.find("-fno-elide-constructors");
    if( m_real_options.end() != it) {
        m_fno_elide_constructors = true;
    }
    it = m_real_options.find("-fno-gnu-keywords");
    if( m_real_options.end() != it) {
        m_fno_gnu_keywords = true;
    }
    it = m_real_options.find("-fno-inline");
    if( m_real_options.end() != it) {
        m_fno_inline = true;
    }
    it = m_real_options.find("-fno-inline-functions");
    if( m_real_options.end() != it) {
        m_fno_inline_functions = true;
    }
    it = m_real_options.find("-fno-lax-vector-conversions");
    if( m_real_options.end() != it) {
        m_fno_lax_vector_conversions = true;
    }
    it = m_real_options.find("-fno-limit-debug-info");
    if( m_real_options.end() != it) {
        m_fno_limit_debug_info = true;
    }
    it = m_real_options.find("-fno-merge-all-constants");
    if( m_real_options.end() != it) {
        m_fno_merge_all_constants = true;
    }
    it = m_real_options.find("-fno-objc-infer-related-result-type");
    if( m_real_options.end() != it) {
        m_fno_objc_infer_related_result_type = true;
    }
    it = m_real_options.find("-fno-operator-names");
    if( m_real_options.end() != it) {
        m_fno_operator_names = true;
    }
    it = m_real_options.find("-fno-rtti");
    if( m_real_options.end() != it) {
        m_fno_rtti = true;
    }
    it = m_real_options.find("-fno-show-column");
    if( m_real_options.end() != it) {
        m_fno_show_column = true;
    }
    it = m_real_options.find("-fno-show-source-location");
    if( m_real_options.end() != it) {
        m_fno_show_source_location = true;
    }
    it = m_real_options.find("-fno-signed-char");
    if( m_real_options.end() != it) {
        m_fno_signed_char = true;
    }
    it = m_real_options.find("-fno-spell-checking");
    if( m_real_options.end() != it) {
        m_fno_spell_checking = true;
    }
    it = m_real_options.find("-fno-threadsafe-statics");
    if( m_real_options.end() != it) {
        m_fno_threadsafe_statics = true;
    }
    it = m_real_options.find("-fno-use-cxa-atexit");
    if( m_real_options.end() != it) {
        m_fno_use_cxa_atexit = true;
    }
    it = m_real_options.find("-fno-validate-pch");
    if( m_real_options.end() != it) {
        m_fno_validate_pch = true;
    }
    it = m_real_options.find("-fobjc-arc");
    if( m_real_options.end() != it) {
        m_fobjc_arc = true;
    }
    it = m_real_options.find("-fobjc-arc-cxxlib");
    if( m_real_options.end() != it) {
        m_fobjc_arc_cxxlib = it->second;
    }
    it = m_real_options.find("-fobjc-arc-exceptions");
    if( m_real_options.end() != it) {
        m_fobjc_arc_exceptions = true;
    }
    it = m_real_options.find("-fobjc-default-synthesize-properties");
    if( m_real_options.end() != it) {
        m_fobjc_default_synthesize_properties = true;
    }
    it = m_real_options.find("-fobjc-dispatch-method");
    if( m_real_options.end() != it) {
        m_fobjc_dispatch_method = it->second;
    }
    it = m_real_options.find("-fobjc-exceptions");
    if( m_real_options.end() != it) {
        m_fobjc_exceptions = true;
    }
    it = m_real_options.find("-fobjc-fragile-abi");
    if( m_real_options.end() != it) {
        m_fobjc_fragile_abi = true;
    }
    it = m_real_options.find("-fobjc-gc");
    if( m_real_options.end() != it) {
        m_fobjc_gc = true;
    }
    it = m_real_options.find("-fobjc-gc-only");
    if( m_real_options.end() != it) {
        m_fobjc_gc_only = true;
    }
    it = m_real_options.find("-fobjc-runtime-has-arc");
    if( m_real_options.end() != it) {
        m_fobjc_runtime_has_arc = true;
    }
    it = m_real_options.find("-fobjc-runtime-has-terminate");
    if( m_real_options.end() != it) {
        m_fobjc_runtime_has_terminate = true;
    }
    it = m_real_options.find("-fobjc-runtime-has-weak");
    if( m_real_options.end() != it) {
        m_fobjc_runtime_has_weak = true;
    }
    it = m_real_options.find("-foverride-record-layout");
    if( m_real_options.end() != it) {
        m_foverride_record_layout = it->second;
    }
    it = m_real_options.find("-fpack-struct");
    if( m_real_options.end() != it) {
        m_fpack_struct = it->second;
    }
    it = m_real_options.find("-fpascal-strings");
    if( m_real_options.end() != it) {
        m_fpascal_strings = true;
    }
    it = m_real_options.find("-fshort-enums");
    if( m_real_options.end() != it) {
        m_fshort_enums = true;
    }
    it = m_real_options.find("-fshort-wchar");
    if( m_real_options.end() != it) {
        m_fshort_wchar = true;
    }
    it = m_real_options.find("-fshow-column");
    if( m_real_options.end() != it) {
        m_fshow_column = true;
    }
    it = m_real_options.find("-fshow-overloads");
    if( m_real_options.end() != it) {
        m_fshow_overloads = it->second;
    }
    it = m_real_options.find("-fsjlj-exceptions");
    if( m_real_options.end() != it) {
        m_fsjlj_exceptions = true;
    }
    it = m_real_options.find("-fsyntax-only");
    if( m_real_options.end() != it) {
        m_fsyntax_only = true;
    }
    it = m_real_options.find("-ftabstop");
    if( m_real_options.end() != it) {
        m_ftabstop = it->second;
    }
    it = m_real_options.find("-ftemplate-backtrace-limit");
    if( m_real_options.end() != it) {
        m_ftemplate_backtrace_limit = it->second;
    }
    it = m_real_options.find("-ftemplate-depth");
    if( m_real_options.end() != it) {
        m_ftemplate_depth = it->second;
    }
    it = m_real_options.find("-ftime-report");
    if( m_real_options.end() != it) {
        m_ftime_report = true;
    }
    it = m_real_options.find("-ftrap-function");
    if( m_real_options.end() != it) {
        m_ftrap_function = it->second;
    }
    it = m_real_options.find("-ftrapv");
    if( m_real_options.end() != it) {
        m_ftrapv = true;
    }
    it = m_real_options.find("-ftrapv-handler");
    if( m_real_options.end() != it) {
        m_ftrapv_handler = it->second;
    }
    it = m_real_options.find("-funknown-anytype");
    if( m_real_options.end() != it) {
        m_funknown_anytype = true;
    }
    it = m_real_options.find("-funroll-loops");
    if( m_real_options.end() != it) {
        m_funroll_loops = true;
    }
    it = m_real_options.find("-fuse-register-sized-bitfield-access");
    if( m_real_options.end() != it) {
        m_fuse_register_sized_bitfield_access = true;
    }
    it = m_real_options.find("-fvisibility");
    if( m_real_options.end() != it) {
        m_fvisibility = it->second;
    }
    it = m_real_options.find("-fvisibility-inlines-hidden");
    if( m_real_options.end() != it) {
        m_fvisibility_inlines_hidden = true;
    }
    it = m_real_options.find("-fwrapv");
    if( m_real_options.end() != it) {
        m_fwrapv = true;
    }
    it = m_real_options.find("-fwritable-strings");
    if( m_real_options.end() != it) {
        m_fwritable_strings = true;
    }
    it = m_real_options.find("-g");
    if( m_real_options.end() != it) {
        m_g = true;
    }
    it = m_real_options.find("-gcc-toolchain");
    if( m_real_options.end() != it) {
        m_gcc_toolchain = it->second;
    }
    it = m_real_options.find("-header-include-file");
    if( m_real_options.end() != it) {
        m_header_include_file = it->second;
    }
    it = m_real_options.find("-help");
    if( m_real_options.end() != it) {
        m_help = true;
    }
    it = m_real_options.find("-idirafter");
    if( m_real_options.end() != it) {
        m_idirafter = it->second;
    }
    it = m_real_options.find("-iframework");
    if( m_real_options.end() != it) {
        m_iframework = it->second;
    }
    it = m_real_options.find("-imacros");
    if( m_real_options.end() != it) {
        m_imacros = it->second;
    }
    it = m_real_options.find("-include");
    if( m_real_options.end() != it) {
        m_include = it->second;
    }
    it = m_real_options.find("-include-pch");
    if( m_real_options.end() != it) {
        m_include_pch = it->second;
    }
    it = m_real_options.find("-include-pth");
    if( m_real_options.end() != it) {
        m_include_pth = it->second;
    }
    it = m_real_options.find("-index-header-map");
    if( m_real_options.end() != it) {
        m_index_header_map = true;
    }
    it = m_real_options.find("-init-only");
    if( m_real_options.end() != it) {
        m_init_only = true;
    }
    it = m_real_options.find("-internal-externc-isystem");
    if( m_real_options.end() != it) {
        m_internal_externc_isystem = it->second;
    }
    it = m_real_options.find("-internal-isystem");
    if( m_real_options.end() != it) {
        m_internal_isystem = it->second;
    }
    it = m_real_options.find("-iprefix");
    if( m_real_options.end() != it) {
        m_iprefix = it->second;
    }
    it = m_real_options.find("-iquote");
    if( m_real_options.end() != it) {
        m_iquote = it->second;
    }
    it = m_real_options.find("-isysroot");
    if( m_real_options.end() != it) {
        m_isysroot = it->second;
    }
    it = m_real_options.find("-isystem");
    if( m_real_options.end() != it) {
        m_isystem = it->second;
    }
    it = m_real_options.find("-iwithprefix");
    if( m_real_options.end() != it) {
        m_iwithprefix = it->second;
    }
    it = m_real_options.find("-iwithprefixbefore");
    if( m_real_options.end() != it) {
        m_iwithprefixbefore = it->second;
    }
    it = m_real_options.find("-iwithsysroot");
    if( m_real_options.end() != it) {
        m_iwithsysroot = it->second;
    }
    it = m_real_options.find("-load");
    if( m_real_options.end() != it) {
        m_load = it->second;
    }
    it = m_real_options.find("-main-file-name");
    if( m_real_options.end() != it) {
        m_main_file_name = it->second;
    }
    it = m_real_options.find("-masm-verbose");
    if( m_real_options.end() != it) {
        m_masm_verbose = true;
    }
    it = m_real_options.find("-mcode-model");
    if( m_real_options.end() != it) {
        m_mcode_model = it->second;
    }
    it = m_real_options.find("-mconstructor-aliases");
    if( m_real_options.end() != it) {
        m_mconstructor_aliases = true;
    }
    it = m_real_options.find("-mdebug-pass");
    if( m_real_options.end() != it) {
        m_mdebug_pass = it->second;
    }
    it = m_real_options.find("-mdisable-fp-elim");
    if( m_real_options.end() != it) {
        m_mdisable_fp_elim = true;
    }
    it = m_real_options.find("-mdisable-tail-calls");
    if( m_real_options.end() != it) {
        m_mdisable_tail_calls = true;
    }
    it = m_real_options.find("-menable-no-infs");
    if( m_real_options.end() != it) {
        m_menable_no_infs = true;
    }
    it = m_real_options.find("-menable-no-nans");
    if( m_real_options.end() != it) {
        m_menable_no_nans = true;
    }
    it = m_real_options.find("-menable-unsafe-fp-math");
    if( m_real_options.end() != it) {
        m_menable_unsafe_fp_math = true;
    }
    it = m_real_options.find("-mfloat-abi");
    if( m_real_options.end() != it) {
        m_mfloat_abi = it->second;
    }
    it = m_real_options.find("-migrate");
    if( m_real_options.end() != it) {
        m_migrate = true;
    }
    it = m_real_options.find("-mlimit-float-precision");
    if( m_real_options.end() != it) {
        m_mlimit_float_precision = it->second;
    }
    it = m_real_options.find("-mlink-bitcode-file");
    if( m_real_options.end() != it) {
        m_mlink_bitcode_file = it->second;
    }
    it = m_real_options.find("-mllvm");
    if( m_real_options.end() != it) {
        m_mllvm = it->second;
    }
    it = m_real_options.find("-mms-bitfields");
    if( m_real_options.end() != it) {
        m_mms_bitfields = true;
    }
    it = m_real_options.find("-mno-global-merge");
    if( m_real_options.end() != it) {
        m_mno_global_merge = true;
    }
    it = m_real_options.find("-mno-zero-initialized-in-bss");
    if( m_real_options.end() != it) {
        m_mno_zero_initialized_in_bss = true;
    }
    it = m_real_options.find("-mnoexecstack");
    if( m_real_options.end() != it) {
        m_mnoexecstack = true;
    }
    it = m_real_options.find("-momit-leaf-frame-pointer");
    if( m_real_options.end() != it) {
        m_momit_leaf_frame_pointer = true;
    }
    it = m_real_options.find("-mqdsp6-compat");
    if( m_real_options.end() != it) {
        m_mqdsp6_compat = true;
    }
    it = m_real_options.find("-mregparm");
    if( m_real_options.end() != it) {
        m_mregparm = it->second;
    }
    it = m_real_options.find("-mrelax-all");
    if( m_real_options.end() != it) {
        m_mrelax_all = true;
    }
    it = m_real_options.find("-mrelocation-model");
    if( m_real_options.end() != it) {
        m_mrelocation_model = it->second;
    }
    it = m_real_options.find("-mrtd");
    if( m_real_options.end() != it) {
        m_mrtd = true;
    }
    it = m_real_options.find("-msave-temp-labels");
    if( m_real_options.end() != it) {
        m_msave_temp_labels = true;
    }
    it = m_real_options.find("-msoft-float");
    if( m_real_options.end() != it) {
        m_msoft_float = true;
    }
    it = m_real_options.find("-mstack-alignment");
    if( m_real_options.end() != it) {
        m_mstack_alignment = it->second;
    }
    it = m_real_options.find("-mstackrealign");
    if( m_real_options.end() != it) {
        m_mstackrealign = true;
    }
    it = m_real_options.find("-mt-migrate-directory");
    if( m_real_options.end() != it) {
        m_mt_migrate_directory = it->second;
    }
    it = m_real_options.find("-munwind-tables");
    if( m_real_options.end() != it) {
        m_munwind_tables = true;
    }
    it = m_real_options.find("-no-code-completion-globals");
    if( m_real_options.end() != it) {
        m_no_code_completion_globals = true;
    }
    it = m_real_options.find("-no-finalize-removal");
    if( m_real_options.end() != it) {
        m_no_finalize_removal = true;
    }
    it = m_real_options.find("-no-implicit-float");
    if( m_real_options.end() != it) {
        m_no_implicit_float = true;
    }
    it = m_real_options.find("-no-ns-alloc-error");
    if( m_real_options.end() != it) {
        m_no_ns_alloc_error = true;
    }
    it = m_real_options.find("-nobuiltininc");
    if( m_real_options.end() != it) {
        m_nobuiltininc = true;
    }
    it = m_real_options.find("-nostdinc++");
    if( m_real_options.end() != it) {
        m_nostdincplusplus = true;
    }
    it = m_real_options.find("-nostdsysteminc");
    if( m_real_options.end() != it) {
        m_nostdsysteminc = true;
    }
    it = m_real_options.find("-o");
    if( m_real_options.end() != it) {
        m_o = it->second;
    }
    it = m_real_options.find("-objc-isystem");
    if( m_real_options.end() != it) {
        m_objc_isystem = it->second;
    }
    it = m_real_options.find("-objcmt-migrate-literals");
    if( m_real_options.end() != it) {
        m_objcmt_migrate_literals = true;
    }
    it = m_real_options.find("-objcmt-migrate-subscripting");
    if( m_real_options.end() != it) {
        m_objcmt_migrate_subscripting = true;
    }
    it = m_real_options.find("-objcxx-isystem");
    if( m_real_options.end() != it) {
        m_objcxx_isystem = it->second;
    }
    it = m_real_options.find("-pg");
    if( m_real_options.end() != it) {
        m_pg = true;
    }
    it = m_real_options.find("-pic-level");
    if( m_real_options.end() != it) {
        m_pic_level = it->second;
    }
    it = m_real_options.find("-pipe");
    if( m_real_options.end() != it) {
        m_pipe = true;
    }
    it = m_real_options.find("-plugin");
    if( m_real_options.end() != it) {
        m_plugin = it->second;
    }
    it = m_real_options.find("-plugin-arg");
    if( m_real_options.end() != it) {
        m_plugin_arg = it->second;
    }
    it = m_real_options.find("-preamble-bytes");
    if( m_real_options.end() != it) {
        m_preamble_bytes = it->second;
    }
    it = m_real_options.find("-print-decl-contexts");
    if( m_real_options.end() != it) {
        m_print_decl_contexts = true;
    }
    it = m_real_options.find("-print-file-name");
    if( m_real_options.end() != it) {
        m_print_file_name = it->second;
    }
    it = m_real_options.find("-print-ivar-layout");
    if( m_real_options.end() != it) {
        m_print_ivar_layout = true;
    }
    it = m_real_options.find("-print-libgcc-file-name");
    if( m_real_options.end() != it) {
        m_print_libgcc_file_name = true;
    }
    it = m_real_options.find("-print-preamble");
    if( m_real_options.end() != it) {
        m_print_preamble = true;
    }
    it = m_real_options.find("-print-prog-name");
    if( m_real_options.end() != it) {
        m_print_prog_name = it->second;
    }
    it = m_real_options.find("-print-search-dirs");
    if( m_real_options.end() != it) {
        m_print_search_dirs = true;
    }
    it = m_real_options.find("-print-stats");
    if( m_real_options.end() != it) {
        m_print_stats = true;
    }
    it = m_real_options.find("-pthread");
    if( m_real_options.end() != it) {
        m_pthread = true;
    }
    it = m_real_options.find("-pubnames-dump");
    if( m_real_options.end() != it) {
        m_pubnames_dump = true;
    }
    it = m_real_options.find("-relaxed-aliasing");
    if( m_real_options.end() != it) {
        m_relaxed_aliasing = true;
    }
    it = m_real_options.find("-relocatable-pch");
    if( m_real_options.end() != it) {
        m_relocatable_pch = true;
    }
    it = m_real_options.find("-remap-file");
    if( m_real_options.end() != it) {
        m_remap_file = it->second;
    }
    it = m_real_options.find("-resource-dir");
    if( m_real_options.end() != it) {
        m_resource_dir = it->second;
    }
    it = m_real_options.find("-rewrite-macros");
    if( m_real_options.end() != it) {
        m_rewrite_macros = true;
    }
    it = m_real_options.find("-rewrite-objc");
    if( m_real_options.end() != it) {
        m_rewrite_objc = true;
    }
    it = m_real_options.find("-rewrite-test");
    if( m_real_options.end() != it) {
        m_rewrite_test = true;
    }
    it = m_real_options.find("-save-temps");
    if( m_real_options.end() != it) {
        m_save_temps = true;
    }
    it = m_real_options.find("-serialize-diagnostic-file");
    if( m_real_options.end() != it) {
        m_serialize_diagnostic_file = it->second;
    }
    it = m_real_options.find("-stack-protector");
    if( m_real_options.end() != it) {
        m_stack_protector = it->second;
    }
    it = m_real_options.find("-static-define");
    if( m_real_options.end() != it) {
        m_static_define = true;
    }
    it = m_real_options.find("-std");
    if( m_real_options.end() != it) {
        m_std = it->second;
    }
    it = m_real_options.find("-stdlib");
    if( m_real_options.end() != it) {
        m_stdlib = it->second;
    }
    it = m_real_options.find("-sys-header-deps");
    if( m_real_options.end() != it) {
        m_sys_header_deps = true;
    }
    it = m_real_options.find("-target");
    if( m_real_options.end() != it) {
        m_target = it->second;
    }
    it = m_real_options.find("-target-abi");
    if( m_real_options.end() != it) {
        m_target_abi = it->second;
    }
    it = m_real_options.find("-target-cpu");
    if( m_real_options.end() != it) {
        m_target_cpu = it->second;
    }
    it = m_real_options.find("-target-feature");
    if( m_real_options.end() != it) {
        m_target_feature = it->second;
    }
    it = m_real_options.find("-target-linker-version");
    if( m_real_options.end() != it) {
        m_target_linker_version = it->second;
    }
    it = m_real_options.find("-time");
    if( m_real_options.end() != it) {
        m_time = true;
    }
    it = m_real_options.find("-token-cache");
    if( m_real_options.end() != it) {
        m_token_cache = it->second;
    }
    it = m_real_options.find("-traditional-cpp");
    if( m_real_options.end() != it) {
        m_traditional_cpp = true;
    }
    it = m_real_options.find("-trigraphs");
    if( m_real_options.end() != it) {
        m_trigraphs = true;
    }
    it = m_real_options.find("-trim-egraph");
    if( m_real_options.end() != it) {
        m_trim_egraph = true;
    }
    it = m_real_options.find("-triple");
    if( m_real_options.end() != it) {
        m_triple = it->second;
    }
    it = m_real_options.find("-undef");
    if( m_real_options.end() != it) {
        m_undef = true;
    }
    it = m_real_options.find("-unoptimized-cfg");
    if( m_real_options.end() != it) {
        m_unoptimized_cfg = true;
    }
    it = m_real_options.find("-v");
    if( m_real_options.end() != it) {
        m_v = true;
    }
    it = m_real_options.find("-verify");
    if( m_real_options.end() != it) {
        m_verify = true;
    }
    it = m_real_options.find("-version");
    if( m_real_options.end() != it) {
        m_version = true;
    }
    it = m_real_options.find("-w");
    if( m_real_options.end() != it) {
        m_w = true;
    }
    it = m_real_options.find("-working-directory");
    if( m_real_options.end() != it) {
        m_working_directory = it->second;
    }
}