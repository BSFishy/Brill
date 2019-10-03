
#include "function_call_expression.h"

#include <vector>

#include "llvm/IR/Function.h"
#include "llvm/IR/Value.h"

#include "util.h"

using namespace Brill::IR;

llvm::Value *FunctionCallExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::Function *callee = ctx->module->getFunction(this->name);
    if (!callee) {
        throw IllegalStateException("Unknown function: " + this->name);
    }

    if (callee->arg_size() != this->arguments.size()) {
        throw IllegalStateException("Incorrect number of arguments passed to: " + this->name);
    }

    std::vector<llvm::Value *> args;
    for (std::shared_ptr<Expression> const& argument : this->arguments) {
        args.push_back(argument->codegen(ctx));

        if (!args.back()) {
            throw IllegalStateException("Could not codegen an argument for function: " + this->name);
        }
    }

    return ctx->builder->CreateCall(callee, args, "call_" + this->name);
}
