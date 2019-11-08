
#include "string_literal.h"

#include "lang/ast/abstract/codegen_context.h"

using namespace Brill::AST;

StringLiteral::StringLiteral(const std::shared_ptr<SymbolTable> &st, std::string v) : Literal(st), value(std::move(v)) {}

llvm::Value *StringLiteral::codegen(std::shared_ptr<CodegenContext> ctx) const {
    return ctx->builder->CreateGlobalStringPtr(this->convert(this->value));
}

std::string StringLiteral::convert(const std::string value) const {
    std::string newValue;

    for (std::string::size_type i = 1; i < value.size()-1; i++) { // Iterate excluding the quotes
        const char c = value[i];

        if (c == '\\' && i+1 < value.size()-1) {
            const char n = value[++i];

            switch (n) {
                case 'n': newValue += '\n'; break;
                case 't': newValue += '\t'; break;
                case 'r': newValue += '\r'; break;
                case '\"': newValue += '\"'; break;
                case '\'': newValue += '\''; break;
                case '\\': newValue += '\\'; break;
                default: break;
            }
        } else {
            newValue += c;
        }
    }

    return newValue;
}
