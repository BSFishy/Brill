
#pragma once

#include <vector>
#include <string>
#include <memory>

#include "llvm/IR/Value.h"

#include "tree/abstract/codegen/code_generator.h"
#include "tree/abstract/codegen/codegen_context.h"
#include "tree/container/statement_container.h"

#include "tree/module.h"
#include "tree/constructs/class/class.h"
#include "tree/statement/statement.h"
#include "argument.h"

namespace Brill::IR {
    class Function : public StatementContainer, public CodeGenerator {
    public:
        std::string name;
        std::shared_ptr<Module> module;
        std::shared_ptr<Class> parentClass;

        std::vector<std::shared_ptr<Argument>> arguments;

        explicit Function(std::shared_ptr<Module> &m, std::string n) : module(m), name(std::move(n)), parentClass(nullptr) {}
        explicit Function(std::shared_ptr<Module> &m, std::string n, std::shared_ptr<Class> &p) : module(m), name(std::move(n)), parentClass(p) {}

        llvm::Value *codegen(std::shared_ptr<CodegenContext>) override;
    };
}
