
grammar ModuleMap;

options {
language=Cpp;
}

topLevel : module* EOF ;

// Module

module : 'module' moduleName? '{' moduleBody '}' ;
moduleName : Identifier ;
moduleBody : moduleContent
           | module
           ;
moduleContent : file* | '*' | '**' ;

// File

file : filename ( '/' filename )* ;
filename : Identifier ;


// LEXER STUFF

MODULE : 'module' ;
PERIOD : '.' ;
SLASH : '/' ;
STAR : '*' ;
DOUBLE_STAR : '**' ;

OPEN_CURLY : '{' ;
CLOSE_CURLY : '}' ;

Identifier : IdentifierHead ( IdentifierBody | IdentifierExtension )* ;
fragment IdentifierHead : [a-zA-Z] ;
fragment IdentifierBody : IdentifierHead | [0-9_] ;
fragment IdentifierExtension : '.' IdentifierBody ;

WS : [ \r\n\t] -> skip ;
