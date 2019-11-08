
#include "function_call_argument.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/expression/expression.h"
#include "tree/TerminalNode.h"

using namespace Brill::AST;

FunctionCallArgument::FunctionCallArgument(const std::shared_ptr<SymbolTable> &st, const std::shared_ptr<Expression> &e) : Node(st) {
    this->expression = e;
}

llvm::Value *FunctionCallArgument::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return this->expression->codegen(ctx);
}

std::shared_ptr<FunctionCallArgument> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::FunctionCallArgumentContext *ctx) {
    if (antlr4::tree::TerminalNode *identifierNode = ctx->Identifier()) {
        cctx->error(identifierNode->getSymbol(), "Named arguments are not implemented");
        return nullptr;
    }

    if (BrillParser::OpContext *operatorContext = ctx->op()) {
        cctx->error(operatorContext->getStart(), "Operator arguments are not implemented");
        return nullptr;
    } else {
        std::shared_ptr<Expression> expression = convert(cctx, ctx->expression());
        if (!expression) {
            return nullptr;
        }

        return std::make_shared<FunctionCallArgument>(cctx->parent->getSymbolTable(), expression);
    }
}
