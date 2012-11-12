OVERVIEW: clang "gcc-compatible" driver

USAGE: clang [options] <inputs>

OPTIONS:
  -###                    Print the commands to run for this compilation
  --analyze               Run the static analyzer
  --help                  Display available options
  --migrate               Run the migrator
  --relocatable-pch       Build a relocatable precompiled header
  --serialize-diagnostics <value>
                          Serialize compiler diagnostics to a file
  -E                      Only run the preprocessor
  -ObjC++                 Treat source input files as Objective-C++ inputs
  -ObjC                   Treat source input files as Objective-C inputs
  -Qunused-arguments      Don't emit warning for unused driver arguments
  -S                      Only run preprocess and compilation steps
  -Wa,<arg>               Pass the comma separated arguments in <arg> to the assembler
  -Wl,<arg>               Pass the comma separated arguments in <arg> to the linker
  -Wp,<arg>               Pass the comma separated arguments in <arg> to the preprocessor
  -Xanalyzer <arg>        Pass <arg> to the static analyzer
  -Xassembler <arg>       Pass <arg> to the assembler
  -Xclang <arg>           Pass <arg> to the clang compiler
  -Xlinker <arg>          Pass <arg> to the linker
  -Xpreprocessor <arg>    Pass <arg> to the preprocessor
  -arcmt-migrate-emit-errors
                          Emit ARC errors even if the migrator can fix them
  -arcmt-migrate-report-output <value>
                          Output path for the plist report
  -c                      Only run preprocess, compile, and assemble steps
  -emit-ast               Emit Clang AST files for source inputs
  -emit-llvm              Use the LLVM representation for assembler and object files
  -fcatch-undefined-behavior
                          Generate runtime checks for undefined behavior.
  -flimit-debug-info      Limit debug information produced to reduce size of debug binary
  -fno-limit-debug-info   Do not limit debug information produced to reduce size of debug binary
  -ftrap-function=<value> Issue call to specified function rather than a trap instruction
  -gcc-toolchain <value>  Use the gcc toolchain at the given directory
  -objcmt-migrate-literals
                          Enable migration to modern ObjC literals
  -objcmt-migrate-subscripting
                          Enable migration to modern ObjC subscripting
  -o <file>               Write output to <file>
  -pipe                   Use pipes between commands, when possible
  -print-file-name=<file> Print the full library path of <file>
  -print-libgcc-file-name Print the library path for "libgcc.a"
  -print-prog-name=<name> Print the full program path of <name>
  -print-search-dirs      Print the paths used for finding libraries and programs
  -rewrite-objc           Rewrite Objective-C source to C++
  -save-temps             Save intermediate compilation results
  -target <value>         Generate code for the given target
  -time                   Time individual commands
  -verify                 Verify output using a verifier.
  -v                      Show commands to run and use verbose output
  -working-directory <value>
                          Resolve file paths relative to the specified directory
  -x <language>           Treat subsequent input files as having type <language>
