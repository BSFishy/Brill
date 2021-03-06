
#include "statement.h"

#include "util.h"

#include "lang/ast/abstract/convert_context.h"
#include "lang/ast/expression/expression.h"
#include "expression_statement.h"

using namespace Brill::AST;

Statement::Statement(const std::shared_ptr<SymbolTable> &st) : Node(st) {}

std::shared_ptr<Statement> Brill::AST::convert(const std::shared_ptr<ConvertContext> &cctx, BrillParser::StatementContext *ctx) {
    if (BrillParser::ExpressionContext *expressionContext = ctx->expression()) {
        std::shared_ptr<Expression> expression = convert(cctx, expressionContext);
        if (!expression) {
            return nullptr;
        }

        return std::make_shared<ExpressionStatement>(cctx->parent->getSymbolTable(), expression);
    } else {
        cctx->error(ctx->getStart(), "Not implemented");
        return nullptr;
    }
}
