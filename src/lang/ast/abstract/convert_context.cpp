
#include "convert_context.h"

#include "lang/ast/diagnostic/compiler_diagnostics.h"
#include "lang/ast/diagnostic/issue.h"

using namespace Brill::AST;

ConvertContext::ConvertContext(std::string mn) : moduleName(mn) {
    this->diagnostics = std::make_shared<CompilerDiagnostics>();
}

ConvertContext::ConvertContext(std::string mn, const std::shared_ptr<Node> &p, const std::shared_ptr<CompilerDiagnostics> &d) : moduleName(mn) {
    this->parent = p;
    this->diagnostics = d;
}

std::shared_ptr<ConvertContext> ConvertContext::withParent(const std::shared_ptr<Node> &p) const {
    return std::make_shared<ConvertContext>(this->moduleName, p, this->diagnostics);
}

void ConvertContext::warn(antlr4::Token *token, const std::string &message) {
    this->diagnostics->warn(token, message);
}

void ConvertContext::error(antlr4::Token *token, const std::string &message) {
    this->diagnostics->error(token, message);
}
