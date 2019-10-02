
#include "brill.h"

#include <iostream>
#include <memory>

using namespace Brill;

std::shared_ptr<ParseContext> Brill::parse(std::istream &stream) {
    std::shared_ptr<antlr4::ANTLRInputStream>  input(new antlr4::ANTLRInputStream(stream));
    std::shared_ptr<BrillLexer>                lexer(new BrillLexer(&*input));
    std::shared_ptr<antlr4::CommonTokenStream> tokens(new antlr4::CommonTokenStream(&*lexer));
    std::shared_ptr<BrillParser>               parser(new BrillParser(&*tokens));

    BrillParser::TopLevelContext *tree = parser->topLevel();

    std::shared_ptr<ParseContext> context(new ParseContext(tree, input, lexer, tokens, parser));
    return context;
}

std::shared_ptr<ParseContext> Brill::parse(const char *) {

}

std::shared_ptr<ParseContext> Brill::parseFile(const char *filename) {
    std::ifstream stream;
    stream.open(filename);

    return parse(stream);
}

void compile(std::istream &stream) {

}

void Brill::compile(const char *filename) {
}

void Brill::compileFile(const char *filename) {
}

void compile(Brill::BrillParser::TopLevelContext *) {

}
