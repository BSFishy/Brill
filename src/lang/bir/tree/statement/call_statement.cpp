
#include "call_statement.h"

#include <vector>

#include "llvm/IR/Value.h"

#include "util.h"

using namespace Brill::IR;

llvm::Value *CallStatement::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::Function *callee = ctx->module->getFunction(this->name);
    if (!callee) {
        throw IllegalStateException("Could not get function " + this->name);
    }

    if (callee->arg_size() != this->parameters.size()) {
        throw IllegalStateException("Incorrect number of parameters passed to " + this->name);
    }

    std::vector<llvm::Value *> args;
    for (std::unique_ptr<Expression> & parameter : this->parameters) {
        args.push_back(parameter->codegen(ctx));

        if (!args.back()) {
            return nullptr;
        }
    }

    return ctx->builder->CreateCall(callee, args, "call_" + this->name);
}
