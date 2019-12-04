subdir('ast')

lang_src = files('brill.cpp')

lang_lib = library('lang', lang_src, include_directories: [antlr_inc, main_inc, util_inc], dependencies: [thread_dep, llvm_dep, antlr_dep, parser_dep], link_with: [ast_lib])
