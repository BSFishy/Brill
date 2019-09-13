
#pragma once

#include "antlr4-runtime.h"
#include <string>

#include "ast/expression.h"

#define START_RULE "expression"

namespace Brill {

antlr4::tree::ParseTree* parse();
antlr4::tree::ParseTree* parseFile(const char *);

void compile();
void compileFile(const char *);

}
