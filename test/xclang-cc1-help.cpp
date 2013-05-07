OVERVIEW: LLVM 'Clang' Compiler: http://clang.llvm.org

USAGE: clang -cc1 [options] <inputs>

OPTIONS:
  -Eonly                  Just run preprocessor, no output (for timings)
  -E                      Only run the preprocessor
  -F <value>              Add directory to framework include search path
  -H                      Show header includes and nesting depth
  -I <value>              Add directory to include search path
  -MG                     Add missing headers to dependency list
  -MP                     Create phony target for each dependency (other than main file)
  -MQ <value>             Specify target to quote for dependency
  -MT <value>             Specify target for dependency
  -P                      Disable linemarker output in -E mode
  -S                      Only run preprocess and compilation steps
  -Wno-rewrite-macros     Silence ObjC rewriting warnings
  -W<warning>             Enable the specified warning
  -add-plugin <name>      Use the named plugin action in addition to the default action
  -analyze-function <value>
                          Run analysis on specific function
  -analyzer-checker-help  Display the list of analyzer checkers that are available
  -analyzer-checker <value>
                          Choose analyzer checkers to enable
  -analyzer-config <value>
                          Choose analyzer options to enable
  -analyzer-constraints <value>
                          Source Code Analysis - Symbolic Constraint Engines
  -analyzer-disable-checker <value>
                          Choose analyzer checkers to disable
  -analyzer-disable-retry-exhausted
                          Do not re-analyze paths leading to exhausted nodes with a different strategy (may decrease code coverage)
  -analyzer-display-progress
                          Emit verbose output about the analyzer's progress
  -analyzer-eagerly-assume
                          Eagerly assume the truth/falseness of some symbolic constraints
  -analyzer-inline-max-stack-depth <value>
                          Bound on stack depth while inlining (4 by default)
  -analyzer-inlining-mode <value>
                          Specify the function selection heuristic used during inlining
  -analyzer-max-loop <value>
                          The maximum number of times the analyzer will go through a loop
  -analyzer-opt-analyze-headers
                          Force the static analyzer to analyze functions defined in header files
  -analyzer-opt-analyze-nested-blocks
                          Analyze the definitions of blocks in addition to functions
  -analyzer-output <value>
                          Source Code Analysis - Output Options
  -analyzer-purge <value> Source Code Analysis - Dead Symbol Removal Frequency
  -analyzer-stats         Print internal analyzer statistics.
  -analyzer-store <value> Source Code Analysis - Abstract Memory Store Models
  -analyzer-viz-egraph-graphviz
                          Display exploded graph using GraphViz
  -analyzer-viz-egraph-ubigraph
                          Display exploded graph using Ubigraph
  -analyze                Run static analysis engine
  -arcmt-check            Check for ARC migration issues that need manual handling
  -arcmt-migrate-emit-errors
                          Emit ARC errors even if the migrator can fix them
  -arcmt-migrate-report-output <value>
                          Output path for the plist report
  -arcmt-migrate          Apply modifications and produces temporary files that conform to ARC
  -arcmt-modify           Apply modifications to files to conform to ARC
  -ast-dump-filter <dump_filter>
                          Use with -ast-dump or -ast-print to dump/print only AST declaration nodes having a certain substring in a qualified name. Use -ast-list to list all filterable declaration node names.
  -ast-dump-xml           Build ASTs and then debug dump them in a verbose XML format
  -ast-dump               Build ASTs and then debug dump them
  -ast-list               Build ASTs and print the list of declaration node qualified names
  -ast-merge <ast file>   Merge the given AST file into the translation unit being compiled.
  -ast-print              Build ASTs and then pretty-print them
  -ast-view               Build ASTs and view them with GraphViz
  -backend-option <value> Additional arguments to forward to LLVM backend (during code gen)
  -c-isystem <directory>  Add directory to the C SYSTEM include search path
  -cfg-add-implicit-dtors Add C++ implicit destructors to CFGs for all analyses
  -chain-include <file>   Include and chain a header file after turning it into PCH
  -cl-fast-relaxed-math   OpenCL only. Sets -cl-finite-math-only and -cl-unsafe-math-optimizations, and defines __FAST_RELAXED_MATH__
  -cl-finite-math-only    OpenCL only. Allow floating-point optimizations that assume arguments and results are not NaNs or +-Inf.
  -cl-kernel-arg-info     OpenCL only. This option allows the compiler to store information about the arguments of a kernel(s)
  -cl-mad-enable          OpenCL only. Enable less precise MAD instructions to be generated.
  -cl-opt-disable         OpenCL only. This option disables all optimizations. The default is optimizations are enabled.
  -cl-single-precision-constant
                          OpenCL only. Treat double precision floating-point constant as single precision constant.
  -cl-std=<value>         OpenCL language standard to compile for
  -cl-unsafe-math-optimizations
                          OpenCL only. Allow unsafe floating-point optimizations.  Also implies -cl-no-signed-zeros and -cl-mad-enable
  -code-completion-at <file>:<line>:<column>
                          Dump code-completion information at a location
  -code-completion-brief-comments
                          Include brief documentation comments in code-completion results.
  -code-completion-macros Include macros in code-completion results
  -code-completion-patterns
                          Include code patterns in code-completion results
  -coverage-cfg-checksum  Emit CFG checksum for functions in .gcno files.
  -coverage-file <value>  Emit coverage data to this filename. The extension will be replaced.
  -coverage-no-function-names-in-data
                          Emit function names in .gcda files.
  -coverage-version=<value>
                          Four-byte version string for gcov files.
  -cxx-abi <value>        Target a particular C++ ABI type
  -cxx-isystem <directory>
                          Add directory to the C++ SYSTEM include search path
  -dD                     Print macro definitions in -E mode in addition to normal output
  -dM                     Print macro definitions in -E mode instead of normal output
  -dependency-dot <value> Filename to write DOT-formatted header dependencies to
  -dependency-file <value>
                          Filename (or -) to write dependency output to
  -detailed-preprocessing-record
                          include a detailed record of preprocessing actions
  -diagnostic-log-file <value>
                          Filename (or -) to log diagnostics to
  -disable-free           Disable freeing of memory on exit
  -disable-llvm-optzns    Don't run LLVM optimization passes
  -disable-llvm-verifier  Don't run the LLVM IR verifier pass
  -disable-red-zone       Do not emit code that uses the red zone.
  -dump-deserialized-decls
                          Dump declarations that are deserialized from PCH, for testing
  -dump-raw-tokens        Lex file in raw mode and dump raw tokens
  -dump-tokens            Run preprocessor, dump internal rep of tokens
  -dwarf-column-info      Turn on column location information.
  -dwarf-debug-flags <value>
                          The string to embed in the Dwarf debug flags record.
  -emit-codegen-only      Generate machine code, but discard output
  -emit-html              Output input source as HTML
  -emit-llvm-bc           Build ASTs then convert to LLVM, emit .bc file
  -emit-llvm-only         Build ASTs and convert to LLVM, discarding output
  -emit-llvm              Use the LLVM representation for assembler and object files
  -emit-module            Generate pre-compiled module file from a module map
  -emit-obj               Emit native object files
  -emit-pch               Generate pre-compiled header file
  -emit-pth               Generate pre-tokenized header file
  -error-on-deserialized-decl <value>
                          Emit error if a specific declaration is deserialized from PCH, for testing
  -faltivec               Enable AltiVec vector initializer syntax
  -fapple-kext            Use Apple's kernel extensions ABI
  -fapple-pragma-pack     Enable Apple gcc-compatible #pragma pack handling
  -fblocks-runtime-optional
                          Weakly link in the blocks runtime
  -fblocks                Enable the 'blocks' language feature
  -fborland-extensions    Accept non-standard constructs supported by the Borland compiler
  -fbracket-depth <value> Maximum nesting level for parentheses, brackets, and braces
  -fcolor-diagnostics     Use colors in diagnostics
  -fcomment-block-commands=<arg>
                          Treat each comma separated argument in <arg> as a documentation comment block command
  -fconst-strings         Use a const qualified type for string literals in C and ObjC
  -fconstant-string-class <class name>
                          Specify the class to use for constant Objective-C string objects.
  -fconstexpr-backtrace-limit <N>
                          Set the maximum number of entries to print in a constexpr evaluation backtrace (0 = no limit).
  -fconstexpr-depth <value>
                          Maximum depth of recursive constexpr function calls
  -fcuda-is-device        Generate code for CUDA device
  -fcxx-exceptions        Enable C++ exceptions
  -fdata-sections         Place each data in its own section (ELF Only)
  -fdebug-compilation-dir <value>
                          The compilation directory to embed in the debug info.
  -fdebugger-cast-result-to-id
                          Enable casting unknown expression results to id
  -fdebugger-objc-literal Enable special debugger support for Objective-C subscripting and literals
  -fdebugger-support      Enable special debugger support behavior
  -fdelayed-template-parsing
                          Parse templated function definitions at the end of the translation unit 
  -fdeprecated-macro      Defines the __DEPRECATED macro
  -fdiagnostics-format <value>
                          Change diagnostic formatting to match IDE and command line tools
  -fdiagnostics-parseable-fixits
                          Print fix-its in machine parseable form
  -fdiagnostics-print-source-range-info
                          Print source range spans in numeric form
  -fdiagnostics-show-category <value>
                          Print diagnostic category
  -fdiagnostics-show-name Print diagnostic name
  -fdiagnostics-show-note-include-stack
                          Display include stacks for diagnostic notes
  -fdiagnostics-show-option
                          Print option name with mappable diagnostics
  -fdiagnostics-show-template-tree
                          Print a template comparison tree for differing templates
  -fdisable-module-hash   Disable the module hash
  -fdollars-in-identifiers
                          Allow '$' in identifiers
  -fdump-record-layouts-simple
                          Dump record layout information in a simple form used for testing
  -fdump-record-layouts   Dump record layout information
  -fdump-vtable-layouts   Dump the layouts of all vtables that will be emitted in a translation unit
  -femit-all-decls        Emit all declarations, even if unused
  -femit-coverage-data    Instrument the program to emit gcov coverage data when run.
  -femit-coverage-notes   Emit a gcov coverage notes file when compiling.
  -fencode-extended-block-signature
                          enable extended encoding of block type signature
  -ferror-limit <N>       Set the maximum number of errors to emit before stopping (0 = no limit).
  -fexceptions            Enable support for exception handling
  -ffake-address-space-map
                          Use a fake address space map; OpenCL testing purposes only
  -ffast-math             Enable the *frontend*'s 'fast-math' mode. This has no effect on optimizations, but provides a preprocessor macro __FAST_MATH__ the same as GCC's -ffast-math flag
  -fforbid-guard-variables
                          Emit an error if a C++ static local initializer would need a guard variable
  -ffp-contract=<value>   Form fused FP ops (e.g. FMAs): fast (everywhere) | on (according to FP_CONTRACT pragma, default) | off (never fuse)
  -ffreestanding          Assert that the compilation takes place in a freestanding environment
  -ffunction-sections     Place each function in its own section (ELF Only)
  -fgnu-keywords          Allow GNU-extension keywords regardless of language standard
  -fgnu89-inline          Use the gnu89 inline semantics
  -fhidden-weak-vtables   Generate weak vtables and RTTI with hidden visibility
  -finstrument-functions  Generate calls to instrument function entry and exit
  -fix-only-warnings      Apply fix-it advice only for warnings, not errors
  -fix-what-you-can       Apply fix-it advice even in the presence of unfixable errors
  -fixit-recompile        Apply fix-it changes and recompile
  -fixit-to-temporary     Apply fix-it changes to temporary files
  -fixit=<value>          Apply fix-it advice creating a file with the given suffix
  -fixit                  Apply fix-it advice to the input source
  -flimit-debug-info      Limit debug information produced to reduce size of debug binary
  -fmacro-backtrace-limit <N>
                          Set the maximum number of entries to print in a macro expansion backtrace (0 = no limit).
  -fmath-errno            Require math functions to indicate errors by setting errno
  -fmessage-length <N>    Format message diagnostics so that they fit within N columns or fewer, when possible.
  -fmodule-name=<name>    Specify the name of the module to build
  -fmodules-cache-path=<directory>
                          Specify the module cache path
  -fmodules-ignore-macro=<value>
                          Ignore the definition of the given macro when building and loading modules
  -fmodules-prune-after=<seconds>
                          Specify the interval (in seconds) after which a module file will be considered unused
  -fmodules-prune-interval=<seconds>
                          Specify the interval (in seconds) between attempts to prune the module cache
  -fmodules               Enable the 'modules' language feature
  -fms-compatibility      Enable Microsoft compatibility mode
  -fms-extensions         Accept some non-standard constructs supported by the Microsoft compiler
  -fmsc-version=<value>   Version of the Microsoft C/C++ compiler to report in _MSC_VER (0 = don't define it (default))
  -fno-access-control     Disable C++ access control
  -fno-assume-sane-operator-new
                          Don't assume that C++'s global operator new can't alias any pointer
  -fno-autolink           Disable generation of linker directives for automatic library linking
  -fno-bitfield-type-align
                          Ignore bit-field types when aligning structures
  -fno-builtin            Disable implicit builtin knowledge of functions
  -fno-common             Compile common globals like normal definitions
  -fno-const-strings      Don't use a const qualified type for string literals in C and ObjC
  -fno-constant-cfstrings Disable creation of CodeFoundation-type constant strings
  -fno-deprecated-macro   Undefines the __DEPRECATED macro
  -fno-diagnostics-fixit-info
                          Do not include fixit information in diagnostics
  -fno-diagnostics-show-note-include-stack
                          Display include stacks for diagnostic notes
  -fno-diagnostics-use-presumed-location
                          Ignore #line directives when displaying diagnostic locations
  -fno-dollars-in-identifiers
                          Disallow '$' in identifiers
  -fno-elide-constructors Disable C++ copy constructor elision
  -fno-elide-type         Do not elide types when printing diagnostics
  -fno-lax-vector-conversions
                          Disallow implicit conversions between vectors with a different number of elements or different element types
  -fno-limit-debug-info   Do not limit debug information produced to reduce size of debug binary
  -fno-merge-all-constants
                          Disallow merging of constants
  -fno-modules-global-index
                          Do not automatically generate or update the global module index
  -fno-objc-infer-related-result-type
                          do not infer Objective-C related result type based on method family
  -fno-operator-names     Do not treat C++ operator name keywords as synonyms for operators
  -fno-rtti               Disable generation of rtti information
  -fno-sanitize-recover   Disable sanitizer check recovery
  -fno-show-column        Do not include column number on diagnostics
  -fno-show-source-location
                          Do not include source location information with diagnostics
  -fno-signed-char        Char is unsigned
  -fno-spell-checking     Disable spell-checking
  -fno-threadsafe-statics Do not emit code to make initialization of local statics thread safe
  -fno-use-cxa-atexit     Don't use __cxa_atexit for calling destructors
  -fno-use-init-array     Don't use .init_array instead of .ctors
  -fno-validate-pch       Disable validation of precompiled headers
  -fno-wchar              Disable C++ builtin type wchar_t
  -fobjc-arc-cxxlib=<value>
                          Objective-C++ Automatic Reference Counting standard library kind
  -fobjc-arc-exceptions   Use EH-safe code when synthesizing retains and releases in -fobjc-arc
  -fobjc-arc              Synthesize retain and release calls for Objective-C pointers
  -fobjc-default-synthesize-properties
                          enable the default synthesis of Objective-C properties
  -fobjc-dispatch-method=<value>
                          Objective-C dispatch method to use
  -fobjc-exceptions       Enable Objective-C exceptions
  -fobjc-gc-only          Use GC exclusively for Objective-C related memory management
  -fobjc-gc               Enable Objective-C garbage collection
  -fobjc-runtime-has-weak The target Objective-C runtime supports ARC weak operations
  -fobjc-runtime=<value>  Specify the target Objective-C runtime kind and version
  -foverride-record-layout=<value>
                          Override record layouts with those in the given file
  -fpack-struct=<value>   Specify the default maximum struct packing alignment
  -fpascal-strings        Recognize and construct Pascal-style string literals
  -fsanitize-address-zero-base-shadow
                          Make AddressSanitizer map shadow memory at zero offset
  -fsanitize-blacklist=<value>
                          Path to blacklist file for sanitizers
  -fsanitize-memory-track-origins
                          Enable origins tracking in MemorySanitizer
  -fsanitize=<check>      Enable runtime instrumentation for bug detection: address (memory errors) | thread (race detection) | undefined (miscellaneous undefined behavior)
  -fshort-enums           Allocate to an enum type only as many bytes as it needs for the declared range of possible values
  -fshort-wchar           Force wchar_t to be a short unsigned int
  -fshow-overloads=<value>
                          Which overload candidates to show when overload resolution fails: best|all; defaults to all
  -fsjlj-exceptions       Use SjLj style exceptions
  -fstrict-enums          Enable optimizations based on the strict definition of an enum's value range
  -ftabstop <N>           Set the tab stop distance.
  -ftemplate-backtrace-limit <N>
                          Set the maximum number of entries to print in a template instantiation backtrace (0 = no limit).
  -ftemplate-depth <value>
                          Maximum depth of recursive template instantiation
  -ftrap-function=<value> Issue call to specified function rather than a trap instruction
  -ftrapv                 Trap on integer overflow
  -ftype-visibility <value>
                          Default type visibility
  -funknown-anytype       Enable parser support for the __unknown_anytype type; for testing purposes only
  -funroll-loops          Turn on loop unroller
  -fuse-init-array        Use .init_array instead of .ctors
  -fuse-register-sized-bitfield-access
                          Use register sized accesses to bit-fields, when possible.
  -fvisibility-inlines-hidden
                          Give inline C++ member functions default visibility by default
  -fvisibility <value>    Default type and symbol visibility
  -fwrapv                 Treat signed integer overflow as two's complement
  -fwritable-strings      Store string literals as writable data
  -gline-tables-only      Emit debug line number tables only
  -g                      Generate source level debug information
  -header-include-file <value>
                          Filename (or -) to write header include output to
  -help                   Display available options
  -idirafter <value>      Add directory to AFTER include search path
  -iframework <value>     Add directory to SYSTEM framework search path
  -imacros <file>         Include macros from file before parsing
  -include-pch <file>     Include precompiled header file
  -include-pth <file>     Include file before parsing
  -include <file>         Include file before parsing
  -index-header-map       Make the next included directory (-I or -F) an indexer header map
  -init-only              Only execute frontend initialization
  -ino-system-prefix <prefix>
                          Treat all #include paths starting with <prefix> as not including a system header.
  -internal-externc-isystem <directory>
                          Add directory to the internal system include search path with implicit extern "C" semantics; these are assumed to not be user-provided and are used to model system and standard headers' paths.
  -internal-isystem <directory>
                          Add directory to the internal system include search path; these are assumed to not be user-provided and are used to model system and standard headers' paths.
  -iprefix <dir>          Set the -iwithprefix/-iwithprefixbefore prefix
  -iquote <directory>     Add directory to QUOTE include search path
  -isysroot <dir>         Set the system root directory (usually /)
  -isystem-prefix <prefix>
                          Treat all #include paths starting with <prefix> as including a system header.
  -isystem <directory>    Add directory to SYSTEM include search path
  -iwithprefixbefore <dir>
                          Set directory to include search path with prefix
  -iwithprefix <dir>      Set directory to SYSTEM include search path with prefix
  -iwithsysroot <directory>
                          Add directory to SYSTEM include search path, absolute paths are relative to -isysroot
  -load <dsopath>         Load the named plugin (dynamic shared object)
  -main-file-name <value> Main file name to use for debug info
  -masm-verbose           Generate verbose assembly output
  -mcode-model <value>    The code model to use
  -mconstructor-aliases   Emit complete constructors and destructors as aliases when possible
  -mdebug-pass <value>    Enable additional debug output
  -mdisable-fp-elim       Disable frame pointer elimination optimization
  -mdisable-tail-calls    Disable tail call optimization, keeping the call stack accurate
  -menable-no-infs        Allow optimization to assume there are no infinities.
  -menable-no-nans        Allow optimization to assume there are no NaNs.
  -menable-unsafe-fp-math Allow unsafe floating-point math optimizations which may decrease precision
  -mfloat-abi <value>     The float ABI to use
  -migrate                Migrate source code
  -mlimit-float-precision <value>
                          Limit float precision to the given value
  -mlink-bitcode-file <value>
                          Link the given bitcode file before performing optimizations.
  -mllvm <value>          Additional arguments to forward to LLVM's option processing
  -mms-bitfields          Set the default structure layout to be compatible with the Microsoft compiler standard
  -mno-global-merge       Disable merging of globals
  -mno-zero-initialized-in-bss
                          Do not put zero initialized data in the BSS
  -mnoexecstack           Mark the file as not needing an executable stack
  -momit-leaf-frame-pointer
                          Omit frame pointer setup for leaf functions
  -mqdsp6-compat          Enable hexagon-qdsp6 backward compatibility
  -mregparm <value>       Limit the number of registers available for integer arguments
  -mrelax-all             (integrated-as) Relax all machine instructions
  -mrelocation-model <value>
                          The relocation model to use
  -mrtd                   Make StdCall calling convention the default
  -msave-temp-labels      (integrated-as) Save temporary labels
  -msoft-float            Use software floating point
  -mstack-alignment=<value>
                          Set the stack alignment
  -mstackrealign          Force realign the stack at entry to every function
  -mstrict-align          Force all memory accesses to be aligned (ARM only)
  -mt-migrate-directory <value>
                          Directory for temporary files produced during ARC or ObjC migration
  -munwind-tables         Generate unwinding tables for all functions
  -no-code-completion-globals
                          Do not include global declarations in code-completion results.
  -no-finalize-removal    Do not remove finalize method in gc mode
  -no-implicit-float      Don't generate implicit floating point instructions
  -no-ns-alloc-error      Do not error on use of NSAllocateCollectable/NSReallocateCollectable
  -nobuiltininc           Disable builtin #include directories
  -nostdinc++             Disable standard #include directories for the C++ standard library
  -nostdsysteminc         Disable standard system #include directories
  -objc-isystem <directory>
                          Add directory to the ObjC SYSTEM include search path
  -objcmt-migrate-literals
                          Enable migration to modern ObjC literals
  -objcmt-migrate-subscripting
                          Enable migration to modern ObjC subscripting
  -objcxx-isystem <directory>
                          Add directory to the ObjC++ SYSTEM include search path
  -o <file>               Write output to <file>
  -pg                     Enable mcount instrumentation
  -pic-level <value>      Value for __PIC__
  -pie-level <value>      Value for __PIE__
  -plugin-arg-<name> <arg>
                          Pass <arg> to plugin <name>
  -plugin <name>          Use the named plugin action instead of the default action (use "help" to list available options)
  -preamble-bytes=<value> Assume that the precompiled header is a precompiled preamble covering the first N bytes of the main file
  -print-decl-contexts    Print DeclContexts and their Decls
  -print-ivar-layout      Enable Objective-C Ivar layout bitmap print trace
  -print-preamble         Print the "preamble" of a file, which is a candidate for implicit precompiled headers.
  -print-stats            Print performance metrics and statistics
  -pthread                Support POSIX threads in generated code
  -relaxed-aliasing       Turn off Type Based Alias Analysis
  -relocatable-pch        Whether to build a relocatable precompiled header
  -remap-file <from>;<to> Replace the contents of the <from> file with the contents of the <to> file
  -resource-dir <value>   The directory which holds the compiler resource files
  -rewrite-macros         Expand macros without full preprocessing
  -rewrite-objc           Rewrite Objective-C source to C++
  -rewrite-test           Rewriter playground
  -serialize-diagnostic-file <filename>
                          File for serializing diagnostics in a binary format
  -split-dwarf-file <value>
                          File name to use for split dwarf debug info output
  -split-dwarf            Split out the dwarf .dwo sections
  -split-stacks           Try to use a split stack if possible.
  -stack-protector-buffer-size <value>
                          Lower bound for a buffer to be considered for stack protection
  -stack-protector <value>
                          Enable stack protectors
  -static-define          Should __STATIC__ be defined
  -std=<value>            Language standard to compile for
  -stdlib=<value>         C++ standard library to use
  -struct-path-tbaa       Turn on struct-path aware Type Based Alias Analysis
  -sys-header-deps        Include system headers in dependency output
  -target-abi <value>     Target a particular ABI type
  -target-cpu <value>     Target a specific cpu type
  -target-feature <value> Target specific attributes
  -target-linker-version <value>
                          Target linker version
  -test-coverage          Do not generate coverage files or remove coverage changes from IR
  -token-cache <path>     Use specified token cache file
  -traditional-cpp        Enable some traditional CPP emulation
  -trigraphs              Process trigraph sequences
  -trim-egraph            Only show error-related paths in the analysis graph
  -triple <value>         Specify target triple (e.g. i686-apple-darwin9)
  -undef                  undef all system defines
  -unoptimized-cfg        Generate unoptimized CFGs for all analyses
  -verify                 Verify output using a verifier
  -version                Print the compiler version
  -v                      Show commands to run and use verbose output
  -working-directory <value>
                          Resolve file paths relative to the specified directory
  -w                      Suppress all warnings
  -x <language>           Treat subsequent input files as having type <language>
