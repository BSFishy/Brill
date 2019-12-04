main_inc = include_directories('.')

# Util
util_inc = include_directories('util')

# Lang
subdir('lang')

# Main
main_src = files('main.cpp')

brill_exe = executable('brill', main_src, include_directories: [antlr_inc, main_inc, util_inc], dependencies: [thread_dep, llvm_dep, antlr_dep, parser_dep], link_with: [lang_lib, ast_lib])
