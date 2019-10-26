
#pragma once

#include <memory>

#include "BrillParser.h"

#include "lang/ast/node.h"

namespace Brill::AST {
    class Statement : public Node {
    public:
        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override = 0;
    };

    std::shared_ptr<Statement> convert(std::shared_ptr<ConvertContext>, BrillParser::StatementContext*);
}
