
#pragma once

#include <string>
#include <list>
#include <memory>

#include "llvm/IR/Value.h"

#include "statement.h"
#include "tree/expression/expression.h"

namespace Brill::IR {
    class CallStatement : public Statement {
    public:
        std::string name;
        std::list<std::unique_ptr<Expression>> parameters;

        explicit CallStatement(std::string n) : name(std::move(n)) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
