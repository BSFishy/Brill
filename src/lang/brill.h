
#include "antlr4-runtime.h"

#include "ast/expression.h"

namespace Brill {

antlr4::tree::ParseTree parse();
antlr4::tree::ParseTree parseFile();

void compile();
void compileFile();

}
