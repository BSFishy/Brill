# Brill library
brill_lib_src = files('brill/Compiler.cpp',
                        'brill/SourceManager.cpp',
                        'brill/AST/ParseTreeVisitor.cpp',
                        'brill/Diagnostics/DiagnosticsEngine.cpp')

brill_lib = library('brill', brill_lib_src, include_directories: [antlr_inc, brill_inc], dependencies: [thread_dep, llvm_dep, antlr_dep, parser_dep])
brill_dep = declare_dependency(include_directories: [brill_inc], link_with: [brill_lib])