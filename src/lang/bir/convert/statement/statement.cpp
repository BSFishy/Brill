
#include "statement.h"

#include "tree/expression/expression.h"
#include "tree/statement/expression_statement.h"
#include "convert/expression/expression.h"

#include "util.h"

using namespace Brill::IR;

std::shared_ptr<Statement> Convert::convert(BrillParser::StatementContext *ctx) {
    if (BrillParser::ExpressionContext *expressionContext = ctx->expression()) {
        std::shared_ptr<Expression> expression = convert(expressionContext);

        return std::shared_ptr<Statement>(new ExpressionStatement(expression));
    } else {
        throw NotImplementedException();
    }
}
