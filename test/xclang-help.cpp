OVERVIEW: clang LLVM compiler

USAGE: clang [options] <inputs>

OPTIONS:
  -###                    Print the commands to run for this compilation
  -E                      Only run the preprocessor
  -F <value>              Add directory to framework include search path
  -H                      Show header includes and nesting depth
  -I <value>              Add directory to include search path
  -MG                     Add missing headers to dependency list
  -MP                     Create phony target for each dependency (other than main file)
  -MQ <value>             Specify target to quote for dependency
  -MT <value>             Specify target for dependency
  -ObjC++                 Treat source input files as Objective-C++ inputs
  -ObjC                   Treat source input files as Objective-C inputs
  -P                      Disable linemarker output in -E mode
  -Qunused-arguments      Don't emit warning for unused driver arguments
  -S                      Only run preprocess and compilation steps
  -Wa,<arg>               Pass the comma separated arguments in <arg> to the assembler
  -Wl,<arg>               Pass the comma separated arguments in <arg> to the linker
  -Wp,<arg>               Pass the comma separated arguments in <arg> to the preprocessor
  -W<warning>             Enable the specified warning
  -Xanalyzer <arg>        Pass <arg> to the static analyzer
  -Xassembler <arg>       Pass <arg> to the assembler
  -Xclang <arg>           Pass <arg> to the clang compiler
  -Xlinker <arg>          Pass <arg> to the linker
  -Xpreprocessor <arg>    Pass <arg> to the preprocessor
  --analyze               Run the static analyzer
  -arcmt-migrate-emit-errors
                          Emit ARC errors even if the migrator can fix them
  -arcmt-migrate-report-output <value>
                          Output path for the plist report
  -cl-kernel-arg-info     OpenCL only. This option allows the compiler to store information about the arguments of a kernel(s)
  -cxx-isystem <directory>
                          Add directory to the C++ SYSTEM include search path
  -c                      Only run preprocess, compile, and assemble steps
  -dD                     Print macro definitions in -E mode in addition to normal output
  -dM                     Print macro definitions in -E mode instead of normal output
  -dependency-dot <value> Filename to write DOT-formatted header dependencies to
  -dependency-file <value>
                          Filename (or -) to write dependency output to
  -emit-ast               Emit Clang AST files for source inputs
  -emit-llvm              Use the LLVM representation for assembler and object files
  -faltivec               Enable AltiVec vector initializer syntax
  -fapple-kext            Use Apple's kernel extensions ABI
  -fapple-pragma-pack     Enable Apple gcc-compatible #pragma pack handling
  -fblocks                Enable the 'blocks' language feature
  -fborland-extensions    Accept non-standard constructs supported by the Borland compiler
  -fbounds-checking       Enable run-time bounds checks
  -fcolor-diagnostics     Use colors in diagnostics
  -fcomment-block-commands=<arg>
                          Treat each comma separated argument in <arg> as a documentation comment block command
  -fcxx-exceptions        Enable C++ exceptions
  -fdata-sections         Place each data in its own section (ELF Only)
  -fdelayed-template-parsing
                          Parse templated function definitions at the end of the translation unit 
  -fdiagnostics-parseable-fixits
                          Print fix-its in machine parseable form
  -fdiagnostics-print-source-range-info
                          Print source range spans in numeric form
  -fdiagnostics-show-name Print diagnostic name
  -fdiagnostics-show-note-include-stack
                          Display include stacks for diagnostic notes
  -fdiagnostics-show-option
                          Print option name with mappable diagnostics
  -fdiagnostics-show-template-tree
                          Print a template comparison tree for differing templates
  -fdollars-in-identifiers
                          Allow '$' in identifiers
  -femit-all-decls        Emit all declarations, even if unused
  -fexceptions            Enable support for exception handling
  -ffast-math             Enable the *frontend*'s 'fast-math' mode. This has no effect on optimizations, but provides a preprocessor macro __FAST_MATH__ the same as GCC's -ffast-math flag
  -ffp-contract=<value>   Form fused FP ops (e.g. FMAs): fast (everywhere) | on (according to FP_CONTRACT pragma, default) | off (never fuse)
  -ffreestanding          Assert that the compilation takes place in a freestanding environment
  -ffunction-sections     Place each function in its own section (ELF Only)
  -fgnu-keywords          Allow GNU-extension keywords regardless of language standard
  -fgnu-runtime           Generate output compatible with the standard GNU Objective-C runtime
  -fgnu89-inline          Use the gnu89 inline semantics
  -finstrument-functions  Generate calls to instrument function entry and exit
  -flimit-debug-info      Limit debug information produced to reduce size of debug binary
  -fmath-errno            Require math functions to indicate errors by setting errno
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
  -fno-builtin            Disable implicit builtin knowledge of functions
  -fno-common             Compile common globals like normal definitions
  -fno-constant-cfstrings Disable creation of CodeFoundation-type constant strings
  -fno-diagnostics-fixit-info
                          Do not include fixit information in diagnostics
  -fno-diagnostics-show-note-include-stack
                          Display include stacks for diagnostic notes
  -fno-dollars-in-identifiers
                          Disallow '$' in identifiers
  -fno-elide-constructors Disable C++ copy constructor elision
  -fno-elide-type         Do not elide types when printing diagnostics
  -fno-lax-vector-conversions
                          Disallow implicit conversions between vectors with a different number of elements or different element types
  -fno-limit-debug-info   Do not limit debug information produced to reduce size of debug binary
  -fno-merge-all-constants
                          Disallow merging of constants
  -fno-objc-infer-related-result-type
                          do not infer Objective-C related result type based on method family
  -fno-operator-names     Do not treat C++ operator name keywords as synonyms for operators
  -fno-rtti               Disable generation of rtti information
  -fno-sanitize-blacklist Don't use blacklist file for sanitizers
  -fno-sanitize-recover   Disable sanitizer check recovery
  -fno-show-column        Do not include column number on diagnostics
  -fno-show-source-location
                          Do not include source location information with diagnostics
  -fno-spell-checking     Disable spell-checking
  -fno-threadsafe-statics Do not emit code to make initialization of local statics thread safe
  -fno-use-cxa-atexit     Don't use __cxa_atexit for calling destructors
  -fno-use-init-array     Don't use .init_array instead of .ctors
  -fobjc-arc-exceptions   Use EH-safe code when synthesizing retains and releases in -fobjc-arc
  -fobjc-arc              Synthesize retain and release calls for Objective-C pointers
  -fobjc-exceptions       Enable Objective-C exceptions
  -fobjc-gc-only          Use GC exclusively for Objective-C related memory management
  -fobjc-gc               Enable Objective-C garbage collection
  -fobjc-runtime=<value>  Specify the target Objective-C runtime kind and version
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
  -fslp-vectorize-aggressive
                          Enable the BB vectorization passes
  -fslp-vectorize         Enable the superword-level parallelism vectorization passes
  -fstrict-enums          Enable optimizations based on the strict definition of an enum's value range
  -ftrap-function=<value> Issue call to specified function rather than a trap instruction
  -ftrapv-handler=<function name>
                          Specify the function to be called on overflow
  -ftrapv                 Trap on integer overflow
  -funroll-loops          Turn on loop unroller
  -fuse-init-array        Use .init_array instead of .ctors
  -fvectorize             Enable the loop vectorization passes
  -fvisibility-inlines-hidden
                          Give inline C++ member functions default visibility by default
  -fvisibility-ms-compat  Give global types 'default' visibility and global functions and variables 'hidden' visibility by default
  -fvisibility=<value>    Set the default symbol visibility for all global declarations
  -fwrapv                 Treat signed integer overflow as two's complement
  -fwritable-strings      Store string literals as writable data
  -gcc-toolchain <value>  Use the gcc toolchain at the given directory
  -gline-tables-only      Emit debug line number tables only
  -g                      Generate source level debug information
  -help                   Display available options
  -idirafter <value>      Add directory to AFTER include search path
  -iframework <value>     Add directory to SYSTEM framework search path
  -imacros <file>         Include macros from file before parsing
  -include-pch <file>     Include precompiled header file
  -include <file>         Include file before parsing
  -index-header-map       Make the next included directory (-I or -F) an indexer header map
  -iprefix <dir>          Set the -iwithprefix/-iwithprefixbefore prefix
  -iquote <directory>     Add directory to QUOTE include search path
  -isysroot <dir>         Set the system root directory (usually /)
  -isystem <directory>    Add directory to SYSTEM include search path
  -iwithprefixbefore <dir>
                          Set directory to include search path with prefix
  -iwithprefix <dir>      Set directory to SYSTEM include search path with prefix
  -iwithsysroot <directory>
                          Add directory to SYSTEM include search path, absolute paths are relative to -isysroot
  --migrate               Run the migrator
  -mllvm <value>          Additional arguments to forward to LLVM's option processing
  -mms-bitfields          Set the default structure layout to be compatible with the Microsoft compiler standard
  -mno-global-merge       Disable merging of globals
  -mno-implicit-float     Don't generate implicit floating point instructions
  -momit-leaf-frame-pointer
                          Omit frame pointer setup for leaf functions
  -mqdsp6-compat          Enable hexagon-qdsp6 backward compatibility
  -mrelax-all             (integrated-as) Relax all machine instructions
  -mrtd                   Make StdCall calling convention the default
  -msoft-float            Use software floating point
  -mstack-alignment=<value>
                          Set the stack alignment
  -mstackrealign          Force realign the stack at entry to every function
  -mstrict-align          Force all memory accesses to be aligned (ARM only)
  -nobuiltininc           Disable builtin #include directories
  -nostdinc++             Disable standard #include directories for the C++ standard library
  -objcmt-migrate-literals
                          Enable migration to modern ObjC literals
  -objcmt-migrate-subscripting
                          Enable migration to modern ObjC subscripting
  -o <file>               Write output to <file>
  -pg                     Enable mcount instrumentation
  -pipe                   Use pipes between commands, when possible
  -print-file-name=<file> Print the full library path of <file>
  -print-ivar-layout      Enable Objective-C Ivar layout bitmap print trace
  -print-libgcc-file-name Print the library path for "libgcc.a"
  -print-prog-name=<name> Print the full program path of <name>
  -print-search-dirs      Print the paths used for finding libraries and programs
  -pthread                Support POSIX threads in generated code
  -rewrite-legacy-objc    Rewrite Legacy Objective-C source to C++
  -rewrite-objc           Rewrite Objective-C source to C++
  -save-temps             Save intermediate compilation results
  -serialize-diagnostics <value>
                          Serialize compiler diagnostics to a file
  -std=<value>            Language standard to compile for
  -stdlib=<value>         C++ standard library to use
  -target <value>         Generate code for the given target
  -time                   Time individual commands
  -traditional-cpp        Enable some traditional CPP emulation
  -trigraphs              Process trigraph sequences
  -undef                  undef all system defines
  -verify                 Verify output using a verifier
  -v                      Show commands to run and use verbose output
  -working-directory <value>
                          Resolve file paths relative to the specified directory
  -w                      Suppress all warnings
  -x <language>           Treat subsequent input files as having type <language>
