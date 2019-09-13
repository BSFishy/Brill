
#include "brill.h"

#include "antlr4-runtime.h"
#include "generated/BrillLexer.h"
#include "generated/BrillParser.h"
#include <iostream>

using namespace Brill;

antlr4::tree::ParseTree *Brill::parseFile(const char *filename) {
  std::ifstream stream;
  stream.open(filename);
  antlr4::ANTLRInputStream input(stream);
  BrillLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);
  BrillParser parser(&tokens);

//   antlr4::tree::ParseTree *tree = parser.parse(parser.getRuleIndex(START_RULE));
  antlr4::tree::ParseTree *tree = parser.expression();
  return tree;
}

void Brill::compile() {
//   AST::Expression expression;
}

void Brill::compileFile(const char *filename) {
}
