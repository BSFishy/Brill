
#include "brill.h"

#include <iostream>

using namespace Brill;

BrillParser::TopLevelContext *Brill::parse(std::istream &stream) {
    antlr4::ANTLRInputStream  input(stream);
    BrillLexer                lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    BrillParser               parser(&tokens);

    BrillParser::TopLevelContext *tree = parser.topLevel();
    return tree;
}

BrillParser::TopLevelContext *Brill::parse(const char *) {

}

BrillParser::TopLevelContext *Brill::parseFile(const char *filename) {
    std::ifstream stream;
    stream.open(filename);

    return parse(stream);
}

void Brill::compile(const char *filename) {
}

void Brill::compileFile(const char *filename) {
}
