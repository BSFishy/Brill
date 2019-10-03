
#include "function_call_expression.h"

#include <vector>

#include "llvm/IR/Function.h"
#include "llvm/IR/Value.h"

#include "util.h"

using namespace Brill::IR;

llvm::Value *FunctionCallExpression::codegen(std::shared_ptr<CodegenContext> ctx) {
    llvm::Function *callee = (llvm::Function *) this->identifier->codegen(ctx);
    if (!callee) {
        throw IllegalStateException("Unknown function called");
    }

    if (callee->arg_size() != this->arguments.size()) {
        throw IllegalStateException("Incorrect number of arguments passed to function");
    }

    std::vector<llvm::Value *> args;
    for (std::shared_ptr<Expression> const& argument : this->arguments) {
        args.push_back(argument->codegen(ctx));

        if (!args.back()) {
            throw IllegalStateException("Could not codegen an argument for function");
        }
    }

    return ctx->builder->CreateCall(callee, args, "_call");
}
