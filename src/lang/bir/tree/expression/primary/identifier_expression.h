
#pragma once

#include <string>
#include <utility>

#include "primary_expression.h"
#include "tree/abstract/codegen/value_generator.h"

namespace Brill::IR {
    class IdentifierExpression : public PrimaryExpression, public ValueGenerator {
    public:
        std::string value;

        explicit IdentifierExpression(std::string v) : value(std::move(v)) {}

        std::string valuegen(std::shared_ptr<CodegenContext>) override;
    };
}
