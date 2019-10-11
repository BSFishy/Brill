
#pragma once

#include <vector>
#include <string>
#include <memory>

#include "llvm/IR/Value.h"

#include "tree/abstract/codegen/named_code_generator.h"
#include "tree/abstract/codegen/codegen_context.h"
#include "tree/container/statement_container.h"

#include "tree/module.h"
#include "tree/container/function_container.h"
#include "tree/statement/statement.h"
#include "argument.h"

namespace Brill::IR {
    class Function : public StatementContainer, public NamedCodeGenerator {
    public:
        std::shared_ptr<Module> module;
        StatementContainer *parentClass;

        std::vector<std::shared_ptr<Argument>> arguments;
        bool varargs = false;

        explicit Function(std::shared_ptr<Module> &m, std::string n) : module(m), NamedCodeGenerator(std::move(n)), parentClass(nullptr) {}
        explicit Function(std::shared_ptr<Module> &m, std::string n, StatementContainer *&p) : module(m), NamedCodeGenerator(std::move(n)), parentClass(p) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
