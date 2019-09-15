
#include "brill.h"

#include "antlr4-runtime.h"
#include "BrillLexer.h"
#include "BrillParser.h"
#include <iostream>

using namespace Brill;

antlr4::tree::ParseTree *Brill::parseFile(const char *filename) {
    std::ifstream stream;
    stream.open(filename);
    antlr4::ANTLRInputStream input(stream);
    BrillLexer lexer(&input);
    antlr4::BufferedTokenStream tokens(&lexer);
    tokens.fill();
    printf("Created token stream:\n");
    for (antlr4::Token *t : tokens.getTokens()) {
        printf("\t%s - %s\n", t->getText().c_str(), lexer.getVocabulary().getSymbolicName(t->getType()).c_str());
    }
    BrillParser parser(&tokens);

    antlr4::tree::ParseTree *tree = parser.topLevel();
    return tree;
}

void Brill::compile() {
//   AST::Expression expression;
}

void Brill::compileFile(const char *filename) {
}
