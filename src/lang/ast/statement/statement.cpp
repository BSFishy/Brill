
#include "statement.h"

#include "util.h"

#include "lang/ast/expression/expression.h"
#include "expression_statement.h"

using namespace Brill::AST;

std::shared_ptr<Statement> Brill::AST::convert(std::shared_ptr<ConvertContext> cctx, BrillParser::StatementContext *ctx) {
    if (BrillParser::ExpressionContext *expressionContext = ctx->expression()) {
        return std::make_shared<ExpressionStatement>(convert(cctx, expressionContext));
    } else {
        throw NotImplementedException();
    }
}
