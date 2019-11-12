
#include "function_call_expression.h"

#include "BrillParser.h"
#include "lang/ast/abstract/codegen_context.h"
#include "lang/ast/abstract/convert_context.h"

#include "function_call_argument.h"

#include "util.h"

using namespace Brill::AST;

FunctionCallExpression::FunctionCallExpression(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<PostfixExpression> &pe) : PostfixExpression(st) {
    postfixExpression = pe;
}

llvm::Value *FunctionCallExpression::codegen(std::shared_ptr<CodegenContext> ctx) const {
    llvm::Function *function = (llvm::Function*) this->postfixExpression->codegen(ctx);
    if (!function) {
        throw IllegalStateException("Could not get function for call.");
    }

    std::vector<llvm::Value*> args;
    for (const auto &argument : this->arguments) {
        auto value = argument->codegen(ctx);
        args.push_back(value);
    }

    return ctx->builder->CreateCall(function->getFunctionType(), function, args);
}

void FunctionCallExpression::addArgument(const std::shared_ptr<FunctionCallArgument> &argument) {
    this->arguments.push_back(argument);
}

std::shared_ptr<FunctionCallExpression> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::FunctionCallExpressionContext *ctx) {
    if (BrillParser::TrailingClosureContext *closureContext = ctx->trailingClosure()) {
        cctx->error(closureContext->getStart(), "Trailing closures are not implemented yet");
        return nullptr;
    }

    std::shared_ptr<PostfixExpression> postfixExpression = convert(cctx, ctx->postfixExpression());
    if (!postfixExpression) {
        return nullptr;
    }

    std::shared_ptr<FunctionCallExpression> callExpression = std::make_shared<FunctionCallExpression>(cctx->parent->getSymbolTable(), postfixExpression);

    if (BrillParser::FunctionCallArgumentClauseContext *argumentContext = ctx->functionCallArgumentClause()) {
        if (BrillParser::FunctionCallArgumentListContext *argumentListContext = argumentContext->functionCallArgumentList()) {
            for (const auto &argumentContext : argumentListContext->functionCallArgument()) {
                std::shared_ptr<FunctionCallArgument> argument = convert(cctx, argumentContext);
                if (!argument) {
                    return nullptr;
                }

                callExpression->addArgument(argument);
            }
        }
    }

    return callExpression;
}
