
#include "function.h"

#include <iostream>
#include <string>

#include "convert/statement/statement.h"

#include "tree/modules.h"
#include "tree/statement/statement.h"

#include "argument.h"

using namespace Brill::IR;

std::shared_ptr<Function> Convert::convert(BrillParser::FunctionDeclarationContext *ctx) {
    std::shared_ptr<IR::Module> module = Brill::getOrCreateModule("test");

    std::basic_string<char> name = ctx->functionName()->Identifier()->getText();
    std::shared_ptr<Function> function(new Function(module, name));

    if (BrillParser::ParameterListContext *parameterListContext = ctx->functionSignature()->parameterClause()->parameterList()) {
        for (BrillParser::ParameterContext* const& parameterContext : parameterListContext->parameter()) {
            std::shared_ptr<Argument> parameter = convert(parameterContext);

            function->arguments.push_back(parameter);
        }

        if (parameterListContext->ELIPSES()) {
            function->varargs = true;
        }
    }

    if (BrillParser::FunctionBodyContext *body = ctx->functionBody()) {
        if (BrillParser::StatementsContext *statements = body->codeBlock()->statements()) {
            for (BrillParser::StatementContext *statementContext : statements->statement()) {
                std::shared_ptr<Statement> statement = convert(statementContext);

                function->addStatement(statement);
            }
        }
    }

    return function;
}
