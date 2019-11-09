
#include "function.h"

#include <vector>

#include "llvm/IR/Verifier.h"
#include "llvm/IR/Type.h"

#include "abstract/convert_context.h"
#include "abstract/codegen_context.h"
#include "lang/ast/symbol_table.h"
#include "lang/ast/value_wrapper.h"
#include "lang/ast/statement/statement.h"
#include "parameter.h"

#include "util.h"

using namespace Brill::AST;

Function::Function(std::string n, const std::shared_ptr<Node> &p, bool v) : NamedNode(n), Node(p->getSymbolTable()->child()), parameters(), varargs(v) {
    parent = p;
}

llvm::Value *Function::codegen(std::shared_ptr<CodegenContext> ctx) const {
    llvm::Function *function = ctx->module->getFunction(this->getName());

    if (!function) {
        std::vector<llvm::Type*> args;
        for (const auto &parameter : this->parameters) {
            args.push_back(parameter->getType(ctx));
        }

        llvm::FunctionType *functionType = llvm::FunctionType::get(llvm::Type::getVoidTy(*(ctx->context)), args, this->varargs);
        function = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, this->getName(), *(ctx->module));
    }

    if (!function) {
        throw IllegalStateException("Could not generate function: " + this->getName());
    }

    if (function->getInstructionCount() != 0) {
        return function;
    }

    unsigned index = 0;
    for (auto &arg : function->args()) {
        arg.setName(this->parameters[index++]->getLocalname());
        this->getSymbolTable()->add(std::make_shared<ValueWrapper>(this->getSymbolTable(), &arg));
        llvm::outs() << "Argument: %s - " << arg.getName().str();
        arg.getType()->print(llvm::outs());
        llvm::outs() << '\n';
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

void Function::setVarargs(bool value) {
    this->varargs = value;
}

void Function::addParameter(std::shared_ptr<Parameter> parameter) {
    this->parameters.push_back(parameter);
}

std::shared_ptr<Function> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::FunctionDeclarationContext *ctx) {
    std::string name = ctx->functionName()->Identifier()->getText();
    std::shared_ptr<Function> function = std::make_shared<Function>(name, cctx->parent);
    std::shared_ptr<ConvertContext> childCtx = cctx->withParent(function);

    BrillParser::FunctionSignatureContext *signatureContext = ctx->functionSignature();
    BrillParser::ParameterClauseContext *parameterClauseContext = signatureContext->parameterClause();
    if (BrillParser::ParameterListContext *parameterListContext = parameterClauseContext->parameterList()) {
        function->setVarargs(parameterListContext->ELIPSES() != nullptr);

        for (const auto &parameterContext : parameterListContext->parameter()) {
            if (std::shared_ptr<Parameter> parameter = convert(childCtx, parameterContext)) {
                function->addParameter(parameter);
            } else {
                return nullptr;
            }
        }
    }

    if (BrillParser::FunctionBodyContext *body = ctx->functionBody()) {
        if (BrillParser::StatementsContext *statements = body->codeBlock()->statements()) {
            for (BrillParser::StatementContext *statementContext : statements->statement()) {
                if (std::shared_ptr<Statement> statement = convert(childCtx, statementContext)) {
                    function->addStatement(statement);
                }
            }
        }
    }

    return function;
}
