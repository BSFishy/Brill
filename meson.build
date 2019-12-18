project('Brill', 'cpp',
        version: '0.1',
        default_options : ['cpp_std=c++17'])

# Threads
thread_dep = dependency('threads')

# CMake stuff
cmake = import('cmake')

antlr = cmake.subproject('antlr')
antlr_inc = antlr.get_variable('antlr4_shared_inc')
antlr_dep = antlr.get_variable('antlr4_shared_dep')

# Antlr grammar stuff
java = find_program('java')

parser_input = files('Brill.g4')
parser_cxx_outputs = ['BrillLexer.h', 'BrillLexer.cpp',
        'BrillParser.h', 'BrillParser.cpp',
        'BrillBaseVisitor.h', 'BrillBaseVisitor.cpp',
        'BrillVisitor.h', 'BrillVisitor.cpp']
parser_outputs = ['BrillLexer.interp', 'Lexer.tokens']
parser_outputs += parser_cxx_outputs

parser = custom_target('gen-parser',
        input: parser_input,
        output: parser_outputs,
        command: [java, '-jar', '/usr/local/lib/antlr-4.7.2-complete.jar',
                '@INPUT@',
                '-o', '@OUTDIR@',
                '-no-listener',
                '-Dlanguage=Cpp',
                '-visitor',
                '-package', 'Brill',
                '-Xexact-output-dir'])
parser_lib = library('parser', parser, include_directories: [antlr_inc], dependencies: [thread_dep, antlr_dep])
parser_dep = declare_dependency(sources: [parser[2], parser[4], parser[6], parser[8]], link_with: [parser_lib])

# LLVM
llvm_dep = dependency('LLVM')
llvm_version = llvm_dep.get_variable(cmake: 'LLVM_PACKAGE_VERSION', configtool: 'version')

# Sources
subdir('include')
subdir('lib')
subdir('tools')

# subdir('src')
# test('basic compile', brill_exe, args: [files('examples/test.brill')])