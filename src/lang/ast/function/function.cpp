
#include "function.h"

#include <vector>

#include "llvm/IR/Verifier.h"

#include "abstract/convert_context.h"
#include "abstract/codegen_context.h"
#include "lang/ast/symbol_table.h"
#include "lang/ast/statement/statement.h"

#include "util.h"

using namespace Brill::AST;

Function::Function(std::string n, const std::shared_ptr<Node> &p) : NamedNode(n), Node(p->getSymbolTable()->child()) {
    parent = p;
}

llvm::Value *Function::codegen(std::shared_ptr<CodegenContext> ctx) const {
    llvm::Function *function = ctx->module->getFunction(this->getName());

    if (!function) {
        llvm::FunctionType *functionType = llvm::FunctionType::get(llvm::Type::getVoidTy(*(ctx->context)), false);

        function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, this->getName(), *(ctx->module));
    }

    if (!function) {
        throw IllegalStateException("Could not generate function: " + this->getName());
    }

    if (!this->getStatements().empty()) {
        llvm::BasicBlock *block = llvm::BasicBlock::Create(*(ctx->context), "entry", function);
        ctx->builder->SetInsertPoint(block);

        this->codegenStatements(ctx);

        ctx->builder->CreateRetVoid();
    }

    llvm::verifyFunction(*function);
    return function;
}

std::shared_ptr<Function> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::FunctionDeclarationContext *ctx) {
    std::string name = ctx->functionName()->Identifier()->getText();
    std::shared_ptr<Function> function = std::make_shared<Function>(name, cctx->parent);
    std::shared_ptr<ConvertContext> childCtx = cctx->withParent(function);

    if (BrillParser::FunctionBodyContext *body = ctx->functionBody()) {
        if (BrillParser::StatementsContext *statements = body->codeBlock()->statements()) {
            for (BrillParser::StatementContext *statementContext : statements->statement()) {
                function->addStatement(convert(childCtx, statementContext));
            }
        }
    }

    return function;
}
